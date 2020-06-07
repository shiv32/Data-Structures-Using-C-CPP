//stack-3
//find factorial of a number using recursion from 0 to 10

#include<iostream>
#include<string>

using namespace std;

//global variable
int number,factorial;
string factMultiply = " ";

void fact(int no,int facto)
{
     if(no<=1){
     cout << "\n================================\n";
      factMultiply += std::to_string(no);
     //final computaion and returing and restoring address
     cout << "\nThe factorial of "<<number<<" is ("<<factMultiply<<" ) = "<<facto<<endl<<endl;
return;
     }else{
     //partial computaion of a program
     facto=facto*no;
     factMultiply += std::to_string(no);
     factMultiply += " * ";
     
     //funtion call to itself that is recurion
     fact(--no,facto);
     }


}

int main()
{
//initialize factorial variable
factorial = 1;

tryagain:
cout << "\n================================\n";
cout << "\nEnter the number from 0 to 10 = ";
cin >> number;

if(number < 0 || number > 10)
{
cout << "\n================================\n";
cout << "\nPls Enter number from 0 to 10"<<endl;
goto tryagain;
}else
{
//starting point of the funtion,which calls itself
fact(number,factorial);
}
return 0;
}
