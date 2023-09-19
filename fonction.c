#include <stdio.h>

void changeAge(int *age); 

int main (void) 
{
    int age = 19;       // integer takes number C N
    int *pAge = &age;   // integer pointer takes adress
    age = 20;

    changeAge(&age);
    char lst[] = "Hello, Name!";
    
    //for (int i = 0; i < 13; ++i){ // ++i et i++ sont identique
    //    printf("%c+", lst[i]);  // \0
    //}
    int i = 0;
    while (lst[i] != '\0'){
        printf("%c ", lst[i]);
        i++;
    }

    printf("\n");

    //printf("Age: %i, adress: %p\n", age, pAge);

    return 0;
}

void changeAge(int *age){
    *age = 30;
    printf("%d AGEEE\n", *age);
}