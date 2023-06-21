// Compile this assignment with: clang -g -Wall main.c -o main.out
// Use this file to implement testing for your
// doubly linked list implementation

#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

#include "my_dll.h"


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main()
{
    dll_t *dll = create_dll();
    dll_push_front(dll,3);
    dll_push_front(dll,2);
    dll_push_front(dll,1);
    dll_push_back(dll,4);
    dll_push_back(dll,5);
    dll_insert(dll,2,10);

    printf("Size: %d\n",dll_size(dll));


    int passed = 0;
    dll_t *test = create_dll();
    dll_push_front(test, 789);
    if (1 == dll_size(test))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(test);

    printf("%d\n",passed);
    return 0;
}