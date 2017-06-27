#include "text_stats.h"

int main(int argc, char **argv){

    int conditions = testConditions(argc, argv);

    if (conditions == 2){	// opzioni non conformi alle specifiche
	printf("Attenzione! Le uniche opzioni ammesse sono -c, -w, -l, -i, -I\n");
	return 2;
    }

    struct node *wordlist = getWords();	//raccolta input

    if(conditions == 1) {	// nessuna opzione digitata

	charCount(wordlist);
	wordCount(wordlist);
	lineCount(wordlist);
	freqCount(wordlist);
	
	return 1;

    } else {
	for (int i=1; i<argc; i++){
    	    for(char *j=argv[i]; *j; j++){

		if(strncmp(j, "-c", MAXOPLEN)==0){
		    charCount(wordlist);

		} else if (strncmp(j, "-w", MAXOPLEN)==0){
		    wordCount(wordlist);

		} else if (strncmp(j, "-l", MAXOPLEN)==0){
		    lineCount(wordlist);

		} else if (strncmp(j, "-i", MAXOPLEN)==0){
		    freqCount(wordlist);

		} else if (strncmp(j, "-I", MAXOPLEN)==0){
		    histogram(wordlist);

		}
	    }
	}
    return 0;
    }
}

/* restituisce '0' se le opzioni sono conformi alle specifiche,
 * '1' se non sono stati immesse opzioni
 * '2' altrimenti
 */
int testConditions(int argc, char **argv){
	
    if(argc < 2){     
	return 1;
    }
    for (int i=1; i<argc; i++){
	char *j=argv[i];
	if( (strncmp(j, "-c", MAXOPLEN) !=0 ) &&
	    (strncmp(j, "-w", MAXOPLEN) !=0 ) &&
	    (strncmp(j, "-l", MAXOPLEN) !=0 ) &&
	    (strncmp(j, "-i", MAXOPLEN) !=0 ) &&
	    (strncmp(j, "-I", MAXOPLEN) !=0 ) ) {
	    	return 2;
	}
    }
    return 0;
}
