#ifndef COUNT_VOWEL_H
#define COUNT_VOWEL_H

#define TOTAL_NUMBER_OF_VOWELS 5

/* A structure that can hold any character and its frequency */
typedef struct {
	char character;
	unsigned int char_freq;
}characters;

/* A structure that can hold all vowels and its frequency */
typedef struct {
	characters * arr;
}vowel;

/* enums used for initializing the vowel arrays for better readability */
enum vowel_enum {
	a,
	e,
	i,
	o,
	u,
};

extern void if_vowel_then_count(vowel *, char);
/* A function to initialize vowel arrays */
extern characters * new_vowel_arr();

#endif
