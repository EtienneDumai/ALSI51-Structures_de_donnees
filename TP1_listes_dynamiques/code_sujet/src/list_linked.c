#include "list_linked.h"

#include <stdio.h>
#include <stdlib.h>

// Returns the address of the cell at the given index
t_cell* get_cell(t_list* list, int index)
{
    t_cell* cell = list->head;
    int i = 0;
    while (cell != NULL)
    {
        if (i == index)
        {
            return cell;
        }
        cell = cell->next;
        i++;
    }
    exit(EXIT_FAILURE);
}

t_list create_empty_list()
{
    t_list l;
    l.head = (t_cell*)malloc(sizeof(t_cell));
    l.size = 0;
    return l;
}

// Returns the element at given index
T get(t_list* list, int index)
{
    return get_cell(list, index)->value;
}

// Sets the element at given index to value val
void set(t_list* list, int index, T val)
{
    t_cell* cell = list->head;
    int i = 0;
    while (cell != NULL)
    {
        if (i == index)
        {
            cell->value = val;
        }
        cell = cell->next;
        i++;
    }
}

// Adds an element to list at index 0
void push_front(t_list* list, T val)
{
    t_cell* newCell = createCell(val);
    newCell->next = list->head;
    list->head = newCell;
    list->size++;

}

// Adds an element to list at the last index
void push_back(t_list* list, T val)
{
    t_cell* cell = list->head;
    t_cell* newCell = createCell(val);
    char inserted = 0;
    while (inserted == 0)
    {
        if (cell->next == NULL)
        {
            cell->next = newCell;
            inserted = 1;
        }
        cell = cell->next;

    }
    if (inserted == 0)
    {
        exit(EXIT_FAILURE);
    }
}

// Inserts an element with value val at given index
void insert(t_list* list, int index, T val)
{
    t_cell* cell = list->head;

    t_cell* prevCell = (t_cell *)malloc(sizeof(t_cell));
    int i = 0;
    while (cell != NULL)
    {
        if (i == index)
        {
            t_cell* tempCell = (t_cell *)malloc(sizeof(t_cell));
            prevCell->next = tempCell;
            tempCell->value = val;
            tempCell->next = cell;
        }
        prevCell = cell;
        cell = cell->next;
    }
    list->size++;
}

// Deletes the element at given index
void delete_at(t_list* list, int index)
{
    t_cell* cell = list->head;

    t_cell* prevCell = (t_cell *)malloc(sizeof(t_cell));
    int i = 0;
    while (cell != NULL)
    {
        if (i == index)
        {
            prevCell->next = cell->next;
        }
        prevCell = cell;
        cell = cell->next;
    }
    list->size--;
}

// Prints the elements of the list in order
void print_list(t_list* list)
{
    printf("[ ");
    t_cell *cell = list->head;
    if (cell == NULL) {
        printf("]\n");
        return;
    }

    while(cell->next != NULL) {
        printf("%d, ", cell->value);
        cell = cell->next;
    }
    printf("%d ]\n", cell->value);
}

// Frees the memory reserved to store the elements
void destroy_list(t_list* list)
{
    free(list->head);
}


t_cell *createCell(T val)
{
    t_cell* cell = (t_cell*)malloc(sizeof(t_cell));
    cell->value = val;
    cell->next = nullptr;
    return cell;
}