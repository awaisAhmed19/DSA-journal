#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int m[100], high=99,low=0,mid=0,target=0;

    printf("Enter the number to be searched");
    scanf("%d",&target);
    //srand(time(NULL));
    for (int i=0;i<100;++i){
        m[i]=(rand()%10)+1;
    }

    for(int i=0;i<100-1;++i){
        for (int j=i+1;j<100;++j){
            if(m[i]>m[j]){
                m[i]=m[i]+m[j];
                m[j]=m[i]-m[j];
                m[i]=m[i]-m[j];
            }
        }
    }

    for(int k=0;k<100;++k){
        printf("%d ",m[k]);
    }
    

    
    while(high>=low){
        mid=high+low/2;
        if(m[mid]==target){
            printf("the number %d is found at position %d",target,mid);
            break;
        }
        if(target<m[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    if (high<low) {
        printf("The  number %d is not present in the array\n", target);        
    }
    return 0;
}
