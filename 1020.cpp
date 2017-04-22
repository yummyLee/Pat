//
// Created by qq985 on 2017/4/14.
//
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int *post;
int *in;
int outputCount = 0;

int main() {

    int n;
    scanf("%d", &n);
    post = new int[n];
    in = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    if (n == 1) {
        printf("%d", in[0]);
        return 0;
    }

//    fun(0, n - 1);

    queue<int> q;
    queue<int> q2;
    q.push(0);
    q.push(n - 1);
    q2.push(0);
    q2.push(n - 1);
    while (!q.empty()) {
        int firstP = q.front();
        q.pop();
        int lastP = q.front();
        q.pop();
        int firstI = q2.front();
        q2.pop();
        int lastI = q2.front();
        q2.pop();

        //printf("PPPPfirst=%d,last=%d\n", firstP, lastP);
        //printf("IIIIfirst=%d,last=%d\n", firstI, lastI);
        int root = post[lastP];
        int rootIndex = 0;
        for (int i = firstI; i <= lastI; i++) {
            if (in[i] == root) {
                rootIndex = i;
                break;
            }
        }
        int rightRange = lastI - rootIndex;
        int leftRange = rootIndex - firstI;
        //printf("rr=%d,lr=%d\n", rightRange, leftRange);
        if (leftRange > 0) {
            q.push(firstP);
            q.push(firstP + leftRange - 1);
            //printf("pushPPP f=%d,l=%d\n", firstP, firstP + leftRange - 1);
            q2.push(firstI);
            q2.push(rootIndex - 1);
            //printf("pushIII f=%d,l=%d\n", firstI, rootIndex - 1);
        }
        if (rightRange > 0) {
            q.push(firstP + leftRange);
            q.push(lastP - 1);
            //printf("pushPPP f=%d,l=%d\n", firstP + leftRange, lastP - 1);
            q2.push(rootIndex + 1);
            q2.push(lastI);
            //printf("pushIII f=%d,l=%d\n", rootIndex + 1, lastI);
        }
        printf("%d", post[lastP]);
        if (++outputCount == n) {
            printf("\n");
            break;
        }else{
            printf(" ");
        }
    }
    return 0;
}
