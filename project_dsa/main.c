#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include "header.h"

int main(){
   node* root=load();
   int ch;
   char word[50];
   char meaning[200];

   printf("******** PERSONAL DICTIONARY **********");


   while(1)
   {
    printf("\n\nEnter your choice.\n1.View Your Dictionary \n2.Add The word\n3.Search for word\n4.Delete word\n0.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 0: printf("Unloading dictionary");
                  unload_rec(root);
                  exit(0);
            break;
        
        
   }
    return 0;
 }
 }
