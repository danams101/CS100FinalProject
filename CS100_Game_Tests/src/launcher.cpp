#include "stdafx.h"

// Test engine
#include "gfx/DisplayText.h"
#include "tests/TestSuite.h"
#include "tests/TestEngine.h"

// Tests
#include "tests/ui_button_test.hpp"
#include "tests/ui_button_test2.hpp"

using namespace std;

void initTests(TestEngine* bing_tests);


int main() {
    DisplayText* console = new DisplayText();
    console->print("Starting testing, may you be blessed\nwith ", "blue");
    console->print("no ", 2);
    console->print("failed tests\n", "blue");

    TestEngine* bing_tests = new TestEngine();

    initTests(bing_tests);

    bing_tests->runTests();

    delete console;
    delete bing_tests;

    cin.get();
    return 0;
}

// Initialize tests
void initTests(TestEngine* bing_tests) {
    DisplayText* console = new DisplayText();
    console->print("[==========] ", 3);
    console->print("Initializing Test Suites\n", 0);

    // UIButtonTest
    bing_tests->addTestSuite(new UIObjectTest(bing_tests->getGlobalData()));
    bing_tests->addTestSuite(new UIButtonTest(bing_tests->getGlobalData()));

    console->print("[==========] ", 1);
    console->print("Finalized Initializing Test Suites\n", 0);
    delete console;
}
