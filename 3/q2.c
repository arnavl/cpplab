#include <stdio.h>
#include <error.h>
#include <stdlib.h>
 
void main(int argc, char *argv[])
{
    FILE *fp;
 
    if (argc == 1) {
        printf("No filename provided\n");
        exit(0);
    }
 
    fp = fopen(argv[1], "r");
 
    if (fp == NULL) {
        perror("File Open error");
        exit(0);
    }
    printf("File successfully opened\n");
}
