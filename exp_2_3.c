/*3.Write a menu driven program for all the operations in case of doubly linked list
a)	Insert at the beginning of the linked list
b)	Insert at the end of the linked list
c)	Insert at the given position of the linked list
d)	Delete from the beginning of the linked list
e)	Delete from the end of the linked list
f)	Delete from the given position of the linked list
g)	Search an element in a given linked list
h)	Traversing/ Display of linked list

*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;

void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void search();
void display();

int main()
{
    int choice;

    do
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1.Insert at Beginning\n");
        printf("2.Insert at End\n");
        printf("3.Insert at Position\n");
        printf("4.Delete from Beginning\n");
        printf("5.Delete from End\n");
        printf("6.Delete from Position\n");
        printf("7.Search Element\n");
        printf("8.Display List\n");
        printf("0.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_pos(); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: delete_pos(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 0: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    while(choice!=0);

    return 0;
}

void insert_begin()
{
    struct node *new=(struct node*)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d",&new->data);

    new->prev=NULL;
    new->next=head;

    if(head!=NULL)
        head->prev=new;

    head=new;
}

void insert_end()
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&new->data);

    new->next=NULL;

    if(head==NULL)
    {
        new->prev=NULL;
        head=new;
        return;
    }

    struct node *temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=new;
    new->prev=temp;
}

void insert_pos()
{
    int pos,i=1;

    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos<=0)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos==1)
    {
        insert_begin();
        return;
    }

    struct node *temp=head;

    while(i<pos-1 && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }

    if(temp==NULL)
    {
        printf("Position out of range\n");
        return;
    }

    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&new->data);

    new->next=temp->next;
    new->prev=temp;

    if(temp->next!=NULL)
        temp->next->prev=new;

    temp->next=new;
}

void delete_begin()
{
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }

    struct node *temp=head;
    head=head->next;

    if(head!=NULL)
        head->prev=NULL;

    free(temp);
}

void delete_end()
{
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }

    struct node *temp=head;

    if(temp->next==NULL)
    {
        free(temp);
        head=NULL;
        return;
    }

    while(temp->next!=NULL)
        temp=temp->next;

    temp->prev->next=NULL;
    free(temp);
}

void delete_pos()
{
    int pos,i=1;

    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos<=0)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos==1)
    {
        delete_begin();
        return;
    }

    struct node *temp=head;

    while(i<pos && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }

    if(temp==NULL)
    {
        printf("Position out of range\n");
        return;
    }

    if(temp->next!=NULL)
        temp->next->prev=temp->prev;

    if(temp->prev!=NULL)
        temp->prev->next=temp->next;

    free(temp);
}

void search()
{
    int key,pos=1;
    struct node *temp=head;

    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d",&key);

    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            printf("Found at position %d\n",pos);
            return;
        }
        temp=temp->next;
        pos++;
    }

    printf("Not found\n");
}

void display()
{
    struct node *temp=head;

    if(temp==NULL)
    {
        printf("List empty\n");
        return;
    }

    printf("NULL <-> ");

    while(temp!=NULL)
    {
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }

    printf("NULL\n");
}