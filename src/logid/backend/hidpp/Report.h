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

#ifndef LOGID_BACKEND_HIDPP_REPORT_H
#define LOGID_BACKEND_HIDPP_REPORT_H

#include <cstdint>
#include "../raw/RawDevice.h"
#include "defs.h"

/* Some devices only support a subset of these reports */
#define HIDPP_REPORT_SHORT_SUPPORTED      1U
#define HIDPP_REPORT_LONG_SUPPORTED	      1U<<1U
/* Very long reports exist, however they have not been encountered so far */

namespace logid {
namespace backend {
namespace hidpp
{
    uint8_t getSupportedReports(std::vector<uint8_t>&& rdesc);

    namespace Offset
    {
        static constexpr uint8_t Type = 0;
        static constexpr uint8_t DeviceIndex = 1;
        static constexpr uint8_t SubID = 2;
        static constexpr uint8_t Feature = 2;
        static constexpr uint8_t Address = 3;
        static constexpr uint8_t Function = 3;
        static constexpr uint8_t Parameters = 4;
    }

    class Report
    {
    public:
        typedef ReportType::ReportType Type;

        class InvalidReportID: public std::exception
        {
        public:
            InvalidReportID() = default;
            const char* what() const noexcept override;
        };

        class InvalidReportLength: public std::exception
        {
        public:
            InvalidReportLength() = default;;
            const char* what() const noexcept override;
        };

        static constexpr std::size_t MaxDataLength = 20;

        Report(Report::Type type, DeviceIndex device_index,
               uint8_t sub_id,
               uint8_t address);
        Report(Report::Type type, DeviceIndex device_index,
                uint8_t feature_index,
                uint8_t function,
                uint8_t sw_id);
        explicit Report(const std::vector<uint8_t>& data);

        Report::Type type() const;
        void setType(Report::Type type);

        logid::backend::hidpp::DeviceIndex deviceIndex() const;
        void setDeviceIndex(hidpp::DeviceIndex index);

        uint8_t feature() const;
        void setFeature(uint8_t feature);

        uint8_t subId() const;
        void setSubId(uint8_t sub_id);

        uint8_t function() const;
        void setFunction(uint8_t function);

        uint8_t swId() const;
        void setSwId(uint8_t sw_id);

        uint8_t address() const;
        void setAddress(uint8_t address);

        std::vector<uint8_t>::iterator paramBegin();
        std::vector<uint8_t>::iterator paramEnd();
        std::vector<uint8_t>::const_iterator paramBegin() const;
        std::vector<uint8_t>::const_iterator paramEnd() const;
        void setParams(const std::vector<uint8_t>& _params);

        struct Hidpp10Error
        {
            uint8_t sub_id, address, error_code;
        };
        bool isError10(Hidpp10Error* error);

        struct Hidpp20Error
        {
            uint8_t feature_index, function, software_id, error_code;
        };
        bool isError20(Hidpp20Error* error);

        std::vector<uint8_t> rawReport () const { return _data; }

        static constexpr std::size_t HeaderLength = 4;
    private:
        std::vector<uint8_t> _data;
    };
}}}

#endif //LOGID_BACKEND_HIDPP_REPORT_H