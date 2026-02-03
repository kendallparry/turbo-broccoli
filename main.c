/*
 * main.c
 * @author kendall parry
 */
#include <stdio.h>
#include <string.h>
#include "stats.h"
#include "menu.h"

#define MAX_INPUT_LEN 128 /** maximum allowed input length */

/**
 * @brief Main function
 */
int main(int argc, char *argv[])
{
	// string input operations
	char input[MAX_INPUT_LEN];
	struct wordstats_t stats = {0};
	printf("Enter strings (# to stop):\n");
	int acceptingInput = 1;

	//capture strings, tokenize, and update stats
	while (acceptingInput == 1)
	{
		fgets(input, MAX_INPUT_LEN, stdin);

		if (strcmp(input, "#\n") != 0 && strcmp(input, "#") != 0)
		{
			char delimiters[] = " \t\n"; //delimit based on space, tab, or new line

			char *token = strtok(input, delimiters);
			//parse current token, update to next token
			while (token != NULL)
			{
				updateStats(&stats, token);
				token = strtok(NULL, delimiters);
			}
			continue;
		}

		// menu operations
		int menu = 1;
		while (menu == 1)
		{
			printMenu();
			char inputNum[5];
			fgets(inputNum, sizeof(inputNum), stdin);
			//if user inputs 1, print stats
			if (strcmp(inputNum, "1\n") == 0)
			{
				//calculating necessary values for printed statistics
				int totalLetters = stats.vowelCount + stats.consonantCount;
				double averageLength = (stats.vowelCount + stats.consonantCount) / (double)stats.wordCount;
				double percentVowels = (stats.vowelCount / (double)totalLetters) * 100;
				double percentConsonants = (stats.consonantCount / (double)totalLetters) * 100;
				printf("Words = %d, Average Word Length = %.2f\n", stats.wordCount, averageLength);
				printf("Vowels = %d (%.2f%%), Consonants = %d (%.2f%%), Total = %d\n\n", stats.vowelCount, percentVowels, stats.consonantCount, percentConsonants, totalLetters);
			}
			//if user inputs 2, print histogram
			else if (strcmp(inputNum, "2\n") == 0)
			{
				printHistogram(&stats);
			}
			//if user inputs 3, continue loop to return to string entry
			else if (strcmp(inputNum, "3\n") == 0)
			{
				menu = 0;
				printf("Enter strings (# to stop):\n");
				continue;
			}
			//if user inputs 4, exit program
			else if (strcmp(inputNum, "4\n") == 0)
			{
				menu = 0;
				acceptingInput = 0;
			}
			//if input was not a valid option, print an error and exit program
			else
			{
				printf("Error: Unknown option %s\n", inputNum);
				menu = 0;
				acceptingInput = 0;
			}
		}
	}

	printf("Exiting...\n");
	return 0;
}
