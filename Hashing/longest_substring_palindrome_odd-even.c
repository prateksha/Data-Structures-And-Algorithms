# include <stdio.h>
# include <string.h>

int longest_sub_palindrome(char *str)
{
  int n = strlen(str);
  int low,high;
  int i;
  int start;
  int max_len = 1;
  for(i=1; i<n; i++)
  {
    low = i-1;
    high = i;
    while(low>=0 && high<n && str[low] == str[high])
    {
      if(high-low+1 > max_len)
      {
        start = low;
        max_len = high-low+1;
      }
      low--;
      high++;
    }
    low = i-1;
    high = i+1;
    while(low>=0 && high<n && str[low]==str[high])
    {
      if(high-low+1 > max_len)
      {
        start = low;
        max_len = high-low+1;
      }
      low--;
      high++;
    }
  }
  for(i=start; i<start+max_len; i++)
    printf("%c",str[i]);
  printf("\n");
  return max_len;
}

int main()
{
  char s[100];
  scanf("%s",s);
  longest_sub_palindrome(s);
  return 0;
}
