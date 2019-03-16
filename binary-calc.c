#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binAdd(int num1[], int num2[], int* result) {
        int carry = 0;
        int test;
        for (int i = 7; i >= 0; i--) {
                test = num1[i] + num2[i] + carry;
                if (test > 2) {
                        result[i] = 1;
                        carry = 1;
                }

                else if (test == 2) {
                        result[i] = 0;
                        carry = 1;
                }

                else if (test == 1) {
                        result[i] = 1;
                        carry = 0;
                }
                else if (test == 0) {
                        result[i] = 0;
                        carry = 0;
                }
        }
        return 0;
}

int binSub(int num1[], int num2[], int* result) {
        int temp[8] = {0};
        for (int i = 0; i < 8; i++){
                if (num2[i] == 0) {
                        temp[i] = 1;
                }
		else {
                        temp[i] = 0;
                }
        }
        int one[8] = {0, 0, 0, 0, 0, 0, 0, 1};
        int arr1[8] = {0};
        int arr2[8] = {0};

        binAdd(temp, one, arr1);        
        binAdd(arr1, num1, result);
        return 0;
}
int main(int argc, char* argv[]) {

        char* arg1 = argv[1];
        char* arg2 = argv[2];
        char* arg3 = argv[3];
        char op = *arg3;
        int num1[8];
	int num2[8];
	int result[8] = {0};
	int temp = 0;
	int temp2 = 0;

        for (int i = 0; i < 8; i++) {
                num1[i] = arg1[i] - '0';
                num2[i] = arg2[i] - '0';
        }
	if (op == '+') {
                int res = binAdd(num1, num2, result);
                for (int i = 0;i <= 7; i++) {
                        if (num1[i] == 1) {
                                temp++;
                        }
			if (num2[i] == 1) {
				temp++;
			}
                }
                if (result[0] != 1 || temp < 8) {
                for (int i =0; i <=7; i ++) {
                                printf("%d", result[i]);
                        }
                        printf("\n");
                        return 0;
                }
                else {
                        fprintf(stderr, "Overflow error!");
                        return 1;
                }
        }
        if (op == '-') {
                int res = binSub(num1, num2, result);
                for (int i = 0;i <= 7; i++) {
                        if (num1[i] == 1) {
                                temp++;
                        }
                        if (num2[i] == 1) {
                                temp2++;
                        }
                }
                if ((res == 0 && temp != temp2) || (res == 0 && (temp + temp2) == 16)) {
                        for (int i =0; i <=7; i ++) {
                                printf("%d", result[i]);
                        }
                        printf("\n");
                        return 0;
                }
                else {
                        fprintf(stderr, "Underflow error!");
                        return 1;
                }

        }
}

