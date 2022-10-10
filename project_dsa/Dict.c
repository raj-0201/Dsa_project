#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "header.h"


node* load()
{
    int i;
     node* root=NULL;
    // Initialize trie for dictionary
    if ((root = malloc (sizeof(node))) == NULL)
    {
        printf ("Out of memory. Dictionary could not be loaded.\n");

    }
    for (i = 0; i < 26; i++)
        root -> child[i] = NULL;
    root->end_of_word=0;
	int index;
	node* tmp = root;

    // Dictionary file
    FILE *dict_file=fopen("dictionary.txt","r+");

    // Dictionary file not opened
    if (dict_file == NULL)
       printf("Error opening dictionary");

    // Store words from Dictionary file
    char word_str[20];
    char meaning[200];


   while((fscanf(dict_file,"%s",word_str))!=EOF)
    { fgets(meaning,200,dict_file);
       int word_len = strlen(word_str);

        for(i=0;i<word_len;i++)
       {



            // Handle letters of the alphabet
            // Neglect character case
             if (isalpha (word_str[i]))
                index = (int)tolower (word_str[i]) - 'a';

            // Handle error cases
            if (index > 25 || index < 0)
                continue;

            // Insert character from word read from dictionary into Trie
            if (tmp -> child[index] == NULL)
            {
                // Create and initialize new next nodes for subsequent letter
                if ((tmp -> child[index] = malloc ( sizeof (node))) == NULL)
                {
                    printf ("Out of memory. Dictionary could not be loaded.\n");

                }
                tmp = tmp -> child[index];
                for (int j = 0; j < 26; j++)
                    tmp -> child[j] = NULL;
                    tmp->end_of_word=0;
            }
            else
                tmp = tmp -> child[index];
             // Set word as present in dictionary
            if (i == word_len - 1){
                tmp -> end_of_word =1;
                strcpy(tmp->meaning,meaning);
                }
        } tmp=root;


    // If end of file not reached before loop termination and error indicator is not set


} fclose(dict_file);

return root;
}
void unload_rec (node* dict_rem)
{
    node* tmp = dict_rem;

    // Recursively freeing allocated memory
    for (int i = 0; i < 26; i++)
        if (tmp -> child[i] != NULL)
            unload_rec (tmp -> child[i]);

    free (tmp);
    tmp = NULL;


}
