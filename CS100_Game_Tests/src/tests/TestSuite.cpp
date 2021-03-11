#include "../stdafx.h"
#include "TestSuite.h"

#include "../gfx/DisplayText.h"

/* Constructors/Destructors */
TestSuite::TestSuite(GlobalData* global_data) {
	this->globalData = global_data;
}

TestSuite::~TestSuite() {

}

/* Accessors */
std::string TestSuite::getName() {
	return this->name;
}

int TestSuite::getID() {
    return this->id;
}

/* Functions */
void TestSuite::setID(int id) {
    this->id = id;
}

void TestSuite::expectedTests(int numberOfTests) {
    DisplayText* console = new DisplayText();

    console->print("[----------] ", 3);
    console->print("Running " + std::to_string(numberOfTests) + " from " + this->name + "\n", 0);
    this->globalData->testCounter->push_back(0);
}

void TestSuite::ranTests() {
    DisplayText* console = new DisplayText();

    console->print("[----------] ", 3);
    console->print("Ran " + std::to_string(this->globalData->testCounter->at(this->id)) + " from " + this->name + "\n", 0);
}

// expect functions
void TestSuite::expect_eq(int input, int expected, std::string title) {
    DisplayText* console = new DisplayText();

    // print running test
    console->print("[ RUN      ] ", 1);
    console->print(this->name + "." + title + "\n", 0);

    try {
        // if passed
        if(input == expected) {
            this->globalData->passedTests->push_back(this->name + "." + title);
            console->print("[       OK ] ", 1);
            console->print(this->name + "." + title + "\n", 0);
        }
        // if failed
        else {
            console->print("[          ] ", 2);
            console->print("Expected equality of integer values:\n", 0);
            console->print("[          ] ", 2);
            console->print("Given: " + std::to_string(input) + "\n", 0);
            console->print("[          ] ", 2);
            console->print("Expected: " + std::to_string(expected) + "\n", 0);

            this->globalData->failedTests->push_back(this->name + "." + title);
            console->print("[  FAILED  ] ", 2);
            console->print(this->name + "." + title + "\n", 0);
        }
    }
    // if the check broke the code
    catch (...) {
        console->print("Expected equality of integer values:\n", 0);
        console->print("Error: ", 2);
        console->print("Code broke, you messed up\n", 0);

        this->globalData->failedTests->push_back(this->name + "." + title);
        console->print("[  FAILED  ] ", 2);
        console->print(this->name + "." + title + "\n", 0);
    }
    this->globalData->testCounter->at(this->id) = this->globalData->testCounter->at(this->id) + 1;
}

void TestSuite::expect_eq(std::string input, std::string expected, std::string title) {
    DisplayText* console = new DisplayText();

    // print running test
    console->print("[ RUN      ] ", 1);
    console->print(this->name + "." + title + "\n", 0);

    // if passed
    if(input == expected) {
        this->globalData->passedTests->push_back(this->name + "." + title);
        console->print("[       OK ] ", 1);
        console->print(this->name + "." + title + "\n", 0);
    }
    // if failed
    else {
        console->print("[          ] ", 2);
        console->print("Expected equality of string values:\n", 0);
        console->print("[          ] ", 2);
        console->print("Given: \"" + input + "\"\n", 0);
        console->print("[          ] ", 2);
        console->print("Expected: \"" +expected + "\"\n", 0);

        this->globalData->failedTests->push_back(this->name + "." + title);
        console->print("[  FAILED  ] ", 2);
        console->print(this->name + "." + title + "\n", 0);
    }
    this->globalData->testCounter->at(this->id) = this->globalData->testCounter->at(this->id) + 1;
}

void TestSuite::expect_eq(bool input, bool expected, std::string title) {
     DisplayText* console = new DisplayText();

    // print running test
    console->print("[ RUN      ] ", 1);
    console->print(this->name + "." + title + "\n", 0);

    // if passed
    if(input == expected) {
        this->globalData->passedTests->push_back(this->name + "." + title);
        console->print("[       OK ] ", 1);
        console->print(this->name + "." + title + "\n", 0);
    }
    // if failed
    else {
        console->print("[          ] ", 2);
        console->print("Expected equality of boolean values:\n", 0);
        console->print("[          ] ", 2);
        if(input) {
            console->print("Given: true\n", 0);

        }
        else {
            console->print("Given: false\n", 0);

        }
        console->print("[          ] ", 2);
        if(expected) {
            console->print("Expected: true\n", 0);

        }
        else {
            console->print("Expected: false\n", 0);

        }

        this->globalData->failedTests->push_back(this->name + "." + title);
        console->print("[  FAILED  ] ", 2);
        console->print(this->name + "." + title + "\n", 0);
    }
    this->globalData->testCounter->at(this->id) = this->globalData->testCounter->at(this->id) + 1;
}
