# include <stdio.h>
# include <string.h>

# define d 256
int search(char pat[], char txt[], int q)
{
  int m = strlen(pat);
  int n = strlen(txt);
  int p=0, t=0, h=1;
  int i,j;
  for(i=0; i<m-1; i++)
  {
    h = (h*d)%q;
  }
  for(i=0; i<m; i++)
  {
    t = (t*d + txt[i])%q;
    p = (p*d + pat[i])%q;
  }
  for(i=0; i<=n-m; i++)
  {
    if(p==t)
    {
      for(j=0; j<m; j++)
      {

        if(txt[i+j]!=pat[j])
          break;
      }
      if(j==m)
        return 1;
    }
    if(i<n-m)
    {
      t = ((t - txt[i]*h)*d + txt[i+m])%q;
      if(t<0)
        t += q;
    }
  }
  return 0;
}

int main()
{
  char pat[10000];
  char txt[10000];
  scanf("%s",pat);
  scanf("%s",txt);
  printf("%d\n",search(pat,txt,101));
  return 0;
}
