// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions.
//   - (You may consider using these printf statements to debug,
//     but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

#include <stdlib.h>

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node
{
    int data;
    struct node *next;
    struct node *previous;
} node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL
{
    int count;    // count keeps track of how many items are in the DLL.
    node_t *head; // head points to the first node in our DLL.
    node_t *tail; // tail points to the last node in our DLL.
} dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t *create_dll()
{
    // TODO: Implement me!!
    dll_t *myDLL = malloc(sizeof(dll_t));
    if (myDLL != NULL)
    {
        myDLL->count = 0;
        myDLL->head = NULL;
        myDLL->tail = NULL;
    }
    return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns -1 if the dll is NULL.
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t *l)
{
    // TODO: Implement me!!
    if (l == NULL)
        return -1;
    return l->count == 0;
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t *l, int item)
{
    // TODO: Implement me!!

    if (l == NULL)
        return -1;

    node_t *newNode = malloc(sizeof(node_t));
    if (newNode == NULL)
        return 0;

    newNode->data = item;
    newNode->next = l->head;
    newNode->previous = NULL;

    if (l->head != NULL)
        l->head->previous = newNode;

    l->head = newNode;

    if (l->tail == NULL)
        l->tail = newNode;

    l->count++;
    return 1;
}

// push a new item to the end of the DLL (after the last node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t *l, int item)
{
    // TODO: Implement me!!
if (l == NULL)
        return -1;

    node_t *newNode = malloc(sizeof(node_t));
    if (newNode == NULL)
        return 0;

    newNode->data = item;
    newNode->next = NULL;
    newNode->previous = l->tail;

    if (l->tail != NULL)
        l->tail->next = newNode;

    l->tail = newNode;

    if (l->head == NULL)
        l->head = newNode;

    l->count++;
    return 1;
}

// Returns the first item in the DLL and also removes it from the list.
// Returns -1 if the DLL is NULL.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t *t)
{
    // TODO: Implement me!!
    if (t == NULL)
        return -1;
    if (t->count == 0)
        return 0;

    int item = t->head->data;
    node_t *temp = t->head;

    t->head = t->head->next;
    if (t->head != NULL)
        t->head->previous = NULL;

    if (temp == t->tail)
        t->tail = NULL;

    free(temp);
    t->count--;
    return item;

    // Note: This line is a 'filler' so the code compiles.
}

// Returns the last item in the DLL, and also removes it from the list.
// Returns a -1 if the DLL is NULL.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t *l)
{
    // TODO: Implement me!!
    if (l == NULL)
        return -1;
    if (l->count == 0)
        return 0;

    int item = l->tail->data;
    node_t *temp = l->tail;

    l->tail = l->tail->previous;
    if (l->tail != NULL)
        l->tail->next = NULL;

    if (temp == l->head)
        l->head = NULL;

    free(temp);
    l->count--;
    return item;

    // Note: This line is a 'filler' so the code compiles.
}

// Inserts a new node before the node at the specified position.
// Returns -1 if the list is NULL
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
int dll_insert(dll_t *l, int pos, int item)
{
    // TODO: Implement me!!
    if (l == NULL)
        return -1;
    if (pos < 0 || pos > l->count)
        return 0;
    if (pos == 0)
        return dll_push_front(l, item);
    if (pos == l->count)
        return dll_push_back(l, item);

    node_t *current = l->head;
    for (int i = 0; i < pos; i++)
        current = current->next;

    node_t *newNode = malloc(sizeof(node_t));
    if (newNode == NULL)
        return 0;

    newNode->data = item;
    newNode->next = current;
    newNode->previous = current->previous;

    current->previous->next = newNode;
    current->previous = newNode;

    l->count++;
    return 1;

    // Note: This line is a 'filler' so the code compiles.
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
//  (does not remove the item)
// Returns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Assume no negative numbers in the list or the number zero.
int dll_get(dll_t *l, int pos)
{
    // TODO: Implement me!!
    if (l == NULL)
        return -1;
    if (pos < 0 || pos >= l->count)
        return 0;

    node_t *current = l->head;
    for (int i = 0; i < pos; i++)
        current = current->next;

    return current->data;
    // Note: This line is a 'filler' so the code compiles.
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
// Returns 0 on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Assume no negative numbers in the list or the number zero.
// Otherwise returns the value of the node removed.
int dll_remove(dll_t *l, int pos)
{
    // TODO: Implement me!!
    if (l == NULL)
        return -1;
    if (pos < 0 || pos >= l->count)
        return 0;
    if (pos == 0)
        return dll_pop_front(l);
    if (pos == l->count - 1)
        return dll_pop_back(l);

    node_t *current = l->head;
    for (int i = 0; i < pos; i++)
        current = current->next;

    int item = current->data;
    current->previous->next = current->next;
    current->next->previous = current->previous;

    free(current);
    l->count--;
    return item;
    // Note: This line is a 'filler' so the code compiles.
}

// DLL Size
// Returns -1 if the DLL is NULL.
// Queries the current size of a DLL
int dll_size(dll_t *l)
{
    // TODO: Implement me!!
    if (l == NULL)
        return -1;
    return l->count;

    // Note: This line is a 'filler' so the code compiles.
}

// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the program terminates.
void free_dll(dll_t *l)
{
    // TODO: Implement me!!
    if (l == NULL)
        return;

    node_t *current = l->head;
    while (current != NULL)
    {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }

    free(l);
}



#endif