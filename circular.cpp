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
void sort(node **head)
{
    node *p=*head,*q;
    for(;p!=NULL;p=p->link)
    {
        for(q=p->link;q!=NULL;q=q->link)
        {
            if(p->data>q->data)
            {
                int temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
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
    printf("sorting the linked list\n");
    sort(&head);
    printf("printing the linked list after sorting\n");
    display(&head);
    printf("making circular link list\n");
    circular(&head);
    printf("printing circular link list\n");
    printcircle(&head);
    return 0;
}

