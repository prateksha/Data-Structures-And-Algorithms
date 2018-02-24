# include <stdio.h>

void swap(int *p, int *q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

int min(int num_array[], int num, int start)
{
  int m = num_array[start];
  int i,r = start;
  for(i=start+1; i<num; i++)
  {
    if(num_array[i]<m)
    {
       r = i;
       m = num_array[i];
    }
  }
  return r;
}

int main()
{
  int num;
  scanf("%d",&num);
  int num_array[100];
  int i;
  for(i=0; i<num; i++)
    scanf("%d",&num_array[i]);
  for(i=0; i<num-1; i++)
  {
    int r = min(num_array,num,i);
    swap(&num_array[i],&num_array[r]);
  }
  for(i=0; i<num; i++)
    printf("%d ",num_array[i]);
  printf("\n");
  return 0;
}
