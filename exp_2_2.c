/*2. Write a menu driven program for all the operations in case of singly circular linked list
a)	Insert at the beginning of the linked list
b)	Insert at the end of the linked list
c)	Insert at the given position of the linked list
d)	Delete from the beginning of the linked list
e)	Delete from the end of the linked list
f)	Delete from the given position of the linked list
g)	Search an element in a given linked list
h)	Reversing a linked list
i)	Traversing/ Display of linked list
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void search();
void reverse();
void display();

int main() {
    int choice;

    do {
        printf("\n--- Singly Circular Linked List Menu ---\n");
        printf("1.Insert at Beginning\n");
        printf("2.Insert at End\n");
        printf("3.Insert at Position\n");
        printf("4.Delete from Beginning\n");
        printf("5.Delete from End\n");
        printf("6.Delete from Position\n");
        printf("7.Search Element\n");
        printf("8.Reverse List\n");
        printf("9.Display List\n");
        printf("0.Exit\n");
        printf("Enter choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_pos(); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: delete_pos(); break;
            case 7: search(); break;
            case 8: reverse(); break;
            case 9: display(); break;
            case 0: exit(0);
            default: printf("Invalid choice\n");
        }

    } while (choice != 0);

    return 0;
}

/* Insert at Beginning */
void insert_begin() {
    struct node *new = malloc(sizeof(struct node));
    if (!new) return;

    printf("Enter value:");
    scanf("%d", &new->data);

    if (head == NULL) {
        new->next = new;
        head = new;
    } else {
        struct node *last = head;
        while (last->next != head)
            last = last->next;

        new->next = head;
        last->next = new;
        head = new;
    }
}

/* Insert at End */
void insert_end() {
    struct node *new = malloc(sizeof(struct node));
    if (!new) return;

    printf("Enter value:");
    scanf("%d", &new->data);

    if (head == NULL) {
        new->next = new;
        head = new;
    } else {
        struct node *last = head;
        while (last->next != head)
            last = last->next;

        last->next = new;
        new->next = head;
    }
}

/* Insert at Position */
void insert_pos() {
    int pos, i = 1;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position:");
    scanf("%d", &pos);

    if (pos == 1) {
        insert_begin();
        return;
    }

    struct node *new = malloc(sizeof(struct node));
    if (!new) return;

    printf("Enter value:");
    scanf("%d", &new->data);

    struct node *temp = head;

    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (i != pos - 1) {
        printf("Invalid position\n");
        free(new);
        return;
    }

    new->next = temp->next;
    temp->next = new;
}

/* Delete from Beginning */
void delete_begin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct node *last = head;
        struct node *temp = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        free(temp);
    }
}

/* Delete from End */
void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;

        while (temp->next->next != head)
            temp = temp->next;

        free(temp->next);
        temp->next = head;
    }
}

/* Delete from Position */
void delete_pos() {
    int pos, i = 1;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position:");
    scanf("%d", &pos);

    if (pos == 1) {
        delete_begin();
        return;
    }

    struct node *temp = head;

    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (temp->next == head) {
        printf("Invalid position\n");
        return;
    }

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
}

/* Search */
void search() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    int key, pos = 1;
    printf("Enter element to search:");
    scanf("%d", &key);

    struct node *temp = head;

    do {
        if (temp->data == key) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Element not found\n");
}

/* Reverse Circular List */
void reverse() {
    if (head == NULL || head->next == head) {
        printf("List too small to reverse\n");
        return;
    }

    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next;
    struct node *last = head;

    while (last->next != head)
        last = last->next;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    head->next = prev;
    last->next = prev;
    head = prev;

    printf("List reversed\n");
}

/* Display */
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(HEAD)\n");
}

