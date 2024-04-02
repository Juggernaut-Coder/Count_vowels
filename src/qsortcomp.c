#include "headers/main.h"

int vowel_freq_compare_function(const void *  a, const void * b) {
	characters * comp_var1 = (characters *)a;
	characters * comp_var2 = (characters *)b;
	return ( comp_var2->char_freq - comp_var1->char_freq );
}