#ifndef puzzle_h
#define puzzle_h

class puzzle{
public:

int rand(int a, int b);

int mat_gen(int arr[]);

void start();

};

int* copy_arr(int arr[]);

int blank_ind(int arr[]);
#endif