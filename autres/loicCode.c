
/* 
 * This file is a part of the C LinkedList library.
 * 
 * File:   LinkedList.h
 * Author: Loïc FORTIN <loic.fortin@etud.univ-montp2.fr>
 *
 * Created on 3 octobre 2014, 09:08
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdbool.h> // bool
#include <string.h> // memcpy, memcmp

#define EMPTY_LIST_EXCEPTION 10
#define INDEX_OUT_OF_RANGE_EXCEPTION 11
#define NUMBER_INSERTION_EXCEPTION 12
#define MEMORY_ALLOCATION_FAIL_EXCEPTION 13
#define CIRCULAR_REFERENCE_EXCEPTION 14

/*
 * This structure represent a single element (node) on the list.
 * It stores the data and has a pointer to the previous and next element (node) of the list.
 */
struct Node {
    void* value;
    struct Node* previous;
    struct Node* next;
};

/*
 * This structure represent the doubly linked list.
 * It stores the length of the list and has a pointer to the first and last element.
 */
struct LinkedList {
    size_t length; // Length of the list
    struct Node* first; // Pointer to the last element of the list
    struct Node* last; // Pointer to the last element of the list
};

/*
 * Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0.
 * 
 * @param list Pointer to the container.
 */
void ll_clear(struct LinkedList* list);

/*
 * Returns a copy of the LinkedList.
 * 
 * @param list Pointer to the container.
 * 
 * @return A copy of the list
 */
struct LinkedList* ll_clone(struct LinkedList* list);

/*
 * Returns true if this list contains the specified element, false otherwise.
 * 
 * @param list Pointer to the container
 * @param value The value to search for.
 */
bool ll_contains(struct LinkedList* list, void* value);

/*
 * Create a new list container.
 * 
 * @param list Pointer to the container.
 * 
 * @return A new LinkedList
 */
struct LinkedList* ll_create();

/*
 * Destroy a list container
 * 
 * @param list Pointer to the container.
 */
void ll_destroy(struct LinkedList* list);

/*
 * Returns whether the list container is empty (i.e. whether its size is 0).
 * 
 * @param list Pointer to the container.
 * 
 * @return true if the container size is 0, false otherwise.
 */
bool ll_empty(struct LinkedList* list);

/*
 * Returns the value of the first element in this list. 
 * 
 * @param list Pointer to the container.
 * 
 * @return The value of the first element in the list
 */
void* ll_first(struct LinkedList* list);

/*
 * Returns the value of the element at the specified position in this list. 
 * 
 * @param list Pointer to the container.
 * 
 * @return The value of an element at a specified position in the list
 */
void* ll_get(struct LinkedList* list, size_t index);

/*
 * The container is extended by inserting new elements before the element at the specified position.
 *
 * This effectively increases the list size by the amount of elements inserted.
 * 
 * @param list Pointer to the container.
 * @param index Inserts the element at the specified position in this list.
 * @param value Value of the inserted elements.
 * @param n Number of elements to insert. Each element is initialized to a copy of value.
 */
void ll_insert(struct LinkedList* list, size_t index, void* value, size_t n);

/*
 * Returns the value of the last element in this list. 
 * 
 * @param list Pointer to the container.
 * 
 * @return The value of the last element in the list
 */
void* ll_last(struct LinkedList* list);

/*
 * Removes and returns the value of the last element in the list container, effectively reducing the container size by one.
 * 
 * This destroys the removed element.
 * 
 * @param list Pointer to the container.
 * 
 * @return The value of the last element of this list
 */
void* ll_pop_back(struct LinkedList* list);

/*
 * Removes and returns the value of the the first element in the list container, effectively reducing its size by one.
 * 
 * This destroys the removed element.
 * 
 * @param list Pointer to the container.
 * 
 * @return The value of the first element of this list
 */
void* ll_pop_front(struct LinkedList* list);

/*
 * Adds a new element at the end of the list container, after its current last element. The content of data is copied to the new element.
 * 
 * This effectively increases the container size by one.
 * 
 * @param list Pointer to the container.
 * @param value Value to be copied to the new element.
 */
void ll_push_back(struct LinkedList* list, void* value);

