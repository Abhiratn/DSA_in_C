#include <stdio.h>

int main(void) {
  int mat1[3][3];
  int mat2[3][3];
  int result[3][3];
  int n;
  for(int i = 0; i < 3; i++){
   for(int j = 0; j < 3; j++){
    printf("Enter First Matrix [%d][%d]:", i , j);
    scanf("%d", &mat1[i][j]);
   }
 }
  for(int i = 0; i < 3; i++){
   for(int j = 0; j < 3; j++){
    printf("Enter Second Matrix [%d][%d]:", i , j);
    scanf("%d", &mat2[i][j]);
   }
 }
for(int i = 0; i < 3; i++){
   for(int j = 0; j < 3; j++){
    result[i][j]= 0;
     for(int k = 0; k < 3; k++){
        result[i][j] += mat1[i][k] * mat2[k][j];
     }
   }
 }
  
 printf("Resultant Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
  return 0;
}