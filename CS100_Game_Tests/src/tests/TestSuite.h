#ifndef __TESTSUITE_H__
#define __TESTSUITE_H__

class TestSuite;

class GlobalData {
	public:
		GlobalData() {};

		/* Global variables */
		std::vector<int>* testCounter;
        std::vector<std::string>* passedTests;
        std::vector<std::string>* failedTests;
};

class TestSuite {

    private:

    protected:
        /* Variables */
        std::string name = "Test Suite";
        int id = 0;

		// Global data to manipulate Game.h
		GlobalData* globalData;

    public:
        /* Constructors/Destructors */
        TestSuite(GlobalData* global_data);
        virtual ~TestSuite();

        /* Accessors */
        std::string getName();
        int getID();

        /* Functions */
        void setID(int id);
        void expectedTests(int numberOfTests);
        void ranTests();

        // expect functions
        void expect_eq(int input, int expected, std::string title);
        void expect_eq(std::string input, std::string expected, std::string title);\
        void expect_eq(bool input, bool expected, std::string title);

        // virtual functions
        virtual void test() = 0;
};

#endif
