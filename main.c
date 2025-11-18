#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#include "calc.h"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RU");
    
    if (argc < 4){
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

    int* res = (int*)calloc(argc / 3, sizeof(int));
    if (res == NULL) {
        printf("memory error\n");
        return 1;
    }

    int i = 1, resCount = 0;
    
    while (i < argc - 2){
        if (i + 2 < argc - 2 && isNum(argv[i]) && isValidOperation(argv[i+1]) && isNum(argv[i+2])){
            res[resCount] = Calculate(atoi(argv[i]), argv[i+1], atoi(argv[i+2]));
            i += 3;
            resCount += 1;
        }
        else if (resCount > 0 && i + 1 < argc - 2 && isNum(argv[i-1]) && isValidOperation(argv[i]) && isNum(argv[i+1])){
            res[resCount-1] = Calculate(res[resCount-1], argv[i], atoi(argv[i+1]));
            i += 2;
        }
        else if (resCount == 0 || i != argc - 2){
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