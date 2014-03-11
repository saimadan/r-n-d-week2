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
int count(node **head)
{
    node *p=*head;
    int count=0;
    while(p!=NULL)
    {
        p=p->link;
        count++;
    }
    return count;
}
void median(node **head,int count)
{
    float mid=0;
    int m1,m2=0;
    if((*head)==NULL)
        printf("empty linked list\n");
    else
    {
        int i=0;
        node *p=*head;
        while(i<=count/2)
        {
            m1=m2;
            m2=p->data;
            p=p->link;
            i++;
        }
        if(count%2!=0)
          printf("median of the singly linked list is %d\n",m2);
        else
        {
            mid=(m1+m2);
            mid/=2;
            printf("median of the linked list is %lf\n",mid);
        }
    }
}

int main()
{
    int n;
    int val,pos;
    node *head=NULL;
    while(1)
    {
        printf("1.insertatbeg\n2.median\n3.display\n4.exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("enter data\n");
            scanf("%d",&val);
            insertatbeg(&head,val);
            break;
        case 2:
            median(&head,count(&head));
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


