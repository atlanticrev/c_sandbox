#include <stdio.h>

enum { max_name_len = 64, max_group_len = 8 };

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

struct student st1 = {
  "Vasya",
  'm',
  1995,
  51311,
  3,
  "312",
  4.792
};

// st1.name = "Vasya";
// st1.sex = 'm';
// st1.year_of_birth = 1995;
// st1.major_code = 51311;
// st1.year = 3;
// st1.group = "312";
// st1.average= 4.792;

int main(int argc, char const **argv)
{
  struct student *ptr;
  ptr = &st1;
  printf("%s\n", ptr->name); /* (*ptr).name */
  printf("%c\n", ptr->sex);
  printf("%d\n", ptr->year);
  return 0;
}



