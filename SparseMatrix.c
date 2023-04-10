#include<stdio.h>

#define MAX_R 10
#define MAX_C 10

void take_input(int matrix[][MAX_C], int rows, int cols) {
    printf("Enter matrix values\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int sparse_input(int matrix[][MAX_C], int row, int cols, int sparse[][3]) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count][2] = matrix[i][j];
                count++;
            }
        }
    }
    return count;
}

void print(int sparse[][3], int count) {
    printf("matrix representation\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int matrix[MAX_R][MAX_C];
    int sparse[MAX_R * MAX_C][3];
    int rows, cols;
    printf("Enter No of rows and columns\n");
    scanf("%d %d", &rows, &cols);
    take_input(matrix, rows, cols);
    int count = sparse_input(matrix, rows, cols, sparse);
    print(sparse, count);
    return 0;
}
