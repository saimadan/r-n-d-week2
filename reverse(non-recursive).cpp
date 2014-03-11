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
void reverse(node **head)
{
    if(*head==NULL)
    {
        printf("no elements in the linked list\n");
    }
    else
    {
        node *next;
        node *current=*head;
        node *prev=NULL;
        while(next!=NULL)
        {
            next=current->link;
            current->link=prev;
            prev=current;
            current=next;
        }
        *head=prev;
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
    printf("\nreversing the elements................\n\n");
    reverse(&head);
    printf("printing the elements after reversing\n\n");
    display(&head);
    return 0;
}
