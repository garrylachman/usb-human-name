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
