#include <stdio.h>
#include <stdlib.h>

/* List item */
struct item 
{
  int data;
  struct item *next;
};

struct item *int_array_to_list(int *arr, int len)
{
  struct item *first = NULL;
  struct item *last = NULL;
  struct item *tmp;

  int i;
  for (i = 0; i < len; i++)
  {
    tmp = malloc(sizeof(struct item));
    tmp->data = arr[i];
    tmp->next = NULL;
    /* If list is not empty */
    if (last)
    {
      last->next = tmp;
      last = last->next;
    }
    else
    {
      first = last = tmp;
    }    
  }
  return first;  
}

void list_walker(struct item *first)
{
  if (!first)
  {
    printf("%s\n", "[ERROR] List is empty");
    return;
  }
  /* walk through with a double pionter */
  struct item **ptr;
  ptr = &first;
  int sum = 0;
  while(*ptr)
  {
    /* do something with list item */
    // printf("%d\n", (*ptr)->data);
    sum += (*ptr)->data;
    /* go to the next list item */
    ptr = &(*ptr)->next;
  }
  printf("%d\n", sum);
}

int main(int argc, char const **argv)
{
  enum { arr_len = 10 };
  int arr[arr_len] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
  struct item *list = int_array_to_list(arr, arr_len);
  list_walker(list);
  return 0;
}
