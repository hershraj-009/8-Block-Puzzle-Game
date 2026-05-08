#include <iostream>
#include "algo.h"
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

void puzzle::start(){

    int arr[9]{};
    int ind = mat_gen(arr);
    int win{};

    while(true){
        std::cout<<" ENTER NUMBER TO SWITCH OR ENTER 999 TO RUN ALGORITHM FROM CURRENT STATE "<<std::endl;
        int inp{};
        std::cin>>inp;
        win=0;

        if(inp == 999){
            int ini_arr[9] = {0,1,2,3,4,5,6,7,8};
            real_deal(ini_arr,arr);
        }

        for(int i=0;i<9;++i){
            if(arr[i]==inp){

                if( (i+1!=ind) && (i-1!=ind) && (i+3!=ind) && (i-3!=ind) ){
                    std::cout<<" INCORRECT MOVEMENT "<<std::endl;
                    break;
                }

                if( i%3==0 ){
                    
                    if( i<=2 ){
                        if( (i+1!=ind) && (i+3!=ind) ){
                            std::cout<<" INCORRECT MOVEMENT "<<std::endl;
                            break;
                        }
                        else{
                            arr[ind]=inp;
                            arr[i]=0;
                            ind=i;
                            break;
                        }
                    }

                    if( i<=5 ){
                        if( (i+1!=ind) && (i+3!=ind) && (i-3!=ind) ){
                            std::cout<<" INCORRECT MOVEMENT "<<std::endl;
                            break;
                        }
                        else{
                            arr[ind]=inp;
                            arr[i]=0;
                            ind=i;
                            break;
                        }
                    }
                    if( i<=8 ){
                        if( (i+1!=ind) && (i-3!=ind) ){
                            std::cout<<" INCORRECT MOVEMENT "<<std::endl;
                            break;
                        }
                        else{
                            arr[ind]=inp;
                            arr[i]=0;
                            ind=i;
                            break;
                        }
                    }
                }

                if( i%3==1 ){
                    
                    if( i<=2 ){
                        if( (i+1!=ind) && (i+3!=ind) && (i-1!=ind) ){
                            std::cout<<" INCORRECT MOVEMENT "<<std::endl;
                            break;
                        }
                        else{
                            arr[ind]=inp;
                            arr[i]=0;
                            ind=i;
                            break;
                        }
                    }

                    if( i<=5 ){
                        if( (i+1!=ind) && (i+3!=ind) && (i-1!=ind) && (i-3!=ind) ){
                            std::cout<<" INCORRECT MOVEMENT "<<std::endl;
                            break;
                        }
                        else{
                            arr[ind]=inp;
                            arr[i]=0;
                            ind=i;
                            break;
                        }
                    }
                    if( i<=8 ){
                        if( (i+1!=ind) && (i-3!=ind) && (i-1!=ind) ){
                            std::cout<<" INCORRECT MOVEMENT "<<std::endl;
                            break;
                        }
                        else{
                            arr[ind]=inp;
                            arr[i]=0;
                            ind=i;
                            break;
                        }
                    }
                }

                if( i%3==2 ){
                    
                    if( i<=2 ){
                        if( (i-1!=ind) && (i+3!=ind) ){
                            std::cout<<" INCORRECT MOVEMENT "<<std::endl;
                            break;
                        }
                        else{
                            arr[ind]=inp;
                            arr[i]=0;
                            ind=i;
                            break;
                        }
                    }

                    if( i<=5 ){
                        if( (i-1!=ind) && (i+3!=ind) && (i-3!=ind) ){
                            std::cout<<" INCORRECT MOVEMENT "<<std::endl;
                            break;
                        }
                        else{
                            arr[ind]=inp;
                            arr[i]=0;
                            ind=i;
                            break;
                        }
                    }
                    if( i<=8 ){
                        if( (i-1!=ind) && (i-3!=ind) ){
                            std::cout<<" INCORRECT MOVEMENT "<<std::endl;
                            break;
                        }
                        else{
                            arr[ind]=inp;
                            arr[i]=0;
                            ind=i;
                            break;
                        }
                    }
                }
            
            }
        }

        std::cout<<"_______"<<std::endl;

        for(int j=0;j<3;++j){
            for (int i=3*j;i<3*j+3;++i){
                if (arr[i]==0){
                    std::cout<<"| ";
                }
                else{
                    std::cout<<"|"<<arr[i];
                }
            }
        std::cout<<"|"<<std::endl;
    }
        std::cout<<"-------"<<std::endl;

        for(int i=0;i<9;++i){
            if(arr[i]!=i){
                ++win;
            }
        }

        if( win == 0){
            std::cout<<"-------- VICTORY --------"<<std::endl;
            break;
        }

    }
}

int* copy_arr(int arr[]){
    int *new_arr = new int[9];
    for(int i=0;i<9;++i){
        new_arr[i] = arr[i]; 
    }
    return new_arr;
}

int blank_ind(int arr[]){
    for(int i=0;i<9;++i){
        if(arr[i]==0){
            return i;
        }
    }
    return 0;
}