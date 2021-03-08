#ifndef UI_TEST_HPP
#define UI_TEST_HPP

//#include "../src/gui/UIObject.h"
//#include "stdafx.h"
#include "../src/gui/UIButton.h"
#include "gtest/gtest.h"

TEST(UiTest, Standard){
    EXPECT_EQ(0, 0);
    EXPECT_EQ(0, 0);
}


/*TEST(UIObject,Standard){
	float x = 1.0;
	float y = 1.0;
	float width = 1.0;
	float height = 1.0;
	UIObject* temp1 = new UIObject(x,y);
	EXPECT_EQ(1,temp1->getX());
}*/

TEST(UiButton,Test1){
	float x = 1;
	float y = 1;
	float width = 1;
	float height = 1;
	std::map<std::string, sf::Color> colors;
	float thickness = 0;
	std::string text = "";
	int textSize = 0;
	sf::Font* font = nullptr;
	bool centered = false;
	//UIButton* temp = new UIButton(x,y,width,height,colors,thickness,text,textSize,font,centered);
	UIButton* temp = new UIButton(x, y, width, height, colors, thickness, text, textSize, font, centered);
	
//	UIButton* temp = new UIButton(x, y, width, height);
//	EXPECT_EQ(false, temp->isCentered());
	EXPECT_EQ(false, temp->isCentered());
	EXPECT_EQ(false, temp->isHovered());
//	EXPECT_EQ(1, temp->getWidth());
//	EXPECT_EQ(1, temp->getHeight());
}

#endif // UI_TEST_HPP
