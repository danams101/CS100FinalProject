#include "../stdafx.h"
#include "TestEngine.h"

#include "../gfx/DisplayText.h"

/* Initializer Functions */

// Initialize the global data
void TestEngine::initGlobalData() {
	/* Sets the global data to pass into the other states */

	this->globalData.testCounter = &this->testCounter;
	this->globalData.passedTests = &this->passedTests;
	this->globalData.failedTests = &this->failedTests;
}

/* Constructors/Destructors */
TestEngine::TestEngine() {

	this->initGlobalData();
}

TestEngine::~TestEngine() {

}

/* Accessors */
GlobalData* TestEngine::getGlobalData() {
    GlobalData* pointer = &this->globalData;
    return pointer;
}

/* Functions */
void TestEngine::addTestSuite(TestSuite* testSuite) {
    DisplayText* console = new DisplayText();

    console->print("[ RUN      ] ", 1);
    console->print("Adding " + testSuite->getName() + "\n", 0);
    this->tests.push_back(testSuite);
    this->tests.at(this->tests.size()-1)->setID(this->tests.size()-1);
    console->print("[       OK ] ", 1);
    console->print("Adding " + testSuite->getName() + "\n", 0);

    delete console;
}

void TestEngine::runTests() {
    DisplayText* console = new DisplayText();
    console->print("[==========] ", 3);
    console->print("Running all tests\n", 0);

    for(unsigned int i = 0; i < this->tests.size(); ++i) {
        this->tests[i]->test();
    }

    // COUNTER SHIT
    console->print("[----------] ", 1);
    console->print("Finished all tests\n", 0);

    int testsRan = 0;
    int testSuitesRan = 0;
    for(unsigned int i = 0; i < this->testCounter.size(); ++i) {
        testsRan += this->testCounter.at(i);
        ++testSuitesRan;
    }
    console->print("[==========] ", 1);
    console->print(std::to_string(testsRan) + " tests from " + std::to_string(testSuitesRan) + " test suites ran\n", 0);

    console->print("[  PASSED  ] ", 1);
    console->print(std::to_string(this->passedTests.size()) + " tests\n", 0);

    if(this->failedTests.size() == 0) {
        console->print("[  FAILED  ] ", 2);
        console->print(std::to_string(this->failedTests.size()) + " tests.\n", 0);
        console->print("Congratulations! Here's some green text for reward!\n", "yellow");
        console->print("SUCCEEDED\nPASSED\nWON\nNO ERRORS\nNO BUGS\nYOU WON AT LIFE\n", 1);
    }
    else {
        console->print("[  FAILED  ] ", 2);
        console->print(std::to_string(this->failedTests.size()) + " tests, listed below:\n", 0);
    }

    for(unsigned int i = 0; i < this->failedTests.size(); ++i) {
        console->print("[  FAILED  ] ", 2);
        console->print(this->failedTests.at(i) + "\n", 0);
    }

    if(this->failedTests.size() == 0) {
        console->print("ALL TESTS PASSED", 4);

    }
    else {
        console->print(std::to_string(this->failedTests.size()) + " FAILED TESTS", 4);
    }

}
