CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE( gui
    main.cpp
    UIButton.cpp
    UIObjectComposite.cpp
    UITextbox.cpp
    UIDisplayText.cpp
)

TARGET_LINK_LIBRARIES(gui sfml-graphics sfml-window sfml-system)