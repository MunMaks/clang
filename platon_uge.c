#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define SIZE 21

double polynome(int a, int b, int c);

void ascii_triangle(int n);

int max_of_three(int a, int b, int c);

int min_of_three(int a, int b, int c);

int puissance (int n, int p);

int diviseurs(int number);

void maison(int n);

int max_tab(int tab[], int size);

int are_equal_tab(int tab1[], int tab2[], int size);

float mean_positive(int* array, int size);

void miroir(int arr1[], int arr2[], int taille);

void shiftLR(int a[], int b[], int size);

int nb_inversions(int t[], int taille);

int est_partie_triee(int* tab);

void print_diff_sym(int* arr1, int size1, int* arr2, int size2);

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

    int size1 = 8, size2 = 8;

    int arr1[] = {1, 3, 5, 7, 9, 11, 13, 14};
    int arr2[] = {0, 1, 5, 6, 8, 11, 15, 16};
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
    A : 1, 3, 5, 7, 9, 11, 13
    B : 0, 1, 5, 6, 8, 11
    A diff B : 0, 3, 6, 7, 8, 9, 13
    */
    int taille_max = (size1 >= size2) ? size1 : size2;

    int difference[size1 + size2];
    int i1 = 0;
    int i2 = 0;
    //int remain = 0;
    int diff_count = 0;

    for (int i = 0; i < size1 + size2; ++i){
        if (i1 == size1){
            if (size1 < size2){
                for (int idx = 0; idx <= (size2 - size1); ++idx){
                    difference[diff_count] = arr2[i2];
                    ++i2;
                }
            }
            break;
        }

        if (i2 == size2){
            if (size1 > size2){
                for (int idx = 0; idx <= (size1 - size2); ++idx){
                    difference[diff_count] = arr1[i1];
                    ++i1;
                }
            }
            break;
        }

        if ((arr1[i1] == arr2[i2])) { //  && (i1 != size1 || i2 != size2) 
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
        printf("A diffe B: %d\n", difference[i]);
    }
}

/*void maison(int n){
    
}*/