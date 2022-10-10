struct node{

    struct node* child[26];
    int end_of_word;
    char meaning[100];
 };
 
 typedef struct node node;
 
node* load();

void unload_rec (node* dict_rem);
