#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node {
    int data;            // Data element
    struct Node* next;   // Pointer to the next node
};


int sommesCroissantes(int li, int col, int tab[][col]);

void boo(int untab[],int deuxtab[]);

int LireChaine(char **s);

int main(){

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
        // Access or manipulate current->data
        
        current = current->next; // Move to the next node

        printf("current: %d\n", current -> data);
    }
    free(head);
    free(newNode);
    free(newNode2);
    return 0;  
}

void boo(int untab[],int deuxtab[]){
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