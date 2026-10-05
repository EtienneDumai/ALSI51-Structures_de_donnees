#include <stdio.h>
#include <stdlib.h>

//#include "list_array.h"
#include "list_linked.h"

int main() {

    t_list list = create_empty_list();
    print_list(&list);
    getchar();

    push_back(&list, 10);
    push_back(&list, 4);
    print_list(&list);
    getchar();

    delete_at(&list, 2);
    print_list(&list);
    getchar();

    insert(&list, 1, 0);
    print_list(&list);
    getchar();

    push_front(&list, 8);
    print_list(&list);
    getchar();

    set(&list, 3, 10);
    print_list(&list);
    getchar();

    printf("list[%d] = %d\n", 1, get(&list, 1));

    destroy_list(&list);

    return 0;
}