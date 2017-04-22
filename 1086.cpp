//
// Created by qq985 on 2017/4/15.
//
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int nodeNum;
int *pp;
int *pre;
int *in;

stack<int> s;

void output(int firstP, int lastP, int firstI, int lastI) {
    if (firstP > lastP || firstP < 0 || lastP < 0) {
        return;
    } else if (firstP == lastP) {
        s.push(pre[firstP]);
        return;
    }
    int root = pre[firstP];
    s.push(root);
    for (int i = 0; i < nodeNum; i++) {
        if (in[i] == root) {
            int leftRange = i - firstI;
            int rightRange = lastI - i;
            int nextFirstLP = firstP + 1;
            int nextLastLP = firstP + leftRange;
            int nextFirstRP = nextLastLP + 1;
            int nextLastRP = nextFirstRP + rightRange - 1;
            if (rightRange > 0) {
                output(nextFirstRP, nextLastRP, i + 1, i + rightRange);
            }
            if (leftRange > 0) {
                output(nextFirstLP, nextLastLP, i - leftRange, i - 1);
            }
        }
    }
}

int main() {


    scanf("%d", &nodeNum);
    if (nodeNum == 1) {
        printf("%d\n", 1);
        return 0;
    }
    stack<int> input;
    pp = new int[nodeNum];
    pre = new int[nodeNum];
    in = new int[nodeNum];
    int preCount = 0, inCount = 0;
    int len = nodeNum * 2;
//    printf("len=%d\n", len);
    for (int i = 0; i < len; i++) {
        char op[10];
        int num;
        scanf("%s", op);
        if (op[1] == 'u') {
//            printf("push\n");
            scanf("%d", &num);
            input.push(num);
            pre[preCount++] = num;
        } else {
//            printf("pop\n");
            in[inCount++] = input.top();
            input.pop();
        }
    }

//    for (int i = 0; i < nodeNum; i++) {
//        printf("%d ", pre[i]);
//    }
//    printf("\n");
//
//    for (int i = 0; i < nodeNum; i++) {
//        printf("%d ", in[i]);
//    }
//    printf("\n");

    output(0, nodeNum - 1, 0, nodeNum - 1);
    while (1) {
        printf("%d", s.top());
        s.pop();
        if (!s.empty()) {
            printf(" ");
        } else {
            printf("\n");
            break;
        }
    }

    return 0;
}