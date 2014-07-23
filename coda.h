#ifndef CODA_H_INCLUDED
#define CODA_H_INCLUDED

#include <stddef.h>
#include <stdint.h>

#include "nodo.h"

static struct list_node {
	size_t array_index;
	uint32_t peso;
	struct list_node *next;
}static_list_inizialization[sizeof(array_backend)/sizeof(array_backend[0])];

void init_list(void);
struct list_node* poll_head(void);
void add_sorted(struct list_node *node);

#endif // CODA_H_INCLUDED
