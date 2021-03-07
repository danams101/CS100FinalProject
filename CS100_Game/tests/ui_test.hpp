#ifndef UI_TEST_HPP
#define UI_TEST_HPP

#include "../src/gui/UIButton.h"
#include "gtest/gtest.h"

TEST(ConstructorT, ZeroWidthHeight){
    EXPECT_EQ(0, 0);
    EXPECT_EQ(0, 0);
}


#endif // UI_TEST_HPP
