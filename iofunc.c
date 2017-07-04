#include "iofunc.h"
#include "node.h"
/*
 * Prende in input da stdin un numero arbitrario di caratteri, restituisce una lista concatenata con le seguenti caratteristiche:
 * 	- in ogni nodo della lista dev'esserci memorizzata una e una sola stringa e la sua occorrenza nell'input
 *	- non possono esistere due nodi con la stessa stringa
 * 	- l'ultimo nodo della lista ha .data = null
 */
struct node *getWords(){
    struct node *list = create(NULL);	// creo il primo nodo della lista concatenata
    char *buffer = calloc(WORDLENGTH, sizeof(char));	//alloco un buffer per memorizzare la parola in input
    int i = 0;		//indice per spostarmi in <buffer>
    char c = (char) getchar();

    while (c != EOF){

	while (c != EOF && c != ' ' && c != '\n' && i < WORDLENGTH-1){ 	//(l'ultimo byte deve rimanere 0)

	    buffer[i]=c;	//memorizzo <c>
	    i++;
	    c = (char) getchar();
	}
	
	list = insertNode(buffer, list);

	// cerco di capire quale condizione del ciclo si sia falsificata:
	if (c == EOF){
	    return list;
	}

	if (c == '\n'){
	    list = insertNode("\n", list);	//mi servira' per il conteggio delle righe
	}
	
	// se era uno spazio lo ignoro, non va salvato nella lista!
	// se ho finito lo spazio in <buffer> non ho altre possibilita'

	buffer = calloc(WORDLENGTH, sizeof(char));
	i=0;
	c = (char) getchar();
    }

    free(buffer);
    return list;
}


// stampa il numero totale dei caratteri ricevuti in input da stdin
void charCount (struct node *list){ 	
    int chars = 0;
    for (struct node *n = list;  n->next;  n = n->next){	//si ferma al penultimo nodo dato che l'ultimo contiene stringa nulla
	if (strlen(n->data)==0)				// caso di spazi multipli
	    chars = chars + n->freq;
	else if (strncmp(n->data, "\n", 1) != 0)	
	    chars = chars + (strlen(n->data) +1)*(n->freq);	//(lunghezza stringa + whitespace) * numero di occorrenze
    }
							//se invece incontro newline
								//ho contato già contato il whitespace (che non c'era) invece di questo newline
    printf("Conteggio caratteri: %d\n", chars);
}


// stampa il numero delle parole ricevute in input da stdin
void wordCount (struct node *list){	
    int words = 0;
    for (struct node *n = list;  n->next;  n = n->next){	
	if ( strncmp(n->data, "\n", 1) && strlen(n->data)>0 ){ 
	    words = words + n->freq;
	}
    }
    printf("Conteggio parole: %d\n", words);
}


// stampa il numero delle linee immesse nell'input da stdin
void lineCount (struct node *list){ 	
    struct node *nl = find("\n", list);
    int lines = 1;	//la prima riga
    if ( nl != NULL ){		
	lines += nl->freq;	//somma alla aprima riga tutte le altre
    }
    printf("Conteggio linee: %d\n", lines);
}


//stampa l'elenco di tutte le parole ricevute in input da stdin e le relative frequenze
void freqCount (struct node *list){

    printf("Conteggio occorrenze di ogni parola:\n");

    for (struct node *n = list;  n->next;  n = n->next){	
	if( strncmp(n->data, "\n", 1) !=0 && strlen(n->data)>0 ) {
	    printf("\"%s\": %d\n", n->data, n->freq);
	}
    }
}


//stampa un istogramma delle frequenze di ogni parola
void histogram (struct node *list){

    printf("Istogramma delle frequenze:\n");

    for (struct node *n = list;  n->next;  n = n->next){	
	
	if ( strncmp(n->data, "\n", 1) && strlen(n->data)>0 ){

	    printf("|");

	    for (int i = 0;  i < n->freq;  i++)
		printf("*");

	    printf(" %s\n", n->data);
	}
    }
}






