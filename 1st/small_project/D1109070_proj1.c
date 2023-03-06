// Randomly generate numbers between 1 and 1000 for user to guess.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void guessGame(void); // function prototype
int isCorrect(int, int); // function prototype
void correct_banner();
int main(void){
    // srand( time( 0 ) ); // seed random number generator
    guessGame();
} // end main
// guessGame generates numbers between 1 and 1000
// and checks user's guess
void guessGame(void){
    int answer; // randomly generated number
    int guess; // user's guess
    int response; // 1 or 2 response to continue game
    // loop until user types 2 to quit game
    do{
        // generate random number between 1 and 1000
        // 1 is shift, 1000 is scaling factor
        answer = 1 + rand() % 1000;
        // prompt for guess
        printf("I have a number between 1 and 1000.\nCan you guess my number?\nPlease type your first guess.\n? ");
        //先設定左界(l)與右界(r)然後一直重複猜(l + r) / 2的數字，其中每次只要猜的數字較大就將右界改為猜的數字減1；猜的數字較小就將左界改為猜的數字加1
        long long l = 1,r = 1000,call_answer,times = 1;
        guess = (l + r) / 2;
        printf("%lld ",guess);
        call_answer = isCorrect(guess, answer);
        // loop until correct number
        while (call_answer != 1){
            if(call_answer == 2){
                l = guess + 1;
            }else if(call_answer == 3){
                r = guess - 1;
            }
            guess = (l + r) / 2;
            printf("%lld ",guess);
            call_answer = isCorrect(guess, answer);
            times++;
        }
        // prompt for another game
        if(times == 1){
            printf("\nExcellent! You guessed the number!\nYou use %lld time.\n",times);
        }else{
            printf("\nExcellent! You guessed the number!\nYou use %lld times.\n",times);
        }
        correct_banner();
        printf("Would you like to play again?\nPlease type ( 1=yes, 2=no )?");   
        scanf("%d", &response);
    } while (response == 1);
} // end function guessGame

// isCorrect returns true if g equals a
// if g does not equal a, displays hint
int isCorrect(int g, int a){
    // guess is correct
    if (g == a){
        return 1;
    }
    // guess is incorrect; display hint
    if (g < a){
        printf( "%s", "Too low. Try again.\n? " );
        return 2;
    }else{
        printf( "%s", "Too high. Try again.\n? " );
        return 3;
    }
    return 0;
} // end function isCorrect
//if guess is correct , print correct_banner
void correct_banner(){
   printf(" _                _\n");             
   printf("| |              | |\n");            
   printf("| |__   __ _  ___| | _____ _ __\n"); 
   printf("| '_ \\ / _` |/ __| |/ / _ \\ '__|\n");
   printf("| | | | (_| | (__|   <  __/ |\n");   
   printf("|_| |_|\\__,_|\\___|_|\\_\\___|_|\n");
}