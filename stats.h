/*
 * stats.h
 */

#ifndef STATS_H_
#define STATS_H_

#define ALPHABET_LENGTH 26 //length of the alphabet array
#define VOWELS "aeiou" //list of vowels
#define VOWELS_LENGTH 6 //length of the vowel list

//struct defining wordstats
struct wordstats_t {
    int vowelCount;
    int consonantCount;
    int wordCount;
    int alphabetCounts[ALPHABET_LENGTH];
};

void updateStats(struct wordstats_t *stats, char *str);

void printHistogram(struct wordstats_t *stats);

#endif /* STATS_H_ */
