#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#include "calc.h"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RU");
    
    if (argc < 5){
        printf("invalid arguments: not enough\n");
    }
    if (strcmp(argv[argc-2], "-k") != 0) {
        printf("invalid arguments: no flag or key\n");
        return 1;
    }

    /*
    for (int i = 0; i < argc; i++) {  
        printf("%s \n", argv[i]);  
    }
    */
    int resCount = (argc-2) / 3;

    int* res = (int*)calloc(resCount, sizeof(int));
    if (res == NULL) {
        printf("memory error\n");
        return 1;
    }
    
    for(int i = 1; i < argc - 2; i+=3){
        if (isNum(argv[i]) && isValidOperation(argv[i+1]) && isNum(argv[i+2])){
            res[i/3] = Calculate(atoi(argv[i]), argv[i+1], atoi(argv[i+2]));
        }
        else{
            printf("invalid arguments: not an expression\n");
            return 1;
        }
    }
    
    for(int i = 1; i < resCount+1; i++){
        printf("Ответ %d: %d\n", i, res[i-1]);
    }
    if (isNum(argv[argc-1])){
        printf("Результирующая строка: ");
        for(int i = 0; i < resCount; i++){
            printf("%c", res[i]-atoi(argv[argc-1]));
        }
        printf("\n");
    }
    else{
        printf("invalid arguments: flag is not a number\n");
        return 1;
    }
    
    free(res);
    return 0;
}