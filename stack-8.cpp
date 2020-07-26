//stack-8
//Evaluate postfix expression using stack (array) in C++
//result will be in float/int

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

//defining the maximum size of the srack
#define MAXSIZE 100

//a class initialised with public and private variables and functions
class POST_EVAL
{
	float stack[MAXSIZE]; 
        int Top;

	public:
	//constructor is called and Top pointer is initialised to -1 when the object is created for the class
	 POST_EVAL()
	 {
	 Top = -1; //empty stack
	 }

	 void push(float);
	 float pop();
	 float Postfix_Eval();
};

//this function will add/insert an element to Top of the stack
void POST_EVAL::push(float item)
{
//if the top pointer already reached the maximum allows size then we can say that the stack is full or overflow
  if(Top == MAXSIZE-1)
  {
  cout <<"\nThe stack is full\n";
  }
  else //otherwise an element can be added or inserted by incrementing the stack pointer Top as follows
  {
  stack[++Top] = item;
  }
}

//this function will delete an element from the Top of the stack
float POST_EVAL::pop()
{
float item;
//if the Top pointer points to NULL, then the stack is empty that is no element is there to delete or pop
if(Top == -1)
{
cout <<"\nThe stack is empty/Invalid Postfix expression\n";
}
else//otherwise the top most element in the stack is poped or deleted by decrementing the Top pointer
{
item = stack[Top--];
}
return item;
}

//this function will return calculated value of postfix expression
float POST_EVAL::Postfix_Eval()
{
float a,b,temp;
int len;
char postfix[MAXSIZE];

cout <<"\nEnter the Postfix expression : ";
cin >> postfix;

//finding length of the string
len = strlen(postfix);

for(int i = 0;i<len;i++)
{

   //operand
if(postfix[i]<='9' && postfix[i]>='0') //postfix[i] is in ASCII 
    push(postfix[i]-48); //postfix[i] is in ASCII 
else //operator
{
  a = pop();
  b = pop();

  switch(postfix[i])
  {
   case '+':
	   temp = b+a; break;
   case '-':
	   temp = b-a; break;
   case '*':
	   temp = b*a; break;
   case '/':
	   temp = b/a; break;
   case '%':
	   temp = fmodf(b,a); break; //fmodf is math lib fun
   case '^': 
           temp = pow(b,a);break;  //pow is math lib fun
  
  }
  push(temp);
}

}
return pop();
}	

int main()
{
char choice;
float RESULT;
POST_EVAL ps;

do
{
  system("clear");//clear terminal	
 
  cout << "\n===== Postfix expression evaluation in C++ ==========\n";
 
  RESULT = ps.Postfix_Eval();
 
  cout <<"\n\nThe postfix evaluation is = "<<RESULT;
 
  cout << "\n\n=====================================================\n";
 
  cout <<"\n\nDo you want to continue (Y/y) : ";
 
  cin >> choice;
 
  system("clear");//clear terminal 
}
while(choice == 'Y' || choice == 'y');
return 0;
}



