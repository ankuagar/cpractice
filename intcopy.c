# include <stdio.h>

void int_copy(int * , int * , int );
int main(void) {

	int arr_source[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int count = sizeof(arr_source)/sizeof(int);
	printf("Size of source array: %lu\n", sizeof(arr_source));
	int arr_dest[count];

	int_copy(arr_dest, arr_source, count);

	for(int i = 0; i < count ; i++) {

		printf("Value at %d = %d\n", i, *(arr_dest + i));

	}

	return 0;
}

void int_copy(int * dest, int * source, int count) {

	for(int i = 0; i < count ; i++) {

		*(dest + i) = *(source + i);

	}

}
