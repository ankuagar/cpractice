#include <stdio.h>


int * add(int, int);



int * add(int a, int b) {

	int c = a + b ; //c is local variable on the stack frame for function add
	return &c; //ERROR: returning address of local variable, which will go out of scope as function returns and stack frame is popped
		       //perhaps will also give compiler WARNING and the executable when run will give Segmentation fault (core dumped)
}


int main() {

	int * ptr = add(2,4);
	printf("The sum is = %d\n", *ptr);

}


