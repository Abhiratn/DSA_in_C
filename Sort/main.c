#include <stdio.h>

int arr[100];
int n;
int i, j;

// Linear sort (Insertion sort)
void lsort() {
  int key;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// Swap can be used for both Bubble and Quick sort
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Bubble sort
void bsort() {
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

// Quick Sort
int low, high;
int partition(int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void qsort(int low, int high) {
  if (low < high) {
    int pi = partition(low, high);

    qsort(low, pi - 1);
    qsort(pi + 1, high);
  }
}

int main(void) {
  int c;
  printf("Enter the number of elements (n): ");
  scanf("%d", &n);
  
  printf("Enter the elements of the array:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  do {
    printf("********************MENU***************************\n");
    printf("1. For Linear Sort\n");
    printf("2. For Bubble Sort\n");
    printf("3. For Quick Sort\n");
    printf("4. Exit\n");
    printf("Enter Your Command: ");
    scanf("%d", &c);

    switch (c) {
    case 1:
      printf("Linear Sort: ");
      lsort();
      break;
    case 2:
      printf("Bubble Sort: ");
      bsort();
      break;
    case 3:
      printf("Quick Sort: ");
      low = 0;
      high = n - 1;
      qsort(low, high);
      break;
    default:
      break;
    }

   // Print the sorted array
    for (i = 0; i < n; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  } while (c != 4);
  return 0;
}