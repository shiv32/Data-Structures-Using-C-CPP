//program-1
//char array,char *, malloc(), free()

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
char arr[10] = "world";
char *arrp = "hello";
int noCh;

printf("\n======= arr detail =========\n");
printf("\nvalue = %s\n",arr);
printf("\nsize = %lu\n",sizeof(arr));
printf("\naddress = %p\n",&arr);

printf("\n======= arrp detail =========\n");
printf("\nvalue = %s\n",arrp);
printf("\nsize = %lu\n",sizeof(arrp));
printf("\naddress = %p\n",&arrp);
printf("\naddress store = %p\n",&arrp[0]);
printf("\nvalue of arrp[0]= %c\n",arrp[0]);

printf("\n======= arrp = arr ============\n");
arrp = arr;

printf("\n======= arr detail =========\n");
printf("\nvalue = %s\n",arr);
printf("\nsize = %lu\n",sizeof(arr));
printf("\naddress = %p\n",&arr);

printf("\n======= arrp detail =========\n");
printf("\nvalue = %s\n",arrp);
printf("\nsize = %lu\n",sizeof(arrp));
printf("\naddress = %p\n",&arrp);
printf("\naddress store = %p\n",&arrp[0]);
printf("\nvalue of arrp[0]= %c\n",arrp[0]);

printf("\n======= malloc ===========\n");
printf("\nEneter No. of char for memory allocation :");
scanf("%d", &noCh);

arrp = (char *)malloc(noCh*sizeof(char));

if(arrp == NULL)
{
printf("\nmemory allocation failed\n");
exit(0);
}else{
printf("\nmemory allocation succesfuln");

printf("\n======= arrp detail =========\n");
printf("\nvalue = %s\n",arrp);
printf("\nsize = %lu\n",sizeof(arrp));
printf("\naddress = %p\n",&arrp);
printf("\naddress of first element  = %p\n",&arrp[0]);
printf("\naddress of last element= %p\n",&arrp[noCh]);
printf("\nvalue of arrp[0]= %c\n",arrp[0]);
printf("\nvalue of arrp[n]= %c\n",arrp[noCh]);
}

printf("\n====== copy value at malloc memory =========\n");

strcpy(arrp,"shivkumaryadav");

printf("\n======= arrp detail =========\n");
printf("\nvalue = %s\n",arrp);
printf("\nsize = %lu\n",sizeof(arrp));
printf("\naddress = %p\n",&arrp);
printf("\naddress of first element  = %p\n",&arrp[0]);
printf("\naddress of last element= %p\n",&arrp[noCh]);
printf("\nvalue of arrp[0]= %c\n",arrp[0]);
printf("\nvalue of arrp[n]= %c\n",arrp[noCh]);

free(arrp);

}	



