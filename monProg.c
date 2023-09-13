#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


void valeur_abs(int *valeur);

void lecture_de_matrice(void);

void MemSwap(void *Un , void *Deux , int taille);


/* BUT : resoud une equation du second degre    */
/* PARAMETRES : valeur :les coefficients entiers*/
/*             adresse : 2 solutions possibles  */
/* RETOUR : le nombre de solution               */
/* -1 equation degeneree                        */
/* 0 pas de solution                            */
/* 1 un racine placee a l'adresse x             */
/* 2 deux racines placees aux adresses x et y   */
/*
int resoudre(int a, int b, int c, double d){
}

int main(void){
  double r1,r2;
  return 0;
}
*/

int main(void){
    /*int val = -100;
    valeur_abs(&val);
    printf("After fonction: %d\n", val);
    
    float square = sqrt(64.64);
    printf("sqrt: %lf\n", square);
    */
    
    //lecture_de_matrice();

    

    int index = 0, n, *marks; // this marks pointer hold the base address
                // of  the block created
    int ans;
    marks = (int*)malloc(sizeof(int)); // dynamically allocate memory using malloc
    // check if the memory is successfully allocated by
    // malloc or not?
    if (marks == NULL) {
        printf("memory cannot be allocated\n");
    }
    else {
        // memory has successfully allocated
        printf("Memory has been successfully allocated by using malloc\n");
        printf("\nMarks = %pc\n", marks); // print the base or beginning address of allocated memory
        do {
            printf("\nEnter Marks: ");
            scanf("%d", &marks[index]); // Get the marks
            printf("Would you like to add more(1 - Yes or 0 - No): ");
            scanf("%d", &ans);
 
            if (ans == 1) {
                index++;
                marks = (int*)realloc(marks, (index + 1) * sizeof(int)); // Dynamically reallocate
                                   // memory by using realloc
                // check if the memory is successfully
                // allocated by realloc or not?
                if (marks == NULL) {
                    printf("Memory cannot be allocated");
                }
                else {
                    printf("Memory has been successfully reallocated using realloc \n");
                    printf("\nBase address of marks are:%p", marks); ////print the base or
                                ///beginning address of
                                ///allocated memory
                }
            }
        } while (ans == 1);
        // print the marks of the students
        for (int i = 0; i <= index; i++) {
            printf("marks of students group #%d are: %d\n", i, marks[i]);
        }
        free(marks);
    }
    return 0;
}


void valeur_abs(int *valeur){
    if (*valeur < 0)
        *valeur = -*valeur;
    
}

void lecture_de_matrice(void){
    int mat[3][3];
    int val = 0;
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            mat[i][j] = val;
            val++;
        }
    }
    val = 0;
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            printf("mat[%d][%d] = %d ", i, j, val++);
        }
        printf("\n");
    }

}


void MemSwap(void *Un , void *Deux , int taille ) {
    char *U, *D; /* pointeurs utilisées comme tableu*/

    char tmp; /* pour l'échange */
    
    U = (char *) Un;
    D = (char *) Deux;
    for (int i = 0; i < taille; i++){
        tmp = U[i];
        U[i] = D[i];
        D[i]= tmp;
    }
}