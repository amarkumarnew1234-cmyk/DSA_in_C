/*4) Write a menu driven program for all the operations in case of doubly circular linked list
4.	Insert at the beginning of the linked list
5.	Insert at the end of the linked list
6.	Insert at the given position of the linked list
7.	Delete from the beginning of the linked list
8.	Delete from the end of the linked list
9.	Delete from the given position of the linked list
10.	Search an element in a given linked list
11.	Traversing/ Display of linked list
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
int count();

int main()
{
    int choice;

    do
    {
        printf("\n--- Doubly Circular Linked List Menu ---\n");
        printf("1.Insert at Beginning\n");
        printf("2.Insert at End\n");
        printf("3.Insert at Position\n");
        printf("4.Delete from Beginning\n");
        printf("5.Delete from End\n");
        printf("6.Delete from Position\n");
        printf("7.Search Element\n");
        printf("8.Display\n");
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

    }while(choice!=0);

    return 0;
}

int count()
{
    if(head==NULL)
        return 0;

    int c=0;
    struct node *temp=head;

    do
    {
        c++;
        temp=temp->next;
    }
    while(temp!=head);

    return c;
}

void insert_begin()
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&new->data);

    if(head==NULL)
    {
        new->next=new;
        new->prev=new;
        head=new;
    }
    else
    {
        struct node *last=head->prev;

        new->next=head;
        new->prev=last;

        last->next=new;
        head->prev=new;

        head=new;
    }
}

void insert_end()
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&new->data);

    if(head==NULL)
    {
        new->next=new;
        new->prev=new;
        head=new;
    }
    else
    {
        struct node *last=head->prev;

        new->next=head;
        new->prev=last;

        last->next=new;
        head->prev=new;
    }
}

void insert_pos()
{
    int pos;
    printf("Enter position: ");
    scanf("%d",&pos);

    int n=count();

    if(pos<=0 || pos>n+1)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos==1)
    {
        insert_begin();
        return;
    }

    if(pos==n+1)
    {
        insert_end();
        return;
    }

    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&new->data);

    struct node *temp=head;
    int i=1;

    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }

    new->next=temp->next;
    new->prev=temp;

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

    if(head->next==head)
    {
        free(head);
        head=NULL;
        return;
    }

    struct node *last=head->prev;
    struct node *temp=head;

    head=head->next;

    head->prev=last;
    last->next=head;

    free(temp);
}

void delete_end()
{
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }

    if(head->next==head)
    {
        free(head);
        head=NULL;
        return;
    }

    struct node *last=head->prev;
    struct node *second_last=last->prev;

    second_last->next=head;
    head->prev=second_last;

    free(last);
}

void delete_pos()
{
    int pos;
    printf("Enter position: ");
    scanf("%d",&pos);

    int n=count();

    if(pos<=0 || pos>n)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos==1)
    {
        delete_begin();
        return;
    }

    if(pos==n)
    {
        delete_end();
        return;
    }

    struct node *temp=head;
    int i=1;

    while(i<pos)
    {
        temp=temp->next;
        i++;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    free(temp);
}

void search()
{
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }

    int key,pos=1;
    printf("Enter element to search: ");
    scanf("%d",&key);

    struct node *temp=head;

    do
    {
        if(temp->data==key)
        {
            printf("Found at position %d\n",pos);
            return;
        }

        temp=temp->next;
        pos++;

    }while(temp!=head);

    printf("Not found\n");
}

void display()
{
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }

    struct node *temp=head;

    printf("HEAD <-> ");

    do
    {
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);

    printf("HEAD\n");
}