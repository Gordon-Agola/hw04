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
    dll_push_front(dll, 3);
    dll_push_front(dll, 2);
    dll_push_front(dll, 1);
    dll_push_back(dll, 4);
    dll_push_back(dll, 5);
    dll_insert(dll, 2, 10);

    print_dll(dll);  // Output: 1 2 10 3 4 5

    printf("Size: %d\n", dll_size(dll));  // Output: 6

    printf("Removed: %d\n", dll_remove(dll, 3));  // Output: 3

    print_dll(dll);  // Output: 1 2 10 4 5

    free_dll(dll);

    

    return 0;
}