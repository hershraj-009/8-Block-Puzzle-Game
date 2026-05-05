#include <iostream>
#include "puzzle.h"

int main(){
puzzle obj;
int arr[9]{};
int ind = obj.mat_gen(arr);
int win{};

while(true){
    std::cout<<" ENTER NUMBER TO SWITCH "<<std::endl;
    int inp{};
    std::cin>>inp;
    win=0;

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