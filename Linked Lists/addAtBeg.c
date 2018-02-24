# include<stdio.h>
# include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void addatbeg(struct node **head, int key)
{
  struct node *temp;
  temp = malloc(sizeof(struct node));
  temp -> data = key;
  temp -> next = *head;
  *head = temp;
}

void printList(struct node *head)
{
  while(head!= NULL)
  {
    printf("%d ",head->data);
    head = head->next;
  }
  printf("\n");
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
  addatbeg(&first,5);
  printList(first);

  return 0;
}
