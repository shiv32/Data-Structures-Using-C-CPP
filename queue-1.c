//queue-1
//Queue using array in C programming

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue_arr[MAX];
int rear = -1; //insertion 
int front = -1; //deletion

//display queue
void display(); //declare

//show queue banner for design
void queueStartBanner()
{
 printf("\n\t\t\t===============================================\n");
 printf("\n\t\t\t\t\t=== Queue ===\n\n");
}
//end of queue banner
void queueEndBanner()
{
 printf("\n\t\t\t===============================================\n");
}

//this function will insert an element to the queue
void insert()
{
    int added_item;
    if(rear == MAX-1)//queue is full
    {
    printf("\nQueue Overflow\n");
    return;
    }
    else
    {
    if(front == -1)//if queue is initially empty
	front = 0;
    
    printf("\n\t\t\tInput the element for adding in queue : ");
    scanf("%d",&added_item);

    rear=rear+1;
    
    //Inserting the element
    queue_arr[rear] = added_item;
    }
    display();//display queue after insert element
}

//this function will delete an element from the queue
void del()
{
   if(front == -1 || front > rear)//queue is empty
   {
	 if(front > rear){//empty queue during deletion
           //reset queue index
            front = -1;
             rear = -1;
	   }

   queueStartBanner();//start banner
   printf("\t\t\t\t\tQueue Underflow\n");
   queueEndBanner();//end banner
   return;
   }
   else
   {
   //deleting the element
   printf("\n\t\t\tElement deleted from queue is : %d\n",queue_arr[front]);
   front = front+1;
   }   
    display(); //display queue after delete element
}

//display all the element of the queue
void display()
{
   int i;
   //checking whether the queue is empty or not
   if(front == -1 || front > rear) //queue is empty
   {
        if(front > rear){//empty queue during deletion
            //reset queue index
            front = -1;
             rear = -1;
           }

   queueStartBanner();//start banner
   printf("\t\t\t\t\tQueue is empty\n");
   queueEndBanner();//end banner
   return;
   }
   else
   {
   queueStartBanner();//start banner
   printf("\t\t\t\tfront->");
   for(i=front;i<=rear;i++){
	   printf("[ ");
       printf("%d",queue_arr[i]);
       printf(" ]");
   }
   printf("<-rear\n");

   printf("\n\t\t\t\tfront : %d\n",front);
   printf("\t\t\t\t rear : %d\n",rear);

   queueEndBanner();//end banner

   printf("\n");
   } 

}

//invalid option msg
void wrongChoice()
{
 queueStartBanner();//start banner
 printf("\t\t\t\t\tWrong Choice\n");
 queueEndBanner();//end banner
}

int main()
{
system("clear"); //clear terminal
queueStartBanner();//start banner
int choice;
while(1) //infinite loop
{
//menu options
printf("\n1. Insert\n");
printf("2. Delete\n");
printf("3. Display\n");
printf("4. Quit\n");
printf("\nEnter your choice : ");

scanf("%d",&choice);
system("clear"); //clear terminal

switch(choice)
{
	case 1:
		insert();//insert element in queue
		break;
	case 2:
		del();//delete element in queue
		break;
	case 3:
	    	display();//display queue element
		break;
	case 4:
	 	exit(1);//exit from program
	default:
		wrongChoice();//display invalid option msg
}
}
return 0;
}

