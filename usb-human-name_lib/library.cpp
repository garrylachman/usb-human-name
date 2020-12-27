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

#include "library.h"

USBHumanName::USBHumanName(const string &dbFilePath)
        : dbFilePath(dbFilePath) {
    this->parseFile();
}

USBHumanName::~USBHumanName() {

}

void USBHumanName::parseFile() {
    ifstream file(this->dbFilePath);
    string line;
    uint16_t lastVendorId;
    string lastVendorName;
    while (getline(file, line)) {
        // todo: implemenet "List of known device classes, subclasses and protocols"
        if (line.rfind("# List of known device classes, subclasses and protocols", 0) == 0 )
            break;
        if (line.rfind("#", 0 ) == 0 || line.empty())
            continue;

        if ( line[0] != '\t' ) {
            // vendor
            auto start = line.find( " ", 0 );
            auto vendorID = line.substr(0, start);
            auto vendorName = line.substr(start);

            trim(vendorName);
            lastVendorId = (uint16_t) strtoul(vendorID.c_str(), nullptr, 16);
            lastVendorName = vendorName;
        } else {
            // product (in parent vendor)
            trim(line);
            auto start = line.find(" ", 0);
            auto productIdStr = line.substr(0, start);
            auto productId = (uint16_t) strtoul(productIdStr.c_str(), nullptr, 16);
            auto productName = line.substr(start);
            trim(productName);

            USBDeviceDesc d = { lastVendorId, lastVendorName, productId, productName};

            // Adding the usb product & vendor to the list
            this->devices.push_back(d);
        }
    }

    this->isLoaded = true;
}

USBDeviceDesc* USBHumanName::findByVendorId(int16_t vId) {
    for(auto &item : this->devices) {
        if (item.vendorId == vId)   {
            return &item;
        }
    }
    return nullptr;
}

USBDeviceDesc *USBHumanName::findByProductId(int16_t pId) {
    for(auto &item : this->devices) {
        if (item.productId == pId)   {
            return &item;
        }
    }
    return nullptr;
}
