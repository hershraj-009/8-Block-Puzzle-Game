#include <iostream>
#include <random>
#include "puzzle.h"

int puzzle::rand(int a, int b){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(a,b);
    return dist(gen);
}

int puzzle::mat_gen(int arr[]){
    int min = 0;
    int max = 8;
    int i = 0;
    int ind=0;

    while(true){

        while(i<8){
            int ind = rand(min,max);
            if(arr[ind] ==0 ) {
                arr[ind] = i+1;
                ++i;
            }
        }

        int inv{};

        for(int j =0;j<8;++j){
            int x {arr[j]};
            for(int k=j+1;k<9;++k){
                if (arr[k]!=0 && arr[k]<x){
                    ++inv;
                }
            }
        }

        if (inv%2 == 0){
            break;
        }
        else{
            i=0;
            for(int j=0;j<9;++j){
                arr[j]=0;
            }
        }

    }
    std::cout<<"_______"<<std::endl;

    for(int j=0;j<3;++j){
        for (int i=3*j;i<3*j+3;++i){
            if (arr[i]==0){
                ind=i;
                std::cout<<"| ";
            }
            else{
                std::cout<<"|"<<arr[i];
            }
        }
    std::cout<<"|"<<std::endl;
}
    std::cout<<"-------"<<std::endl;

    return ind;

}