/*
 * Inserts a new element at the beginning of the list, right before its current first element. The content of data is copied to the inserted element.
 * 
 * This effectively increases the container size by one.
 * 
 * @param list Pointer to the container.
 * @param value Value to be copied to the new element.
 */
void ll_push_front(struct LinkedList* list, void* value);

/*
 * Removes the head (first element) of this list.
 * 
 * This destroys the removed element.
 * 
 * @param list Pointer to the container.
 */
void ll_remove(struct LinkedList* list);

/*
 * Removes the element at the specified position in this list.
 * 
 * This destroys the removed element.
 * 
 * @param list Pointer to the container
 * @param index The index of the element to be removed
 */
void ll_remove_at(struct LinkedList* list, size_t index);

/*
 * Returns the number of elements in the list container.
 * 
 * @param list Pointer to the container
 * 
 * @return The size of the container
 */
size_t ll_size(struct LinkedList* list);

/*
 * Exchanges the value of x by the value of y, which is another value of the same type. Sizes may differ.
 * 
 * After the call to this function, the elements in x are those which were in y before the call, and the elements of y are those which were in x. 
 * 
 * @param list Pointer to the doubly linked list
 * @param x Position of the first element
 * @param y Position of the second element
 */
void ll_swap(struct LinkedList* list, size_t x, size_t y);


#ifdef  __cplusplus
}
#endif

#endif  /* LINKEDLIST_H */





///////////////////////////////////////////////////////////////////////////



/* 
 * This file is a part of the C LinkedList library.
 * 
 * File:   LinkedList.h
 * Author: Loïc FORTIN <loic.fortin@etud.univ-montp2.fr>
 *
 * Created on 6 octobre 2014, 07:41
 */

//#include "LinkedList.h"

void ll_clear(struct LinkedList* list) {
    // Iterate until the list is empty
    while(!ll_empty(list)) {
        ll_remove(list);
    }
}

struct LinkedList* ll_clone(struct LinkedList* list) {
    struct LinkedList* tmp = ll_create();
    struct Node* ite = list->first;
    
    // Iterate until the end of the list
    while(ite) {
        /*
         * We must allocate a new block of memory to copy the value.
         * ite->value is a void*. We are allocating 1*sizeof(ite->value) so we don't need a
         * void** but a simple void* (in this case, using void** is not necessary because 
         * malloc return a pointer to a single block of memory, which is equivalent to a table 
         * with only one line).
         */
        void* value = (void*) malloc(sizeof(ite->value));
        
        if(!value)
            exit(MEMORY_ALLOCATION_FAIL_EXCEPTION);
        
        memcpy(value, ite->value, sizeof(ite->value));
        ll_push_back(tmp, value);
        ite = ite->next;
        
        if(ite == list->first) {
            exit(CIRCULAR_REFERENCE_EXCEPTION);
        }
    }
    
    return tmp;
}

bool ll_contains(struct LinkedList* list, void* value) {
    if(ll_empty(list))
        return false;
    
    struct Node* ite = list->first;
    
    // Iterate until we reach the value
    while(ite && (memcmp(ite->value, value, sizeof(value)) != 0)) {
        ite = ite->next;
        
        if(ite == list->first) {
            exit(CIRCULAR_REFERENCE_EXCEPTION);
        }
    }
    
    return ((ite && (memcmp(ite->value, value, sizeof(value)) == 0)) ? true : false);
}

struct LinkedList* ll_create() {
    struct LinkedList* list = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    
    if(!list)
        exit(MEMORY_ALLOCATION_FAIL_EXCEPTION);
    
    list->first = NULL;
    list->last = NULL;
    list->length = 0;
    
    return list;
}

void ll_destroy(struct LinkedList* list) {
    ll_clear(list);
    free(list);
}

bool ll_empty(struct LinkedList* list) {
    return ((list->length == 0) ? true : false);
}

void* ll_first(struct LinkedList* list) {
    if(ll_empty(list))
        exit(EMPTY_LIST_EXCEPTION);
    
    return list->first->value;
}

void* ll_get(struct LinkedList* list, size_t index) {
    if(ll_empty(list))
        exit(EMPTY_LIST_EXCEPTION);
    
    //if(index < 0 || index >= list->length)
    if(index >= list->length)
        exit(INDEX_OUT_OF_RANGE_EXCEPTION);
    
    struct Node* ite = list->first;
    size_t i = 0;
    
    // Iterate until we reach the position
    while(i != index) {
        ite = ite->next;
        ++i;
    }
    
    return ite->value;
}

