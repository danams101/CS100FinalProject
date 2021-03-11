#ifndef __CAMPSTATUS_HPP__
#define __CAMPSTATUS_HPP__

#include "../stdafx.h"

#include "TestSuite.h"

#include "../../../CS100_Game/src/inventory/campStatus.hpp"

class CampStatusTest : public TestSuite {

    private:

    public:
        CampStatusTest(GlobalData* global_data) : TestSuite(global_data) {
            this->name = "CampStatusTest";
        }
		virtual ~CampStatusTest() {
		}

		void test() {
		    expectedTests(27);
            std::string title;
            CampStatus* temp1 = new CampStatus();

            title = "standard";
            expect_eq(temp1->getNumTents(),0,title);
            expect_eq(temp1->getNumTraps(),0,title);
            expect_eq(temp1->getRadioProgress(),0,title);
            expect_eq(temp1->getReqWoodsTent(),1,title);
            expect_eq(temp1->getReqClothsTent(),1,title);
            expect_eq(temp1->getReqWoodsTrap(),1,title);
            expect_eq(temp1->getReqMetalsTrap(),1,title);
            expect_eq(temp1->getReqMetalsRadio(),1,title);
            expect_eq(temp1->getReqElectronicsRadio(),1,title);

            title = "incrementTents";
            temp1->incrementTents();
            expect_eq(temp1->getNumTents(),1,title);

            title = "setTentsdecimal";
            temp1->setTents(2.1);
            expect_eq(temp1->getNumTents(),2,title);

            title = "setTentsNegative";
            temp1->setTents(-2);
            expect_eq(temp1->getNumTents(),-2,title);

            title = "resetTents";
            temp1->setTents(1);
            expect_eq(temp1->getNumTents(),1,title);

            title = "incrementTraps";
            temp1->incrementTraps();
            expect_eq(temp1->getNumTraps(),1,title);

            title = "setTrapsdecimal";
            temp1->setTraps(2.1);
            expect_eq(temp1->getNumTraps(),2,title);

            title = "setTrapsNegative";
            temp1->setTraps(-2);
            expect_eq(temp1->getNumTraps(),-2,title);

            title = "resetTraps";
            temp1->setTraps(1);
            expect_eq(temp1->getNumTraps(),1,title);

            title = "incrementRadio";
            temp1->incrementRadioProgress();
            expect_eq(temp1->getRadioProgress(),10,title);

            title = "setRadioProgressDecimal";
            temp1->setRadioProgress(2.1);
            expect_eq(temp1->getRadioProgress(),2,title);

            title = "setRadioProgressNegative";
            temp1->setRadioProgress(-2);
            expect_eq(temp1->getRadioProgress(),-2,title);

            title = "resetRadioProgress";
            temp1->setRadioProgress(1);
            expect_eq(temp1->getRadioProgress(),1,title);

            title = "updateMaterial";
            temp1->updateReqMaterials();
            expect_eq(temp1->getReqWoodsTent(),2,title);
            expect_eq(temp1->getReqClothsTent(),2,title);
            expect_eq(temp1->getReqWoodsTrap(),2,title);
            expect_eq(temp1->getReqMetalsTrap(),2,title);
            expect_eq(temp1->getReqMetalsRadio(),3,title);
            expect_eq(temp1->getReqElectronicsRadio(),2,title);

            ranTests();

            delete temp1;
		}
};

#endif

