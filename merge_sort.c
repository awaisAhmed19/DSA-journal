#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int left,int mid,int right){
  int n1=mid-left+1;
  int n2=right-mid;

  int* leftarr=(int*)malloc(n1*sizeof(int));
  int* rightarr=(int*)malloc(n2*sizeof(int));

  for(int i=0;i<n1;i++){
    leftarr[i]=arr[left+i];
  }
  for(int j=0;j<n2;j++){
    rightarr[j]=arr[mid+1+j];
  }

  int i=0;
  int j=0;
  int k=left;

  while(i<n1&&j<n2){
    if(leftarr[i]<=rightarr[j]){
      arr[k++]=leftarr[i++];
    }else{
      arr[k++]=rightarr[j++];
    }
  }
  while(i<n1){
    arr[k++]=leftarr[i++];
  }
  while(j<n2){
    arr[k++]=rightarr[j++];
  }
  free(leftarr);
  free(rightarr);
}

void mergeSort(int arr[],int left, int right){
  if (left < right){
    int mid=(left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
  }
}

int main(){
  int size=10;
  int arr[]={9,8,7,6,5,4,3,2,1,0};
  mergeSort(arr,0,size-1);
  for(int i=0;i<size;i++){
    printf("%d\n",arr[i]);
  }
}
