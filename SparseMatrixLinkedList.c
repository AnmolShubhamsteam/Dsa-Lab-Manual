#include <stdio.h>
#include <stdlib.h>

#define MAX_R 10
#define MAX_C 10

struct Node {
    int row;
    int col;
    int val;
    struct Node* next;
};

void take_input(int matrix[][MAX_C], int rows, int cols) {
    printf("Enter matrix values\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

struct Node* sparse_input(int matrix[][MAX_C], int row, int cols) {
    struct Node* head = NULL;
    struct Node* current = NULL;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
                new_node->row = i;
                new_node->col = j;
                new_node->val = matrix[i][j];
                new_node->next = NULL;

                if (head == NULL) {
                    head = new_node;
                    current = new_node;
                } else {
                    current->next = new_node;
                    current = current->next;
                }
            }
        }
    }

    return head;
}

void print(struct Node* head) {
    printf("matrix representation\n");
    while (head != NULL) {
        printf("%d\t%d\t%d\n", head->row, head->col, head->val);
        head = head->next;
    }
}

int main() {
    int matrix[MAX_R][MAX_C];
    int rows, cols;
    printf("Enter No of rows and columns\n");
    scanf("%d %d", &rows, &cols);
    take_input(matrix, rows, cols);
    struct Node* head = sparse_input(matrix, rows, cols);
    print(head);
    return 0;
}
