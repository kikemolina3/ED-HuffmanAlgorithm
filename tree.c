#include "tree.h"
#include <stdlib.h>

Tree NewNode(char x, int y)
{
    Tree t=malloc(sizeof(Tree));
    t->info=x;
    t->freq=y;
    t->left=NULL;
    t->right=NULL;

    return t;
}

Tree MakeAdd(Tree a, Tree b)
{
    Tree t=malloc(sizeof(Tree));
    t->freq= a->freq + b->freq;
    t->info='\0';
    t->left=a;
    t->right=b;

    return t;
}


