//
// Created by qq985 on 2017/4/19.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char chars[110];
int len;

bool isPAT(char c) {
    if (c == 'P' || c == 'A' || c == 'T') {
        return true;
    } else {
        return false;
    }
}

int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", chars);
        len = strlen(chars);
        bool isTrue = true;
        int pIndex = -1;
        for (int j = 0; j < len; ++j) {
            if (!isPAT(chars[j])) {
                isTrue = false;
                break;
            }
            if (chars[j] == 'T') {
                isTrue = false;
                break;
            }
            if (chars[j] == 'P') {
                pIndex = j;
                break;
            }
        }
        if (pIndex == -1 || !isTrue) {
            printf("NO\n");
            continue;
        }
        int preA = pIndex;
        int aCount = 0;
        int tIndex = -1;
        for (int k = pIndex + 1; k < len; ++k) {
            if (!isPAT(chars[k])) {
                isTrue = false;
                break;
            }
            if (chars[k] == 'P') {
                isTrue = false;
                break;
            }
            if (chars[k] == 'T') {
                tIndex = k;
                break;
            }
        }
        if (tIndex == -1 || !isTrue) {
            printf("NO\n");
            continue;
        }
        int inA = tIndex - pIndex - 1;
        if (inA < 1) {
            printf("NO\n");
            continue;
        }
        for (int l = tIndex + 1; l < len; ++l) {
            if (chars[l] != 'A') {
                isTrue = false;
                break;
            }
        }
        if (!isTrue) {
            printf("NO\n");
            continue;
        }
        int postA = len - 1 - tIndex;
//        printf("preA=%d,inA=%d,postA=%d\n", preA, inA, postA);
        if (postA < ((inA - 1) * preA + preA)) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}