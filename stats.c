/*
 * stats.c
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stats.h"

/**
 * Helper function: checks if a character is a vowel
 * @param c the character to check
 * @returns 1 if c is a vowel, 0 otherwise
 */
int isVowel(char c)
{
	for (int i = 0; i < VOWELS_LENGTH; i++)
	{
		if (c == VOWELS[i])
		{
			return 1;
		}
	}
	return 0;
}

/**
 * Update the stats
 * @param stats	the struct containing the word stats
 * @param str	the string used to update the word stats
 */
void updateStats(struct wordstats_t *stats, char *str)
{
	int length = strlen(str);
	// goes through each character in the string
	for (int i = 0; i < length; i++)
	{
		// only processes alphabet characters (using ctype.h package)
		if (isalpha(str[i]))
		{
			char character = (char)tolower(str[i]);
			// if vowel, increment vowel count
			if (isVowel(character) == 1)
			{
				(stats->vowelCount)++;
			}
			// else, increment consonant count
			else
			{
				(stats->consonantCount)++;
			}
			// get index in alphabetical order by subtracting a
			int index = character - 'a';
			stats->alphabetCounts[index]++;
		}
	}
	(stats->wordCount)++;
}

/**
 * Printing the histogram based on word stats
 * @param stats	the struct containing word stats
 */
void printHistogram(struct wordstats_t *stats){
	int *counts = stats->alphabetCounts;
	int maxIndex = 0; //array index of letter with the highest count
	//loop through alphabet counts and find highest count
	for (int i = 0; i<ALPHABET_LENGTH; i++){
		if(counts[i]>=counts[maxIndex]){
			maxIndex = i;
		}
	}
	//loop through each level, starting with the highest count
	for (int i = counts[maxIndex]; i > 0; i--){
		//loop through alphabet counts and print '*' if it has a count at the level of i and ' ' otherwise
		for (int j = 0; j<ALPHABET_LENGTH; j++){
			if(counts[j]>=i){
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
	//loop through each the length of the alphabet and print each letter
	//start with 'a' and add i to get the right letter for that index 
	for (int i = 0; i<ALPHABET_LENGTH; i++){
		printf("%c ", 'a' + i);
	}
	printf("\n");
	//loop through the alphabet counts and print out each count
	for (int i = 0; i<ALPHABET_LENGTH; i++){
		printf("%d ",counts[i]);
	}
	printf("\n\n");
}
