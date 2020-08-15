#include <stdio.h>
#include <stdlib.h>

/* List item */
struct item
{
  int data;
  struct item *next;
};

// Add item to the tail of the list
// struct item *int_array_to_list(int *arr, int len)
// {
//   struct item *first = NULL, *last = NULL, *tmp;

//   int i;
//   for (i = 0; i < len; i++)
//   {
//     tmp = malloc(sizeof(struct item));
//     tmp->data = arr[i];
//     tmp->next = NULL;
//     /* If list is not empty */
//     if (last)
//     {
//       last->next = tmp;
//       last = last->next;
//     }
//     else
//     {
//       first = last = tmp;
//     }
//   }
// }

// Add item to the head of the list
// struct item *int_array_to_list(int *arr, int len)
// {
//   struct item *first = NULL, *tmp;

//   int i;
//   for (i = len - 1; i >= 0; i--)
//   {
//     tmp = malloc(sizeof(struct item));
//     tmp->data = arr[i];
//     tmp->next = first;
//     first = tmp;
//   }

//   return first;
// }

// Recursive case
struct item *int_array_to_list(int *arr, int len)
{
  struct item *tmp;
  if (!len)
	return NULL;
  tmp = malloc(sizeof(struct item));
  tmp->data = *arr;
  tmp->next = int_array_to_list(arr + 1, len - 1);
  return tmp;
}

// Case 0
// int int_list_sum(const struct item *list)
// {
//   int sum = 0;
//   const struct item *tmp = list;
//   while(tmp)
//   {
//     sum += tmp->data;
//     tmp = tmp->next;
//   }
//   return sum;
// }

// Case 1
// int int_list_sum(const struct item *list)
// {
//   int sum = 0;
//   const struct item *tmp = list;
//   for(tmp = list; tmp; tmp = tmp->next)
//   {
//     sum += tmp->data;
//   }
//   return sum;
// }

// Case 2 (Recursive)
int int_list_sum(const struct item *list)
{
  return list ? list->data + int_list_sum(list->next) : 0;
}

// Case 0
// void delete_int_list(struct item *list)
// {
//   while(list)
//   {
//     struct item *tmp = list;
//     list = list->next;
//     free(tmp);
//   }
// }

// Case 1
// void delete_int_list(struct item *list)
// {
//   while(list)
//   {
//     struct item *tmp = list->next;
//     free(list);
//     list = tmp;
//   }
// }

// Case 2 (Recursive)
void delete_int_list(struct item *list)
{
  if (!list)
    return;
  delete_int_list(list->next);
  free(list);    
}

// Case 0
// void list_filter(struct item **curr)
// {
//   /* walk through with a double pointer */
//   while(*curr)
//   {
//     /* do something with list item */
//     if ((*curr)->data % 2 == 0)
//     {
//       struct item *tmp = *curr;
//       *curr = (*curr)->next;
//       free(tmp);
//     }
//     else
//     {
//       printf("%d\n", (*curr)->data);
//       curr = &(*curr)->next;
//     }
//   }
// }

void list_walker(struct item **curr)
{
  while(*curr)
  {
    printf("%d\n", (*curr)->data);
    curr = &(*curr)->next;
  }
}

// Case 1 (Recursive)
void list_filter(struct item **curr)
{
  if (!*curr)
    return;
  list_filter(&(*curr)->next);
  if ((*curr)->data % 2 == 0)
  {
    struct item *tmp = *curr;
    *curr = (*curr)->next;
    free(tmp);
  }
}

int main(int argc, char const **argv)
{
  enum { arr_len = 10 };
  int arr[arr_len] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  struct item *list = int_array_to_list(arr, arr_len);
  list_filter(&list);
  list_walker(&list);
  // printf("%d\n", int_list_sum(list));
  return 0;
}
