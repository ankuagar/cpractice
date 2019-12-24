#include <stdio.h>
#include <malloc.h>

#define NUM_ROWS 5
#define NUM_COLS 10
#define CONSTANT 17

char buffer[100];
void dynamic_allocation_malloc1();
void dynamic_allocation_malloc2();
void dynamic_allocation_malloc3();

int main() {


//    dynamic_allocation_malloc1();
//    dynamic_allocation_malloc2();
    dynamic_allocation_malloc3();
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

void dynamic_allocation_malloc3() {

    int (**ptr)[]; //ptr is a pointer to a pointer to a 1-d integer array
    ptr = malloc(NUM_ROWS * sizeof(int(*)[])); // allocate as many as NUM_ROWS pointers to 1-d int arrays. The memory holds pointers to rows
                                               // assign the first location of the memory block to ptr

    printf("Size of pointer to 1-d int array is = %u\n", sizeof(int (*)[]));
    printf("Size of int is = %u\n", sizeof(int));
 
    printf("Printing addresses of allocated block of pointers to pointer to 1-d int array:\n");
    for(unsigned int i = 0; i < NUM_ROWS; i++) {
        printf("Address %u = %p\n",i,ptr+i);
    } 
    
    //Allocate and assign arrays to all pointers to 1-d arrays
    for(int row=0; row < NUM_ROWS; row++) {  
       ptr[row] = malloc(NUM_COLS * sizeof(int)); //ptr[row] is of type pointer to 1-d array
                                                  //size of 1-d array is NUM_COLS
       //set all int values to 17                                                   
       for(int col=0; col < NUM_COLS; col++) {
            (*ptr[row])[col] = CONSTANT; //ptr[row] contains pointer to 1-d array, *(ptr[row]) gives 1-d array
                                         //(*ptr[row])[col] is of type int. [col] gives element of the array at index col
      }
    }
    
    printf("Printing all addresses:\n");
    for(unsigned int row=0; row < NUM_ROWS; row++) {
        for(unsigned int col = 0; col < NUM_COLS; col++ ) {
            printf("ptr = %p, row = %u, address where pointer to row stored, ptr + row = %p, starting address of row, ptr[row] = %p, address of int # %u (*ptr[row]) + col = %p\n", ptr, row, ptr + row, ptr[row], col, (*ptr[row]) + col); // ptr[row] gives pointer to 1-d array. *ptr[row] gives 1-d array. Both will print address of 0th integer
                                                                 // in that array   
        }
        printf("\n");
    }   
}
