#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>

struct node {
    int data;
    struct node* next;
};

typedef struct node node_t;

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

int main(int argc, char const *argv[]) {

    return 0;
}
