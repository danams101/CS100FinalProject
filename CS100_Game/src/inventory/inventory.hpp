#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_

class Inventory{
private:
	int numWood = 0;
	int numMeat = 0;
	int numMetal = 0;
	int numCloth = 0;
        int numElectronics = 0;
public:
	Inventory(){
	  numWood = 0;
	  numMeat = 0;
          numMetal = 0;
	  numCloth = 0;
          numElectronics = 0;
}
	void SetWood(){
	numWood = 0;
}
	void SetWood(int num){
	numWood = num;
}
        void SetMeat(){
        numMeat = 0;
}
        void SetMeat(int num){
        numMeat = num;
}
        void SetMetal(){
        numMetal = 0;
}
        void SetMetal(int num){
        numMetal = num;
}
        void SetCloth(){
        numCloth = 0;
}
        void SetCloth(int num){
        numCloth = num;
}
        void SetElectronics(){
        numElectronics = 0;
}
        void SetElectronics(int num){
        numElectronics = num;
}

	int getnumWood(){
	return numWood;	
}
	int getnumMeat(){
	return numMeat;
}
        int getnumMetal(){
        return numMetal;
}
        int getnumCloth(){
        return numCloth;
}
        int getnumElectronics(){
        return numElectronics;
}
	
};

#endif
