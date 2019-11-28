#ifndef DICT
#define DICT

#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct Dict
{
    List **table;
    int capacity;
    int size;
}Dict;

Dict *D_new(int capacity);
int D_put(Dict *dict, char *key, char *value); //true/false
int Hash(Dict *dict, char *key);
int D_search(Dict *dict, char *key);
Dict *D_duplicate(Dict *dict);
void D_print(Dict * dict);


#endif