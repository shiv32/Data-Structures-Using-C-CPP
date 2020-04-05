//stack-2
//stack using array in c++

#include<iostream>

using namespace std;

#define MAXSIZE 100

class STACK_ARRAY
{
int stack[MAXSIZE];
int Top;

	public:
       STACK_ARRAY()
       {
       Top = -1;
       }
void push();
void pop();
void traverse();       
};

void STACK_ARRAY::push()
{
int item;

if(Top == MAXSIZE-1)
{
cout << "\n Stack is full\n";
}else{
cout << "\nenter the element to be inserted : \n";
cin >> item;
stack[++Top] = item;
}
}

void STACK_ARRAY::pop()
{
int item;

if(Top == -1)
{
cout << "\nStack is empty\n";
}else{
item = stack[Top--];
cout << "\nThe deleted element  is : \n"<<item;
}

}

void STACK_ARRAY::traverse()
{
int i;

if(Top == -1)
{
cout << "\nStack is empty\n";
}else{
cout << "\nThe element in the stack is/are : \n";

for(i=Top;i>=0;i--)
	cout<<"\n"<<stack[i];
}
}

int main()
{
int choice;
char ch;
bool cond = true;

STACK_ARRAY ps;

while(cond)
{
//menue
cout << "\n=======================\n";
cout <<"\n1. PUSH";
cout <<"\n2. POP";
cout <<"\n3. TRAVERSE";
cout <<"\n4. QUIT";
cout <<"\n-----------------------\n";
cout << "\nEnter your choice : \n";
cin >> choice;
cout <<"\n------------------------\n";

switch(choice)
{

	case 1:
	ps.push();
        break;	
       
	case 2:
        ps.pop();
        break; 
    
	case 3:
        ps.traverse();
        break; 

	case 4:
        cout << "\nSuccessfully Quit !\n";
	cond = false;	
        break;

	default:
	cout<<"\nYoy Entered wrong choice !\n";

}

}
return 0;
}


