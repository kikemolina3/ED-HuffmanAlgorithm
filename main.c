#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

typedef struct
{
    char info;
    int freq;
}Symbol;

/* GLOBAL VARIABLES */
    Symbol sym[30];
    int n_sym=0;

    Tree tr[30];

    char table[100];

    char bin[100];


int searchSymbol(char a)
{
    int i=0;
    while(i<n_sym)
    {
        if(a==sym[i].info)
        {
            return i;
        }
        i++;
    }
    return -1;
}

void loadData(char m[])
{
    int i=0, index;
    while(m[i]!='\0')
    {
        index=searchSymbol(m[i]);
        if(index!=-1)
        {
            (sym[index].freq)+=1;
        }
        else
        {
            sym[n_sym].freq=1;
            sym[n_sym].info=m[i];
            n_sym++;
        }
        i++;
    }
}

void generateNodes()
{
    int i;
    for(i=0; i<n_sym; i++)
    {
        tr[i]=NewNode(sym[i].info, sym[i].freq);
    }
}

void printData()
{
    int i;
    for(i=0; i<n_sym; i++)
    {
        printf("Symbol: %c\nFrequency: %i\n\n", sym[i].info, sym[i].freq);
    }
}


void quickSort(Tree t[], int ini, int fin)
{
    int i, j, pivot;
    Tree aux=malloc(sizeof(Tree));

    if(ini<fin){
      pivot=ini;
      i=ini;
      j=fin;

      while(i<j){
         while(t[i]->freq <= t[pivot]->freq && i<fin)
            i++;
         while(t[j]->freq > t[pivot]->freq)
            j--;
         if(i<j){
            aux=t[i];
            t[i]=t[j];
            t[j]=aux;
         }
      }

      aux=t[pivot];
      t[pivot]=t[j];
      t[j]=aux;

      quickSort(t, ini,j-1);
      quickSort(t, j+1,fin);
}
}
void quicksort_sym(int ini,int fin){
   int i, j, pivot, aux_freq;
   char aux_info;

   if(ini<fin){
      pivot=ini;
      i=ini;
      j=fin;

      while(i<j){
         while(sym[i].freq<=sym[pivot].freq && i<fin)
            i++;
         while(sym[j].freq>sym[pivot].freq)
            j--;
         if(i<j){
            aux_freq=sym[i].freq;
            sym[i].freq=sym[j].freq;
            sym[j].freq=aux_freq;
            aux_info=sym[i].info;
            sym[i].info=sym[j].info;
            sym[j].info=aux_info;
         }
      }

      aux_freq=sym[pivot].freq;
      sym[pivot].freq=sym[j].freq;
      sym[j].freq=aux_freq;
      aux_info=sym[pivot].info;
      sym[pivot].info=sym[j].info;
      sym[j].info=aux_info;

      quicksort_sym(ini,j-1);
      quicksort_sym(j+1,fin);
   }
}

void decodeBin(char a[], Tree t)
{
    int i=0;
    Tree next;
    next=t;
    while(a[i]!='\0'/* || end*/)
    {
        if(a[i]=='0')
        {
            next=next->left;
        }
        if(a[i]=='1')
        {
            next=next->right;
        }
        if(next->left==NULL && next->right==NULL)
        {

            putchar(next->info);
            next=t;
        }
        i++;
    }
}

Tree makeTree()
{
    int i=0;
    Tree prov;
    while(i<n_sym-1)
    {
        prov=MakeAdd(tr[i], tr[i+1]);
        i++;
        tr[i]=prov;
        quickSort(tr, i,n_sym-1);
    }
    return prov;
}

void equivalencias(Tree t)
{

    if(t->info!='\0')
    {
        printf("%s\t - %c\n", table, t->info);
    }
    if(t->left)
    {
        strcat(table,"0");
        equivalencias(t->left);
    }
    if(t->right)
    {
        strcat(table,"1");
        equivalencias(t->right);
    }
    table[strlen(table)-1]='\0';

}


int main()
{

    table[0]='\0';
    /* SCANNING & SORTING MESSAGE */
    char message[100];
    printf("Enter a message: ");
    scanf("%s",message);
    loadData(message);
    quicksort_sym(0,n_sym-1);
    generateNodes();
    printData();
    Tree t=makeTree();
  equivalencias(t);

    /* MAKING TREE */
    //Cua tail_trees=Crear_cua(10);
    //int r_sym=0;                            /* Variable which mission is travel the frequency's list */

 /*   Tree t1=NewNode(sym[r_sym].info, sym[r_sym].freq);
    r_sym++;
    Tree t2=NewNode(sym[r_sym].info, sym[r_sym].freq);
    r_sym++;
    Tree t3=MakeAdd(t1,t2);*/

 /*   Tree t1,t2,t3,t4,t5;
    t1=NewNode('w',1);
    t2=NewNode('8',1);
    t3=MakeAdd(t2,t1);
    t4=NewNode('a',1);
    t5=MakeAdd(t4,t3);*/

    scanf("%s",bin);
    //printf("%s",bin);
    decodeBin(bin,t);

//   printf("%c %i",t->left->info, t->left->info);
    getchar();
    return 0;
}
