#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertRear(struct Node* head, int data) {
    struct Node* temp = createNode(data);
    if (head == NULL) {
        return temp;
    }
    struct Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = temp;
    return head;
}

struct Node* reverse(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node* prev = NULL;
    struct Node* cur = head;
    while (cur != NULL) {
        struct Node* forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
    }
    return prev;
}

void print(struct Node* head) {
    struct Node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    for (int i = 0; i < 5; i++) {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        head = insertRear(head, data);
    }
    print(head);
    printf("\n");
    head = reverse(head);
    print(head);
    return 0;
}
