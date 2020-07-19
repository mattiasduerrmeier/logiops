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
#include "NullAction.h"
#include "../Device.h"
#include "../backend/hidpp20/features/ReprogControls.h"

using namespace logid::actions;

NullAction::NullAction(Device* device) : Action(device)
{
}

void NullAction::press()
{
    _pressed = true;
}

void NullAction::release()
{
    _pressed = false;
}

uint8_t NullAction::reprogFlags() const
{
    return backend::hidpp20::ReprogControls::TemporaryDiverted;
}