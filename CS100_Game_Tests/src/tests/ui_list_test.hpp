#ifndef __UI_LIST_TEST_HPP__
#define __UI_LIST_TEST_HPP__

#include "../stdafx.h"

#include "TestSuite.h"

#include "../../../CS100_Game/src/gui/UIList.cpp"


class UIListTest : public TestSuite {

    private:

    public:
        UIListTest(GlobalData* global_data) : TestSuite(global_data) {
            this->name = "UIListTest";
        }
		virtual ~UIListTest() {
		}

	void test() {
	    expectedTests(2);
            std::string title;
	    title = "Standard";
            UIList* temp1 = new UIList();
            expect_eq(temp1->getX(),0,title);
            expect_eq(temp1->getY(),0,title);
	    ranTests();
            delete temp1;
}
};

#endif
