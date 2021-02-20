#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_

class Inventory{
private:
	int numWood = 0;
	int numMeat = 0;
	int numMetal = 0;
	int numSteels = 0;
public:
	Inventory(){
		numWood = 0;
		numMeat = 0;
		numMetal = 0;
		numSteels = 0;
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
        void SetSteels(){
        numSteels = 0;
}
        void SetSteels(int num){
        numSteels = num;
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
        int getnumSteels(){
        return numSteels;
}
	
};

#endif
