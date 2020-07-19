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

#ifndef LOGID_BACKEND_HIDPP20_FEATURE_DEVICENAME_H
#define LOGID_BACKEND_HIDPP20_FEATURE_DEVICENAME_H

#include "../Feature.h"
#include "../feature_defs.h"
#include "../EssentialFeature.h"

namespace logid {
namespace backend {
namespace hidpp20
{
    class DeviceName : public Feature
    {
    public:
        static const uint16_t ID = FeatureID::DEVICE_NAME;
        virtual uint16_t getID() { return ID; }

        enum Function : uint8_t
        {
            GetLength = 0,
            GetDeviceName = 1
        };

        explicit DeviceName(Device* device);

        uint8_t getNameLength();
        std::string getName();
    };

    class EssentialDeviceName : public EssentialFeature
    {
    public:
        static const uint16_t ID = FeatureID::DEVICE_NAME;
        virtual uint16_t getID() { return ID; }

        explicit EssentialDeviceName(hidpp::Device* device);

        uint8_t getNameLength();
        std::string getName();
    };
}}}

#endif //LOGID_BACKEND_HIDPP20_FEATURE_DEVICENAME_H