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

#include <cassert>
#include <string>
#include "Error.h"

using namespace logid::backend::hidpp10;

Error::Error(uint8_t code): _code(code)
{
    assert(code != Success);
}

const char* Error::what() const noexcept
{
    switch(_code) {
    case Success:
        return "Success";
    case InvalidSubID:
        return "Invalid sub ID";
    case InvalidAddress:
        return "Invalid address";
    case InvalidValue:
        return "Invalid value";
    case ConnectFail:
        return "Connection failure";
    case TooManyDevices:
        return "Too many devices";
    case AlreadyExists:
        return "Already exists";
    case Busy:
        return "Busy";
    case UnknownDevice:
        return "Unknown device";
    case ResourceError:
        return "Resource error";
    case RequestUnavailable:
        return "Request unavailable";
    case InvalidParameterValue:
        return "Invalid parameter value";
    case WrongPINCode:
        return "Wrong PIN code";
    default:
        return "Unknown error code";
    }
}

uint8_t Error::code() const noexcept
{
    return _code;
}