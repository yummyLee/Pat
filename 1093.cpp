//
// Created by qq985 on 2017/4/10.
//
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char chars[100100];
    scanf("%s", chars);

    long long pCount = 0;
    long long tCount = 0;
    long long mod = 1000000007;
    int len = strlen(chars);
    bool stop = false;
    bool isAFound = false;
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (chars[i] == 'P' && !stop) {
            pCount++;
        } else if (chars[i] == 'A' && !isAFound) {
            stop = true;
            isAFound = true;
            index = i;
        } else if (chars[i] == 'T' && stop) {
            tCount++;
            if (tCount == 0) {
                break;
            }
        }
    }

//    printf("index=%d\n", index);
//    printf("p=%d,t=%d\n", pCount, tCount);

    long long patCount = 0;
    if (index == len - 1) {
        printf("%d\n", 0);
    } else {
        patCount += (pCount * tCount);
        patCount %= mod;
        for (int i = index + 1; i < len; i++) {
            if (chars[i] == 'A') {
                patCount += (pCount * tCount);
                patCount %= mod;
            } else if (chars[i] == 'P') {
                pCount++;
            } else if (chars[i] == 'T') {
                tCount--;
            }
//            printf("p=%d,t=%d\n", pCount, tCount);
        }
    }

    printf("%d\n", patCount);

    return 0;
}
