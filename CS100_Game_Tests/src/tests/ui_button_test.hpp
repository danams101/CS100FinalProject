#ifndef __UI_BUTTON_TEST_HPP__
#define __UI_BUTTON_TEST_HPP__

#include "../stdafx.h"

#include "TestSuite.h"

#include "../../../CS100_Game/src/gui/UIObject.cpp"
#include "../../../CS100_Game/src/gui/UIButton.cpp"

class UIButtonTest : public TestSuite {

    private:

    public:
        UIButtonTest(GlobalData* global_data) : TestSuite(global_data) {
            this->name = "UIButtonTest";
        }
		virtual ~UIButtonTest() {
		}

		void test() {
		    expectedTests(4);
            std::string title;

            // SubEvaluateNonZero
            title = "SubEvaluateNonZero";
            int a = 5;
            int b = 2;
            this->expect_eq(a - b, 3, title);

            // XPosAt1
            title = "XPosAt1";
            float x = 1;
            float y = 1;
            float width = 1;
            float height = 1;
            std::map<std::string, sf::Color> colors;
            UIButton* temp1 = new UIButton(x, y, width, height, colors);
            this->expect_eq(temp1->getX(), 1, title);

            // CenteredFalse
            title = "CenteredFalse";
            this->expect_eq(temp1->isCentered(), false, title);

            // EmptyText
            title = "EmptyText";
            this->expect_eq(temp1->getText(), "", title);

            ranTests();
		}
};

#endif
