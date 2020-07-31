#include <stdio.h>

enum { 
  max_name_len = 64, 
  max_group_len = 8 
};

struct student
{
  char name[max_name_len];
  char sex; /* 'm' of 'f' */
  int year_of_birdth;
  int major_code;
  int year;
  char group[max_group_len];
  float average;
};

int main(int argc, char const **argv)
{
  struct student st1 = { "Vasya", 'm', 1995, 51311, 3, "312", 4.792 };
  struct student *ptr;
  ptr = &st1;
  printf("%s\n", ptr->name); /* (*ptr).name */
  printf("%c\n", ptr->sex);
  printf("%d\n", ptr->year);
  return 0;
}



