//stack-4
//simulation of tower of hanoi using recurion

#include<iostream>
#include<string>

using namespace std;

//global variables for disks
string x;
string y;
string z;

class tower
{
//private variables
int NoDisk;
char FromTower, ToTower, AuxTower;

	public:
void hanoi(int,char,char,char); //for recursive calling
void displayTowers(int,char,char,char); //display towers and disks
};
                      //      X             Z           Y            
void tower::hanoi(int NoDisk,char FromTower,char ToTower,char AuxTower)
{

if(NoDisk == 1)
{ 
cout <<"\n Move disk 1 from tower "<<FromTower<<" to tower "<<ToTower<<endl;
displayTowers(NoDisk,FromTower,ToTower,AuxTower);
return;
}

hanoi(NoDisk-1,FromTower,AuxTower,ToTower);

cout<<"\n Move disk "<<NoDisk<<" from tower "<<FromTower<<" to tower "<<ToTower<<endl;
displayTowers(NoDisk,FromTower,ToTower,AuxTower);

hanoi(NoDisk-1,AuxTower,ToTower,FromTower);
return;
}

void tower::displayTowers(int NoDisk,char FromTower,char ToTower,char AuxTower)
{
//remove top disks from towers
if(FromTower == 'X'){
  const auto pos = x.find_last_of("("); //(3)(2)(1)
	  x = x.substr(0,pos);
}

if(FromTower == 'Y'){
  const auto pos = y.find_last_of("("); //(3)(2)(1)
          y = y.substr(0,pos);
}

if(FromTower == 'Z'){
  const auto pos = z.find_last_of("("); //(3)(2)(1)
          z = z.substr(0,pos);
}

//add disks in towers
if(ToTower == 'X'){
  x += "(";
  x += std::to_string(NoDisk);
  x += ")";  // (1)
}

if(ToTower == 'Y'){
  y += "(";
  y += std::to_string(NoDisk);
  y += ")";  // (1)
}

if(ToTower == 'Z'){
  z += "(";
  z += std::to_string(NoDisk);
  z += ")";  // (1)
}

//display towers with disks
cout <<"\n================================\n";
cout << "X : "<<x<<endl;
cout << "Y : "<<y<<endl;
cout << "Z : "<<z<<endl;
cout <<"\n================================\n";
}

int main()
{
int No;
tower Ob;

cout<<"\n\t\t\t--- Tower of Hanoi ---\n";

cout<<"\n\nEnter No. of Disks = ";
cin>>No;
cout<<endl;

//display towers starting position
for(int i = No;i>0;i--){
  x += "(";
  x += std::to_string(i);
  x += ")";  // (1)
}

cout <<"\n======= Towers starting postion  =======\n";
cout << "X : "<<x<<endl;
cout << "Y : "<<endl;
cout << "Z : "<<endl;
cout <<"\n================================\n";

Ob.hanoi(No,'X','Z','Y');

return 0;
}

