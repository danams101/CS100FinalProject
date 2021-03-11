#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

#include "../stdafx.h"

#include "TestSuite.h"

#include "../../../CS100_Game/src/inventory/inventory.hpp"

class InventoryTest : public TestSuite {

    private:

    public:
        InventoryTest(GlobalData* global_data) : TestSuite(global_data) {
            this->name = "InventoryTest";
        }
	virtual ~InventoryTest() {
		}
	void test() {
	    expectedTests(25);
            std::string title;

            Inventory* temp1 = new Inventory();

            title = "Standard";
            expect_eq(temp1->getnumWood(),0,title);
            expect_eq(temp1->getnumMeat(),0,title);
            expect_eq(temp1->getnumMetal(),0,title);
            expect_eq(temp1->getnumElectronics(),0,title);
            expect_eq(temp1->getnumCloth(),0,title);

            title = "GivenValue";
            temp1->SetWood(5);
            temp1->SetMeat(5);
            temp1->SetMetal(5);
            temp1->SetCloth(5);
            temp1->SetElectronics(5);
            expect_eq(temp1->getnumWood(),5,title);
            expect_eq(temp1->getnumMeat(),5,title);
            expect_eq(temp1->getnumMetal(),5,title);
            expect_eq(temp1->getnumElectronics(),5,title);
            expect_eq(temp1->getnumCloth(),5,title);

            title = "ResetValue";
            temp1->SetWood();
            temp1->SetMeat();
            temp1->SetMetal();
            temp1->SetCloth();
            temp1->SetElectronics();
            expect_eq(temp1->getnumWood(),0,title);
            expect_eq(temp1->getnumMeat(),0,title);
            expect_eq(temp1->getnumMetal(),0,title);
            expect_eq(temp1->getnumElectronics(),0,title);
            expect_eq(temp1->getnumCloth(),0,title);

            title = "SetValueToNegative";
            temp1->SetWood(-1);
            temp1->SetMeat(-1);
            temp1->SetMetal(-1);
            temp1->SetCloth(-1);
            temp1->SetElectronics(-1);
            expect_eq(temp1->getnumWood(),-1,title);
            expect_eq(temp1->getnumMeat(),-1,title);
            expect_eq(temp1->getnumMetal(),-1,title);
            expect_eq(temp1->getnumElectronics(),-1,title);
            expect_eq(temp1->getnumCloth(),-1,title);

            title = "GivenDecimalValue";
            temp1->SetWood(1.1);
            temp1->SetMeat(1.2);
            temp1->SetMetal(1.3);
            temp1->SetCloth(1.4);
            temp1->SetElectronics(1.5);
            expect_eq(temp1->getnumWood(),1,title);
            expect_eq(temp1->getnumMeat(),1,title);
            expect_eq(temp1->getnumMetal(),1,title);
            expect_eq(temp1->getnumElectronics(),1,title);
            expect_eq(temp1->getnumCloth(),1,title);
		
            title = "JustAFunnyTest";
            temp1->SetWood(temp1->getnumWood());
            expect_eq(temp1->getnumWood(),1,title);
           
	    ranTests();

            delete temp1;
		}
};

#endif

