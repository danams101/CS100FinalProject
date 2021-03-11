#ifndef __UI_BUTTONTIMER_TEST_HPP__
#define __UI_BUTTONTIMER_TEST_HPP__

#include "../stdafx.h"

#include "TestSuite.h"
#include "../../../CS100_Game/src/gui/UIButtonTimer.cpp"



class UIButtonTimerTest : public TestSuite {

    private:

    public:
        UIButtonTimerTest(GlobalData* global_data) : TestSuite(global_data) {
            this->name = "UIButtonTimerTest";
        }
		virtual ~UIButtonTimerTest() {
		}
		void test() {
		    expectedTests(4);
            std::string title;

            title = "standard";
            float x = 1;
			float y = 1;
			float width = 1;
			float height = 1;
			std::map<std::string, sf::Color> colors;
            UIButtonTimer* temp1 = new UIButtonTimer(x, y, width, height, colors);
            this->expect_eq(temp1->getX(),1,title);

            title = "isDone";
            this->expect_eq(temp1->isTimerDone(),false,title);

            title = "isClickable";
            this->expect_eq(temp1->isClickable(),true,title);

            title = "setActivation";
            temp1->setTimerActivation(false);
            this->expect_eq(temp1->isActive(),false,title);

            ranTests();
            delete temp1;
		}
};

#endif
