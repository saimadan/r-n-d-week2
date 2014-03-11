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
void nthpos(node **head,int pos,int count)
{
    int n=count-pos+1;
    if(n<0||pos<1)
    {
        printf("not possible\n");
    }
    else
    {
        node *p=*head,*q=*head;
        if(n!=1)
        {
           int i=1;
            while(i<n-1)
            {
                p=p->link;
                i++;
            }
             q=p->link;
            p->link=NULL;
        }
        else
        {
            *head=NULL;
        }
        while(q!=NULL)
        {
            node *temp=q;
            q=q->link;
            free(temp);
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
        printf("1.insertatbeg\n2.nthpos\n3.display\n4.exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("enter data\n");
            scanf("%d",&val);
            insertatbeg(&head,val);
            break;
        case 2:
            printf("enter nth pos\n");
            scanf("%d",&pos);
            nthpos(&head,pos,count(&head));
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

