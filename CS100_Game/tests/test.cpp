//#nclude "/home/csmajs/ffan005/final-project-powerrangers/googletest/googletest/include/gtest/gtest.h":include "gtest/gtest.h"
#include "/home/csmajs/ffan005/final-project-powerrangers/googletest/googletest/include/gtest/gtest.h"
#include "../src/stdafx.h"
#include "ui_test.hpp"
#include "state_test.hpp"

int main(int argc, char **argv){
     ::testing::InitGoogleTest(&argc, argv);
         return RUN_ALL_TESTS();
}
