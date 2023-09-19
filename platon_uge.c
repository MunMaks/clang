#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

double polynome(int a, int b, int c);

void ascii_triangle(int n);

int max_of_three(int a, int b, int c);

int min_of_three(int a, int b, int c);

int puissance (int n, int p);

int diviseurs(int number);

void maison(int n);

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
    int var = 6;
    int div = diviseurs(var);
    printf("DIV: %d\n", div);
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
    int max1, max2;
    max1 = (a >= b) ? a : b;
    max2 = (c >= b) ? c : b;
    
    return (a >= c) ? max1 : max2;
}

int min_of_three(int a, int b, int c){
    int minimum1, minimum2;
    minimum1 = (a <= b) ? a : b;
    minimum2 = (c <= b) ? c : b;
    
    return (a <= c) ? minimum1 : minimum2;
}

int puissance (int n, int p){
    if (p < 0) {return 0;}
    if (p == 0) {return 1;}
    
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

void maison(int n){
    
}