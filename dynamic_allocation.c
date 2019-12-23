#include <stdio.h>
#include <malloc.h>

#define NUM_ROWS 5
#define NUM_COLS 10
#define CONSTANT 17

char buffer[100];
void dynamic_allocation_malloc1();
void dynamic_allocation_malloc2();

int main() {


    dynamic_allocation_malloc1();
    dynamic_allocation_malloc2();

}



void dynamic_allocation_malloc1() {

    int (*ptr)[NUM_COLS]; //ptr is a pointer to 1-d array of 10 integers (use Right left rule to decipher)
    ptr = malloc(NUM_ROWS * NUM_COLS * sizeof(int)); // allocate memory

    //initialize all memory locations to CONSTANT
    for(int i = 0 ; i < NUM_ROWS; i++) 
        for(int j = 0 ; j < NUM_COLS; j++)
            ptr[i][j] = CONSTANT; // IMP: since ptr is a pointer to 1-d array of 10 integers, 
                                  // ptr + 1 will advance by 10 integers, ptr + 2 will advance
                                  // by 20 integers etc
    printf("Printing from %s\n", __func__);
    //print all memory locations
    for(int i = 0 ; i < NUM_ROWS; i++)  {
        for(int j = 0 ; j < NUM_COLS; j++) {
            snprintf(buffer, 40, "ptr[%d][%d] = %d ", i,j,ptr[i][j]);
            printf("%-20s", buffer );
        }
        printf("\n");
    }
            

}

void dynamic_allocation_malloc2() {

    int *ptr; //ptr is a pointer to an int
    ptr = malloc(NUM_ROWS * NUM_COLS * sizeof(int)); // allocate memory

    //initialize all memory locations to CONSTANT
    for(int i = 0 ; i < NUM_ROWS * NUM_COLS; i++)
            ptr[i] = CONSTANT; // IMP: since ptr is a pointer an int, ptr + 1 will advance by 1 int,
                               //ptr + 2 will advance by 2 ints, etc
    printf("Printing from %s\n", __func__);
    //print all memory locations
    for(int i = 0 ; i < NUM_ROWS * NUM_COLS; i++) {
            if(i > 0 && i % 10 == 0)
                printf("\n");
            snprintf(buffer, 40, "ptr[%d] = %2d", i, ptr[i] );
            printf("%-20s", buffer );
    }
    printf("\n");
}
