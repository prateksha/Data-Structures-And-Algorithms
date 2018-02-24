# include <stdio.h>
void print(int array[],int n)
{
  int i = 0;
  for(i=0;i<n;i++)
    printf("%d ",array[i]);
}

void merge(int arr[],int l,int m, int r)
{
  int result[100000];
  int i=l,j=m+1,k=0;
  while(i<m+1 && j<=r)
  {
    if(arr[i]<arr[j])
    {
      result[k] = arr[i];
      k++;
      i++;
    }
    else
    {
      result[k] = arr[j];
      k++;
      j++;
    }
  }
  while(i<=m)
  {
    result[k] = arr[i];
    k++;
    i++;
  }
  while(j<=r)
  {
    result[k] = arr[j];
    j++;
    k++;
  }

  int z=0;
  int p=l;
  while(p<=r)
  {
    arr[p] = result[z];
    z++;
    p++;
  }
}
void mergesort(int arr[],int l, int r)
{
  int m = (r+l)/2;
  if(l==r)
    return;
  else
  {
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
  }
}


int main()
{
  int n;
  scanf("%d",&n);
  int arr[100];
  int i;
  for(i=0; i<n; i++)
    scanf("%d",&arr[i]);
  mergesort(arr,0,n-1);
  print(arr,n);
  printf("\n");
  return 0;
}
