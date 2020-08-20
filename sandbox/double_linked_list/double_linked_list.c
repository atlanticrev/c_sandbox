#include <stdio.h>
#include <stdlib.h>

// Item
struct item {
    double data;
    struct item *prev, *next;
};

// List
struct item *first = NULL;
struct item *last = NULL;
struct item *curr = NULL;
struct item *tmp = NULL;

void add_front(double data)
{
    tmp = malloc(sizeof(struct item));
    tmp->data = data;
    tmp->prev = NULL;
    tmp->next = first;
    if (first)
        first->prev = tmp;
    else
        last = tmp;
    first = tmp;
}

void add_back(double data)
{
    tmp = malloc(sizeof(struct item));
    tmp->data = data;
    tmp->prev = last;
    tmp->next = NULL;
    if (last)
        last->next = tmp;
    else
        first = tmp;
    last = tmp;    
}

void delete_front()
{
    if (first)
    {
        tmp = first;
        first = first->next;
        if (first)
        {
            first->prev = NULL;
        }
        else
            last = NULL;
        free(tmp);
    }
}

void delete_back()
{
    if (last)
    {
        tmp = last;
        last = last->prev;
        if (last)
        {
            last->next = NULL;
        }
        else
            first = NULL;
        free(tmp);
    }
}

void list_walker()
{
    struct item *tmp;
    tmp = first;
    while(tmp)
    {
        printf("%lf\n", tmp->data);
        tmp = tmp->next;
    }
}

void flush_list()
{
    if (first)
    {
        first = first->next;
        while (first)
        {
            free(first->prev);
            first = first->next;
        }
        free(last);
        last = NULL;        
    }
}

int main(int argc, char const **argv)
{
    printf("----before----\n");
    add_back(1.5);    
    add_back(2.5); 
    add_back(3.5); 
    list_walker();
    printf("----after----\n");
    delete_front();
    list_walker();   
    return 0;
}
