/*
 * Copyright 2019-2020 PixlOne
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <algorithm>
#include "GestureAction.h"
#include "../Device.h"
#include "../backend/hidpp20/features/ReprogControls.h"

using namespace logid::actions;
using namespace logid;
using namespace logid::backend;

GestureAction::Direction GestureAction::toDirection(std::string direction)
{
    std::transform(direction.begin(), direction.end(), direction.begin(),
            ::tolower);
    if(direction == "up")
        return Up;
    else if(direction == "down")
        return Down;
    else if(direction == "left")
        return Left;
    else if(direction == "right")
        return Right;
    else if(direction == "none")
        return None;
    else
        throw std::invalid_argument("direction");
}

GestureAction::Direction GestureAction::toDirection(int16_t x, int16_t y)
{
    if(x >= 0 && y >= 0)
        return x >= y ? Right : Down;
    else if(x < 0 && y >= 0)
        return -x <= y ? Down : Left;
    else if(x <= 0 && y < 0)
        return x <= y ? Left : Up;
    else
        return x <= -y ? Up : Right;
}

GestureAction::GestureAction(Device* dev, libconfig::Setting& config) :
    Action (dev), _config (dev, config)
{
}

void GestureAction::press()
{
    _pressed = true;
    _x = 0, _y = 0;
    for(auto& gesture : _config.gestures())
        gesture.second->press();
}

void GestureAction::release()
{
    _pressed = false;
    bool threshold_met = false;

    auto d = toDirection(_x, _y);
    auto primary_gesture = _config.gestures().find(d);
    if(primary_gesture != _config.gestures().end()) {
        threshold_met = primary_gesture->second->metThreshold();
        primary_gesture->second->release(true);
    }

    for(auto& gesture : _config.gestures()) {
        if(gesture.first == d)
            continue;
        if(!threshold_met) {
            if(gesture.second->metThreshold()) {
                // If the primary gesture did not meet its threshold, use the
                // secondary one.
                threshold_met = true;
                gesture.second->release(true);
                break;
            }
        } else {
            gesture.second->release(false);
        }
    }

    if(!threshold_met) {
        if(_config.noneAction()) {
            _config.noneAction()->press();
            _config.noneAction()->release();
        }
    }
}

void GestureAction::move(int16_t x, int16_t y)
{
    auto new_x = _x + x, new_y = _y + y;

    if(abs(x) > 0) {
        if(_x < 0 && new_x >= 0) { // Left -> Origin/Right
            auto left = _config.gestures().find(Left);
            if(left != _config.gestures().end())
                left->second->move(_x);
            if(new_x) { // Ignore to origin
                auto right = _config.gestures().find(Right);
                if(right != _config.gestures().end())
                    right->second->move(new_x);
            }
        } else if(_x > 0 && new_x <= 0) { // Right -> Origin/Left
            auto right = _config.gestures().find(Right);
            if(right != _config.gestures().end())
                right->second->move(-_x);
            if(new_x) { // Ignore to origin
                auto left = _config.gestures().find(Left);
                if(left != _config.gestures().end())
                    left->second->move(-new_x);
            }
        } else if(new_x < 0) { // Origin/Left to Left
            auto left = _config.gestures().find(Left);
            if(left != _config.gestures().end())
                left->second->move(-x);
        } else if(new_x > 0) { // Origin/Right to Right
            auto right = _config.gestures().find(Right);
            if(right != _config.gestures().end())
                right->second->move(x);
        }
    }

    if(abs(y) > 0) {
        if(_y > 0 && new_y <= 0) { // Up -> Origin/Down
            auto up = _config.gestures().find(Up);
            if(up != _config.gestures().end())
                up->second->move(_y);
            if(new_y) { // Ignore to origin
                auto down = _config.gestures().find(Down);
                if(down != _config.gestures().end())
                    down->second->move(new_y);
            }
        } else if(_y < 0 && new_y >= 0) { // Down -> Origin/Up
            auto down = _config.gestures().find(Down);
            if(down != _config.gestures().end())
                down->second->move(-_y);
            if(new_y) { // Ignore to origin
                auto up = _config.gestures().find(Up);
                if(up != _config.gestures().end())
                    up->second->move(-new_y);
            }
        } else if(new_y < 0) { // Origin/Up to Up
            auto up = _config.gestures().find(Up);
            if(up != _config.gestures().end())
                up->second->move(-y);
        } else if(new_y > 0) {// Origin/Down to Down
            auto down = _config.gestures().find(Down);
            if(down != _config.gestures().end())
                down->second->move(y);
        }
    }

    _x = new_x; _y = new_y;
}

uint8_t GestureAction::reprogFlags() const
{
    return (hidpp20::ReprogControls::TemporaryDiverted |
        hidpp20::ReprogControls::RawXYDiverted);
}

GestureAction::Config::Config(Device* device, libconfig::Setting &root) :
    Action::Config(device)
{
    try {
        auto& gestures = root.lookup("gestures");

        if(!gestures.isList()) {
            logPrintf(WARN, "Line %d: gestures must be a list, ignoring.",
                    gestures.getSourceLine());
            return;
        }

        int gesture_count = gestures.getLength();

        for(int i = 0; i < gesture_count; i++) {
            if(!gestures[i].isGroup()) {
                logPrintf(WARN, "Line %d: gesture must be a group, skipping.",
                        gestures[i].getSourceLine());
                continue;
            }

            Direction d;
            try {
                auto& direction = gestures[i].lookup("direction");
                if(direction.getType() != libconfig::Setting::TypeString) {
                    logPrintf(WARN, "Line %d: direction must be a string, "
                                    "skipping.", direction.getSourceLine());
                    continue;
                }

                try {
                    d = toDirection(direction);
                } catch(std::invalid_argument& e) {
                    logPrintf(WARN, "Line %d: Invalid direction %s",
                            direction.getSourceLine(), (const char*)direction);
                    continue;
                }
            } catch(libconfig::SettingNotFoundException& e) {
                logPrintf(WARN, "Line %d: direction is a required field, "
                                "skipping.", gestures[i].getSourceLine());
                continue;
            }

            if(_gestures.find(d) != _gestures.end() || (d == None && _none_action)) {
                logPrintf(WARN, "Line %d: Gesture is already defined for "
                                "this direction, duplicate ignored.",
                          gestures[i].getSourceLine());
                continue;
            }

            if(d == None) {
                try {
                    _none_action = Action::makeAction(_device,
                            gestures[i].lookup("action"));
                } catch (InvalidAction& e) {
                    logPrintf(WARN, "Line %d: %s is not a valid action, "
                                    "skipping.", gestures[i].lookup("action")
                                    .getSourceLine(), e.what());
                } catch (libconfig::SettingNotFoundException& e) {
                    logPrintf(WARN, "Line %d: action is a required field, "
                                    "skipping.", gestures[i].getSourceLine(),
                                    e.what());
                }
                continue;
            }

            try {
                _gestures.emplace(d, Gesture::makeGesture(_device,
                        gestures[i]));
            } catch(InvalidGesture& e) {
                logPrintf(WARN, "Line %d: Invalid gesture: %s",
                        gestures[i].getSourceLine(), e.what());
            }
        }

    } catch(libconfig::SettingNotFoundException& e) {
        logPrintf(WARN, "Line %d: gestures is a required field, ignoring.",
                root.getSourceLine());
    }
}

std::map<GestureAction::Direction, std::shared_ptr<Gesture>>&
    GestureAction::Config::gestures()
{
    return _gestures;
}

std::shared_ptr<Action> GestureAction::Config::noneAction()
{
    return _none_action;
}