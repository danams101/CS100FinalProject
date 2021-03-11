#ifndef __UI_BUTTON_TEST2_HPP__
#define __UI_BUTTON_TEST2_HPP__

#include "../stdafx.h"

#include "TestSuite.h"

// #include "../../../CS100_Game/src/gui/UIObject.cpp"
// #include "../../../CS100_Game/src/gui/UIButton.cpp"

class UIButtonTest : public TestSuite {

    private:

    public:
        UIButtonTest(GlobalData* global_data) : TestSuite(global_data) {
            this->name = "UIButtonTest";
        }
		virtual ~UIButtonTest() {
		}

		void test() {
			expectedTests(11);
			std::string title;
		
			title = "XPosAt1";
			float x = 1;
			float y = 1;
			float width = 1;
			float height = 1;
			std::map<std::string, sf::Color> colors;
			UIButton* temp1 = new UIButton(x, y, width, height, colors);
			this->expect_eq(temp1->getX(), 1, title);
			
			title = "CenteredFalse";
			this->expect_eq(temp1->isCentered(), false, title);

			title = "EmptyText";
			this->expect_eq(temp1->getText(), "", title);

           		 title = "HoveredFalse";
          		 this->expect_eq(temp1->isHovered(), false, title);

            		title = "ActiveFlase";
            		this->expect_eq(temp1->isActive(), false, title);

            		title = "ClickedFlase";
            		this->expect_eq(temp1->isClicked(), false, title);

            		title = "setStateHover";
            		temp1->setState("hover");
            		this->expect_eq(temp1->isHovered(),true,title);

            		title = "setStateActive";
            		temp1->setState("active");
            		this->expect_eq(temp1->isActive(),true,title);

            		title = "setText";
            		temp1->setText("NotEmpty");
            		this->expect_eq(temp1->getText(), "NotEmpty", title);

            		title = "setPosition";
            		temp1->setPosition(1,1);
            		this->expect_eq(temp1->getX(),1,title);
            		this->expect_eq(temp1->getY(),1,title);
			
			ranTests();
		}
};

#endif
