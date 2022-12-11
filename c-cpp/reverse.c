#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node; // small name struct node to call it

int main(int argc, char *argv[]) // argc is count of  all args v[]; argv let write args after ./helo by run, where helo is args[0] 
{
    node *list = NULL;
    
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]); // atoi converts int to *char (string)

          node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return 1;
        }

        n->number = number; // (*n).number = number so it's request one of element of object based on struct
        n->next = NULL;

        n->next = list;
        list = n;  
    }

    node *ptr = list; 
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    ptr = list;
    while (ptr != NULL)
    {   
        node *next = ptr->next;
        free(ptr);
        ptr = next; 
    }
}