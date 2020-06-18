#ifndef LOGID_IPC_UTIL_H
#define LOGID_IPC_UTIL_H

#include "../Device.h"
#include <hidpp/defs.h>
#include <string>

namespace logid::IPC
{
    struct deviceInfo {
        std::string path;
        HIDPP::DeviceIndex index;
    };
    deviceInfo parseDevName(std::string name);
    std::string toDevName(deviceInfo devInfo);
    std::string toDevName(std::string path, HIDPP::DeviceIndex index);
    std::string toDBusPath(logid::Device* device);
    std::string toDBusPath(std::string path, HIDPP::DeviceIndex index);
}

#endif //LOGID_IPC_UTIL_H