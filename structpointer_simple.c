# include <stdio.h>
# include <string.h>
struct tag {

    char lname[20];
    char fname[20];
    int age;
    float rate;
};

struct tag my_struct;

void show_name(struct tag *);

int main() {

    struct tag *struct_ptr;
    struct_ptr = &my_struct;
    strcpy(my_struct.lname, "Agarwal");
    strcpy(my_struct.fname, "Ankur");
    my_struct.age = 35;
    my_struct.rate = 9.25;

    printf("In main\n\nFirst name is %s\n", my_struct.fname);
    printf("Last name is %s\n", my_struct.lname);
    printf("Age is %d\n", my_struct.age);
    printf("Rate is %f\n\nDone with main\n\n", my_struct.rate);

    show_name(struct_ptr);

}


void show_name(struct tag * ptr) {

    printf("In function show_name\n\nFirst name is %s\n", ptr->fname);
    printf("Last name is %s\n", ptr->lname);
    printf("Age is %d\n", ptr->age);
    printf("Rate is %f\n\nDone with show_name\n", ptr->rate);

}