void ll_insert(struct LinkedList* list, size_t index, void* value, size_t n) {
    if(n < 1)
        exit(NUMBER_INSERTION_EXCEPTION);
    
    size_t k = 0; // Number of elements insered
    
    // If list is empty AND index == 0, we create a new element
    if(ll_empty(list) && index == 0) {
        struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));

        if(!tmp)
            exit(MEMORY_ALLOCATION_FAIL_EXCEPTION);

        // Updating element
        tmp->previous = NULL;
        tmp->next = NULL;
        tmp->value = value;

        // Updating list
        list->first = tmp;
        list->last = tmp;
        ++list->length;
        
        ++k;
    }

    //if(index < 0 || index >= list->length)
    if(index >= list->length)
        exit(INDEX_OUT_OF_RANGE_EXCEPTION);
    
    struct Node* ite = list->first;
    size_t j = 0;
    
    // Iterate until we reach the position
    while(j != index) {
        ite = ite->next;
        ++j;
    }
    
    while(k < n) {
        struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));

        if(!tmp)
            exit(MEMORY_ALLOCATION_FAIL_EXCEPTION);
        
        // Updating element
        tmp->previous = ite->previous;
        tmp->next = ite;
        tmp->value = value;
        ite->previous = tmp;
        
        // If it is the first element, we need to update the list
        if(tmp->previous == NULL)
            list->first = tmp;
        else
            (tmp->previous)->next = tmp;
        
        ++list->length;
        
        ++k;
    }
}

void* ll_last(struct LinkedList* list) {
    if(ll_empty(list))
        exit(EMPTY_LIST_EXCEPTION);
    
    return list->last->value;
}

void* ll_pop_back(struct LinkedList* list) {
    void* value = ll_last(list);
    
    ll_remove_at(list, list->length - 1);
    
    return value;
}

void* ll_pop_front(struct LinkedList* list) {
    void* value = ll_first(list);
    
    ll_remove(list);
    
    return value;
}

void ll_push_back(struct LinkedList* list, void* value) {
    if(ll_empty(list)) {
        ll_push_front(list, value);
    }
    else {
        ll_insert(list, list->length - 1, value, 1);
        ll_swap(list, list->length - 2, list->length - 1);
    }
}

void ll_push_front(struct LinkedList* list, void* value) {
    
    ll_insert(list, 0, value, 1);
}

void ll_remove(struct LinkedList* list) {
    ll_remove_at(list, 0);
}

void ll_remove_at(struct LinkedList* list, size_t index) {
    if(ll_empty(list))
        exit(EMPTY_LIST_EXCEPTION);
    
    //if(index < 0 || index >= list->length)
    if(index >= list->length)
        exit(INDEX_OUT_OF_RANGE_EXCEPTION);
    
    struct Node* tmp = list->first;
    size_t i = 0;
    
    // Iterate until we reach the position
    while(i != index) {
        tmp = tmp->next;
        ++i;
    }
    
    free(tmp->value);
    
    if(tmp->previous != NULL) {
        (tmp->previous)->next = tmp->next;
    }
    else {
        list->first = tmp->next;
    }
    
    if(tmp->next != NULL) {
        (tmp->next)->previous = tmp->previous;
    }
    else {
        list->last = tmp->previous;
    }
    
    tmp->previous = NULL;
    tmp->next = NULL;
    
    free(tmp);
    
    --list->length;
}

size_t ll_size(struct LinkedList* list) {
    return list->length;
}

void ll_swap(struct LinkedList* list, size_t x, size_t y) {
    if(ll_empty(list))
        exit(EMPTY_LIST_EXCEPTION);
    
    //if(x < 0 || x >= list->length)
    if(x >= list->length)
        exit(INDEX_OUT_OF_RANGE_EXCEPTION);
    
    //if(y < 0 || y >= list->length)
    if(y >= list->length)
        exit(INDEX_OUT_OF_RANGE_EXCEPTION);
    
    struct Node* xtmp = list->first;
    size_t i = 0;
    
    // Iterate until we reach the position
    while(i != x) {
        xtmp = xtmp->next;
        ++i;
    }
    
    struct Node* ytmp = list->first;
    size_t j = 0;
    
    // Iterate until we reach the position
    while(j != y) {
        ytmp = ytmp->next;
        ++j;
    }
    
    void* vtmp = xtmp->value;
    xtmp->value = ytmp->value;
    ytmp->value = vtmp;
}








