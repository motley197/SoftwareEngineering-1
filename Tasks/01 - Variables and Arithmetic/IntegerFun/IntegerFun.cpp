#include <iostream>

int main()
{
    unsigned short width = 32000, length = 32000; 
    unsigned int area = width * length;
    printf("width = %d , length = %d , area = %d\n", width, length, area);
    printf("Size of a int is %zd bytes\n", sizeof(int));
    printf("Size of a short is %zd bytes\n", sizeof(short));
    printf("Size of a long is %zd bytes\n", sizeof(long));
    printf("Size of a long long is %zd bytes\n", sizeof(long long));
}
