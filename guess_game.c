#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
    
    int number, guess, attempts, maxattempts;
    int choice, score=0;
    int range;
    
    srand(time(0));
    
    do{
        printf(" \n---------- NUMBER GUESSING GAME ----------\n");
        
        printf("\n");
        printf("Select Difficulty :-\n");
        printf("\n");
        printf("1. Easy (1-50, 10 attempts\n");
        printf("2. Medium(1-100, 7 attempts \n");
        printf("3.Hard(1-200, 3 attempts \n");
        printf("Enter your choice -> \n");
        scanf("%d", &choice);
        
        if(choice == 1){
            range = 50;
            maxattempts = 10;
        }
        else if(choice == 2){
            range = 100;
            maxattempts = 7;
        }
        else if(choice == 3){
            range = 200;
            maxattempts = 3;
        }
        else{
            printf("In-valid Choice\n\n");
            break;
        }
        
        number = rand()% range + 1;
        attempts=0;
        
        printf("Guess the number between (1 to %d)\n", range);
        
        while(attempts < maxattempts){
            printf("attempts left : %d \n", maxattempts - attempts);
            
            printf("Enter your guess -->\n");
            scanf("%d", &guess);
            
            attempts++;
            
            if(guess > number){
                printf("Too High\n");
            }
            else if(guess < number){
                printf("Too Low\n");
            }
            else{
                printf("Correct 🎯 \n");
                score += (maxattempts - attempts+1)*10;
                break;
            }
        }
        
        if(guess != number){
            printf("Game Over ❌ \n The number was %d\n", number);
            printf("your score = %d", score);
            
            printf("\nPlay again ? / (1=Yes/ 0=No)\n ");
            
            printf("Enter your choice -->\n");
            scanf("%d", &choice);
            
        }
    }while(choice == 1);
        
        printf("Final score: %d\n", score);
        printf("Thanks for Playing 🥸");
    

    return 0;

