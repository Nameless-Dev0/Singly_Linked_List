#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

typedef struct node node_t;
typedef struct linked_list list_t;

void insert_node_at_beg(list_t* list, int value);
void insert_node_at_end(list_t* list, int value);
void insert_node_at_pos(list_t* list, int value, int position);

void search_and_delete_node(int value, list_t* list);

list_t* make_list(void);
void destroy_list(list_t* list);

void display_list(list_t* list);
void reverse_list(list_t* list);

#endif // LINKED_LIST_H


