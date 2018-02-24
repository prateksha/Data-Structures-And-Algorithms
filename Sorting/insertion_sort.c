# include <stdio.h>

void insertion_sort(int num_array[], int num, int i, int j)
{
  int temp = num_array[i],extra;
  int k;
  for(k=j; k<=i; k++)
  {
    extra = num_array[k];
    num_array[k] = temp;
    temp = extra;
  }
}

int main()
{
  int num;
  scanf("%d",&num);
  int num_array[100];
  int i,r,j;
  for(i=0; i<num; i++)
    scanf("%d",&num_array[i]);
  for(i=1; i<num; i++)
  {
    r = i;
    for(j=i-1; j>=0; j--)
    {
      if(num_array[i]<num_array[j])
        r = j;
    }
    if(r!=i)
      insertion_sort(num_array,num,i,r);
  }
  for(i=0; i<num; i++)
    printf("%d ",num_array[i]);
  printf("\n");
  return 0;
}
