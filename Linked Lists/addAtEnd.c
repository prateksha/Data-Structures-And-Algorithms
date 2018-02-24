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

void addAtEnd(struct node *head,int key)
{
  struct node *temp,*t;
  temp = head;
  t = (struct node*)malloc(sizeof(struct node));
    while(temp->next!=NULL)
    {
      temp = temp->next;
    }
    temp->next = t;
  t->data = key;
  t->next = NULL;
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
  addAtEnd(first,7);
  printList(first);

  return 0;
}
