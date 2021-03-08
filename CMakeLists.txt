CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE( test
	CS100_Game/src/stdafx.cpp
	CS100_Game/src/gui/UIObject.cpp
	CS100_Game/src/gui/UIButton.cpp
	CS100_Game/tests/test.cpp
)

INCLUDE_DIRECTORIES(
        CS100_Game/lib/SFML_linux/include
)


TARGET_LINK_LIBRARIES(test gtest -LCS100_Game/lib/SFML_linux/lib sfml-graphics sfml-window sfml-system)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

