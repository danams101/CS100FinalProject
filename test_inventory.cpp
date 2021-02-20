#include <iostream>
#include "inventory.hpp"
using namespace std;

int main(){
  Inventory* Test1 = new Inventory();
  Test1->SetWood(5);
  cout <<  Test1->getnumWood()<<endl;
}
