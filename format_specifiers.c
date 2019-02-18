# include <stdio.h>
# include <wchar.h>
# include <stddef.h>
//Reference:
//http://www.cplusplus.com/reference/cstdio/printf/
//https://en.cppreference.com/w/cpp/io/c/fprintf

int main() {

    printf("%%\n");

    //For %c
    printf("%c\n", 97);
    printf("%-4c\n", 97); //left justified in with 4
    //printf("%+c\n", 97); //flag '+' results in undefined behavior with 'c' conversion specifier
    //printf("% c\n", 97); //flag ' ' results in undefined behavior with 'c' conversion specifier
    //printf("%0.4c\n", 97); //precision used with 'c' conversion specifier, resulting in undefined behavior
                           //flag '0' results in undefined behavior with 'c' conversion specifier
    wint_t wint =   97;
    printf("%lc\n", wint); //length sub-specifier 'l' used with %c
    printf("%4lc\n", wint); //right justified, width 4

    //For %s
    printf("%s\n", "This is a string");
    printf("%20s\n", "This is a string"); //right justified in width 20
    //printf("%+20s\n", "This is a string"); //right justified in width 20
                                           // flag '+' results in undefined behavior with 's' conversion specifier
    //printf("% s\n", "This is a string"); //flag ' ' results in undefined behavior with 's' conversion specifier
    //printf("%#20s\n", "This is a string"); //flag '#' results in undefined behavior with 's' conversion specifier
    //printf("%020s\n", "This is a string"); //flag '0' results in undefined behavior with 's' conversion specifier
                                           // but the string is padded with 0s
     printf("%20.9s\n", "This is a string"); //right justified by default, print 9 chars max in a width of 20
     printf("%-20.9s\n", "This is a string"); //left justified, print 9 chars max in a width of 20
     //printf("%020.9s\n", "This is a string"); //flag '0' results in undefined behavior with 's' conversion specifier
                                               // but the right(by default) justified string, has 9 chars printed, occupies a width of 20 // and is padded with 0s on the left
     wchar_t *wchar = L"This is a wchar string"; // string literal starts with 'L'
     printf("%ls\n", wchar);
     printf("%40ls\n", wchar); //right justified by default in width 40
     //printf("%+40ls\n", wchar); //right justified in width 40
                                // flag '+' results in undefined behavior with 's' conversion specifier
     //printf("% ls\n", wchar); //flag ' ' results in undefined behavior with 's' conversion specifier
     //printf("%#40ls\n", wchar); //flag '#' results in undefined behavior with 's' conversion specifier
     //printf("%040ls\n", wchar); //flag '0' results in undefined behavior with 's' conversion specifier
                                 // but the string is padded with 0s
     printf("%40.20ls\n", wchar); // right justified by default, print 20 chars max in a width of 40
     printf("%-40.20ls\n", wchar); // left justified, print 20 chars max in a width of 40
     //printf("%040.20ls\n", wchar); //flag '0' results in undefined behavior with 's' conversion specifier, but the right(by default) justified string, has 20 chars printed, occupies a width of 40 and is padded with 0s on the left

     // For %d or %i

     int i = 54;
     printf("%d\n", i); // print with %d, right justified by default
     printf("%i\n", i); // print with %i, right justified by default
     printf("%10i\n", i); // print with %i, right justified by default in a width of 10 spaces
     printf("%-10i\n", i); // print with %i, left justified in a width of 10 spaces
     printf("%-+10i\n", i); // print with %i, left justified in a width of 10 spaces, with a leading positive sign
     printf("% -10i\n", i); // print with %i, left justified in a width of 10 spaces, use a blank space before the value, if no sign is going to be written
     printf("% 10i\n", i); // print with %i, right justified (by default) in a width of 10 spaces, use a blank space before the value, if no sign is going to be written
     printf("%+10i\n", i); // print with %i, right justified (by default) in a width of 10 spaces, with a leading positive sign
     printf("%+010i\n", i); // print with %i, right justified (by default) in a width of 10 spaces, use a leading positive sign for positive number, left pad with 0s
     //printf("%+#10i\n", i); //flag '#' results in undefined behavior with 'i' conversion specifier, simply ignores #

     //For %o
     unsigned int unsigned_int = 34;
     printf("%10.4o\n",unsigned_int); //in a width of 10, write minimum 4 digits, since the value to be written is shorter than 4, the result is padded with leading zeros, right justified (by default)
     printf("%#10o\n",unsigned_int); //in a width of 10, precede the value with a 0, right justified (by default)

     unsigned char unsigned_char = 'A';
     printf("%10.2hho\n",unsigned_char); //in a width of 10, write minimum 2 digits, even though the value to be written is larger than 2 spaces, it is not truncated, also it is not padded with leading zero. right justified by default

     printf("%10.4hho\n",unsigned_char); //in a width of 10, write minimum 4 digits, since the value to be written is smaller than 4 spaces, it is  padded with leading zero. right justified by default

     ptrdiff_t ptr_diff = 10;
     printf("%10.4to\n", ptr_diff); //in a width of 10, write minimum 4 digits, since the value to be written is smaller than 4 spaces, it is padded with leading zero. right justified by default

     printf("%#10to\n", ptr_diff); //in a width of 10, right justified by default. it is padded with one leading zero due to # flag

     printf("%010to\n", ptr_diff); //in a width of 10, right justified by default. it is padded with leading zeros due to 0 flag

     double dbl = 3.247;

     printf("%0+15.9f\n", dbl); //in a width of 15, print 9 digits after decimal point. due to + flag, introduce a positive sign for the positive number, right justified by default, left pads with 0 due to 0 flag

     printf("%+-15.9f\n", dbl); //in a width of 15, print 9 digits after decimal point. due to + flag, introduce a positive sign for the positive number, left justified due to - flag

     double dbl1 = 3;
     printf("%0+15.9F\n", dbl1); //in a width of 15, print 9 digits after decimal point. due to + flag, introduce a positive sign for the positive number, right justified by default, left pads with 0 due to 0 flag

     printf("%+-15.9F\n", dbl1); //in a width of 15, print 9 digits after decimal point. due to + flag, introduce a positive sign for the positive number, left justified due to - flag

     printf("%+#15.0F\n", dbl1); //in a width of 15, print 0 digits after decimal point due to 0 precision. due to + flag, introduce a positive sign for the positive number, right justified by default. the # flag forces the written output to contain a decimal point even though no digits follow

     // For %e

     double dbl2 = 34.7562;
     printf("%0+20.9e\n", dbl2); //in a width of 20, print 9 digits after decimal point. due to + flag, introduce a positive sign for the positive number, right justified by default, left pads with 0 due to 0 flag

     printf("%+-20.9e\n", dbl2); //in a width of 20, print 9 digits after decimal point. due to + flag, introduce a positive sign for the positive number, left justified due to - flag

     printf("%+#20.0e\n", dbl2); //in a width of 20, print 0 digits after decimal point due to 0 precision. due to + flag, introduce a positive sign for the positive number, right justified by default. the # flag forces the written output to contain a decimal point even though no digits follow

     printf("%+20.0e\n", dbl2); //in a width of 20, print 0 digits after decimal point due to 0 precision. due to + flag, introduce a positive sign for the positive number, right justified by default.

}
