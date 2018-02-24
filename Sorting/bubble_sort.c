# include <stdio.h>

 void swap(int *p, int *q)
 {
   int temp = *p;
   *p = *q;
   *q = temp;
 }

 int main()
 {
   int num;
   scanf("%d",&num);
   int num_array[100];
   int i,j;
   for(i=0; i<num; i++)
    scanf("%d",&num_array[i]);
   for(i=0; i<num-1; i++)
   {
     for(j=0; j<num-1-i; j++)
     {
       if(num_array[j]>num_array[j+1])
        swap(&num_array[j],&num_array[j+1]);
     }
   }
   for(i=0; i<num; i++)
    printf("%d ",num_array[i]);
  printf("\n");
  return 0;
 }
