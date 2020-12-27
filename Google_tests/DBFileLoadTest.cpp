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

#include "gtest/gtest.h"
#include "library.h"

USBHumanName usb("./data/usb.ids");

TEST(DBFileTestSuite, ReadyTest){

    EXPECT_TRUE(usb.isLoaded);
    EXPECT_GT(usb.getList().size(), 1);

}

TEST(DBFileTestSuite, FindVendorTest){

    int16_t exampleVendorId = 0x4e8;
    EXPECT_EQ(usb.findByVendorId(exampleVendorId)->vendorName, "Samsung Electronics Co., Ltd");
    EXPECT_NE(usb.findByVendorId(exampleVendorId)->vendorName, "Samsung");
    EXPECT_TRUE(usb.findByVendorId(0x4e72) == nullptr);

}

TEST(DBFileTestSuite, FindProductTest){

    int16_t exampleProductId = 0x6860;
    EXPECT_EQ(usb.findByProductId(exampleProductId)->productName, "Galaxy A5 (MTP)");
    EXPECT_EQ(usb.findByProductId(exampleProductId)->vendorName, "Samsung Electronics Co., Ltd");
    EXPECT_NE(usb.findByProductId(exampleProductId)->productName, "Samsung");
    EXPECT_TRUE(usb.findByProductId(0x4e72) == nullptr);

}

TEST(DBFileTestSuite, FullDataTest){

    for ( auto it = usb.getList().begin(); it != usb.getList().end(); ++it  ) {
        EXPECT_GE(it->vendorId, 0);
        EXPECT_GE(it->productId, 0);
    }
}