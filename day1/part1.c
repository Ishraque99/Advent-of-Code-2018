#include <stdio.h>
#include <stdlib.h>
//#define LINE_SIZE 200
int main() {

    FILE* fp;

    
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File not found");
        exit(1);
    }

    const size_t line_size = 100;
    char* line = malloc(line_size);
    
    int freq = 0;

    while (fgets(line, line_size, fp) != NULL) {
        printf(line);
        freq += atoi(line);
    }
    printf("\n %d", freq);
    getchar();
    return 0;
}