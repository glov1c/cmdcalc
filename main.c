#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "calc.h"

int main(int argc, char** argv) {
    if (strcmp(argv[argc-2], "-k") != 0) {
        printf("invalid enter: no flag or key\n");
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

    int i = 0, resCount = 0;
    /*
    while (argv[i] != "-k"){
        if (isnum(argv[i]) && isValidOperation(argv[i+1]) && isnum(argv[i+2])){

        }
    }
    */
    return 0;
}