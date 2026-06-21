/*1. Write a menu driven program for all the operations in case of singly linked list
a) Insert at the beginning
b) Insert at the end
c) Insert at the given position
d) Delete from the beginning
e) Delete from the end
f) Delete from the given position
g) Search an element
h) Reverse a linked list
i) Merge two linked lists
j) Traversing / Display
k) Detect loop in a linked list
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = head;
    head = n;
}

void insert_end(int x) {
    struct node *n = malloc(sizeof(struct node)), *t = head;
    n->data = x;
    n->next = NULL;
    if (!head) { head = n; return; }
    while (t->next) t = t->next;
    t->next = n;
}
void insert_pos(int x, int pos) {
    struct node *n = malloc(sizeof(struct node)), *t = head;
    for (int i = 1; i < pos - 1 && t; i++) t = t->next;
    if (!t) return;
    n->data = x;
    n->next = t->next;
    t->next = n;
}

void delete_begin() {
    if (!head) return;
    struct node *t = head;
    head = head->next;
    free(t);
}
void delete_end() {
    struct node *t = head;
    if (!head) return;
    if (!head->next) { free(head); head = NULL; return; }
    while (t->next->next) t = t->next;
    free(t->next);
    t->next = NULL;
}

void delete_pos(int pos) {
    struct node *t = head;
    for (int i = 1; i < pos - 1 && t; i++) t = t->next;
    if (!t || !t->next) return;
    struct node *d = t->next;
    t->next = d->next;
    free(d);
}

void search(int x) {
    struct node *t = head;
    int pos = 1;
    while (t) {
        if (t->data == x) {
            printf("Element found at position %d\n", pos);
            return;
        }
        t = t->next;
        pos++;
    }
    printf("Element not found\n");
}

void reverse() {
    struct node *prev = NULL, *cur = head, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

void display() {
    struct node *t = head;
    while (t) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

void detect_loop() {
    struct node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("Loop detected\n");
            return;
        }
    }
    printf("No loop detected\n");
}

int main() {
    int ch, x, pos;
    while (1) {
        printf("\n1.InsertBeg 2.InsertEnd 3.InsertPos 4.DelBeg 5.DelEnd");
        printf("\n6.DelPos 7.Search 8.Reverse 9.Display 10.DetectLoop 0.Exit\n");
        scanf("%d",&ch);
        switch (ch) {
            case 1: scanf("%d",&x); insert_begin(x); break;
            case 2: scanf("%d",&x); insert_end(x); break;
            case 3: scanf("%d%d",&x,&pos); insert_pos(x,pos); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: scanf("%d",&pos); delete_pos(pos); break;
            case 7: scanf("%d",&x); search(x); break;
            case 8: reverse(); break;
            case 9: display(); break;
            case 10: detect_loop(); break;
            case 0: exit(0);
        }
    }
}

