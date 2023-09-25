#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define SIZE 21
#define MAX 20
#define N 20

typedef struct People{
    char first_name[63];
    char last_name[64];
    int age;
}People;

typedef struct Vector3d{
    int x;
    int y;
    int z;
}Vector3d;

typedef enum {
    lundi,
    mardi,
    mercredi,
    jeudi,
    vendredi,
    samedi,
    dimanche
} Jour;


double polynome(int a, int b, int c);

void ascii_triangle(int n);

int max_of_three(int a, int b, int c);

int min_of_three(int a, int b, int c);

int puissance (int n, int p);

int diviseurs(int number);

void maison(int n);

void remplir(char tab[MAX][MAX], int li, int col);

int max_tab(int tab[], int size);

int are_equal_tab(int tab1[], int tab2[], int size);

float mean_positive(int* array, int size);

void miroir(int arr1[], int arr2[], int taille);

void shiftLR(int a[], int b[], int size);

int nb_inversions(int t[], int taille);

int est_partie_triee(int* tab);

void print_diff_sym(int* arr1, int size1, int* arr2, int size2);

int length(char* word);

int scalar_product3d(Vector3d u, Vector3d v);

int pgcd(int a, int b);

void premiers_entre_eux(int t[][N]);

void remplir(char tab[MAX][MAX], int li, int col);

int est_palindrome(char s[]);

int main()
{
    int x = 3;
    
    //ascii_triangle(3);
    int a = -924, b = 992, c = 993;
    int maxim = max_of_three(a, b, c);
    int minim = min_of_three(a, b, c);
    //printf("%d\n", maxim);
    //printf("%d\n", minim);
    
    int num_puissance = puissance(-8, 4);
    //printf("puissance: %d\n", num_puissance);
    //int var = 6;
    //int div = diviseurs(var);
    //printf("DIV: %d\n", div);
    //int array[] = {20, -98, 15, -59, 86, -21, -95, 80, -71, 43, 75, -7, -34, -83};
    //int length = *(&array + 1) - array;
    //float mediana = mean_positive(array, length);
    //printf("meidana: %f\n", mediana);

    /*int arr1[] = {1, 2, 3, 4};
    //int arr2[] = {1, 2, 3, 4};
    int length = *(&arr1 + 1) - arr1;*/

    //miroir(arr1, arr2, length);
    /*
    shiftLR(arr1, arr2, length);
    for (int i = 0; i < length; ++i){
        printf("arr1[%d] = %d: arr2[%d] = %d\n", i, arr1[i], i, arr2[i]);
    }
    //int example[] = {3, 1, 2};
    //int nb_inversions_ex = nb_inversions(example, 3);
    printf("nb : %d\n", nb_inversions_ex);
    */
    //int tab_ex[] = {1, 2, 3, 4, 5, 6, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 10, 10};  // from 6 to 17 (included) they become smaller.
    //printf("result: %d\n", est_partie_triee(tab_ex));

    int size1 = 8, size2 = 6;

    int arr1[] = {1, 3, 5, 7, 9, 11, 13, 14};
    int arr2[] = {0, 1, 5, 6, 8, 11};
    print_diff_sym(arr1, size1, arr2, size2);

    return 0;
}

double polynome(int a, int b, int c){
    // (a - 3)(b^2 + 2)(c - 8)
    double res = (a - 3) * ((b*b) + 2) * (c - 8);
    return res;
}

void ascii_triangle(int n){
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < i; ++j){
            printf("%c", 052);
        }
        printf("\n");
    }
}

int max_of_three(int a, int b, int c){
    //  Ternary operator data_type variable = (condition) ? (return first) : (return second);
    //  That means if our condition return true so we take a value from return first. If your condition is false, we return second variable immediately.
    int maximum1, maximum2;
    maximum1 = (a >= b) ? (a) : (b);
    maximum2 = (c >= b) ? (c) : (b);
    
    return (a >= c) ? (maximum1) : (maximum2);
}

int min_of_three(int a, int b, int c){
    //  Ternary operator data_type variable = (condition) ? (return first) : (return second);
    //  That means if our condition return true so we take a value from return first. If your condition is false, we return second variable immediately.
    int minimum1, minimum2;
    minimum1 = (a <= b) ? (a) : (b);
    minimum2 = (c <= b) ? (c) : (b);
    
    return (a <= c) ? (minimum1) : (minimum2);
}

