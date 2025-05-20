#include <stdio.h>

int* selectionSort(int size,int arr[]){
  for (int i=0;i,i<size-1;i++){
    int min=i;
    int temp=0;
    for(int j=i+1;j<size;j++){
      if(arr[j]<arr[min]){
        min=j;
      }
    }
    temp=arr[min];
    arr[min]=arr[i];
    arr[i]=temp;
  }
  return arr;
}

int main(){
  int size=10;
  int arr[]={9,8,7,6,5,4,4,3,2,1};
  int* out=selectionSort(size,arr);
  for(int i=0;i<size;i++){
    printf("%d\n",out[i]);
  }
  return 0;

}
