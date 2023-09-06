#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
    int data;            // Data element
    struct Node* next;   // Pointer to the next node
}Cellule, *Liste;


int sommesCroissantes(int li, int col, int tab[][col]);

void boo(int untab[],int deuxtab[]);

int LireChaine(char **s);

int countLinked(struct Node* lst);

void push(struct Node** head_ref, int new_data); // push in new head in Linked List

void insertAfter(struct Node* prev_node, int new_data); // insert in Linked List 

void append(struct Node** head_ref, int new_data); // append at the end of Linked List

int main(void){

    //int mat[5][5] = {{1, 2, 3, 4, 5},{2, 2, 3, 4, 5},{3, 2, 3, 4, 5}, {4, 2, 3, 4, 5}, {5, 2, 3, 4, 5}};
    //int res;
    //res = sommesCroissantes(5, 5, mat);
    //printf("res: %d\n", res);
    //int n;
    //char * Chaine;
    //n = LireChaine(&Chaine);
    //printf("%d\n", n);

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));

    head -> data = 41;              // Assign data
    head -> next = newNode;

    newNode -> data = 42;           // Assign data
    newNode -> next = newNode2;     // Initialize the next pointer

    newNode2 -> data = 43;
    newNode2 -> next = NULL;

    struct Node* current = head;
    while (current != NULL) {
        current = current->next;} // Move to the next node
    free(head);
    free(newNode);
    free(newNode2);

    int count = countLinked(head);
    printf("Count: %d\n", count);
    return 0;  
}

void boo(int untab[],int deuxtab[]){
    // le test de QCM;
    int tmp;
    tmp = *untab;
    *untab = *deuxtab;
    *deuxtab = tmp;
}

int sommesCroissantes(int li, int col, int tab[][col]){
    int i, j, sommeCourante = 0, sommePrecedente = 0;
    for(i = 0; i < li; i++){
        sommePrecedente = sommeCourante; 

        for(j = 0; j < col; j++)
            sommeCourante += tab[i][j];
            printf("sommeCourante: %i\n", sommeCourante);
        if(i > 0 && sommeCourante < sommePrecedente)
            return 0;

        sommeCourante = 0;
        printf("somme precesente: %i\n", sommePrecedente);
    }
    return 1;
}

int LireChaine(char **s){

    char seen[1025];
    int nbchar;
    scanf("%1024s", seen);
    nbchar = strlen(seen);

    *s = (char *) malloc (nbchar+1);
    
    if (*s == NULL){
        strcpy(*s, seen);
    }
    else nbchar -= 1;
    free(*s);
    return nbchar;
}

int countLinked(struct Node* lst){
    struct Node* index = lst;
    int count = 1;
    while (index != NULL){
        count++;
        index = index -> next;
    }
    return count;
}

void push(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    /* 2. put in the data  */
    new_node -> data = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}


void insertAfter(struct Node* prev_node, int new_data) //insert in Linked List
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }
 
    /* 2. allocate new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    /* 3. put in the data */
    new_node->data = new_data;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}


void append(struct Node** head_ref, int new_data)  // append at the end of the Linked List
{
    /* 1. allocate node */
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    struct Node* last = *head_ref; /* used in step 5*/
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. This new node is going to be the last node, so
    make next of it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty, then make the new
    * node as head */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}
