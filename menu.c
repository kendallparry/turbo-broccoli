/*
 * menu.c
 */

#include <stdio.h>
#include "menu.h"

/**
 * Printing the word stats menu
 */
void printMenu(){
    printf("*** WORD STATS MENU ***\n");
    printf("Enter 1 to print frequencies.\n");
    printf("Enter 2 to print histogram.\n");
    printf("Enter 3 to return to inputting more strings.\n");
    printf("Enter 4 to quit.\n");
}