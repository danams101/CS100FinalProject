#ifndef __UI_DISPLAYTEXT_TEST_HPP__
#define __UI_DISPLAYTEXT_TEST_HPP__

#include "../stdafx.h"

#include "TestSuite.h"

#include "../../../CS100_Game/src/gui/UIDisplayText.cpp"


class UIDisplayTextTest : public TestSuite {

    private:

    public:
        UIDisplayTextTest(GlobalData* global_data) : TestSuite(global_data) {
            this->name = "UIDisplayTextTest";
        }
		virtual ~UIDisplayTextTest() {
		}

		void test() {
		  expectedTests(11);
  	          std::string title;
            float x = 1;
            float y = 1;
            float width = 1;
            float height = 1;
            std::map<std::string, sf::Color> colors;
            std::string text = "Hello";

            UIDisplayText* temp1 = new UIDisplayText(x,y,width,height,colors,text);
            title = "Standard";
            this->expect_eq(temp1->getX(),1,title);
            this->expect_eq(temp1->getY(),1,title);
            this->expect_eq(temp1->getWidth(),1,title);
            this->expect_eq(temp1->getHeight(),1,title);

            title = "hasCharLimit";
            this->expect_eq(temp1->hasCharLimit(),false,title);

            title = "DefaultCharLimit";
            this->expect_eq(temp1->getCharLimit(),0,title);

            title = "getString";
            this->expect_eq(temp1->getText(),"Hello",title);

            title = "setText";
            temp1->setText("World");
            this->expect_eq(temp1->getText(),"World",title);

            title = "setEmptyText";
            temp1->setText("");
            this->expect_eq(temp1->getText(),"",title);

            title = "setPosition";
            float z = 1;
            float t = 1;
            temp1->setPosition(z,t);
            this->expect_eq(temp1->getX(),1,title);
            this->expect_eq(temp1->getY(),1,title);

            ranTests();
            delete temp1;
	}
};

#endif
