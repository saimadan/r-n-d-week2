#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    node *link;
};
void circledisp(node **head)
{
  node *p=*head;
  if(p==NULL)
  {
      printf("empty circular link list\n");
  }
  else
  {
    do
    {
        printf("%d->",p->data);
        p=p->link;
    } while(p!=(*head));
    printf("%d ",(*head)->data);
  }
  printf("\n");
}
void insert(node **head,int val)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=val;
    if(*head==NULL)
    {
        *head=newnode;
        (*head)->link=newnode;
    }
    else
    {
        node *p=*head;
        node *q=*head;
        while(q->link!=*head)
        {
            q=q->link;
        }
        if((*head)->data>newnode->data)
        {
            newnode->link=*head;
            q->link=newnode;
            *head=newnode;
        }
        else
        {
            while(p->data<newnode->data)
            {
                q=p;
                p=p->link;
                if(p==(*head))
                {
                    break;
                }
            }
            newnode->link=q->link;
            q->link=newnode;
        }
    }
}
int main()
{
    int n;
    node *head=NULL;
    int val,i;
    while(1)
    {
        printf("1.insert\n2.display\n3.exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("enter data\n");
            scanf("%d",&val);
            insert(&head,val);
            break;
        case 2:
            printf("displaying circular linklist\n");
            circledisp(&head);
            break;
        case 3:
            exit(0);
        default:
            printf("not a proper choice\n");
            break;
        }
    }
    return 0;
}

