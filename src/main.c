#include "headers/main.h"

int main(int argc, char **argv) {
	/* Check if files names are passed as argument strings.
   	 * If not arguments are passed the program inform the user
   	 * that the program requires arguments to operate and terminates.
   	 */
	if (argc == 1) {
	    printf("No arguments were passed.\nPlease pass path of files containing "
	           "strings to count the vowels.\n");
	    /* Stop screen from disappearing until any character is pressed */
	    getchar();
	    return EXIT_NO_INPUT;
	}
	/* Ensure that all file path exist and files are readable, otherwise terminates */
	unsigned int verification_result = verify_files_exist_and_readable(argc, argv);
	if (verification_result !=0) {
		printf("You have entered %u invalid argument(s).\nPlease check the above "
    	"error message(s) and re-enter correct argument(s).\n",
    	verification_result);
    	/* Stop screen from disappearing until any character is pressed */
    	getchar();
    	return EXIT_INVALID_INPUT;
	}
	for (int i = 1; i < argc; ++i) {
		/* Open and print the name of the vowel counting string file */
		FILE *vowel_counting_file = fopen(argv[i], "r");
		assert(vowel_counting_file != NULL);
		printf("#FILE NAME: %s\n", argv[i]);
		char line_buffer[MAX_LINE_BUFFER_SIZE]; 
		/* fgets: If the end-of-file is encountered while attempting to read a character, the eof indicator is set (feof). 
		 * If this happens before any characters could be read, the pointer returned 
		 * is a null pointer (and the contents of str remain unchanged).
		 */
		while( fgets(line_buffer, MAX_LINE_BUFFER_SIZE, vowel_counting_file) != NULL ) {
			/* Use strcmp to ignore line feed and hash symbol variants */
			if(strcmp(line_buffer,"\n") !=0  && strcmp(line_buffer," \n") !=0 && strcmp(line_buffer,"#\n") !=0 && strcmp(line_buffer,"# \n") !=0 ) {
				/* Create a new vowel array  */
				vowel vowel = {.arr=new_vowel_arr()};
				/* Iterate line_buffer using a for loop to count vowels */
				for(int j=0; j<strlen(line_buffer); j++) {
					if_vowel_then_count(&vowel,line_buffer[j]) ;
				}
				/* Sort */
				qsort( vowel.arr,TOTAL_NUMBER_OF_VOWELS,sizeof(characters),vowel_freq_compare_function );
				/* Print line_buffer  */
				printf("%s",line_buffer);
				/* Use for loop to show vowel counts of line_buffer in a sorted fashion decending order */
				for(int k=0;k<TOTAL_NUMBER_OF_VOWELS;k++) {
					printf("%c:%u ",vowel.arr[k].character,vowel.arr[k].char_freq);
				}
				/* Print line feed for next string containing vowel  */
				printf("\n");
				/* Free the vowel array created by the constructor new_vowel_arr()  */
				free(vowel.arr);	
			}
		}
		/* Close the vowel counting string file */
		int fclose_res = fclose(vowel_counting_file);
    	assert(fclose_res == 0);
	}
	/* Stop screen from disappearing until any character is pressed */
    getchar();
	return EXIT_SUCCESS;
}
