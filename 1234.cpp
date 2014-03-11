r-n-d-week2
===========

week 2 programs of mission r&amp;d
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    node *link;
};
void insert(int n,node **head)
{
    while(n!=0)
    {
        node *newnode=(node *)malloc(sizeof(node));
        newnode->link=*head;
        newnode->data=n%10;
        *head=newnode;
        n/=10;
    }
}
void display(node **head)
{
    node *p=*head;
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->link;
    }
}
int main()
{
    node *head=NULL;
    int n;
    printf("enter th element to insert\n");
    scanf("%d",&n);
    insert(n,&head);
    printf("printing the elements\n");
    display(&head);
    return 0;
}
