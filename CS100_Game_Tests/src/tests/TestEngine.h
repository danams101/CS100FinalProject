#ifndef __TESTENGINE_H__
#define __TESTENGINE_H__

#include "TestSuite.h"

class TestEngine {

    private:
        /* Variables */
        std::vector<TestSuite*> tests;

		GlobalData globalData;
        std::vector<int> testCounter;
        std::vector<std::string> passedTests;
        std::vector<std::string> failedTests;

        /* Initializer Functions */
		void initGraphicsSettings();
		void initGlobalData();

    public:
        /* Constructors/Destructors */
        TestEngine();
        virtual ~TestEngine();

        /* Accessors */
        GlobalData* getGlobalData();

        /* Functions */
        void addTestSuite(TestSuite* testSuite);
        void runTests();
};






#endif
