#include <stdio.h>
#include <string.h>


void ascii_character(void);

void guess_secret_num(void);

void lecture_carac(void);

void menu_colors(void);

void addTen(int *n);

void changeFonction(int *a, int *b);

int rock_papper_scissors(void);

int LireInf2(void);

int arbitre(int *firstplayer, int *secondplayer);

void ten_times_rock_papper_scissors(void);

int main(void){
    int n = 59;
    int m = 111;    

    

    //ascii_character();
    //guess_secret_num();
    //lecture_carac();
    //menu_colors();
    
    /*printf("n before %d\n", n);
    addTen(&n);
    printf("n after %d\n", n);*/

    /*printf("n, m before: %d, %d\n", n, m);
    changeFonction(&n, &m);
    printf("n, m after: %d, %d\n", n, m);*/

    //ten_times_rock_papper_scissors();
    
    return 0;
}

void ascii_character(void){
    for (int i = 48; i < 127; ++i){

        if (i >= 48 && i <= 57)
            printf("Ascii caractere %c code %d\n", i, i);
        if (i >= 65 && i <= 90)
            printf("Ascii caractere %c code %d\n", i, i);
    }
}
void guess_secret_num(void){
    int secret_num = 269;
    int guess;
    int count = 1;

    while (count != 10){
        printf("Enter a variable between 0 and 1000: \n");
        scanf("%d", &guess);
        if (guess == secret_num){
            printf("YOU WIN!\n");
            printf("You did %d trys\n", count);
            break;
        } 
        else if (guess < secret_num) {
            printf("Greater than your guess\n");
            count++;
            }
        else {
            printf("Less than your guess\n");
            count++;
            }
    }
    if (count == 10) printf("Sorry You have no more trys, try again\n");
}

void lecture_carac(void){
    char char1;
    char char2;
    printf("Entrez le premier caractère : ");
    scanf(" %c", &char1);  // Ajout d'un espace pour ignorer les séparateurs

    printf("Entrez le deuxième caractère : ");
    scanf(" %c", &char2);  // Ajout d'un espace pour ignorer les séparateurs

    printf("* %c *\n", char1);
    printf("* %c *\n", char2);
}

void menu_colors(void){
    char ch[6];
    char arr[11][10] = {"Green", "Red", "Blue", "Yellow", "Black", "White", "Brown", "Orange", "Brown", "Grey", "Pink"};
    int len = *(&arr + 1) - arr;
    printf("Choose a color from this list: \n");
    for (int i = 0; i < len; ++i){
        printf("%s  ", arr[i]);
    }
    printf("\nEnter a color's name please: ");
    scanf("%s", ch);    

    for(int i = 0; i < len; ++i){
        if (strcmp(ch, arr[i]) == 0){
            printf("You choosed: %s\n", arr[i]);
            break;
        }
        else {
            continue;
        }
        if (i == len - 1) {
            printf("We have not this color: %s\n", ch);
            break;
        }

    }
}

void addTen(int *n){
    *n += 10;
}

void changeFonction(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int rock_papper_scissors(void){
    // caillou par 0, papier par 1 et ciseaux par 2.
    int firstplayer;
    int secondplayer;
    firstplayer = LireInf2();
    secondplayer = LireInf2();
    int game = arbitre(&firstplayer, &secondplayer);
    return game;
}

int LireInf2(void){
    int user_input;
    do {
        printf("Choose between 0 - Rock, 1 - Papper, 2 - Scissors: ");
        if (scanf("%d", &user_input) == 1 && user_input >= 0 && user_input <= 2) {
            return user_input;
        }
        printf("Invalid input. Please try again.\n");

        while (getchar() != '\n'); // Clear input buffer
    } while(1);
}

int arbitre(int *firstplayer, int *secondplayer){
    if (*firstplayer == *secondplayer){
        printf("It's a DRAW! \n");
        return 0;
    }
    else if (*firstplayer == (*secondplayer + 1) % 3){
        printf("Player 1 WON! \n");
        return 1;
    }
    else {
        printf("Player 2 WON!\n");
        return 2;
    }
}


void ten_times_rock_papper_scissors(void){
    int player1, player2;
    for (int i = 0; i < 10; ++i) {
        int play = rock_papper_scissors();

        if (play == 1) 
            player1 += 1;
        else if (play == 2) 
            player2 += 1;
        else 
            continue;
    }
    printf("Score total after 10 games: \nPlayer 1: %d \nPlayer 2: %d\n", player1, player2);
}