////////////////////////////////////////////////////////////














///////////////////////////////////////////////////////////////////////





/* 
 * This file is a part of the C LinkedList library.
 * 
 * File:   LinkedList.h
 * Author: Loïc FORTIN <loic.fortin@etud.univ-montp2.fr>
 *
 * Created on 7 octobre 2014, 10:48
 */

#include <stdio.h>
#include <stdlib.h>
//#include "LinkedList.h"

/*
 * 
 */
int main(int argc, char** argv) {
    printf("Entering software\n");
    
    struct LinkedList* list = ll_create();
    
    if(ll_empty(list))
        printf("Empty list\n");
    else
        printf("Not empty list\n");
    
    printf("Size of the list : %zu\n", ll_size(list));
    
    printf("Adding values (back)...\n");
    
    for(int i = 1; i <= 10; ++i) {
        int* val = (int*) malloc(sizeof(int));
        *val = i;
        ll_push_back(list, (void*) val);
    }
    
    printf("Size of the list : %zu\n", ll_size(list));
    
    printf("Adding values (front)...\n");
    
    for(int i = 11; i <= 20; ++i) {
        int* val =(int*) malloc(sizeof(int));
        *val = i;
        ll_push_front(list, (void*) val);
    }
    
    printf("Size of the list : %zu\n", ll_size(list));
    
    printf("Adding value 333 at a specified position (11)...\n");
    
    int* val = (int*) malloc(sizeof(int));
    *val = 333;
    ll_insert(list, 11, (void*) val, 1);
    
    printf("Size of the list : %zu\n", ll_size(list));
    
    printf("Swapping first and last values\n");
    
    ll_swap(list, 0, list->length - 1);
    
    printf("Listing values :\n");
    
    for(size_t i = 1; i <= ll_size(list); ++i)
        printf("Number %zu = %d\n", i, *((int*) ll_get(list, i-1)));
    
    printf("Search for value 333... ");
    int* dval = (int*) malloc(sizeof(int));
    *dval = 333;
    if(ll_contains(list, (void*) dval)) {
        printf("found ");
        
        int* sval = (int*) ll_get(list, 11);
        
        printf("(%d)\n", *sval);
    }
    else {
        printf("not found\n");
    }
    
    printf("Search for value 894... ");
    int* dval2 = (int*) malloc(sizeof(int));
    *dval2 = 894;
    if(ll_contains(list, (void*) dval2)) {
        printf("found ");
        
        int* sval2 = (int*) ll_get(list, 11);
        
        printf("(%d)\n", *sval2);
    }
    else {
        printf("not found\n");
    }
    
    printf("Getting value 10 : %d\n", *((int*) ll_get(list, 9)));
    
    printf("Cloning list (name : list2)\n");
    
    struct LinkedList* list2 = ll_clone(list);
    
    printf("Size of list2 : %zu\n", ll_size(list2));
    
    for(size_t i = 1; i <= ll_size(list2); ++i)
        printf("list2 : Number %zu = %d\n", i, *((int*) ll_get(list2, i-1)));
    
    printf("Removing first value (list)...\n");
    
    ll_remove(list);
    
    printf("Size of list : %zu\n", ll_size(list));
    
    printf("Clearing all values from list...\n");
    ll_clear(list);
    
    printf("Size of the list : %zu\n", ll_size(list));
    
    for(size_t i = 1; i <= ll_size(list); ++i)
        printf("Number %zu = %d\n", i, *((int*) ll_get(list, i-1)));
    
    printf("Destroying list\n");
    
    ll_destroy(list);
    
    printf("Size of list2 : %zu\n", ll_size(list2));
    
    printf("Destroying list2\n");
    
    ll_destroy(list2);

    printf("Ending software\n");
    
    return (EXIT_SUCCESS);
}


