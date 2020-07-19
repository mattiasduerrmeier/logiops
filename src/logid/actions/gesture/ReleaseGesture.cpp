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
#include "ReleaseGesture.h"

using namespace logid::actions;

ReleaseGesture::ReleaseGesture(Device *device, libconfig::Setting &root) :
    Gesture (device), _config (device, root)
{
}

void ReleaseGesture::press()
{
    _axis = 0;
}

void ReleaseGesture::release(bool primary)
{
    if(metThreshold() && primary) {
        _config.action()->press();
        _config.action()->release();
    }
}

void ReleaseGesture::move(int16_t axis)
{
    _axis += axis;
}

bool ReleaseGesture::metThreshold() const
{
    return _axis >= _config.threshold();
}