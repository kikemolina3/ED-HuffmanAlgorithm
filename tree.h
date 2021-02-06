#include <stdlib.h>

#ifndef TREE
#define TREE

struct node{
     int freq;
     char info;
     struct node *left;
     struct node *right;
};

typedef struct node Node;
typedef Node *Tree;

Tree NewNode(char x, int y);
Tree MakeAdd(Tree a, Tree b);

#endif


