# include<stdio.h>
# include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};
void printList(struct node *head)
{
  while(head!= NULL)
  {
    printf("%d ",head->data);
    head = head->next;
  }
  printf("\n");
}

void delAtPos(struct node **head,int pos)
{
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp = *head;
  int c;
  while(temp!=NULL)
    {
      c++;
      temp = temp->next;
    }
  temp = NULL;
  int count = 0;
  if(pos>c-1)
    printf("Invalid\n");
  else
    {
      temp = *head;
      struct node *prev = (struct node*)malloc(sizeof(struct node));
      prev->next = *head;
      while(pos!=count)
      {
        count++;
        temp = temp->next;
        prev = prev->next;
      }
      if(pos==0)
        *head = temp->next;
      else
        prev->next = temp->next;

    }
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

  printList(first);
  delAtPos(&first,0);
  printList(first);

  return 0;
}
