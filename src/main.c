#include "linked_list.h"
#define LOOP_ONE_SIZE (55)
#define LOOP_TWO_SIZE (22)

int main(){
    list_t* numbers_list = make_list();
    
    for (int i = 5; i < LOOP_ONE_SIZE; i += 5)
        insert_node_at_end(numbers_list, i);
    display_list(numbers_list);

    printf("-----------------\n");
    
    for (int i = 2; i < LOOP_TWO_SIZE; i += 2)
        insert_node_at_beg(numbers_list, i);
    display_list(numbers_list);
    
    printf("-----------------\n");

    insert_node_at_pos(numbers_list, 999, 10);
    display_list(numbers_list);

    free_list(numbers_list);
    numbers_list = NULL;
    
    return 0;
}