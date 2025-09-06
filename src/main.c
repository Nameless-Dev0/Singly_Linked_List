#include "linked_list.h"

#define LOOP_ONE_SIZE (55)
#define LOOP_TWO_SIZE (22)

#define SHOW_LIST(LIST)             \
do                                  \
{                                   \
    display_list(numbers_list);     \
    printf("-----------------\n");  \
} while (0)


int main(){
    list_t* numbers_list = make_list();
    
    for (int i = 5; i < LOOP_ONE_SIZE; i += 5)
        insert_node_at_end(numbers_list, i);

    for (int i = 2; i < LOOP_TWO_SIZE; i += 2)
        insert_node_at_beg(numbers_list, i);

    insert_node_at_pos(numbers_list, 999, 10);
    
    SHOW_LIST(numbers_list);
    search_and_delete_node(999, numbers_list);
    SHOW_LIST(numbers_list);

    free_list(&numbers_list);
    return 0;
}

