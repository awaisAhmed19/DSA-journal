#include <iostream>

int main(){
    int m[100],i;
    char k;
    
    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"\nEnter the elements in an array"<<std::endl;
    for(i=1;i<=10;i++){
        std::cin>>m[i];
    }
    std::cout<<"\nto access array element from indexing"<<std::endl;
    while(true){
        std::cout<<"\nEnter 'a' the if u want to continue"<<std::endl;
        std::cin>>k;
        if(k=='a'){
            break;
        }
        else{
            std::cout<<"\nEnter the index to access"<<std::endl;
            std::cin>>i;
            
            if(i>=0 && i<10){
                std::cout<<"at index " <<i<< " we have " <<m[i]<<std::endl;
            }else {
                std::cout<<"Invalid index. Index should be between 0 and 10"<<std::endl;
            }
        }
    }
    return 0;
}

