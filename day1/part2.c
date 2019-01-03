#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <strings.h>
//#define LINE_SIZE 200

typedef struct node {
    int val;
    struct node* next;
}
node_t;

void push(node_t* head, int val) {
    node_t* iterator = head;
    while(iterator->next != NULL) {
        iterator = iterator->next;
    }

    iterator->next = malloc(sizeof(node_t));
    iterator->next->val = val;
    iterator->next->next = NULL;
    //printf("pushed val: %d\n", val);
}

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

bool match(node_t* head, int freq) {
    node_t* iter = head;
    while (iter->next != NULL) {
        //printf("checking val: %d VS freq: %d\n", iter->val, freq);
        if (iter->val == freq) {
            return true;
        }
        iter = iter->next;
    }
    return false;
}

int main() {

    FILE* fp;

    node_t* head = NULL;
    head = malloc(sizeof(node_t));
    head->next = NULL;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File not found\n");
        exit(1);
    }

    const size_t line_size = 100;
    char* line = malloc(line_size);
    
    int freq = 0;
    head->val = freq;

    
    //while (fgets(line, line_size, fp) != NULL) {
    while (!feof(fp)) {
        //printf(line);
        fgets(line, line_size, fp);
        if (feof(fp)) {
            rewind(fp);
        }
        freq += atoi(line);
        push(head, freq);
        if (match(head, freq)) {
            printf("MATCHED!! at %d\n", freq);
            getchar();
        }
        //printf("Head value: %d\n", head->val);
        
    }
    
    //print_list(head);

    
    printf("Final Frequency: %d\n", freq);

    getchar();
    return 0;
}