#include <stdlib.h>
#include <stdio.h>
 int main () {
  int target=0,arr[100],flag=0;
  for (int i=0;i<100;i++) {
   arr[i]= rand()%100;
  }
  for(int j=0;j<100;j++){
    printf("%d ",arr[j]);
  }
  scanf("%d",&target);
  for (int i = 0; i < 100; i++) {
    if(arr[i]==target){
      flag=1;
      printf("target found at %d", i);
      break;
    }
  }
  if(flag==0){
    printf("item not found");
  }
  return 0;
} 
