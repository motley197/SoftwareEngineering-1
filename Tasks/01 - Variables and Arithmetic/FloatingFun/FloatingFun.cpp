#include <iostream>

int main()
{
    // float 
    float pi_float = 3.14159265358979323846;
    printf("The value of pi is approximately %f\n", pi_float);

    // double
    double pi_double = 3.14159265358979323846L;
    printf("The value of pi is approximately %.12lf\n", pi_double);

    // char
    char c = 65;
    printf("c has the value %d and is the %c character\n\n", c, c);

    printf("Size of a float is %zd bytes\n", sizeof(float));
    printf("Size of a double is %zd bytes\n", sizeof(double));
    printf("Size of a char is %zd bytes\n", sizeof(char));
}


