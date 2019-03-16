#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isNumeric(char num[]) {
    int i = 1;
    if (!isdigit(num[0]) && num[0] != '-'){
	return 0;
    }
    while (num[i] != '\0') {
        if (!isdigit(num[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int argc, char* argv[])
{
    if( argc < 4 ) {
        fprintf(stderr, "Usage: calc value1 value2 operator\n");
        return 1;
    }
    int test, num1, num2;
    char* arg1 = argv[1];
    char* arg2 = argv[2];
    char* arg3 = argv[3];
    num1 = atoi(arg1);
    num2 = atoi(arg2);
    char op = *arg3;

    int result1 = isNumeric(arg1);
    int result2 = isNumeric(arg2);

    if(result1 == 0 || result2 == 0) {
        fprintf(stderr, "calc error: operands must be integers!\n");
        return 2;
    }
    else {
        switch(op) {
            case '+':
                printf ("%d\n", num1 + num2);
                break;
            case '-':  
                printf("%d\n", num1 - num2);
                break;
            case '/':  
                printf("%d\n", num1 / num2);
                break;
            case '%':  
                printf("%d\n", num1 % num2);
                break;
            case 'x':  
                printf("%d\n", num1 * num2);
                break;
            default:
                fprintf(stderr, "calc error: invalid operator!\n");
                return 1;
                break;
        }
    }
    return 0;
}

