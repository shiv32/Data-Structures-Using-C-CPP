//program-2
//malloc(), calloc(), realloc()

#include<stdio.h>
#include<stdlib.h>

void main()
{
int *arrp;
int i, noMem;
int *newp;

printf("\n===== before malloc() ======\n");
printf("\nvalue of arrp[0] before malloc(): %d \n",arrp[0]);

printf("\n===== malloc() ======\n");
printf("\nEnter Value for interger to allocate memory by malloc and calloc: ");
scanf("%d",&noMem);

arrp = (int *)malloc(noMem*sizeof(int));

if(arrp == NULL)
{
printf("\nMemory allocation is failed by malloc()\n");
exit(0);
}	

for(i=0;i<noMem;i++)
{
printf("\nvalue of arrp[%d] at address %p : %d \n", i,&arrp[i],arrp[i]);
}

free(arrp);

printf("\n===== calloc() ======\n");

arrp = (int *)calloc(noMem, sizeof(int));

if(arrp == NULL)
{
printf("\nMemory allocation is failed by calloc()\n");
exit(0);
}

for(i=0;i<noMem;i++)
{
printf("\nvalue of arrp[%d] at address %p : %d \n", i,&arrp[i],arrp[i]);
}

free(arrp);



printf("\n===== realloc() ======\n");
printf("\nEnter Value for interger to resize memory by realloc(): ");
scanf("%d",&noMem);

newp = (int *)realloc(arrp, noMem*sizeof(int));

if(arrp == NULL)
{
printf("\nMemory allocation is failed by realloc()\n");
exit(0);
}

for(i=0;i<noMem;i++)
{
printf("\nvalue of newp[%d] at address %p : %d \n", i,&newp[i],newp[i]);
}

free(newp);
}	

