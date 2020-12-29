//----------------------------------------------------------------------------//
//                                                                            //
// usb-human-name is hosted at https://github.com/garrylachman/usb-human-name //
// and distributed under the MIT License (MIT).                               //
//                                                                            //
// Copyright (c) Garry Lachman (garry@lachman.co)                             //
//                                                                            //
// Permission is hereby granted, free of charge, to any person obtaining a    //
// copy of this software and associated documentation files (the "Software"), //
// to deal in the Software without restriction, including without limitation  //
// the rights to use, copy, modify, merge, publish, distribute, sublicense,   //
// and/or sell copies of the Software, and to permit persons to whom the      //
// Software is furnished to do so, subject to the following conditions:       //
//                                                                            //
// The above copyright notice and this permission notice shall be included in //
// all copies or substantial portions of the Software.                        //
//                                                                            //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR //
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   //
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    //
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER //
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    //
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        //
// DEALINGS IN THE SOFTWARE.                                                  //
//                                                                            //
//----------------------------------------------------------------------------//

#ifndef USB_HUMAN_NAME_USB_HUMAN_NAME_H
#define USB_HUMAN_NAME_USB_HUMAN_NAME_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include <algorithm>
#include <cctype>
#include <locale>
#include <vector>
#include <map>
#include "exported.h"



// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

struct EXPORTED USBDeviceDesc {
    uint16_t vendorId;
    std::string vendorName;
    uint16_t productId;
    std::string productName;
};

class EXPORTED USBHumanName {
    public:
        USBHumanName(const string &dbFilePath);
        ~USBHumanName();
        bool isLoaded = false;
        auto getList() {
            return this->devices;
        }
        USBDeviceDesc* findByVendorId(int16_t vId);
        USBDeviceDesc* findByProductId(int16_t pId);
    private:
        void parseFile();
        string dbFilePath;
        vector<USBDeviceDesc> devices;
};

#endif //USB_HUMAN_NAME_USB_HUMAN_NAME_H
