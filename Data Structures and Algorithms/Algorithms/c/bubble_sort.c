#include<stdio.h>

int main(){

   int count, temp, i, j, number[30];

   printf("Enter the number of inputs?: ");
   scanf("%d",&count);				//entering no.of inputs

   printf("Enter %d numbers: ",count);

   for(i=0;i<count;i++)
   scanf("%d",&number[i]);			//entering the inputs

   
   for(i=count-2;i>=0;i--){			//bubble sort algorithm
      for(j=0;j<=i;j++){
        if(number[j]>number[j+1]){
           temp=number[j];
           number[j]=number[j+1];
           number[j+1]=temp;
        }
      }
   }

   printf("Sorted elements: ");			//printing outputs in sorted order
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}
