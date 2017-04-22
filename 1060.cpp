//
// Created by qq985 on 2017/4/11.
//
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int findPoint(char num[120]) {
    int len = strlen(num);
    int res = len;
    for (int i = 0; i < len; i++) {
        if (num[i] == '.') {
            res = i;
            break;
        }
    }
    return res;
}

void outputRes(char num1[120], int numOfSig, int pointPosition1, char res1[120]) {
    int len1 = strlen(num1);
    int startIndex1 = pointPosition1;
    for (int i = 0; i < pointPosition1; i++) {
        if (num1[i] != '0') {
            startIndex1 = i;
            break;
        }
    }
    res1[0] = '0';
    res1[1] = '.';
    res1[2 + numOfSig] = '*';
    res1[3 + numOfSig] = '1';
    res1[4 + numOfSig] = '0';
    res1[5 + numOfSig] = '^';

    int index1 = startIndex1;
    bool isStart = false;
    for (int i = 0; i < numOfSig;) {

        if (index1 >= len1) {
            res1[2 + i] = '0';
            i++;
        } else {
            if (num1[index1] != '0' && num1[index1] != '.' && !isStart) {
                res1[2 + i] = num1[index1];
                startIndex1 = index1;
//                printf("startchar=%c\n",num1[index1]);
//                printf("startindex=%d\n",i);
                isStart = true;
                i++;
            } else if (isStart && num1[index1] != '.') {
                res1[2 + i] = num1[index1];
                i++;
            }
        }
        index1++;
    }
    char *expChar = new char[101];
    int exp1 = pointPosition1 - startIndex1;
    if (exp1 < 0) {
        exp1++;
    }
    sprintf(expChar, "%d", exp1);

    int exp1len = strlen(expChar);
    for (int i = 0; i < exp1len; i++) {
        res1[6 + numOfSig + i] = expChar[i];
    }
    res1[6 + numOfSig + exp1len] = '\0';
}

int main() {

    int numOfSig;
    char num1[120];
    char num2[120];
    scanf("%d%s%s", &numOfSig, num1, num2);
    int pointPosition1 = findPoint(num1);
    int pointPosition2 = findPoint(num2);

    char res1[120];
    char res2[120];
    outputRes(num1, numOfSig, pointPosition1, res1);
    outputRes(num2, numOfSig, pointPosition2, res2);
    if (strcmp(res1, res2) == 0) {
        printf("YES %s\n", res1);
    } else {
        printf("NO %s %s\n", res1, res2);
    }
    return 0;
}
