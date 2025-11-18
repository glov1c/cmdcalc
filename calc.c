#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc.h"

char* demux(int *arr, int key){

}

int isnum(char* s){
    for(int i = 0; i < strlen(s); i++){
        if (!isdigit(s[i])){
            return 0;
        }
    }
    return 1;
}

int isValidOperation(char *s){
    char operations[] = "+-*%";
    for(int i = 0; i < strlen(operations); i++){
        if (strcmp(s, operations[i]) == 0){
            return 1;
        }
    }
    return 0;
}