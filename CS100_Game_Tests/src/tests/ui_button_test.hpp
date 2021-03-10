#ifndef __UI_BUTTON_TEST_HPP__
#define __UI_BUTTON_TEST_HPP__

#include "../stdafx.h"

#include "TestSuite.h"

#include "../../../CS100_Game/src/gui/UIObject.cpp"
#include "../../../CS100_Game/src/gui/UIButton.cpp"

class UIButtonTest : public TestSuite {

    private:

    public:
        UIObjectTest(GlobalData* global_data) : TestSuite(global_data) {
            this->name = "UIObjectTest";
        }
		virtual ~UIObjectTest() {
		}

		void test() {
		expectedTests(8);
        	std::string title;

            title = "XPosAt1";
            float x = 1;
            float y = 1;
            float width = 1;
            float height = 1;
            std::map<std::string, sf::Color> colors;
            UIButton* temp1 = new UIButton(x, y, width, height, colors);
            this->expect_eq(temp1->getX(), 1, title);

            title = "YPosAt1";
            this->expect_eq(temp1->getY(), 1, title);


            title = "WidthAt1";
            this->expect_eq(temp1->getWidth(),1,title);

            title = "HeightAt1";
            this->expect_eq(temp1->getHeight(),1,title);

            title = "SetPosition";
            temp1->setPosition(1,1);
            this->expect_eq(temp1->getX(),1,title);
            this->expect_eq(temp1->getY(),1,title);

            title = "SetSize";
            temp1->setSize(10,10);
            this->expect_eq(temp1->getWidth(),10,title);
            this->expect_eq(temp1->getHeight(),10,title);
            ranTests();

            delete temp1;
		}
};

#endif
