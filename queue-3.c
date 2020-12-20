//queue-3
//Input and output restricted dequeue(double ended queue) using array in C

#include <stdio.h>
#include <stdlib.h> //exit()

#define MAX 5 // 5 element max in dequeue

int deque_arr[MAX]; //dequeue array

//for dequeue array index
int left;
int right;

void display_dequeue(); //display dequeue element
void mainmenu(); //main menu for dequeue

//insert an element at the right side of the dequeue
void insert_right()
{
system("clear");
int added_item;

//check dequeu overflow
if((left == 0 && right == MAX-1) || (left == right+1))
{
printf("\n\t\t\t\t\t\tDequeue Overflow\n");
return;
}

if(left == -1)//if queue is initially empty
{
 //for first element	
 left = 0;
 right = 0;
}
else if(right == MAX-1) //right is at last position of dequeue
 right = 0;
else
 right = right+1;

printf("\n\t\t\t\tInput the element for adding in Dequeue: ");
scanf("%d",&added_item);

//inputting the element at the right
deque_arr[right] = added_item;
display_dequeue();
}

//insert an element at the left side of the dequeue
void insert_left()
{
system("clear");
int added_item;

//checking for queue overflow
if((left == 0 && right == MAX-1) || (left == right+1))
{
printf("\n\t\t\t\t\t\tDequeue Overflow\n");
return;
}

if(left == -1)//if queue is initially empty
{
//for first element	
left = 0;
right = 0;
}
else if(left == 0)
	left = MAX-1;
    else
	left = left-1;

printf("\n\t\t\t\tInput the element for adding in Dequeue : ");
scanf("%d", &added_item);
//inputting at the left side of the queue
deque_arr[left] = added_item;
display_dequeue();
}

//delete an element from the left side of the dequeue
void delete_left()
{
system("clear");
//checking for queue underflow
if(left == -1)
{
printf("\n\t\t\t\t\t\tDequeue Underflow\n");
return;
}

//deleting the element from the left side
printf("\n\t\t\t\tElement deleted from Dequeue is: %d\n",deque_arr[left]);
if(left == right)//Queue has only one element
{
//reset dequeue array index
left = -1;
right = -1;
}
else if(left == MAX-1)
	left = 0;
     else
         left = left+1;

display_dequeue();	 
}

//delete an element from the right side of the dequeue
void delete_right()
{
system("clear");
//checking for underflow condition
if(left == -1)
{
printf("\n\t\t\t\t\t\tDequeue Underflow\n");
return;
}

printf("\n\t\t\t\tElement deleted from Dequeue is: %d\n",deque_arr[right]);
if(left == right) //queue has only one element
{
//reset dequeue index 	
left = -1;
right = -1;
}
else if(right == 0)
	right = MAX-1;
     else
        right=right-1;
display_dequeue();
}

//display all the element of the deqeue 
void display_dequeue()
{
system("clear");
int front_pos = left, rear_pos = right;
//checking whether the queue is empty or not
if(left == -1)
{
printf("\n\t\t\t\t\t\tDequeue is empty\n");
return;
}
//display the dequeue elements
printf("\n\t\t\t\tDequeue elements: ");
if(front_pos <= rear_pos)
{
   while(front_pos <= rear_pos)
   {
   printf("[ "); //open bracket symbol for array
   printf("%d",deque_arr[front_pos]);
   printf(" ]"); //close bracket symbol for array 
   front_pos++;
   }
}
else
{

 while(front_pos <= MAX-1)
 {
  printf(" [");
  printf("%d",deque_arr[front_pos]);
  printf(" ]");
  front_pos++;
 }
 front_pos = 0;
 
 while(front_pos <= rear_pos)
 {
 printf(" [");
 printf("%d",deque_arr[front_pos]);
 printf(" ]");
 front_pos++;
 }
}
printf("\n");
}

//implement all the operation of the input restricted dequeue
void input_que()
{
system("clear");
int choice;
while(1)
{
printf("\n\t\t\t\t================================================\n");
printf("\n\t\t\t\t\t -: Input restricted Dequeue :-\n");
//menu options to input restricted dequeue
printf("\n\t\t\t\t1. Insert at right\n");
printf("\t\t\t\t2. Delete from left\n");
printf("\t\t\t\t3. Delete from right\n");
printf("\t\t\t\t4. Display\n");
printf("\t\t\t\t5. Main menu\n");
printf("\t\t\t\t6. Quit\n");
printf("\n\t\t\t\t================================================\n");
printf("\n\t\t\t\tEnter your choice : ");
scanf("%d",&choice);

switch(choice)
{
	case 1:
		insert_right();
		break;
	case 2:
		delete_left();
		break;
	case 3:
		delete_right();
		break;
	case 4:
		display_dequeue();
		break;
	case 5:
                mainmenu();
	        break;
	case 6:
	        system("clear");
	        exit(0);
	        break;
	default :
	        system("clear");
	        printf("\n\t\t\t\t\t\tWrong choice\n");
}
}
}

//implement all the operation of the output restricted dequeue
void output_que()
{
system("clear");
int choice;
while(1)
{
printf("\n\t\t\t\t================================================\n");
printf("\n\t\t\t\t\t -: Output restricted Dequeue :-\n");
//menu options for output restricted dequeue
printf("\n\t\t\t\t1. Insert at right\n");
printf("\t\t\t\t2. Insert at left\n");
printf("\t\t\t\t3. Delete from left\n");
printf("\t\t\t\t4. Display\n");
printf("\t\t\t\t5. Main Menu\n");
printf("\t\t\t\t6. Quit\n");
printf("\n\t\t\t\t================================================\n");

printf("\n\t\t\t\tEnter your choice : ");
scanf("%d",&choice);

switch(choice)
{
	case 1:
		insert_right();
		break;
	case 2:
		insert_left();
		break;
	case 3:
		delete_left();
		break;
	case 4:
		display_dequeue();
		break;
	case 5:
                mainmenu();
		break;
	case 6:
		system("clear");
		exit(0);
		break;
	default :
		system("clear");
		printf("\n\t\t\t\t\t\tWrong choice\n");
}
}
}

void mainmenu()
{
system("clear");

//reset dequeue array index
left = -1;
right = -1; 

int choice;
repeat: //label for goto statement
printf("\n\t\t\t\t================================================\n");
//main menu option
printf("\n\t\t\t\t -: Input and Output restricted Dequeue :-\n");
printf("\n\t\t\t\t1. Input restricted Dequeue\n");
printf("\t\t\t\t2. Output restricted Dequeue\n");
printf("\t\t\t\t3. Exit\n");
printf("\n\t\t\t\t================================================\n\n");

printf("\t\t\t\tEnter your choice : ");
scanf("%d",&choice);

switch(choice){
       case 1:
                input_que();
                break;
       case 2:
                output_que();
                break;
       case 3:
		system("clear");
                exit(0);
                break;

       default:
		system("clear");
                printf("\n\t\t\t\t\t\tWrong choice\n");
		goto repeat; //control jump to repeat label 
}
}

void main()
{
	mainmenu();
}

