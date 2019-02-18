#include<stdio.h>

int main() {

    char multi[5][3] = {

        {'a','b','\0'},
        {'d','e','\0'},
        {'g','h','\0'},
        {'j','k','\0'},
        {'m','n','\0'}

    };
    for(int i = 0; i < 5 ; i++){
        printf("multi[%d] is %s\n",i, multi[i]);
    }

}
