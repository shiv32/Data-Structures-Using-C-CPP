//queue-2
//Circular Queue using array in c++

#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 5 //circualar queue size

//a class is created for the circular queue
class circular_queue
{
 int cqueue_arr[MAX] = {0};
 int front,rear;

	public:
             //a constructor is created to initialize the variables
	     circular_queue()
	     {
	     //C. queue is empty     
	      front = -1;
	       rear = -1;
	     }

          //public function declaration
	  void insert(); //insert circular queue element
	  void del();   //delete circular queue element
	  void display(); //display cicular queue element 
	  void cqueueIndex(int front_pos,int front,int rear); //display filled circular queue index
	  void freeIndex(int front,int rear); //display circular queue free index 
	  void queueStartBanner(); //start banner 
	  void queueEndBanner();  //end banner
	  void wrongChoice(); //wrong chioce msg
};

//start banner
void circular_queue::queueStartBanner()
{
 printf("\n\t\t\t===============================================\n");
 printf("\n\t\t\t\t\t=== Circular Queue ===\n\n");
}

//end banner
void circular_queue::queueEndBanner()
{
 printf("\n\t\t\t===============================================\n");
}


//display free index in queue
void circular_queue::freeIndex(int front,int rear)
{
	 if((front == 0 && rear == MAX-1) || (front == rear+1))//cq is not empty
           {
             cout <<endl;
             cout << "\t\t\t\t\t---------------------"<<endl;	     
             cout << "\t\t\t\t\tAll C. Queue Index Full "<<endl;
	     cout << "\t\t\t\t\t---------------------"<<endl;

          }else if(rear == MAX-1)//rear is at last position of queue
          {
               int i = 0;
               while(i < front){
                       cout << "\t\t\t\t\tindex "<<i<<" :"<<endl;
                        i++;
               }

          }else{ 
                   if(front <= rear)
                   {
                  int j = rear;
                  do{
                       cout << "\t\t\t\t\tindex "<<++j<<" :"<<endl;
                  }while(j < MAX-1);

                 
                  if(j == MAX-1)
                  {   
                        j = 0;
                        if(j < front)
                        {   
                        do{
                           cout << "\t\t\t\t\tindex "<<j++<<" :"<<endl;
                          }while(j < front);
                       }
                  }
                }else if(rear <= front){
                       int j = rear;
                      do{
                          cout << "\t\t\t\t\tindex "<<++j<<" :"<<endl;
                        }while(j < front-1);
                }
           } 
}

//display filled circular queue index
void circular_queue::cqueueIndex(int front_pos,int front,int rear)
{
        //display c. queue element
        if((front_pos == front) && (front_pos ==  rear))
         cout<<"\t\t\t\t\tindex "<<front_pos<<" : "<<"["<<cqueue_arr[front_pos]<<"]"<<" <== front(delete), rear(insert)"<<endl;
        else  if(front_pos == front)
            cout<<"\t\t\t\t\tindex "<<front_pos<<" : "<<"["<<cqueue_arr[front_pos]<<"]"<<" <== front(delete)"<<endl;
        else if(front_pos == rear)
            cout<<"\t\t\t\t\tindex "<<front_pos<<" : "<<"["<<cqueue_arr[front_pos]<<"]"<<" <== rear(insert)"<<endl;
        else
            cout<<"\t\t\t\t\tindex "<<front_pos<<" : "<<"["<<cqueue_arr[front_pos]<<"]"<<endl;         
}

//function to insert an element to the circular queue
void circular_queue::insert()
{
int added_item;

//checking for overflow condition
if((front == 0 && rear == MAX-1) || (front == rear+1))
{
queueStartBanner();
cout<<"\n\t\t\t\t\t    C. Queue Overflow\n";
queueEndBanner();
return;
}

//queue is empty
if(front == -1)
{
front = 0;
rear = 0;
}else if(rear == MAX-1)//rear is at last position of queue
rear = 0;
else
   rear = rear + 1;

cout << "\n\n\t\t\tEnter the element for insertion in C. Queue : ";
cin >> added_item;
cqueue_arr[rear] = added_item;
display(); //display cq element
}


//delete an element from the c. queue
void circular_queue::del()
{
//checking for c. queue underflow
if(front == -1)
{
queueStartBanner();
cout << "\n\t\t\t\t\t    C. Queue Underflow\n";
queueEndBanner();
return;
}

cout << "\n\t\t\tElement deleted from C. Queue is : "<<cqueue_arr[front]<<"\n";

if(front == rear)//c. queue has only one element
{
front = -1;
 rear = -1;
}else if(front == MAX -1)
         front = 0;
 else
    front = front + 1;

    display();//display cq element
}

//display the element in the c. queue
void circular_queue::display()
{
	queueStartBanner(); //start banner

	//display element	
	int front_pos = front,rear_pos=rear;
        
	//checking cirular queue is empty or not
        if(front == -1)
        { 
        cout<<"\n\t\t\t\t\t    C. Queue is empty\n";
        queueEndBanner();	
        return;
        }

        if(front_pos <= rear_pos)
        {
           while(front_pos <= rear_pos)
           {       
		   //display c. queue filled index
		   cqueueIndex(front_pos,front,rear);   
	           front_pos++;
	   
           }
        }else
        {
           while(front_pos <= MAX-1)
           {       
		   //display c. queue filled index
		   cqueueIndex(front_pos,front,rear);  
	           front_pos++;
	   
           }
           front_pos = 0;
           while(front_pos <= rear_pos)
           {        
		   //display c. queue filled index
                   cqueueIndex(front_pos,front,rear);	   
		   front_pos++;

           }
        }
	 //display free index in c. queue
         freeIndex(front,rear);
         cout <<endl;   
         queueEndBanner();	 //end banner
}

void circular_queue::wrongChoice()
{
   queueStartBanner();
   cout << "\n\t\t\t\t\t    Wrong choice\n";
   queueEndBanner();
}

//main body
int main()
{
int choice;
//creating the object of class
circular_queue cq;

//clear terminal
system("clear");

while(1)
{
//Menu
cout << "\n1. Insert\n";
cout << "\n2. Delete\n";
cout << "\n3. Display\n";
cout << "\n4. Quit\n";
cout << "\nEnter your choice : ";

cin >> choice;

//clear terminal
system("clear");

switch(choice)
{
	case 1:
		cq.insert();
		break;
	case 2:
		cq.del();
		break;
	case 3:
		cq.display();
		break;
	case 4:
		exit(1);
	default:
		cq.wrongChoice();
}

}
return 0;
}







