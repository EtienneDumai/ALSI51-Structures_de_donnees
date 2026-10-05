#include "list_array.h"

#include <stdio.h>
#include <stdlib.h>
#define INIT_CAPACITY 20
// Allocates a larger array and moves the data to this new array
void realloc_list(t_list* list) {
    unsigned int new_capacity = 2 * list->capacity;
    T *new_data = (T*) malloc(new_capacity * sizeof(T));
    for (unsigned int i = 0; i < list->size; i++) {
        new_data[i] = list->data[i];
    }
    free(list->data);
    list->data = new_data;
    list->capacity = new_capacity;
}

// Shifts the elements of indices index_start .. size-1 one position to the right
// It is assumed that capacity >= size + 1
void shift_right(t_list* list, int index_start) {
    for (unsigned int i = list->size; i > index_start; i--)
    {
        list->data[i] = list->data[i - 1];
    }
}

// Shifts the elements of indices index_start .. size-1 one position to the left
void shift_left(t_list* list, int index_start) {
    for (unsigned int i = index_start-1; i < list->size-1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
}


t_list create_empty_list()
{
    t_list l;
    l.data = (T*) malloc(sizeof(T));
    l.size = 0;
    l.capacity = INIT_CAPACITY;
    return l;
}

T get(t_list *list, int index)
{
    return list->data[index];
}

void set(t_list *list, int index, T val)
{
    list->data[index] = val;
}
void push_front(t_list *list, T val)
{
    insert(list, 0, val);
}
void push_back(t_list *list, T val)
{
    set(list, list->size++, val);
}
void insert(t_list *list, int index, T val)
{
    if (list->size == list->capacity)
    {
        realloc_list(list);
    }
    shift_right(list, index);
    set(list, index, val);
    list->size++;
}
void delete_at(t_list *list, int index)
{
    shift_left(list, index + 1);
    list->size--;
}
void print_list(t_list *list)
{
    for (unsigned int i = 0; i < list->size; i++)
    {
        printf("%d ", list->data[i]);
    }
}

void destroy_list(t_list *list)
{
    free(list->data);
    free(list);
}