#include <stdio.h>

# define NUM_ONE_DIM_ELEMS 5
# define NUM_TWO_DIM_ROWS 3
# define NUM_TWO_DIM_COLS 5

void iterate_one_dim(int[]);
void iterate_one_dim1(int *);
void iterate_two_dim(int[][NUM_TWO_DIM_COLS]);
void iterate_two_dim1(int (*)[NUM_TWO_DIM_COLS]);
void iterate_two_dim2(int *);
void iterate_two_dim3(int (*)[][NUM_TWO_DIM_COLS]); // pointer to two dimensional array
void iterate_two_dim4(int (*)[][NUM_TWO_DIM_COLS]) ; // pointer to two dimensional array

int main() {

    int one_dim[] = {1,2,3,4,5};
    int two_dim[][NUM_TWO_DIM_COLS] = { //note the second dimension needs to be specified to resolve expression like two_dim[1]
                        {1,2,3,4,5},    // second dimension tells how many integers to move the two_dim pointer
                        {6,7,8,9,10},
                        {11,12,13,14,15}
                    };
    iterate_one_dim(one_dim);
    iterate_one_dim1(one_dim);

    iterate_two_dim(two_dim);
    iterate_two_dim1(two_dim);
    iterate_two_dim2(*two_dim);
    iterate_two_dim3(&two_dim);
    iterate_two_dim4(&two_dim);

    //Of course all addresses are numerically identical because the address of a composite type is the address of its first element, a rule which applies recursively, so that (size_t)&two_dim == (size_t)two_dim && (size_t)two_dim == (size_t)*two_dim. The difference is in the types.)
    //See https://stackoverflow.com/questions/54759781/passing-a-2-d-array-to-a-function/54762218#54762218
    printf("Value of two_dim is : %p\n", two_dim);
    printf("Address of 2-d array (&two_dim) is : %p\n", &two_dim);
    printf("Address of very 1st integer (&two_dim[0][0], same as *two_dim) in two_dim is : %p\n", *two_dim);

}

void iterate_one_dim(int one_dim[]) { //function parameter uses array notation
    printf("One dim array passed using array notation\n" );
    for(int i = 0; i < NUM_ONE_DIM_ELEMS; i++) {

        printf("one_dim[%d] is %d\n", i, one_dim[i] );
    }
    printf("\n");
}
void iterate_one_dim1(int * one_dim1) { //function parameter uses pointer notation
    printf("One dim array passed using pointer notation\n");

    for(int i = 0; i < NUM_ONE_DIM_ELEMS; i++) {

        printf("one_dim1[%d] is %d\n", i, one_dim1[i] );
    }
    printf("\n");

}

void iterate_two_dim(int two_dim[][NUM_TWO_DIM_COLS]) { //function parameter uses array notation
    printf("Two dim array passed using array notation\n" );
    for(int row = 0; row < NUM_TWO_DIM_ROWS; row++) {
        for(int col = 0; col < NUM_TWO_DIM_COLS; col++) {
            printf("two_dim[%d][%d] = %-4d  ", row,col, two_dim[row][col] );
        }
        printf("\n");
    }
    printf("\n");
}

void iterate_two_dim1(int (*two_dim)[NUM_TWO_DIM_COLS]) { //function parameter uses pointer notation
    printf("Two dim array passed using pointer notation\n" );
    for(int row = 0; row < NUM_TWO_DIM_ROWS; row++) {
        for(int col = 0; col < NUM_TWO_DIM_COLS; col++) {
            printf("two_dim[%d][%d] = %-4d  ", row,col, two_dim[row][col] );
        }
        printf("\n");
    }
    printf("\n");
}

void iterate_two_dim2(int *two_dim) { //function parameter uses pointer notation
    printf("Two dim array passed using pointer notation, address of 1st element in 1st array sent\n" );
    char buffer[100];
    for(int count = 0; count < NUM_TWO_DIM_ROWS*NUM_TWO_DIM_COLS; count++) {
            if(count > 0 && count % NUM_TWO_DIM_COLS == 0 )
                printf("\n");
            snprintf(buffer, 40, "two_dim[%d] = %2d", count, two_dim[count] );
            printf("%-20s", buffer );
        }
        printf("\n\n");
}


void iterate_two_dim3(int (*two_dim)[][NUM_TWO_DIM_COLS]) {
    printf("Two dim array sent using address of 2-d array, skipping num rows in parameter\n");
    for(int row = 0 ; row < NUM_TWO_DIM_ROWS; row++) {
        for(int col = 0 ; col < NUM_TWO_DIM_COLS; col++) {
            printf("(*two_dim)[%d][%d] = %-4d  ", row,col, (*two_dim)[row][col] );
        }
        printf("\n");
    }
    printf("\n");

}

void iterate_two_dim4(int (*two_dim)[NUM_TWO_DIM_ROWS][NUM_TWO_DIM_COLS]) {
    printf("Two dim array sent using address of 2-d array, specifying num rows in parameter, since we use sizeof operator\n");
    //num rows are needed in parameter because sizeof operator needs to compute the size of entire 2-d array
    size_t rows = sizeof(*two_dim)/sizeof((*two_dim)[0]); // size of entire 2d array divided by size of 1st row
    size_t cols = sizeof((*two_dim)[0])/sizeof((*two_dim)[0][0]); // size of of first row divided by size of 1st elem of 1st row
    for(size_t row = 0 ; row < rows; row++) {
        for(size_t col = 0 ; col < cols; col++) {
            printf("(*two_dim)[%lu][%lu] = %-4d  ", row,col, (*two_dim)[row][col] );
        }
        printf("\n");
    }
    printf("\n");

}
