// Makeing structure in c
#include <stdio.h>
/*structure syntax
struct <struct_name>{
  int aa
  float bb
  char cc
  };
*/

struct Mystruct{
 int a;
 float b;
 char c[50];
};

int main(void) {
//declare variable
  struct Mystruct test;
//Assign values
  test.a = 25;
  test.b = 0.24;
//test.c = ABCD;
  strcpy(test.c,"ABCD");

//Access Structure
  printf("Int: %d\n", test.a);  
  printf("Float: %f\n", test.b);  
  printf("Char: %s\n", test.c);  

  return 0;
}