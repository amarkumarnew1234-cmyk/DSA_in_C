/*
5.	Write a menu driven program for the addition, subtraction, and multiplication of two polynomials using singly linked lists.
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef;
    int exp;
    struct node *next;
};

struct node* insert(struct node *head,int c,int e)
{
    if(c==0)
        return head;

    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->coef=c;
    new->exp=e;
    new->next=NULL;

    if(head==NULL || head->exp<e)
    {
        new->next=head;
        return new;
    }

    struct node *temp=head;

    while(temp->next && temp->next->exp>e)
        temp=temp->next;

    if(temp->next && temp->next->exp==e)
    {
        temp->next->coef+=c;
        free(new);
    }
    else
    {
        new->next=temp->next;
        temp->next=new;
    }

    return head;
}

void display(struct node *head)
{
    if(head==NULL)
    {
        printf("0\n");
        return;
    }

    while(head)
    {
        if(head->coef>0 && head!=NULL)
            printf("+");

        printf("%dx^%d ",head->coef,head->exp);
        head=head->next;
    }

    printf("\n");
}

struct node* add(struct node *p1,struct node *p2)
{
    struct node *res=NULL;

    while(p1 && p2)
    {
        if(p1->exp==p2->exp)
        {
            res=insert(res,p1->coef+p2->coef,p1->exp);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->exp>p2->exp)
        {
            res=insert(res,p1->coef,p1->exp);
            p1=p1->next;
        }
        else
        {
            res=insert(res,p2->coef,p2->exp);
            p2=p2->next;
        }
    }

    while(p1)
    {
        res=insert(res,p1->coef,p1->exp);
        p1=p1->next;
    }

    while(p2)
    {
        res=insert(res,p2->coef,p2->exp);
        p2=p2->next;
    }

    return res;
}

struct node* subtract(struct node *p1,struct node *p2)
{
    struct node *res=NULL;

    while(p1 && p2)
    {
        if(p1->exp==p2->exp)
        {
            res=insert(res,p1->coef-p2->coef,p1->exp);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->exp>p2->exp)
        {
            res=insert(res,p1->coef,p1->exp);
            p1=p1->next;
        }
        else
        {
            res=insert(res,-p2->coef,p2->exp);
            p2=p2->next;
        }
    }

    while(p1)
    {
        res=insert(res,p1->coef,p1->exp);
        p1=p1->next;
    }

    while(p2)
    {
        res=insert(res,-p2->coef,p2->exp);
        p2=p2->next;
    }

    return res;
}

struct node* multiply(struct node *p1,struct node *p2)
{
    struct node *res=NULL;

    for(struct node *t1=p1;t1;t1=t1->next)
    {
        for(struct node *t2=p2;t2;t2=t2->next)
        {
            res=insert(res,
                       t1->coef*t2->coef,
                       t1->exp+t2->exp);
        }
    }

    return res;
}

int main()
{
    struct node *p1=NULL,*p2=NULL,*result=NULL;
    int choice,n,c,e;

    do
    {
        printf("\n1.Create P1\n2.Create P2\n3.Display\n4.Add\n5.Subtract\n6.Multiply\n0.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                p1=NULL;
                printf("Number of terms: ");
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                {
                    printf("Coef Exp: ");
                    scanf("%d%d",&c,&e);
                    p1=insert(p1,c,e);
                }
                break;

            case 2:
                p2=NULL;
                printf("Number of terms: ");
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                {
                    printf("Coef Exp: ");
                    scanf("%d%d",&c,&e);
                    p2=insert(p2,c,e);
                }
                break;

            case 3:
                printf("P1 = ");
                display(p1);
                printf("P2 = ");
                display(p2);
                break;

            case 4:
                result=add(p1,p2);
                printf("Addition = ");
                display(result);
                break;

            case 5:
                result=subtract(p1,p2);
                printf("Subtraction = ");
                display(result);
                break;

            case 6:
                result=multiply(p1,p2);
                printf("Multiplication = ");
                display(result);
                break;
        }

    }while(choice!=0);

    return 0;
}
