#include <stdio.h>
struct sparse{
 int row;
 int col;
};


int main(void) {
  struct sparse a;
  a.row = 5;
  a.col = 5;  
  int sa[a.row][a.col];
  printf("Order of Matrix :",a.row,a.col);
  scanf("%d %d", &a.row,&a.col);
  for(int i = 0; i < a.row; i++){
    for(int j = 0; j < a.col; j++){
     printf("Enter the elements of the matrix:\n");
      scanf("%d", &sa[i][j]);
    }
  }

  printf("3 Tuple representation: \n");
  for(int i = 0; i < a.row; i++){
    for(int j = 0; j < a.col; j++){
      if(sa[i][j] != 0){
        printf("%d\t%d\t%d\n", (i+1), (j+1), sa[i][j]);
      }
    }
  }
 
return 0;
}

/*
**************FAILED EXPERIMENT*************
struct sparse{
 int arr[3];
};


struct sparse ar;
  for(int i = 0; i < 3; i++){
    printf("Enter Matrix [%d]", i);
    scanf("%d", &ar.arr[i]);
  }
  //printf("%d", ar.arr[i]);
  printf("%d""%d""%d", ar.arr[0], ar.arr[1], ar.arr[2]);

*/