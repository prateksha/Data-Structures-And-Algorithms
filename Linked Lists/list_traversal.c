# include<stdio.h>
# include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};

int search(struct node *head, int x)
{
  while(head!= NULL)
  {
    if(head -> data == x)
      return 1;
    head = head ->next;
  }
  return 0;
}


int main()
{
  struct node *first = NULL;
  struct node *second = NULL;
  struct node *third = NULL;

  first = (struct node*)malloc(sizeof(struct node));
  second = (struct node*)malloc(sizeof(struct node));
  third = (struct node*)malloc(sizeof(struct node));

  first -> data = 2;
  first -> next = second;
  second -> data = 4;
  second -> next = third;
  third -> data = 6;
  third -> next = NULL;

  printf("%d\n",search(first,2));
  printf("%d\n",search(first,3));

  return 0;
}
