#include "../stdafx.h"
#include "DisplayText.h"

// PROPER LIBRARIES PER OS
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef linux
#endif

/* Constructors/Destructors */
DisplayText::DisplayText() {

}

DisplayText::~DisplayText() {

}


/* Accessors */

/* Functions */

void DisplayText::print(std::string text, std::string color) {

    // Windows
    #ifdef _WIN32
    if(color == "white")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (7 | FOREGROUND_INTENSITY));
    if(color == "green")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (10 | FOREGROUND_INTENSITY));
    if(color == "red")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (4 | FOREGROUND_INTENSITY));
    if(color == "purple")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (5 | FOREGROUND_INTENSITY));
    if(color == "blue")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 | FOREGROUND_INTENSITY));
    if(color == "yellow")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 | FOREGROUND_INTENSITY));
    std::cout << text;
    // reset console to default color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (7 | FOREGROUND_INTENSITY));
    #endif

    // Linux
    #ifdef __linux__
    std::string colorCode;
    std::string resetCode = "\033[0m";
    if(color == "white")
        colorCode = "\033[;37m";
    if(color == "green")
        colorCode = "\033[;32m";
    if(color == "red")
        colorCode = "\033[;31m";
    if(color == "purple")
        colorCode = "\033[;35m";
    if(color == "blue")
        colorCode = "\033[;34m";
    if(color == "yellow")
        colorCode = "\033[;33m";
    std::cout << colorCode << text << resetCode;
    #endif
}

void DisplayText::print(std::string text, int color) {

    // Windows
    #ifdef _WIN32
    switch (color) {
        case WHITE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (7 | FOREGROUND_INTENSITY));
            break;
        case GREEN:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (10 | FOREGROUND_INTENSITY));
            break;
        case RED:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (4 | FOREGROUND_INTENSITY));
            break;
        case PURPLE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (5 | FOREGROUND_INTENSITY));
            break;
        case BLUE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 | FOREGROUND_INTENSITY));
            break;
        case YELLOW:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 | FOREGROUND_INTENSITY));
            break;
    }
    std::cout << text;
    // reset console to default color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (7 | FOREGROUND_INTENSITY));
    #endif

    // Linux
    #ifdef __linux__
    std::string colorCode;
    std::string resetCode = "\033[0m";
    switch (color) {
        case WHITE:
            colorCode = "\033[;37m";
            break;
        case GREEN:
            colorCode = "\033[;32m";
            break;
        case RED:
            colorCode = "\033[;31m";
            break;
        case PURPLE:
            colorCode = "\033[;35m";
            break;
        case BLUE:
            colorCode = "\033[;34m";
            break;
        case YELLOW:
            colorCode = "\033[;33m";
            break;
    }
    std::cout << colorCode << text << resetCode;
    #endif
}
