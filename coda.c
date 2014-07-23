#include "coda.h"

struct list_node *list_head;

void init_list(void){
    size_t list_size = sizeof(array_backend)/sizeof(array_backend[0]);
    size_t i;

    list_head = NULL;

    struct list_node **index = &list_head;
    for (i = 0; i < list_size; i++ ){
        static_list_inizialization[i].array_index = i;
        static_list_inizialization[i].peso = 0;
        add_sorted( &static_list_inizialization[i] );
    }

}

void add_sorted(struct list_node *node) {
	struct list_node **index = &list_head;
	while (*index != NULL && (*index)->peso < node->peso) {
		index = &((*index)->next);
	}
	node->next = *index;
	*index = node;
}

struct list_node* poll_head(void) {
	struct list_node *index = list_head;
	list_head = list_head->next;
	return index;
}

struct list_node* poll_head_time(uint32_t peso) {
    struct list_node *index = list_head;
    if (index->peso <= peso){
        list_head = list_head->next;
        return index;
    }else{
        return NULL;
    }
}
