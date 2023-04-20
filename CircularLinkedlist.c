#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert_at_first(struct Node* head, int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    if (head == NULL) {
        temp->next = temp;
    } else {
        struct Node* cur = head;
        while (cur->next != head) {
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = head;
    }
    return temp;
}

struct Node* insert_at_end(struct Node* head, int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    if (head == NULL) {
        temp->next = temp;
        head = temp;
    } else {
        struct Node* cur = head;
        while (cur->next != head) {
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = head;
    }
    return head;
}

void print(struct Node* head) {
    struct Node* cur = head;
    while (cur->next != head) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("%d ", cur->data);
}

int main() {
    struct Node* head = NULL;
    for (int i = 0; i < 5; i++) {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        head = insert_at_first(head, data);
    }
    print(head);
    printf("\n");
    for (int i = 0; i < 5; i++) {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        head = insert_at_end(head, data);
    }
    print(head);
    return 0;
}