int puissance (int n, int p){
    if (p < 0) return 0;
    if (p == 0) return 1;
    
    int res = 1;
    for (int i = 0; i < p; ++i){
        res = res * n;
    }
    return res;
}

int diviseurs(int number) {
    if (number <= 0) return -1;
    int count = 0;
    for (int i = 1; i <= number; ++i){
        if ((number % i) == 0){
            printf("%d\n", i);
            ++count;
        }
    }
    //printf("%d a %d diviseurs\n", number, count);
    return count;
}

int max_tab(int tab[], int size){
    if (size <= 0) return -1;

    int maximum = 0;
    for (int i = 0; i < size; ++i){
        if (tab[i] > maximum){
            maximum = tab[i];
        }
    }
    return maximum; 
} 

int are_equal_tab(int tab1[], int tab2[], int size){
    for (int i = 0; i < size; ++i){
        if (tab1[i] != tab2[i]){
            return 0;
        }
    }
    return 1;
}

float mean_positive(int* array, int size){
    //  Ternary operator data_type variable = (condition) ? (return first) : (return second);
    //  That means if our condition return true so we take a value from return first. If your condition is false, we return second variable immediately.
    if (size <= 0) return 0.0;

    float count = 0.0, mean = 0.0;
    for (int i = 0; i < size; ++i) {
        if (array[i] >= 0) {
            mean += array[i];
            count++;
        }
    }
    //printf("mean: %f, count : %f\n", mean, count);
    // if mean and count aren't zero, so we return "mean devide by count" otherwise we return "0.0" as result.
    return (mean != 0 && count != 0) ? (mean / count) : (0.0);  
}

void miroir(int arr1[], int arr2[], int taille){
    int idx = 0;
    for (int i = taille - 1; i >= 0; --i){
        arr2[idx] = arr1[i]; 
        //printf("arr1[%d] = arr2[%d]\n", arr1[idx], arr2[idx]);
        idx++;
    }
}

void shiftLR(int a[], int b[], int size){
    // a = {1, 2, 3, 4}, b = {1, 2, 3, 4}   // right
    // a = {4, 1, 2, 3}, b = {2, 3, 4, 1}   // left
    if (size <= 0) {return;}

    int last_val_a = a[size-1];
    int first_val_b = b[0];
    for (int i = size-1; i > 0; --i){       // We start from last element till first
        a[i] = a[i - 1];
    }    

    for (int i = 0; i < size - 1; ++i)  {   // We start from first element till SIZE - 1
        b[i] = b[i + 1];    
    }
    a[0] = last_val_a;          // We change last val in a that we saved before.
    b[size-1] = first_val_b;    // We change first val in b that we saved before.
}

int nb_inversions(int t[], int taille){
    // {3, 1, 2} = (0, 1), (0, 2) = return 2
    // {1, 3, 2, 0} = (0, 3), (1, 2), (1, 3), (2, 3) = return 4
    int count = 0;
    for (int i = 0; i < taille-1; ++i) {
        for (int j = i + 1; j < taille; ++j) {
            if (t[i] > t[j]){
                //printf("t[i]-%d , t[j]-%d\n", t[i], t[j]);
                ++count;
            }
        }
    }
    return count;
}

int est_partie_triee(int* tab){
    for (int i = 6; i < 17; ++i){
        if (tab[i] < tab[i+1]) {
            return 0;
        }
    }   
    return 1;
}

void print_diff_sym(int* arr1, int size1, int* arr2, int size2){
    /*
    int A[] = {1, 3, 5, 7, 9, 11, 13, 14};
    int B[] = {0, 1, 5, 6, 8, 11, 15, 16};
    A diff B : 0, 3, 6, 7, 8, 9, 13, 14, 15, 16
    */
    int taille_max = (size1 >= size2) ? size1 : size2;

    int difference[size1 + size2];
    int i1 = 0;
    int i2 = 0;
    int diff_count = 0;

    for (int i = 0; i < size1 + size2; ++i){
        if (i1 == size1){
            if (i2 < size2){
                for (int idx = 0; idx <= (size2 - i2); ++idx){
                    difference[diff_count] = arr2[i2];
                    ++i2;
                    ++diff_count;
                }
            }
            break;
        }

        if (i2 == size2){
            if (i1 < size1){
                for (int idx = 0; idx <= (size1 - i1); ++idx){
                    difference[diff_count] = arr1[i1];
                    ++i1;
                    ++diff_count;
                }
            }
            break;
        }

        if (arr1[i1] == arr2[i2]) { //  && (i1 != size1 || i2 != size2) 
            ++i1;
            ++i2;
            continue;
        }

        else if (arr1[i1] < arr2[i2]){
            difference[diff_count] = arr1[i1];
            ++i1;
            ++diff_count;
        }
        else if (arr1[i1] > arr2[i2]){
            difference[diff_count] = arr2[i2];
            ++i2;
            ++diff_count;
        }

    }
    for (int i = 0; i < diff_count; ++i){
        printf("%d ", difference[i]);
    }
}


