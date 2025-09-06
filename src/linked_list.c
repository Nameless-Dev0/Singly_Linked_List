#include "linked_list.h"

static inline node_t* create_node(int value); 

#define CREATE_AND_VALIDATE_NODE(VALUE, NEW_NODE)   \
do {                                                \                                                 
    NEW_NODE = create_node(VALUE);                  \
    if (!NEW_NODE) {                                \
        printf("Node insertion failed\n");          \
        return;                                     \
    }                                               \
} while (0)                                         \
 

struct node{
    int data;
    struct node* next;
};

struct linked_list{
    struct node* head;
};


static inline node_t* create_node(int value){
    node_t* new_node = malloc(sizeof(node_t));
    if(!new_node){
        perror("Node creation failed");
        return NULL;
    }
    new_node -> data = value;
    new_node -> next = NULL;
    return new_node;
}

list_t* make_list(void){ 
    list_t* list = malloc(sizeof(list_t)); // Ensure head pointer is heap allocated (lifetime)
    if(!list){
        perror("List creation failed");
        return NULL;
    }
    list->head = NULL;
    return list;
}

void insert_node_at_beg(list_t* list, int value){
    node_t* new_node;
    CREATE_AND_VALIDATE_NODE(value, new_node);
    new_node -> next = list -> head;
    list->head = new_node;
}

void insert_node_at_end(list_t* list, int value){
    node_t *current_node, *new_node;
    CREATE_AND_VALIDATE_NODE(value, new_node);

    // empty list
    if (!(list -> head)) {
        list -> head = new_node;
        return;
    }
    
    current_node = list -> head; 
    while(current_node ->  next)
        current_node = current_node -> next;
    current_node -> next =  new_node;
}


void insert_node_at_pos(list_t* list, int value, int position){
    node_t *new_node, *current_node;
    CREATE_AND_VALIDATE_NODE(value, new_node);

    if (position < 1){
        printf("Invalid position value.\n");
        return;
    }

    if (position == 1)
    {
        new_node -> next = list -> head;
        list -> head  = new_node;
        return;
    }

    current_node = list -> head;
    for (int i = 1; (i < position - 1) && (current_node != NULL); i++)
        current_node = current_node -> next;
    
    if (!(current_node))
    {
        printf("Invalid position value.\n");
        return;
    }
    
    new_node -> next = current_node -> next;
    current_node -> next = new_node;
}

void display_list(list_t* list){
    node_t *current_node = list -> head;
    int node_count = 1;

    if(!(current_node)) return;
    
    while(current_node != NULL)
    {
        printf("Node %d, data: %d\n", node_count, current_node -> data);
        current_node = current_node -> next;
        node_count++;
    }
}


void free_list(list_t** list){
    if (!list || !(*list)) return; 

    node_t *current_node = (*list) -> head;
    node_t *next_node;

    while(current_node != NULL){
        next_node = current_node -> next;
        free(current_node);
        current_node = next_node;
    }
    
    free(*list);
    *list = NULL;
}
