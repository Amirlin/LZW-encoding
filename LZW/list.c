#include "list.h"

List *L_new(char *key, char *value)
{
	List *new= (List *)malloc(sizeof(List));
	new->value=value;
	new->key=key;
	new->pNext=NULL;
	return new;
}
int L_search(List *pHead, char *key)
{
	if (pHead==NULL)
		return -1;
	List *temp=pHead;
	while(temp!=NULL)
	{
		if (strcmp(temp->key,key)==0 || strcmp(temp->value,key)==0)
			return 0;
		temp=temp->pNext;
	}
		return 1;
}
int L_append(List **ppHead, char *key, char *value)
{
	List *new = L_new(key,value);
	List *temp=*ppHead;
	if (L_search(temp,key)!=0 )
	{
		new->pNext = *ppHead;
		 *ppHead = new;
    		return 1;
	}
	return 0;//if there is key in list
} //true/false
void L_print(List *pHead)
{
	List *temp=pHead;
    if (temp == NULL)
    {
        puts("");
        return;
    }

    while (temp != NULL)
    {
        printf("[key:%s,value:%s] => ",
        	temp->key,temp->value);
        temp = temp->pNext;
    }
    puts("");
}
// int main(int argc, char const *argv[])
// {
// 	List *list=L_new("hello","world");
// 	L_append(&(list), "i", "hate");
// 	L_append(&list, "every", "thatis");
// 	L_append(&list, "everything", "that");
// 	L_append(&list, "every", "thatis");


// 	L_print(list);

// 	return 0;
// }




