#include "dict.h"

Dict *D_new(int capacity)
{
	 Dict *dict=(Dict *) malloc(sizeof(Dict));

    dict->size = 0;
    dict->capacity=capacity;
    dict->table =(List **)malloc(capacity * sizeof(List *));
    int i;
    for (int i = 0; i < capacity; i++){
        dict->table[i] = NULL;
    }
    return dict;
}
int Hash(Dict *dict, char *key)
{
    if (dict == NULL || dict->capacity <= 0)
        return -1;
    int index;
    for (index = 0; *key != '\0'; key++)
    {
        index = (index * 256 + (int)(*key)) % dict->capacity;
    }
    return index;
}
int D_put(Dict *dict, char *key, char *value)
{
    if (dict == NULL || dict->capacity <= 0)
        return -1;

    int index = Hash(dict,key);
   return L_append(&(dict->table[index]),key,value);
} //true/false

//search if an element key is already exists in dict
int D_search(Dict *dict, char *key)
{
    int index=Hash(dict,key);
    if (L_search(dict->table[index],key)==0)
       return 0;
   return 1;
}
Dict *D_duplicate(Dict *dict)
{
    Dict *newDict=D_new(dict->capacity);
    for (int i = 0; i < dict->capacity; ++i)
    {
        newDict->table[i]=dict->table[i];   
    }
    return newDict;
}


void D_print(Dict *dict)
{
     int i;
    for (i = 0; i < dict->capacity; i++)
    {
        printf("[%d]:", i);
        L_print(dict->table[i]);
    }
}
// int main(int argc, char const *argv[])
// {
//     Dict *dict =D_new(20);
//     printf("created\n");
//     D_put(dict,"hellok","worldv");
//     D_put(dict,"hlk","nov");
//     D_put(dict,"helk","yeav");
//     D_put(dict,"hlk","nov");

//     printf("added\n");

//     D_print(dict);

//     return 0;
// }



