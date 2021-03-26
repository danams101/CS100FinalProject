CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE ( launch
    launcher.cpp
    stdafx.cpp
    Game.cpp
    states/State.cpp
    states/MainMenuState.cpp
    states/StoryState.cpp
    states/GameState.cpp
    gfx/GraphicsSettings.cpp
    gfx/GraphicsConverter.cpp
    gui/UIObject.cpp
    gui/UIList.cpp
    gui/UIButton.cpp
    gui/UIStatBar.cpp
    gui/UIDisplayText.cpp
    gui/UITextbox.cpp
    gui/UIButtonTimer.cpp
)

ADD_EXECUTABLE ( dialogueTreeTest
    dialogue/main.cpp
    stdafx.cpp
    # Game.cpp
    # states/State.cpp
    # states/MainMenuState.cpp
    # states/StoryState.cpp
    # states/GameState.cpp
    gfx/GraphicsSettings.cpp
    gfx/GraphicsConverter.cpp
    gui/UIObject.cpp
    gui/UIList.cpp
    gui/UIButton.cpp
    # gui/UIStatBar.cpp
    # gui/UIDisplayText.cpp
    # gui/UITextbox.cpp
    # gui/UIButtonTimer.cpp
    dialogue/dialogueGraph.cpp
)


INCLUDE_DIRECTORIES(
        CS100_Game/lib/SFML/include
)


TARGET_LINK_LIBRARIES(launch -LCS100_Game/lib/SFML/lib sfml-graphics sfml-window sfml-system)
TARGET_LINK_LIBRARIES(dialogueTreeTest -LCS100_Game/lib/SFML/lib sfml-graphics sfml-window sfml-system)