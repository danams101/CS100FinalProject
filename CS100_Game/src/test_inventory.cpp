#include <iostream>
#include "inventory.hpp"
using namespace std;

int main(){
  Inventory* Test1 = new Inventory();
  cout << "Testing constructor, everything shall be set as 0, number of Wood: " << Test1->getnumWood() << ", number of Meat: " << Test1->getnumMeat();
  cout << ", number of Metal: " << Test1->getnumMetal() << ", number of Steels: " << Test1->getnumSteels() << endl;
  
  Inventory* Test2 = new Inventory();
  Test2->SetWood(5);
  cout <<"number of Wood is set as 5, expecting 5 getting: "<< Test2->getnumWood()<<endl;
  Test2->SetWood();
  cout <<"number of Wood is set back to 0, expecting 0 getting: "<< Test2->getnumWood()<<endl;
  Test2->SetWood(-1);
  cout <<"number of Wood is set as -1, expecting -1 getting: " << Test2->getnumWood()<<endl;
  Test2->SetWood(5.1);
  cout <<"number of Wood is set as 5.1, but we used int, expecting 5, getting: " << Test2->getnumWood()<<endl;
  //Test2->SetWood(a);
  //cout <<"number of Wood is set as a, expecting terminate, getting: " << Test2->getnumWood()<<endl;
  cout <<"The code for rest three object is identical to wood, so Ima just test wood :)" << endl;
}
