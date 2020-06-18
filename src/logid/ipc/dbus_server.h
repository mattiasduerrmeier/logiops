
/*
 *	This file was automatically generated by dbusxx-xml2cpp; DO NOT EDIT!
 */

#ifndef __dbusxx__dbus_server_h__ADAPTOR_MARSHAL_H
#define __dbusxx__dbus_server_h__ADAPTOR_MARSHAL_H

#include <dbus-c++/dbus.h>
#include <cassert>

namespace pizza {
namespace pixl {

class logiops_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    logiops_adaptor()
    : ::DBus::InterfaceAdaptor("pizza.pixl.logiops")
    {
        bind_property(Version, "s", true, false);
        bind_property(Receivers, "as", true, false);
        bind_property(Devices, "as", true, false);
        register_method(logiops_adaptor, Reload, _Reload_stub);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedArgument Reload_args[] = 
        {
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument DeviceConnected_args[] = 
        {
            { "device", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument DeviceDisconnected_args[] = 
        {
            { "device", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument ReceiverConnected_args[] = 
        {
            { "receiver", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument ReceiverDisconnected_args[] = 
        {
            { "receiver", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod logiops_adaptor_methods[] = 
        {
            { "Reload", Reload_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod logiops_adaptor_signals[] = 
        {
            { "DeviceConnected", DeviceConnected_args },
            { "DeviceDisconnected", DeviceDisconnected_args },
            { "ReceiverConnected", ReceiverConnected_args },
            { "ReceiverDisconnected", ReceiverDisconnected_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty logiops_adaptor_properties[] = 
        {
            { "Version", "s", true, false },
            { "Receivers", "as", true, false },
            { "Devices", "as", true, false },
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface logiops_adaptor_interface = 
        {
            "pizza.pixl.logiops",
            logiops_adaptor_methods,
            logiops_adaptor_signals,
            logiops_adaptor_properties
        };
        return &logiops_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */
    ::DBus::PropertyAdaptor< std::string > Version;
    ::DBus::PropertyAdaptor< std::vector< std::string > > Receivers;
    ::DBus::PropertyAdaptor< std::vector< std::string > > Devices;

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual void Reload() = 0;

public:

    /* signal emitters for this interface
     */
    void DeviceConnected(const std::string& arg1)
    {
        ::DBus::SignalMessage sig("DeviceConnected");
        ::DBus::MessageIter wi = sig.writer();
        wi << arg1;
        emit_signal(sig);
    }
    void DeviceDisconnected(const std::string& arg1)
    {
        ::DBus::SignalMessage sig("DeviceDisconnected");
        ::DBus::MessageIter wi = sig.writer();
        wi << arg1;
        emit_signal(sig);
    }
    void ReceiverConnected(const std::string& arg1)
    {
        ::DBus::SignalMessage sig("ReceiverConnected");
        ::DBus::MessageIter wi = sig.writer();
        wi << arg1;
        emit_signal(sig);
    }
    void ReceiverDisconnected(const std::string& arg1)
    {
        ::DBus::SignalMessage sig("ReceiverDisconnected");
        ::DBus::MessageIter wi = sig.writer();
        wi << arg1;
        emit_signal(sig);
    }

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _Reload_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        Reload();
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
};

namespace logiops {

class Config_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    Config_adaptor()
    : ::DBus::InterfaceAdaptor("pizza.pixl.logiops.Config")
    {
        bind_property(Devices, "as", true, false);
        register_method(Config_adaptor, Get, _Get_stub);
        register_method(Config_adaptor, GetAll, _GetAll_stub);
        register_method(Config_adaptor, ReloadAll, _ReloadAll_stub);
        register_method(Config_adaptor, ReloadDevice, _ReloadDevice_stub);
        register_method(Config_adaptor, SaveAll, _SaveAll_stub);
        register_method(Config_adaptor, SaveDevice, _SaveDevice_stub);
        register_method(Config_adaptor, ClearAll, _ClearAll_stub);
        register_method(Config_adaptor, Clear, _Clear_stub);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedArgument Get_args[] = 
        {
            { "device", "s", true },
            { "property", "s", true },
            { "value", "v", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument GetAll_args[] = 
        {
            { "device", "s", true },
            { "properties", "a{sv}", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument ReloadAll_args[] = 
        {
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument ReloadDevice_args[] = 
        {
            { "device", "s", true },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument SaveAll_args[] = 
        {
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument SaveDevice_args[] = 
        {
            { "device", "s", true },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument ClearAll_args[] = 
        {
            { "device", "s", true },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument Clear_args[] = 
        {
            { "device", "s", true },
            { "property", "s", true },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod Config_adaptor_methods[] = 
        {
            { "Get", Get_args },
            { "GetAll", GetAll_args },
            { "ReloadAll", ReloadAll_args },
            { "ReloadDevice", ReloadDevice_args },
            { "SaveAll", SaveAll_args },
            { "SaveDevice", SaveDevice_args },
            { "ClearAll", ClearAll_args },
            { "Clear", Clear_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod Config_adaptor_signals[] = 
        {
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty Config_adaptor_properties[] = 
        {
            { "Devices", "as", true, false },
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface Config_adaptor_interface = 
        {
            "pizza.pixl.logiops.Config",
            Config_adaptor_methods,
            Config_adaptor_signals,
            Config_adaptor_properties
        };
        return &Config_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */
    ::DBus::PropertyAdaptor< std::vector< std::string > > Devices;

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual ::DBus::Variant Get(const std::string& device, const std::string& property) = 0;
    virtual std::map< std::string, ::DBus::Variant > GetAll(const std::string& device) = 0;
    virtual void ReloadAll() = 0;
    virtual void ReloadDevice(const std::string& device) = 0;
    virtual void SaveAll() = 0;
    virtual void SaveDevice(const std::string& device) = 0;
    virtual void ClearAll(const std::string& device) = 0;
    virtual void Clear(const std::string& device, const std::string& property) = 0;

public:

    /* signal emitters for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _Get_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        std::string argin2; ri >> argin2;
        ::DBus::Variant argout1 = Get(argin1, argin2);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
    ::DBus::Message _GetAll_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        std::map< std::string, ::DBus::Variant > argout1 = GetAll(argin1);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
    ::DBus::Message _ReloadAll_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        ReloadAll();
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
    ::DBus::Message _ReloadDevice_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        ReloadDevice(argin1);
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
    ::DBus::Message _SaveAll_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        SaveAll();
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
    ::DBus::Message _SaveDevice_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        SaveDevice(argin1);
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
    ::DBus::Message _ClearAll_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        ClearAll(argin1);
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
    ::DBus::Message _Clear_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        std::string argin2; ri >> argin2;
        Clear(argin1, argin2);
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
};

class Device_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    Device_adaptor()
    : ::DBus::InterfaceAdaptor("pizza.pixl.logiops.Device")
    {
        bind_property(Name, "s", true, false);
        bind_property(DeviceID, "q", true, false);
        bind_property(Features, "as", true, false);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedMethod Device_adaptor_methods[] = 
        {
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod Device_adaptor_signals[] = 
        {
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty Device_adaptor_properties[] = 
        {
            { "Name", "s", true, false },
            { "DeviceID", "q", true, false },
            { "Features", "as", true, false },
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface Device_adaptor_interface = 
        {
            "pizza.pixl.logiops.Device",
            Device_adaptor_methods,
            Device_adaptor_signals,
            Device_adaptor_properties
        };
        return &Device_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */
    ::DBus::PropertyAdaptor< std::string > Name;
    ::DBus::PropertyAdaptor< uint16_t > DeviceID;
    ::DBus::PropertyAdaptor< std::vector< std::string > > Features;

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */

public:

    /* signal emitters for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
};

class Receiver_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    Receiver_adaptor()
    : ::DBus::InterfaceAdaptor("pizza.pixl.logiops.Receiver")
    {
        bind_property(Devices, "as", true, false);
        register_method(Receiver_adaptor, Pair, _Pair_stub);
        register_method(Receiver_adaptor, Unpair, _Unpair_stub);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedArgument Pair_args[] = 
        {
            { "device", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument Unpair_args[] = 
        {
            { "device", "s", true },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod Receiver_adaptor_methods[] = 
        {
            { "Pair", Pair_args },
            { "Unpair", Unpair_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod Receiver_adaptor_signals[] = 
        {
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty Receiver_adaptor_properties[] = 
        {
            { "Devices", "as", true, false },
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface Receiver_adaptor_interface = 
        {
            "pizza.pixl.logiops.Receiver",
            Receiver_adaptor_methods,
            Receiver_adaptor_signals,
            Receiver_adaptor_properties
        };
        return &Receiver_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */
    ::DBus::PropertyAdaptor< std::vector< std::string > > Devices;

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual std::string Pair() = 0;
    virtual void Unpair(const std::string& device) = 0;

public:

    /* signal emitters for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _Pair_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argout1 = Pair();
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
    ::DBus::Message _Unpair_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        Unpair(argin1);
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
};

namespace Device {

class Button_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    Button_adaptor()
    : ::DBus::InterfaceAdaptor("pizza.pixl.logiops.Device.Button")
    {
        bind_property(Remapped, "b", true, false);
        bind_property(ActionType, "s", true, false);
        bind_property(Action, "a{sv}", true, false);
        register_method(Button_adaptor, Reset, _Reset_stub);
        register_method(Button_adaptor, ClearAction, _ClearAction_stub);
        register_method(Button_adaptor, Remap, _Remap_stub);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedArgument Reset_args[] = 
        {
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument ClearAction_args[] = 
        {
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument Remap_args[] = 
        {
            { "actionType", "s", true },
            { "action", "s", true },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod Button_adaptor_methods[] = 
        {
            { "Reset", Reset_args },
            { "ClearAction", ClearAction_args },
            { "Remap", Remap_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod Button_adaptor_signals[] = 
        {
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty Button_adaptor_properties[] = 
        {
            { "Remapped", "b", true, false },
            { "ActionType", "s", true, false },
            { "Action", "a{sv}", true, false },
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface Button_adaptor_interface = 
        {
            "pizza.pixl.logiops.Device.Button",
            Button_adaptor_methods,
            Button_adaptor_signals,
            Button_adaptor_properties
        };
        return &Button_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */
    ::DBus::PropertyAdaptor< bool > Remapped;
    ::DBus::PropertyAdaptor< std::string > ActionType;
    ::DBus::PropertyAdaptor< std::map< std::string, ::DBus::Variant > > Action;

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual void Reset() = 0;
    virtual void ClearAction() = 0;
    virtual void Remap(const std::string& actionType, const std::string& action) = 0;

public:

    /* signal emitters for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _Reset_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        Reset();
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
    ::DBus::Message _ClearAction_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        ClearAction();
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
    ::DBus::Message _Remap_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        std::string argin2; ri >> argin2;
        Remap(argin1, argin2);
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
};

class DPI_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    DPI_adaptor()
    : ::DBus::InterfaceAdaptor("pizza.pixl.logiops.Device.DPI")
    {
        bind_property(DPI, "i", true, false);
        bind_property(AvailableDPIs, "ai", true, false);
        register_method(DPI_adaptor, SetDPI, _SetDPI_stub);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedArgument SetDPI_args[] = 
        {
            { "DPI", "i", true },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod DPI_adaptor_methods[] = 
        {
            { "SetDPI", SetDPI_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod DPI_adaptor_signals[] = 
        {
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty DPI_adaptor_properties[] = 
        {
            { "DPI", "i", true, false },
            { "AvailableDPIs", "ai", true, false },
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface DPI_adaptor_interface = 
        {
            "pizza.pixl.logiops.Device.DPI",
            DPI_adaptor_methods,
            DPI_adaptor_signals,
            DPI_adaptor_properties
        };
        return &DPI_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */
    ::DBus::PropertyAdaptor< int32_t > DPI;
    ::DBus::PropertyAdaptor< std::vector< int32_t > > AvailableDPIs;

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual void SetDPI(const int32_t& DPI) = 0;

public:

    /* signal emitters for this interface
     */

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _SetDPI_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        int32_t argin1; ri >> argin1;
        SetDPI(argin1);
        ::DBus::ReturnMessage reply(call);
        return reply;
    }
};

} } } } 
#endif //__dbusxx__dbus_server_h__ADAPTOR_MARSHAL_H