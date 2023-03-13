// Design and develop a program in C that uses Hash Function H:K->L as H(K)=K mod m(reminder
// method) and implement hashing technique to map a given key K to the address space L. Resolve
// the collision (if any) using linear probing.
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
typedef struct {
    int key;
    int value;
} pair;
pair table[TABLE_SIZE];

int hash(int key) {
    return key % TABLE_SIZE;
}
void insert(int key, int value) {
    int index = hash(key);
    while (table[index].key != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    table[index].key = key;
    table[index].value = value;
}
int search(int key) {
    int index = hash(key);
    while (table[index].key != -1) {
        if (table[index].key == key) {
            return table[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return 0;
}
void print_table() {
    int i;
    printf("Key\tValue\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t%d\n", table[i].key, table[i].value);
    }
}
int main() {
    int key, value,n;
    char ch;
    printf("Enter no of students \n");
    scanf("%d",&n);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
    table[i].key = -1;
    table[i].value = 0;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter key and value to insert: ");
        scanf("%d %d", &key, &value);
        insert(key, value);
    }
    
    printf("\nHash table contents:\n");
    print_table();
    printf("\nEnter key to search for: ");
    scanf("%d", &key);
    value = search(key);
    if (value != 0) {
        printf("Value found: %d\n", value);
    } else {
        printf("Key not found\n");
    }
    return 0;
}
