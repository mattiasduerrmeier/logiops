# logiops

This is an unofficial driver for Logitech mice and keyboard.

This is currently only compatible with HID++ \>2.0 devices.

## Configuration
[Refer to the wiki for details.](https://github.com/PixlOne/logiops/wiki/Configuration)

You may also refer to logid.example.cfg for an example.

Default location for the configuration file is /etc/logid.cfg.

## Dependencies

This project requires a C++14 compiler, cmake, libevdev, libudev, and libconfig. For popular distributions, I've included commands below.

**Debian/Ubuntu:** `sudo apt install cmake libevdev-dev libudev-dev libconfig++-dev`

**Arch Linux:** `sudo pacman -S cmake libevdev libconfig pkgconf`

## Building

To build this project, run:

```
mkdir build
cd build
cmake ..
make
```

To install, run `sudo make install` after building. You can set the daemon to start at boot by running `sudo systemctl start logid`.

## Donate
This program is (and will always be) provided free of charge. If you would like to support the development of this project by donating, you can donate to my Ko-Fi below.

<a href='https://ko-fi.com/R6R81QQ9M' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://cdn.ko-fi.com/cdn/kofi1.png?v=2' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>

I'm also looking for contributors to help in my project; feel free to submit a pull request or e-mail me if you would like to contribute.

## Compatible Devices

[For a list of tested devices, check TESTED.md](TESTED.md)

## Special Thanks
Thanks to the following people for contributing to this repository.

- [Clément Vuchener & contributors for creating the old HID++ library](https://github.com/cvuchener/hidpp)
- [Developers of Solaar for providing information on HID++](https://github.com/pwr-Solaar/Solaar)
- [Nestor Lopez Casado for providing Logitech documentation on the HID++ protocol](http://drive.google.com/folderview?id=0BxbRzx7vEV7eWmgwazJ3NUFfQ28)
- Everyone listed in the contributors page
