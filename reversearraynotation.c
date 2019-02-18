# include <stdio.h>

int main(){

    int arr[] = {1,2,3,4,5};

    printf("Originally arr[%d] = %d\n", 2, arr[2]);

    arr[2] = 2*2 ; // assignment using array notation

    printf("After assignment using array notaion arr[2] = %d\n", arr[2]);

    2[arr] = 2*2*2; // assignment using reverse array notation

    printf("After assignment using reverse array notaion 2[arr] = %d\n", arr[2]);


    return 0;
}
