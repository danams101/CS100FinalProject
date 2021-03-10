#ifndef _CAMPSTATUS_HPP_
#define _CAMPSTATUS_HPP_

class CampStatus {
    private:
        int numTents;
        int numTraps;
        int radioProgress;

        //nesessary resources to build things
        int reqWoodsTent;
        int reqClothsTent;
        
        int reqWoodsTrap;
        int reqMetalsTrap;

        int reqMetalsRadio;
        int reqElectronicsRadio;

    public:

        CampStatus(){
            numTents = 0;
            numTraps = 0;
            radioProgress = 0;

            reqWoodsTent = 1;
            reqClothsTent = 1;
        
            reqWoodsTrap = 1;
            reqMetalsTrap = 1;

            reqMetalsRadio = 1;
            reqElectronicsRadio = 1;
        }

        int getNumTents(){
            return numTents;
        }
        int getNumTraps(){
            return numTraps;
        }

        int getRadioProgress(){
            return radioProgress;
        }
        int getReqWoodsTent(){
            return reqWoodsTent;
        }
        int getReqClothsTent(){
            return reqClothsTent;
        }
        int getReqWoodsTrap(){
            return reqWoodsTrap;
        }
        int getReqMetalsTrap(){
            return reqMetalsTrap;
        }
        int getReqMetalsRadio(){
            return reqMetalsRadio;
        }
        int getReqElectronicsRadio(){
            return reqElectronicsRadio;
        }



        void incrementTents(){
            ++numTents;
        }
        void incrementTraps(){
            ++numTraps;
        }
        void incrementRadioProgress(){
            radioProgress += 10;
        }

        void setTents(int n){
            numTents = n;
        }
        void setTraps(int n){
            numTraps = n;
        }
        void setRadioProgress(int n){
            radioProgress = n;
        }

        void updateReqMaterials(){
            reqWoodsTent = numTents * 2;
            reqClothsTent = numTents * 2;
            reqWoodsTrap = numTraps * 2;
            reqMetalsTrap = numTraps * 2;
            reqMetalsRadio = radioProgress/2 + 3;
            reqElectronicsRadio = radioProgress + 1;
        }
};



#endif







/*int tents;
        int requiredTentWood;
        int traps;
        int requiredTrapWood;
        int requiredTrapMetal;*/