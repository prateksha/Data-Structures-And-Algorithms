# include <stdio.h>
# include <stdlib.h>

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

void delatend(struct node *head)
{
  struct node *temp;
  struct node *t;
  temp = head;
  if((temp->next)!= NULL)
  {
    t = temp;
    temp = temp->next;
  }
  t->next = NULL;
  free(temp);
  //return temp;
}

void addatbeg(struct node **head, int key)
{
  struct node *temp;
  temp = malloc(sizeof(struct node));
  temp -> data = key;
  temp -> next = *head;
  *head = temp;
}

void reverse(struct node **head)
{
  struct node *p = NULL,*c=*head,*n;
  while(c!=NULL)
  {
    n = c->next;
    c->next = p;
    p = c;
    c = n;
  }
  *head = p;
}

void reverse_diff(struct node **head)
{
  int count = 0;
  while(head!=NULL)
  {
    count++;
    head = head->next;
  }
  int i=0;
  while(i<count)
  {

  }

}
