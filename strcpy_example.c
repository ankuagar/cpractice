# include <stdio.h>
# include <string.h>
int main() {
    // When using strcpy,  need to assign 1 extra space in dest than the length of the source string to allow space for '\0'
    // So, lname should be minimum 8 in length. Anything less is giving a runtime "Abort trap: 6", which means program is accessing
    // memory it does not own
    char lname[8];
    strcpy(lname, "Agarwal");
    printf("String is %s\n", lname);
    return 0;
}
