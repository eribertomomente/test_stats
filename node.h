#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXOPLEN 2		//Max lunghezza delle opzioni digitate dall'utente da riga di comando
#define WORDLENGTH 32		//Max lunghezza stringa memorizzabile in un nodo

#define nodefile

#ifdef nodefile

struct node {
    char *data;		// stringa memorizzata
    int freq;		// occorrenze della stringa
    struct node *next;	// puntatore al prossimo nodo
};

struct node *create(char *);				// Costruttore nuovo nodo
struct node *append(struct node *, struct node *); 	// Inserimento di un elemento in lista concatenata
// Ricerca del nodo contenente la stringa <str> in <list>,
//   restituisce il puntatore al nodo con <str> in caso positivo, null altrimenti
struct node *find(char *, struct node *);
struct node *insertNode(char *, struct node *);		// Inserimento di un nuovo nodo contente <str> in <list>

#endif
