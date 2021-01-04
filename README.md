![CMake](https://github.com/garrylachman/usb-human-name/workflows/CMake/badge.svg)
![Release](https://github.com/garrylachman/usb-human-name/workflows/Release/badge.svg)

# USB Human Name
### Humanize USB vendor and product codes library

This library uses usb.ids file to provide easy translate api from vendors and products codes provided by libs like libusb to real names.

USB Human Name is a minimal project that's kept deliberately very small. When you build it using CMake/make (see below) it generates:

 1. A tiny **static library** `libusb_human_name`,
 2. **An executable unit test** `Google_Tests_run`  using [Google Test library](https://github.com/google/googletest).

## Usage

### Prerequisites

You will need:

 * A modern C/C++ compiler
 * CMake 3.1+ installed (on a Mac, run `brew install cmake`)
 * If you prefer to code in a great IDE, I highly recommend [Jetbrains CLion](https://www.jetbrains.com/clion/). It is fully compatible with this project.

### Building The Project

#### Git Clone

First we need to check out the git repo:

```bash
❯ mkdir ~/workspace
❯ cd ~/workspace
❯ git clone \
    https://github.com/garrylachman/usb-human-name \
    usb-human-name
❯ cd usb-human-name
❯ mkdir build
❯ cd build
❯ cmake ..
❯ make
```
<img src="https://i.imgur.com/14Ltwbn.gif" />


#### Running the tests

```bash
❯ Google_tests/Google_Tests_run
[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from DBFileTestSuite
[ RUN      ] DBFileTestSuite.ReadyTest
[       OK ] DBFileTestSuite.ReadyTest (2 ms)
[ RUN      ] DBFileTestSuite.FindVendorTest
[       OK ] DBFileTestSuite.FindVendorTest (0 ms)
[ RUN      ] DBFileTestSuite.FindProductTest
[       OK ] DBFileTestSuite.FindProductTest (0 ms)
[ RUN      ] DBFileTestSuite.FullDataTest
[       OK ] DBFileTestSuite.FullDataTest (36181 ms)
[----------] 4 tests from DBFileTestSuite (36184 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (36184 ms total)
[  PASSED  ] 4 tests.
```

## File Locations

 * `usb-human-name_lib/*` — C++ code that ultimately compiles into a library
 * `Google_tests/lib` — C++ libraries used for tests (eg, Google Test)
 * `Google_tests` — C++ test suite
 
#### Contributing

**Pull Requests are WELCOME!** Please submit any fixes or improvements, and I promise to review it as soon as I can at the project URL:

 * [Project Github Home](https://github.com/garrylachman/usb-human-name)
 * [Submit Issues](https://github.com/garrylachman/usb-human-name/issues)
 * [Pull Requests](https://github.com/garrylachman/usb-human-name/pulls)

### License

&copy; 2020 Garry Lachman (garry@lachman.co).

Open sourced under MIT license, the terms of which can be read here — [MIT License](http://opensource.org/licenses/MIT).
