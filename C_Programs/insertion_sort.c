#include <stdio.h>

int* insertionSort(int size, int arr[]){
  for (int i=1;i<size;i++){
    int key = arr[i];
    int j=i-1;
    while(j>=0&&key<arr[j]){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
  }
  return arr;
}

int main(){
  int size=10;
  int arr[]={9,8,7,6,5,4,3,2,1,1};
  int* out=insertionSort(size,arr);
  printf("\n ");
  for(int i=0;i<size;i++){
    printf("%d ",out[i]);
  }
  return 0;
}
