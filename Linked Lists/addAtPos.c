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

void addAtPos(struct node **head,int pos,int key)
{
  int count = 0;
  struct node *temp,*extra,*t,*p;
  t = NULL;
  t = (struct node*)malloc(sizeof(struct node));
  temp = *head;
  while(temp!=NULL)
  {
    count++;
    temp = temp->next;
  }
  if(pos==0)
  {
    struct node *tem;
    tem = malloc(sizeof(struct node));
    tem -> data = key;
    tem -> next = *head;
    *head = tem;
  }

  else if(pos <= count)
  {
    int c = 0;
    p = *head;
    extra = p->next;
    while(pos-1!=c)
    {
      extra = extra->next;
      p = p->next;
      c++;
    }
    p->next = t;
    t->data = key;
    t->next = extra;
  }
  else
  {
    printf("Invalid\n");
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

  int c;
  scanf("%d",&c);

  printList(first);
  addAtPos(&first,c,10);
  printList(first);

  return 0;
}
