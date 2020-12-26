#ifndef USB_HUMAN_NAME_LIBRARY_H
#define USB_HUMAN_NAME_LIBRARY_H

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

#endif //USB_HUMAN_NAME_LIBRARY_H
