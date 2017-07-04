#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define iofunc

#ifdef iofunc

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

#endif
