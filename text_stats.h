#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXOPLEN 2		//Max lunghezza delle opzioni digitate dall'utente da riga di comando
#define WORDLENGTH 32		//Max lunghezza stringa memorizzabile in un nodo

struct node {
    char *data;		// stringa memorizzata
    int freq;		// occorrenze della stringa
    struct node *next;	// puntatore al prossimo nodo
};

/* Funzione di controllo sulle opzioni digitate da riga di comando:
 *	restituisce '0' se le opzioni sono conformi alle specifiche,
 *	   	    '1' se non sono stati immesse opzioni
 *	            '2' altrimenti
 */
int testConditions (int, char **);


/*
 * Prende in input da stdin un numero arbitrario di caratteri, restituisce una lista concatenata con le seguenti caratteristiche:
 * 	- in ogni nodo della lista dev'esserci memorizzata una e una sola stringa e la sua occorrenza nell'input
 *	- non possono esistere due nodi con la stessa stringa
 * 	- l'ultimo nodo della lista ha .data = null
 */
struct node *getWords();

void wordCount(struct node*);	//stampa il numero delle parole ricevute in input
void charCount(struct node*);	//stampa il numero totale dei caratteri ricevuti in input
void lineCount (struct node *);	//stampa il numero delle linee immesse nell'input
void freqCount (struct node *);	//stampa l'elenco di tutte le parole ricevute in input e le relative frequenze
void histogram (struct node *);	//stampa un istogramma delle frequenze di ogni parola

struct node *create(char *);				// Costruttore nuovo nodo
struct node *append(struct node *, struct node *); 	// Inserimento di un elemento in lista concatenata
// Ricerca del nodo contenente la stringa <str> in <list>,
//   restituisce il puntatore al nodo con <str> in caso positivo, null altrimenti
struct node *find(char *, struct node *);
struct node *insertNode(char *, struct node *);		// Inserimento di un nuovo nodo contente <str> in <list>

