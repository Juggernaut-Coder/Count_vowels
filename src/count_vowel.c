#include "headers/main.h"

characters * new_vowel_arr() {
	characters * vowel_arr = (characters*)calloc(TOTAL_NUMBER_OF_VOWELS,sizeof(characters));
	vowel_arr[a].character = 'a';
	vowel_arr[e].character = 'e';
	vowel_arr[i].character = 'i';
	vowel_arr[o].character = 'o';
	vowel_arr[u].character = 'u';
	return vowel_arr;
}

void if_vowel_then_count(vowel * vowel, char char_to_check) {
	switch(char_to_check) {
		case 'A':
		case 'a':
			vowel->arr[a].char_freq++;
			break;
		case 'E':
		case 'e':
			vowel->arr[e].char_freq++;
			break;
		case 'I':
		case 'i':
			vowel->arr[i].char_freq++;
			break;
		case 'O':
		case 'o':
			vowel->arr[o].char_freq++;
			break;
		case 'U':
		case 'u':
			vowel->arr[u].char_freq++;
			break;
	}
}