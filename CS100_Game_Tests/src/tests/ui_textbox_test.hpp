#ifndef __UI_TEXTBOX_TEST_HPP__
#define __UI_TEXTBOX_TEST_HPP__

#include "../stdafx.h"

#include "TestSuite.h"

#include "../../../CS100_Game/src/gui/UITextbox.cpp"


class UITextboxTest : public TestSuite {

    private:

    public:
        UITextboxTest(GlobalData* global_data) : TestSuite(global_data) {
            this->name = "UITextboxTest";
        }
		virtual ~UITextboxTest() {
		}

	void test() {
		    expectedTests(9);
            std::string title;

            title = "standard";
            float x = 1;
			float y = 1;
			std::map<std::string, sf::Color> colors;

            UITextbox* temp1 = new UITextbox(x,y,colors);
            this->expect_eq(temp1->getX(),1,title);
            this->expect_eq(temp1->getY(),1,title);

            title = "checkifSelected";
            this->expect_eq(temp1->isSelected(),false,title);

            title = "checkCharLimit";
            this->expect_eq(temp1->getCharLimit(),24,title);

            title = "checkString";
            this->expect_eq(temp1->getText(),"",title);

            title = "reverseSelection";
            temp1->setSelected(true);
            this->expect_eq(temp1->isSelected(),true,title);
            this->expect_eq(temp1->getText(),"",title);

            title = "positionTest";
            temp1->setPosition(1,1);
            this->expect_eq(temp1->getX(),1,title);
            this->expect_eq(temp1->getY(),1,title);

            ranTests();
            delete temp1;
		}
};
