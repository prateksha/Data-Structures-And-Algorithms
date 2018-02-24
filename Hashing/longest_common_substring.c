//Assume len1>len2
# include <stdio.h>
# include <string.h>
# define d 10
# define m 101

char s1[100001];
char s2[100001];
int len1;
int len2;
int hash1[100000];
int hash2[100000];
int res_a=-1,res_b=-1;
int max=0;

void print_array(int arr[], int n)
{
  int i;
  for(i=0; i<n; i++)
    printf("%d ",arr[i]);
  printf("\n");
}


int binary_search(int start,int end,char *s1,char *s2)
{
  if((start<=end) && (start+end)/2 <=len2)
  {
    //printf("Entering Binary Search Function\n");
    int check = (start + end)/2;
    int arr[m] = {0};
    int i;
    arr[hash2[check-1]%m] = 1;

    int p = 1;
    for(i=0; i<check; i++)
      p = (p*d)%m;
    for(i=1; i<len2-check+1; i++)
    {
      arr[(hash2[i+check-1]%m - (hash2[i-1]*p)%m + m)%m] = 1;
    }
    if(arr[hash1[check-1]%m]==1)
    {
      if(check>max)
      {
        res_a = 0;
        res_b = check-1;
        max = check;
      }
      binary_search(check+1,end,s1,s2);

    }
    else
    {
      for(i=1; i<=len1-check; i++)
      {
        if(arr[(hash1[i+check-1]%m - (hash1[i-1]*p)%m +m)%m] == 1)
        {
          //printf("Entering More\n");
          if(check>max)
          {
            res_a = i;
            res_b = i+check-1;
            max = check;
          //  printf("res_a  = %d res_b = %d\n",res_a,res_b);
          }
        //  if(check+1<=end)
            binary_search(check+1,end,s1,s2);
        //  else
          //  return max;
        }
        else
        {
          //printf("Entering Less\n");
          binary_search(start,check-1,s1,s2);
        }
      }
    }
  }
//  printf("FINALLY OUT!!\n");
}

void lcs(char *s1, char *s2)
{
  len1 = strlen(s1);
  len2 = strlen(s2);
  hash1[0]=s1[0]%m,hash2[0]=s2[0]%m;
  int i;
  for(i=1; i<len1; i++)
    hash1[i] = ((hash1[i-1]*d) + s1[i])%m;
  for(i=1; i<len2; i++)
    hash2[i] = ((hash2[i-1]*d) + s2[i])%m;
  print_array(hash1,len1);
  print_array(hash2,len2);
  binary_search(0,len2,s1,s2);
}

int main()
{
  scanf("%s %s",s1,s2);
  lcs(s1,s2);
  printf("Starting Index = %d and Ending Index =  %d \n",res_a,res_b );
  printf("Length = %d\n",max);
  int i;
  if(res_a>=0 && res_b>=0)
  {
    for(i=res_a; i<=res_b; i++)
      printf("%c",s1[i]);
    printf("\n");
  }
  return 0;
}
