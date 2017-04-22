//
// Created by qq985 on 2017/4/19.
//
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {

    char num[110];
    scanf("%s", num);
    int len = strlen(num);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        int temp = num[i] - '0';
        sum += temp;
    }
    char res[110];
    sprintf(res, "%d", sum);
    len = strlen(res);
    for (int j = 0; j < len; ++j) {
        switch (res[j]) {
            case '0':
                printf("ling");
                break;
            case '1':
                printf("yi");
                break;
            case '2':
                printf("er");
                break;
            case '3':
                printf("san");
                break;
            case '4':
                printf("si");
                break;
            case '5':
                printf("wu");
                break;
            case '6':
                printf("liu");
                break;
            case '7':
                printf("qi");
                break;
            case '8':
                printf("ba");
                break;
            case '9':
                printf("jiu");
                break;
            default:
                break;
        }
        if (j!=len-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
}
