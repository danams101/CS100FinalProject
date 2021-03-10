CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE( testing
	launcher.cpp
    stdafx.cpp
    tests/TestEngine.cpp
    tests/TestSuite.cpp
    gfx/DisplayText.cpp

)

INCLUDE_DIRECTORIES(
        CS100_Game/lib/SFML/include
)


TARGET_LINK_LIBRARIES(testing -LCS100_Game/lib/SFML/lib sfml-graphics sfml-window sfml-system)