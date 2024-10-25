#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int game(char you, char computer)
{
    
    if (you == computer)
        return -1;

    
    if (you == 's' && computer == 'p')
        return 0;
    else if (you == 'p' && computer == 's') 
        return 1;

    
    if (you == 's' && computer == 'z')
        return 1;
    else if (you == 'z' && computer == 's')
        return 0;

    
    if (you == 'p' && computer == 'z')
        return 0;
    else if (you == 'z' && computer == 'p')
        return 1;
}

int main()
{
    int n, player_score = 0, computer_score = 0;
    char you, computer;
    int result;
    srand(time(NULL));

    printf("Welcome to Stone-Paper-Scissors game!\n");

    
    while (1) {
        n = rand() % 100;

        if (n < 33)
            computer = 's'; 
        else if (n >= 33 && n < 66)
            computer = 'p'; 
        else
            computer = 'z'; 

        printf("\nEnter 's' for Stone, 'p' for Paper, 'z' for Scissor (or 'q' to quit): ");
        scanf(" %c", &you);

        
        if (you == 'q') {
            printf("\nGame Over!\nFinal Scores:\nPlayer: %d\nComputer: %d\n", player_score, computer_score);
            break;
        }

        result = game(you, computer);

        if (result == -1) {
            printf("Game Draw!\n");
        }
        else if (result == 1) {
            printf("You won this round!\n");
            player_score++;
        }
        else {
            printf("Computer won this round!\n");
            computer_score++;
        }

        printf("You chose: %c | Computer chose: %c\n", you, computer);
        printf("Current Scores -> Player: %d | Computer: %d\n", player_score, computer_score);
    }

    return 0;
}
