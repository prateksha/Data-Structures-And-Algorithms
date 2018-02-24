# include <stdio.h>

void push(int stack[], int *top, int key)
{
  stack[*top] = key;
  (*top)++;
}

void pop(int * top)
{
  if((*top)>0)
  {
    (*top)--;
  }
}

int getMax(int hist[], int n)
{
  int stack[100];
  int t = 0;
  int *top = &t;
  int max_area = 0;
  int area_with_top;
  int i =0,x;
  while(i<n)
  {
    if((*top)==0 || hist[stack[(*top)-1]] <= hist[i])
      {
        push(stack,top,i);
        i++;
      }
    else
    {
      x = stack[(*top)-1];
      pop(top);
      area_with_top = hist[x] * ((*top)==0 ? i : i-stack[(*top)-1] - 1);
      if (max_area < area_with_top)
           max_area = area_with_top;
      printf("area %d\n",area_with_top);
    }

  }
  while((*top)>0)
  {
    x = stack[(*top)-1];
    pop(top);
    area_with_top = hist[x] * ((*top)==0 ? i : i-stack[(*top)-1] - 1);
    if (max_area < area_with_top)
         max_area = area_with_top;
  }
  return max_area;
}

int main()
{
  int n;
  int hist[100];
  scanf("%d",&n);
  int i;
  for(i=0; i<n; i++)
    scanf("%d",&hist[i]);
  printf("%d\n",getMax(hist,n));
  return 0;
}
