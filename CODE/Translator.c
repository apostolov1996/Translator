#include <stdio.h>
#include <string.h>

#define DMAX 30
#define DMAX_WORDS 100
typedef struct {
	char italian[DMAX];
	char english[DMAX];
	int index; /* if index=0, we have an empty space*/
}Word;
	
typedef struct{
	Word word[DMAX_WORDS];
}Dictionary;

/*
1) Insert new word;
2) General view of the dictionary;
3) Delete word;
4) Search a word in italian and translate it in english;
5) Inport words;
6) Export words;
7) Exit; */
int main () {
	Dictionary dictionary;
	Dictionary coppyDictionary;
	int option;
	int deleteOperation;
	int searchOption;
	int turnback;
	int deleteIndex;
	int searchIndex;
	char deleteEnglish[DMAX];
	char deleteItalian[DMAX];
	char word[DMAX];
	char null[1];
	char outputFileName[DMAX];
	char inputFileName[DMAX];
	null[0]='\0';
	null[1]='\0';
	int i, k;
	int emptySlotsCounter;
	int position;
	
	FILE *output;
	FILE *input;
	FILE *database;
	
	
	for (i=0; i<DMAX_WORDS; i=i+1) {
		dictionary.word[i].index=DMAX_WORDS+1;
		strcpy(dictionary.word[i].english, null);
		strcpy(dictionary.word[i].italian, null);
	}   
	
	printf("ENGLISH/ITALIAN TRANSLATE DICTIONARY");
	
	do {
		printf("\n___________________________________________________________________________________________\n");
		printf("1) Insert a new word.\n");
		printf("2) General view of the dictionary.\n");
		printf("3) Delete a word.\n");
		printf("4) Search a word in italian and translate it in english.\n");
		printf("5) Inport data.\n");
		printf("6) Export data.\n");
		printf("7) Exit.\n\n");
		printf("Before every operation inport database.txt.\n");
		printf("Before exit export your data, save it to database.txt.\n");
		printf("Option: ");
		scanf("%d", &option);
		

		if (option==1) {
			printf("This option allows you to insert a new word.\n");
			printf("Please insert the requested data.\n");
			printf("___________________________________________________________________________________________\n");
			emptySlotsCounter=0;
			/* OPERATIONS*/
			for (i=0; i<DMAX_WORDS; i=i+1) {
				if (dictionary.word[i].index==(DMAX_WORDS+1)) {
					emptySlotsCounter=emptySlotsCounter+1;
				} else {
				}
			}
			if (emptySlotsCounter!=0) {
				position=DMAX_WORDS-emptySlotsCounter;
				printf("You have %d empty slots. You're going to insert a word inside the %d position.\n", emptySlotsCounter, position);
				printf("Insert the word in italian: ");
				scanf("%s", dictionary.word[position].italian);
				printf("Insert the word in english: ");
				scanf("%s", dictionary.word[position].english);
				dictionary.word[position].index=position;
 			} else {
 			    printf("You have no free space. You can write a new word, but the last one is going to be cancelled.\n");
 			    printf("Insert the word in italian: ");
 			    scanf("%s", dictionary.word[DMAX_WORDS-1].italian);
 			    printf("Insert the word in english: ");
 			    scanf("%s", dictionary.word[DMAX_WORDS-1].english);
 			    dictionary.word[DMAX_WORDS-1].index=DMAX_WORDS-1; 				
			}
			printf("___________________________________________________________________________________________\n");
			printf("If you want to go back to the main menu, please insert 0.\n");
			printf("If you want to exit, insert any other key.\n");
			printf("Request: ");
			scanf("%d", &turnback);
		} else if (option==2) {
			printf("This option allows you to see all the words inside the dictionary.\n");
			printf("___________________________________________________________________________________________\n");
			/*OPERATIONS*/
			for (i=0; i<DMAX_WORDS; i=i+1) {
				if (dictionary.word[i].index!=(DMAX_WORDS+1)) {
			    	printf("Index: %d\n", dictionary.word[i].index);
				    printf("Word in Italian: %s\n", dictionary.word[i].italian);
				    printf("Word in English: %s\n", dictionary.word[i].english);
				    printf("_________________________________________________________\n");
				} else {
				}
			}
			printf("___________________________________________________________________________________________\n");
			printf("If you want to go back to the main menu, please insert 0.\n");
			printf("If you want to exit, insert any other key.\n");
			printf("Request: ");
			scanf("%d", &turnback);
		} else if (option==3) {
			printf("This option allows you to delete a word.\n");
			printf("Please insert the requested data.\n");
			printf("___________________________________________________________________________________________\n");
			/*OPERATIONS*/
			printf("You can delete a word using his index number, or using the word in italian or in english.\n");
			printf("Please choose how you'want to delete the word.\n");
			printf("1) To delete a word using the index counter.\n");
			printf("2) To delete it, using the word in english.\n");
			printf("3) To delete it, using the word in italian.\n");
			printf("Operation: ");
			scanf("%d", &deleteOperation);
			if (deleteOperation==1) {
				/* Delete it using his index number*/
				printf("Insert the index of the word: ");
				scanf("%d", &deleteIndex);
				for (i=0; i<DMAX_WORDS; i=i+1) {
					if (deleteIndex==dictionary.word[i].index) {
						dictionary.word[i].index=DMAX_WORDS+1;
						strcpy(dictionary.word[i].italian, null);
						strcpy(dictionary.word[i].english, null);
					} else {
					}
			    }	
			} else if (deleteOperation==2) {
				/* Delete it using the word in english */
				printf("Insert the word in english: ");
				scanf("%s", deleteEnglish);
				for (i=0; i<DMAX_WORDS; i=i+1) {
					if (strcmp(deleteEnglish, dictionary.word[i].english)==0) {
						dictionary.word[i].index=DMAX_WORDS+1;
						strcpy(dictionary.word[i].italian, null);
						strcpy(dictionary.word[i].english, null);
					} else {
					}
				}	
			} else if (deleteOperation==3) {
				/* Delete it using the word in italian*/
				printf("Insert the word in italian: ");
				scanf("%s", deleteItalian);
				for (i=0; i<DMAX_WORDS; i=i+1) {
					if (strcmp(deleteItalian, dictionary.word[i].italian)==0) {
						dictionary.word[i].index=DMAX_WORDS+1;
						strcpy(dictionary.word[i].italian, null);
						strcpy(dictionary.word[i].english, null);
					} else {
					}
				}
			} else {
			}
			for (i=0; i<DMAX_WORDS; i=i+1) {
				coppyDictionary.word[i].index=DMAX_WORDS+1;
				strcpy(coppyDictionary.word[i].english, null);
				strcpy(coppyDictionary.word[i].italian, null);
			}
			/* NOW I HAVE TO REORDER THE LIST */
			k=0;
			for (i=0; i<DMAX_WORDS; i=i+1) {
				if (dictionary.word[i].index!=DMAX_WORDS+1) {
					coppyDictionary.word[i].index=k;
					strcpy(coppyDictionary.word[i].italian, dictionary.word[i].italian);
					strcpy(coppyDictionary.word[i].english, dictionary.word[i].english);
					dictionary.word[i].index=DMAX_WORDS+1;
					strcpy(dictionary.word[i].italian, null);
					strcpy(dictionary.word[i].english, null);
					k=k+1;
				} else {
				}
			}
			for (i=0; i<DMAX_WORDS; i=i+1) {
				dictionary.word[i].index=coppyDictionary.word[i].index;
				strcpy(dictionary.word[i].italian, coppyDictionary.word[i].italian);
				strcpy(dictionary.word[i].english, coppyDictionary.word[i].english);
			}
			printf("___________________________________________________________________________________________\n");
			printf("If you want to go back to the main menu, please insert 0.\n");
			printf("If you want to exit, insert any other key.\n");
			printf("Request: ");
			scanf("%d", &turnback);
		} else if (option==4) {
			printf("This option allows you to search a word inside the dictionary.\n");
			printf("You can insert an italian word, and as output you can see the translation.\n");
			printf(" You can insert an english word, and as output you can see the translation.\n");
			printf("You can also searh them using an index number.\n");
			printf("1) Insert an italian word and translate it.\n");
			printf("2) Insert an english word and translate it.\n");
			printf("3) Insert an index number and see the italian and the english word.\n");
			printf("Option: ");
			scanf("%d", &searchOption);
			if (searchOption==1) {
				/* SEARCH an italian word and translate it */
				printf("Insert the word in italian: ");
				scanf("%s", word);
				printf("OUTPUT:\n");
				for (i=0; i<DMAX_WORDS; i=i+1) {
					if (strcmp(word, dictionary.word[i].italian)==0) {
						printf("Index number: %d\n", dictionary.word[i].index);
						printf("Word in Italian: %s\n", dictionary.word[i].italian);
						printf("Word in English: %s\n", dictionary.word[i].english);
					} else {
					}
				}
				printf("If the output is empty, it is becouse we can't translate the requested word.\n");
				printf("Please be pationet, wait for an update.\n");
			} else if (searchOption==2) {
				printf("Insert the word in english: ");
				scanf("%s", word);
				printf("OUTPUT:\n");
				for (i=0; i<DMAX_WORDS; i=i+1) {
					if (strcmp(word, dictionary.word[i].english)==0) {
						printf("Index number: %d\n", dictionary.word[i].index);
						printf("Word in Italian: %s\n", dictionary.word[i].italian);
						printf("Word in English: %s\n", dictionary.word[i].english);
					} else {
					}
				}
				printf("If the output is empty, it is becouse we can't translate the requested word.\n");
				printf("Please be pationet, wait for an update.\n");
			} else if (searchOption==3) {
				/* SEARCH BY INDEX NUMBER */
				printf("Insert the index number: ");
				scanf("%d", &searchIndex);
				printf("OUTPUT:\n");
				printf("Index number: %d\n", dictionary.word[searchIndex].index);
				printf("Word in Italian: %s\n", dictionary.word[searchIndex].italian);
				printf("Word in English: %s\n", dictionary.word[searchIndex].english);
			} else {
			}
			printf("___________________________________________________________________________________________\n");
			/*OPERATIONS*/
			printf("___________________________________________________________________________________________\n");
			printf("If you want to go back to the main menu, please insert 0.\n");
			printf("If you want to exit, insert any other key.\n");
			printf("Request: ");
			scanf("%d", &turnback);
		} else if (option==5) {
			printf("This option allows you to inport data.\n");
			printf("___________________________________________________________________________________________\n");
			/*OPERATIONS*/
			printf("Insert the input file name: ");
			scanf("%s", inputFileName);
			input=fopen(inputFileName, "r");
	        for (i=0; i<DMAX_WORDS; i=i+1) {
				fscanf(input, "Index: %d) %s - %s\n", &dictionary.word[i].index, dictionary.word[i].italian, dictionary.word[i].english);
			}
			fclose(input);
			printf("___________________________________________________________________________________________\n");
			printf("If you want to go back to the main menu, please insert 0.\n");
			printf("If you want to exit, insert any other key.\n");
			printf("Request: ");
			scanf("%d", &turnback);
		} else if (option==6) {
			printf("This option allows you to export data.\n");
			printf("___________________________________________________________________________________________\n");
			/*OPERATIONS*/
			printf("Where do you want to save data?\n");
			printf("Please enter the name of the text file. Please insert it in this way (name.txt).\n");
			printf("File: ");
			scanf("%s", outputFileName);
			output=fopen(outputFileName, "w");
			if (output) {
				for (i=0; i<DMAX_WORDS; i=i+1) {
					fprintf(output, "Index: %d) %s - %s\n", dictionary.word[i].index, dictionary.word[i].italian, dictionary.word[i].english);				
				}
			} else {
			}
			fclose(output);
			printf("___________________________________________________________________________________________\n");
			printf("If you want to go back to the main menu, please insert 0.\n");
			printf("If you want to exit, insert any other key.\n");
			printf("Request: ");
			scanf("%d", &turnback);
		} else {
			turnback=1;
		}
	} while (turnback==0);
	printf("\n___________________________________________________________________________________________\n");
	printf("Goodbye!\n");
	return 0;
	getch();
}
