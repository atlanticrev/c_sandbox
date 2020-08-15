#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int data;
    struct Item* next;
} Item;

typedef struct List {
    Item* first;
    Item* last;
    Item* tmp;
} List;

// Find list element
void find(List* list) {
    printf("%d\n", list->first->data);    
}

// Add to begin of the list
int add_to_list_f(List* list, Item* item) {
    list->tmp = item;        
    list->tmp->next = list->first;
    list->first = list->tmp;
    return 1;        
}

// Add to end of the list
int add_to_list_l(List* list, Item* item) {
    list->tmp = item;
    list->tmp->next = NULL;
    if (!list->last) {
        list->first = list->tmp;
        list->last = list->tmp;        
    } else {
        list->last->next = list->tmp;
        list->last = list->tmp;
    }
    return 1;        
}

// Print all elements of the list
void print_all_elements(List* list) {
    Item** ptr;
    ptr = &list->first;
    while (*ptr) {
        printf("%d\n", (*ptr)->data);  
        ptr = &(*ptr)->next;      
    }    
}

int main(int argc, char const **argv)
{
    struct List newList = { NULL, NULL, NULL };

    struct Item newEl_1 = { 0 };
    struct Item newEl_2 = { 1 };
    struct Item newEl_3 = { 2 };
    struct Item newEl_4 = { 3 };
    struct Item newEl_5 = { 4 };
    struct Item newEl_6 = { 5 };
    struct Item newEl_7 = { 6 };
    struct Item newEl_8 = { 7 };
    struct Item newEl_9 = { 8 };

    add_to_list_f(&newList, &newEl_1);
    add_to_list_f(&newList, &newEl_2);
    add_to_list_f(&newList, &newEl_3);
    add_to_list_f(&newList, &newEl_4);
    add_to_list_f(&newList, &newEl_5);
    add_to_list_f(&newList, &newEl_6);
    add_to_list_f(&newList, &newEl_7);
    add_to_list_f(&newList, &newEl_8);
    add_to_list_f(&newList, &newEl_9);

    // add_to_list_l(&newList, &newEl_1);
    // add_to_list_l(&newList, &newEl_2);
    // add_to_list_l(&newList, &newEl_3);
    // add_to_list_l(&newList, &newEl_4);
    // add_to_list_l(&newList, &newEl_5);
    // add_to_list_l(&newList, &newEl_6);
    // add_to_list_l(&newList, &newEl_7);
    // add_to_list_l(&newList, &newEl_8);
    // add_to_list_l(&newList, &newEl_9);

    print_all_elements(&newList);

    return 0;
}



