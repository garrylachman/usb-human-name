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