#ifndef __UI_STATBAR_TEST_HPP__
#define __UI_STATBAR_TEST_HPP__

#include "../stdafx.h"

#include "TestSuite.h"

#include "../../../CS100_Game/src/gui/UIStatBar.cpp"


class UIStatBarTest : public TestSuite {

    private:

    public:
        UIStatBarTest(GlobalData* global_data) : TestSuite(global_data) {
            this->name = "UIStatBarTest";
        }
		virtual ~UIStatBarTest() {
		}

	void test() {
	    expectedTests(16);
            std::string title;

            title = "standard";
            float x = 1;
			float y = 1;
			float width = 1;
			float height = 1;
			std::map<std::string, sf::Color> colors;
			float duration = 1;
            UIStatBar* temp1 = new UIStatBar(x,y,width,height,colors,duration);
            this->expect_eq(temp1->getX(),1,title);
	    this->expect_eq(temp1->getY(),1,title);
            this->expect_eq(temp1->getWidth(),1,title);
            this->expect_eq(temp1->getHeight(),1,title);

            title = "ActivedFalse";
            this->expect_eq(temp1->isActivated(),false,title);

            title = "DoneFalse";
            this->expect_eq(temp1->isDone(),false,title);

            title = "TimeDuration";
            this->expect_eq(temp1->getTimerDuration(),1,title);

            title = "getBarLength";
            this->expect_eq(temp1->getBarLength(),1,title);

            title = "setActivation";
            temp1->setActivation(true);
            this->expect_eq(temp1->isActivated(),true,title);

            title = "resetBar";
            temp1->resetBar();
            this->expect_eq(temp1->isActivated(),false,title);
            this->expect_eq(temp1->isDone(),false,title);
            this->expect_eq(temp1->getBarLength(),1,title);

            title = "updateProgress";
            temp1->updateProgress(1);
            this->expect_eq(temp1->isActivated(),false,title);
            this->expect_eq(temp1->isDone(),false,title);
            this->expect_eq(temp1->getBarLength(),1,title);
            this->expect_eq(temp1->getTimerDuration(),1,title);

            ranTests();
            delete temp1;
		}
};

#endif

