#ifndef algo_h
#define algo_h

class metadata{
public:

int res_move{};

int curr_state[9]{};
metadata *par_add{nullptr};

metadata();

metadata(int temp_memo);

};

class stk{
public:

metadata *nod_add {nullptr};
stk *ptr{nullptr};
};

stk* def(int *arr, metadata *add, int win[], int move);

stk* int_def(int ini_state[], int win[]);

void real_deal(int arr[], int win[]);

stk* cal(int x, int arr[], metadata *add, int win[]);

void win_case(metadata *obj);

#endif