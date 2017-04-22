//
// Created by qq985 on 2017/4/8.
//

#include<iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

bool isPrimeJudge(int resultNum) {
    bool isPrime = true;
    if (resultNum < 2) {
        isPrime = false;
    } else {
        for (int i = 2; i <= sqrt(resultNum); i++) {
            if (resultNum % i == 0) {
                isPrime = false;
            }
        }
    }
    return isPrime;
}

int main() {

    int n, radix;
    while (scanf("%d%d", &n, &radix)) {
        if (n < 0) {
            break;
        }

        bool isPrime=isPrimeJudge(n);
        if(!isPrime){
            printf("No\n");
            continue;
        }

        char nums[50];
        sprintf(nums, "%d", n);
        int len = strlen(nums);
        int maxNumber = 0;
        for (int i = 0; i < len; i++) {
            int temp = nums[i] - '0';
            if (temp > maxNumber) {
                maxNumber = temp;
            }
        }

        char cNums[50] = {'\0'};
        int cLenCount = 0;
//        if (maxNumber > radix - 1) {

        while (n != 0) {
            int quotient = n / radix;
            int modRest = n - quotient * radix;
            cNums[cLenCount++] = modRest + '0';
            n = quotient;
        }
//        } else {
//            for (int i = 0; i < len; i++) {
//                cNums[i] = nums[len - 1 - i];
//            }
//        }

        printf("%s\n", cNums);

        int resultNum = 0;
        int e = 1;
        len = strlen(cNums);
        for (int i = len - 1; i >= 0; i--) {
            int temp = cNums[i] - '0';
            resultNum += (temp * e);
            e *= radix;
//            printf("%d\n",resultNum);
        }



//        sscanf(cNums, "%d", &resultNum);
        printf("resultNum=%d\n", resultNum);

        isPrime = isPrimeJudge(resultNum);


        if (isPrime) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}

