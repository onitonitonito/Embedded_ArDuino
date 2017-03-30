// *ref = https://goo.gl/1dl6xu

#include <stdio.h>
#define SWAP(a,b)  {int t; t = a; a=b; b=t;} // exchange (a) witn (b)

void BubbleSort(int *base, int n);

int main(void)  {
  int arr[10] = { 10,4,3,9,5,8,7,6,2,1 };
  BubbleSort(arr, 10);
  return 0;
}
void ViewArr(int *arr, int n);

void BubbleSort(int *base, int n) {
  int i, j;
  ViewArr(base, n);                       // print current status
  for (i = n; i>1; i--) {                 // squeez range to arrange fowward.
    for (j = 1; j<i; j++) {
      if (base[j - 1]>base[j]) {        // if front bigger
        SWAP(base[j - 1], base[j]); // exchange
        ViewArr(base, n);           // print status
      }
    }
  }
}

void ViewArr(int *arr, int n) {
  int i = 0;
  for (i = 0; i<n; i++)  {
    printf("%2d ", arr[i]);
  }
  printf("\n");
}
