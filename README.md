DarkSky-CPP
==============

A callback-based C++ wrapper for the [Dark Sky API](https://darksky.net/dev), using the C++11 standard. It is heavily modularised and object-oriented so that multiple listeners can easily be attached to different sections.

* **Version:** 2014-12-08
* **Author:** Todd Shore
* **Website:** https://github.com/Crystalix007/DarkSky-CPP
* **Licensing:** Copyright &copy; 2014 Todd Shore. Licensed for distribution under the Apache License 2.0: See the files `NOTICE` and `LICENSE`.

Requirements
---------------------------
* Compiler: This was developed primarily using Clang 3.4.1 on an Ubuntu-derived Linux system; There was some minimal usage of GCC as well as MinGW under Windows 7, but I haven't tested these compilers on the newest version of the code.
* `json-c` 0.11: https://github.com/json-c/json-c/
* For the demo application, `cURL` 7.35 is also required

Demo
---------------------------
A makefile is included for building the included demo application `console-weather`: Use the target `Debug` to build an executable with debugging symbols and `Release` to build one without. As stated above, this makefile was tested largely only on an Ubuntu-based system, so it may need to be changed to work on your system.


To do
---------------------------
* Add callbacks for [forecast data blocks](https://darksky.net/dev/docs#data-block-object)
* Improve build process: E.g. use CMake instead of writing makefile manually
* Add console-writing functionalities for as-yet-unimplemented callbacks
* Make demo program support printing out SI measurements as well
* Make demo writer classes wrap data at terminal edge
