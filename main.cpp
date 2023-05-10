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

hashTable_t createHashTable(int m) {
	hashTable_t table;
	table.id = new int[m];
	table.status = new int[m];
    table.links = new int[m];
    table.cache_status = new int[m];
    table.size = 0;
    table.m = m;

    return table;
}

void insertToHashTable(hashTable_t* table, int id, int link, int cache_status) {
    int i = 0;
    int index = double_hash(id, i, table->m);
    while (table->status[index] == 1) {
        i++;
        index = double_hash(id, i, table->m);
    }

    table->id[index] = id;
    table->links[index] = link;
    table->cache_status[index] = cache_status;
    table->status[index] = 1;
    table->size++;
}

void removeFromHashTable(hashTable_t *table, int id) {
    int i = 0;
    int index = double_hash(id, i, table->m);
    while (table->id[index] != id && i < table->m) {
        i++;
        index = double_hash(id, i, table->m);
    }
    if (table->id[index] == id) {
        table->status[index] = 0;
        table->cache_status[index] = 0;
        table->size--;
    }
}

int main(int argc, char const *argv[]) {
    
    return 0;
}
