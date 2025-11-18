#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "calc.h"


int isNum(char* s){
    for(int i = 0; i < strlen(s); i++){
        if (!isdigit(s[i])){
            if (i == 0 && s[0] != '-'){
                return 0;
            }
        }
    }
    return 1;
}

int isValidOperation(char *s){
    if (strcmp(s, "+") == 0){
        return 1;
    }
    if (strcmp(s, "*") == 0){
        return 1;
    }
    if (strcmp(s, "-") == 0){
        return 1;
    }
    if (strcmp(s, "%") == 0){
        return 1;
    }
    return 0;
}

int Calculate(int a, char *s, int b){
    if (strcmp(s, "+") == 0){
        return a + b;
    }
    if (strcmp(s, "-") == 0){
        return a - b;
    }
    if (strcmp(s, "*") == 0){
        return a * b;
    }
    if (strcmp(s, "%") == 0){
        return a % b;
    }
    return 0;
}