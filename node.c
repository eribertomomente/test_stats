#include "text_stats.h"

// Costruttore nuovo nodo
struct node *create(char *data) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->freq = 1;
    ptr->next = NULL;
    return ptr;
}

// Inserimento di un elemento in lista concatenata
struct node *append(struct node *newnode, struct node *list) {
    newnode->next = list;
    return newnode;
}

// Ricerca del nodo contenente la stringa <str> in <list>. Restituisce il puntatore al nodo con <str> in caso positivo, null altrimenti
struct node *find(char *str, struct node *list){
    if (list->data == NULL){
	return NULL;
    } else if (strncmp(list->data,str, WORDLENGTH)==0){
	return list;
    } else {
	return find(str, list->next);
   }
}


// Inserimento di un nuovo nodo contente <str> in <list>
struct node *insertNode(char *str, struct node *list){
    struct node *n = find(str, list);
    if (n != NULL){
	n->freq++;
	return list;
    } else {
	struct node *newword = create(str);
	return append(newword, list);
    }
}
