#include "public.h"

int ArgPos(char* str, int argc, char** argv){
    int a;

    for(a = 1 ; a < argc ; a++) if (!strcmp(str, argv[a])){
        if(a == argc - 1){
            cout << "Argument missing for " << str << endl;
            exit(1);
        }

        return a;
    }

    return -1;
}

void generateArray(int* array, long size, int seed){
    srand(seed);

    for(auto i = 0 ; i < size ; i++){
        array[i] = rand()%(2^30) + 1;
    }
}

void printArray(int* array, long size){
    for(auto i = 0 ; i < size ; i++){
        cout << array[i] << " ";
    }
}

