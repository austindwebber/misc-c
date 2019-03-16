#include <stdio.h>
#include <stdlib.h>

int bitDivision(int dividend, int divisor, int originalDivisor, int* remainder) {
    int quotient = 1;

    if (dividend == divisor) { //dividing by same number = 1
        *remainder = 0;
        return 1;
    }

    else if (dividend < divisor) { //dividing by larger number = <1
        *remainder = dividend;
        return 0;
    }

    while (divisor <= dividend) { //shift bits left
        divisor = divisor << 1; 
        quotient = quotient << 1;
    }

    if (dividend < divisor) { //shift bits right
        divisor = divisor >> 1;
        quotient = quotient >> 1;
    }

    quotient = quotient + bitDivision(dividend - divisor, originalDivisor, originalDivisor, remainder); //recursive call

    return quotient;
}

int main(int argc, char* argv[]) {
    int divisor, num;
    char* arg1 = argv[1];
    char* arg2 = argv[2];
    num = atoi(arg1);
    divisor = atoi(arg2);
    int remainder = 0;

    printf("quotient: %d\n", bitDivision(num, divisor, divisor, &remainder));
    printf("remainder: %d\n", remainder);

    return 0;
}
