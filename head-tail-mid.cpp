#include<stdio.h>
#include<stdlib.h>
struct dnode
{
    dnode *left;
    int data;
    dnode *right;
};
void mid(dnode **p)
{
    if(p==NULL)
    {
        printf("empty doubly linked list\n");
    }
    else
    {
             dnode *head=*p,*tail=*p;
            while(tail->right!=NULL)
            {
                tail=tail->right;
            }
            while(1)
            {
                if(head->right!=NULL&&head->right==tail->left)
                {
                    printf("mid element is %d\n",head->right->data);
                    break;
                }
                else if((head->right==tail)&&(tail->left==head))
                {
                    printf("mid lements are %d %d\n",head->data,tail->data);
                    break;
                }
                head=head->right;
                tail=tail->left;
            }
    }


}
void insert(dnode **head,int data)
{
    dnode *newnode=(dnode *)malloc(sizeof(dnode));
    newnode->data=data;
    if((*head)==NULL)
    {
        newnode->left=NULL;
        newnode->right=NULL;
        *head=newnode;
    }
    else
    {
        newnode->left=NULL;
        newnode->right=(*head);
        newnode->right->left=newnode;
        *head=newnode;
    }
}

void display(dnode **head)
{
    dnode *p=*head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->right;
    }
    printf("\n");
}
int main()
{
    int n;
    dnode *head=NULL;
    int val;
    while(1)
    {
        printf("1.insert\n2.mid\n3.display\n4.exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf("enter the alement ot insert\n");
            scanf("%d",&val);
            insert(&head,val);
            break;
        case 2:
            mid(&head);
            break;
        case 3:printf("displaying the elements in the linked list\n");
            display(&head);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
