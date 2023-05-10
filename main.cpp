#include <iostream>
#include <string.h>
#include <cmath>

struct node {
    int data;
    struct node* next;
};

struct hashTable {
    int* id;
    int* status; // 0: boş, 1: dolu
    int* links;
    int* cache_status; // 0: cache'de değil, 1: cache'de
    int size; 
    int m;
};

typedef struct node node_t;
typedef struct hashTable hashTable_t;

void printlist(node_t *head) {
    node_t *temp = head;

    while (temp != NULL) {
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int horner(std::string str) {
    int len = str.length();
    int num;

    for (int i = 0; i < len; i++) {
        num += (str[i] - '0') * pow(10, len - 1 - i);
    }
    return num;
}

int double_hash(int key, int i, int m) {
    int h1 = key % m;
    int h2 = 1 + (key % (m - 1));
    return (h1 + i*h2) % m;
}

int main(int argc, char const *argv[]) {
    
    return 0;
}
