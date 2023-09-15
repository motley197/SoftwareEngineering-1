#include <stdio.h>

//This is a 128-bit constant - specified in hex
const long long NN = 0x12345678ABCD0001LL;

int main()
{ 
	printf("Size of variable types\n\n");
	
    // Integer
    int count = 0;
    printf("count = %d\n", count);

    // Add one to count
    count = count + 1;
    printf("New value of count = %d\n", count);

    // Char
    char character;
    character = 'A';
    printf("The character %c has the ASCII code %d\n", character, character);

    // Short
    short shortCount = 32767;
    printf("The value of shortCount is %hd\n", shortCount);
    shortCount = shortCount + 1;
    printf("add 1 and shortCount is %hd\n", shortCount);

    // Long long
    printf("A very large number %lld\n", NN);
    printf("A very large number in hex %llX\n", NN);

    // float 
    float pi_float = 3.14159265358979323846;
    printf("The value of pi is approximately %f\n", pi_float);

    // double
    double pi_double = 3.14159265358979323846L;
    printf("The value of pi is approximately %.12lf\n", pi_double);

    // Data type sizes (in bytes)
    printf("Size of a char is %zd bytes\n", sizeof(char));
    printf("Size of a short is %zd bytes\n", sizeof(short));
    printf("Size of a int is %zd bytes\n", sizeof(int));
    printf("Size of a long is %zd bytes\n", sizeof(long));
    printf("Size of a long long is %zd bytes\n", sizeof(long long));
    printf("Size of a float is %zd bytes\n", sizeof(float));
    printf("Size of a double is %zd bytes\n", sizeof(double));

    // Stop
    while (true);

	// TASK: Run the program and observe the output on the terminal 
	//       Change some of the values and again observe the output.


} 