# include<stdio.h>
# include<string.h>

int long_substr_palindrome(char * str)
{
  int n = strlen(str);
  int table[1000][1000];
  int i,j,k;
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {
      if(i==j)
        table[i][j] = 1;
      else
        table[i][j] = 0;
    }
  }
  int max_len = 1;
  int start = 0;
  for(i=0; i<n-1; i++)
  {
    if(str[i] == str[i+1])
    {
      table[i][i+1] = 1;
      start = i;
      max_len = 2;
    }
  }
  int end;
  for(k=3; k<=n; k++)
  {
    for(i=0; i<n-k+1; i++)
    {
      end = i+k-1;
      if(table[i+1][end-1]==1 && str[i] == str[end])
      {
        table[i][end] = 1;
        if(k>max_len)
        {
          start = i;
          max_len = k;
        }
      }
    }
  }
  for(i=start; i<=end; i++)
    printf("%c",str[i]);
  printf("\n");
  return max_len;
}

int main()
{
    char str[100];
    scanf("%s",str);
    long_substr_palindrome(str);
    return 0;
}
