//
// Created by qq985 on 2017/4/11.
//
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

struct factor {
    int num;
    int exponent;
};


int primeCount = 0;
int primeList[100010] = {0};

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void findPrime() {
    for (int i = 2; i < 100010; i++) {
        if (isPrime(i)) {
            primeList[primeCount++] = i;
        }
    }
}

int main() {
    findPrime();
    factor fact[10];
    int n;
    int factorCount = 0;
    scanf("%d", &n);
    int sourceN = n;
    if (n == 1) {
        printf("1=");
    } else {
        printf("%d=", n);

        int sqrtN = sqrt(sourceN);
        for (int i = 0; primeList[i] <= sqrtN && i < primeCount; i++) {
            if (n % primeList[i] == 0) {
                int count = 0;
                while (n % primeList[i] == 0) {
                    count++;
//                    printf("nnn=%d\n",n);
                    n /= primeList[i];
                }
                fact[factorCount].num = primeList[i];
                fact[factorCount++].exponent = count;
            }
        }
    }
    if (factorCount > 0) {
//        printf("factorCount=%d\n",factorCount);
        bool pre = false;
        for (int i = 0; i < factorCount; i++) {
            if (pre) {
                printf("*");
            }
            printf("%d", fact[i].num);
            if (fact[i].exponent > 1) {
                printf("^%d", fact[i].exponent);
            }
            pre = true;
        }
        if (n > 1) {
            printf("*%d", n);
        }
    } else {
        printf("%d", sourceN);
    }
    printf("\n");
    return 0;
}
