#include <iostream>
#include "algo.h"
#include "puzzle.h"

int main(){
puzzle obj;

int choice{};
std::cout<<" Enter 0 to play by self OR Enter 1 to execte the algorithm "<<std::endl;
std::cin>>choice;

if(choice == 0){
obj.start();
}

else if(choice == 1){

int win[9]{};
int ind = obj.mat_gen(win);
int ini_arr[9]{0,1,2,3,4,5,6,7,8};

real_deal(ini_arr,win);
}

else{
    std::cout<<" ENTER A VALID CHOICE "<<std::endl;
}

}