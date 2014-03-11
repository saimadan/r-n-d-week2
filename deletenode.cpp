#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    node *link;
};
void insertatbeg(node **head,int val)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=val;
    newnode->link=*head;
    *head=newnode;
}
void erase(node **head,int val)
{
    node *p=*head,*q;
    while(p!=NULL)
    {
        if(p->data==val)
        {
            node *frees=p;
            if(p==(*head))
           {
                p=p->link;
                *head=p;
                free(frees);
           }
         else
          {
                q->link=p->link;
                p=p->link;
                free(frees);
          }
        }
        else
        {
            q=p;
            p=p->link;
        }
    }
}
void display(node **head)
{
    node *p=*head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");
}
int main()
{
    int n;
    int val;
    node *head=NULL;
    while(1)
    {
        printf("1.insertatbeg\n2.delete\n3.display\n4.exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("enter data");
            scanf("%d",&val);
            insertatbeg(&head,val);
            break;
        case 2:
            printf("enter value to delete\n");
            scanf("%d",&val);
            erase(&head,val);
            break;
        case 3:
            printf("displaying elements\n");
            display(&head);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
