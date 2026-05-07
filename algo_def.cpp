#include <iostream>
#include <stdlib.h>
#include "algo.h"
#include "puzzle.h"

metadata::metadata(){
    ;
}

metadata::metadata(int temp_memo){
    
    if(temp_memo==1){
        res_move = 2;
    }
      
    else if(temp_memo==2){
        res_move = 1;
    }
      
    else if(temp_memo==3){
        res_move = 4;
    }
      
    else if(temp_memo==4){
        res_move = 3;
    }
}

stk* def(int *arr, metadata *add, int win[], int move){

    metadata *obj = new metadata(move);

    obj->par_add = add;

    if(move == (obj->par_add)->res_move){
        return nullptr;
    }

    stk *next = new stk();
    next->nod_add = obj;

    for(int i=0;i<9;++i){
        obj->curr_state[i]=arr[i];
    }

    int chec = 0;
    for(int i =0;i<9;++i){
        if(arr[i]!=win[i]){
            ++chec;
        }
    }
    
    if(chec==0){
        win_case(obj);
    }

    return next;
}

stk* int_def(int ini_state[], int win[]){

    metadata *obj = new metadata();
    stk *top = new stk();
    top->nod_add = obj;
    
    for(int i=0;i<9;++i){
        obj->curr_state[i]=ini_state[i];
    }
    obj->par_add = nullptr;

    int chec = 0;
    for(int i =0;i<9;++i){
        if(ini_state[i]!=win[i]){
            ++chec;
        }
    }
    
    if(chec==0){
        win_case(obj);
    }

    return top;
}

void real_deal(int arr[], int win[]){

    // 1->left, 2->right, 3->up, 4->down
    int act[9]{24,124,14,234,1234,134,23,123,13};
    stk *top = int_def(arr,win);
    metadata *add = top->nod_add;
    stk *temp = top;

    while(true){
    add = top->nod_add;
    int bla = blank_ind(arr);

    int curr = act[bla];
    for(int i = curr;i>0;){
        temp->ptr = cal(i%10,arr,add,win);
        if(temp->ptr != nullptr){
        temp = temp->ptr;
        }
        i/=10;
    }
    stk *del = top;
    top = top->ptr;
    del->ptr = nullptr;
    delete del;
    del = nullptr;
    for(int i=0;i<9;++i){
    arr[i] = (top->nod_add)->curr_state[i];
    }
    }
}

stk* cal(int x, int arr[], metadata *add, int win[]){

    if(x==1){
        int *new_arr = copy_arr(arr);
        int ind = blank_ind(arr);
        new_arr[ind] = new_arr[ind-1];
        new_arr[ind-1]=0;
        stk* next = def(new_arr,add,win,x);
        delete[]new_arr;
        new_arr = nullptr;
        return next;
    }

    else if(x==2){
        int *new_arr = copy_arr(arr);
        int ind = blank_ind(arr);
        new_arr[ind] = new_arr[ind+1];
        new_arr[ind+1]=0;
        stk* next = def(new_arr,add,win,x);
        delete[]new_arr;
        new_arr = nullptr;
        return next;
    }

    else if(x==3){
        int *new_arr = copy_arr(arr);
        int ind = blank_ind(arr);
        new_arr[ind] = new_arr[ind-3];
        new_arr[ind-3]=0;
        stk* next = def(new_arr,add,win,x);
        delete[]new_arr;
        new_arr = nullptr;
        return next;
    }

    else if(x==4){
        int *new_arr = copy_arr(arr);
        int ind = blank_ind(arr);
        new_arr[ind] = new_arr[ind+3];
        new_arr[ind+3]=0;
        stk* next = def(new_arr,add,win,x);
        delete[]new_arr;
        new_arr = nullptr;
        return next;
    }

    return nullptr;
}

void win_case(metadata *obj){

    int steps{};

    while(obj->par_add != nullptr){

        ++steps;

        std::cout<<"_______"<<std::endl;

        for(int j=0;j<3;++j){
            for (int i=3*j;i<3*j+3;++i){
                if (obj->curr_state[i]==0){
                    std::cout<<"| ";
                }
                else{
                    std::cout<<"|"<<obj->curr_state[i];
                }
            }
        std::cout<<"|"<<std::endl;
        }
        std::cout<<"-------"<<std::endl;

        obj=obj->par_add;
    }

    std::cout<<"_______"<<std::endl;

    for(int j=0;j<3;++j){
        for (int i=3*j;i<3*j+3;++i){
            if (obj->curr_state[i]==0){
                std::cout<<"| ";
            }
            else{
                std::cout<<"|"<<obj->curr_state[i];
            }
        }
    std::cout<<"|"<<std::endl;
    }
    std::cout<<"-------"<<std::endl;

    std::cout<<" Total number of steps taken : "<<steps+1<<std::endl;

    exit(0);
}