/*

int main(int argc, char* argv[]){
    int X = 0, Y = 0, Z = 0;
    //int total = 0;
    while(--argc > 0){
        //printf("%s ", argv[argc]);
        char* word = argv[argc];
        int len_word = length(word);

        for (int i = 0; i < len_word; ++i){
            if (word[i] >= 'A' && word[i] <= 'A' + 26) ++X;

            else if(word[i] >= 'a' && word[i] <= 'a' + 26) ++Y;
            
            else ++Z;
            //++total;
        }
    }

    printf("Nombre de majuscules : %d\n", X);
    printf("Nombre de miniscules : %d\n", Y);
    printf("Nombre d'autres caractères : %d\n", Z);
    return 0;
}

int length(char* word){
    int i = 0;
    while (word[i] != '\0') ++i;
    return i;
}

*/
/*int string_length(char* s){
    int i = 0;
    while (s[i] != '\0') ++i;
    return i;
}*/

int length(char* word){
    int i = 0;
    while (word[i] != '\0') ++i;
    return i;
}

void to_upper_in_string(char* s) {
    if (s == NULL) {return;}
        // segmentation faults 
    int len = length(s);
    for (int i = 0; i < len; i++) {
        // On change les lettres miniscules en majuscule s'il est necessaire.
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
    }
}

int scalar_product3d(Vector3d u, Vector3d v) {
    int result = 0;
    result = (u.x) * (v.x) + (u.y) * (v.y) + (u.z) * (v.z);
    return result;
}

int pgcd(int a, int b){
    int res;
      
    for(int i = 1; i <= a && i <= b; ++i)
    {
        if((a % i) == 0 && (b % i == 0)){
            res = i;
        }
    }
    return res;
}

void premiers_entre_eux(int t[][N]){
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if(i == 0 && j == 0) {
                t[i][j] = -1;
            }
            else if ( pgcd(i, j) == 1 ) {
                t[i][j] = 1;
            }
            else t[i][j] = 0;
        }
    }
}

void remplir(char tab[MAX][MAX], int li, int col){
    int letter = 0;
    for (int i = 0; i < li; ++i){
        for (int j = 0; j < col; ++j){
            tab[i][j] = 'a' + letter;  //ASCII 'a'+1 = 'b'
            //printf("%c ",  tab[i][j]);
            ++letter;
            if (letter == 26) letter = 0;
        }
        //printf("\n");  // 2 tentatives ratees a cause de deux printf()...
    }
}
/*
void fill_tab(int LI, int COL, int N, int tab[][COL][N]);

void fill_tab(int LI, int COL, int N, int tab[][COL][N]){
    int count = 1;
    for (int i = 0; i < LI; ++i){

        for (int j = 0; j < COL; ++j){
          
            for (int k = 0; k < N; ++k){
                tab[i][j][k] = count;
                ++count;
            }
        }
    }
}*/
/*
int index_max_3d(int t[M][M][M], int s1, int s2, int s3, int* m1, int* m2, int* m3);
int index_max_3d(int t[M][M][M], int s1, int s2, int s3, int* m1, int* m2, int* m3){
    int valeur_max = t[0][0][0];
    for (int i = 0; i < s1; ++i){
        for (int j = 0; j < s2; ++j){
            for (int k = 0; k < s3; ++k){
                if (valeur_max < t[i][j][k]){
                    valeur_max = t[i][j][k];

                    *m1 = i; *m2 = j; *m3 = k;
                }

            }
        }
    }
    return valeur_max;
}*/

int est_palindrome(char s[]){
    int len = string_length(s);
    int half = len / 2;

    for (int i = 0; i < half; ++i){
        if (s[i] != s[len-i-1]) { return 0; }
    }
    return 1;
}