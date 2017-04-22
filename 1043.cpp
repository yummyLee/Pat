//
// Created by qq985 on 2017/4/13.
//
#include <iostream>
#include<cstdio>
#include <queue>

using namespace std;

queue<int> q;
int judge = 0;

bool isBinary(int a[], int l, int h) {
    if (l >= h) {
        if (l == h) {
//            printf("%d", a[l]);
//            if (l != 0) {
//                printf(" ");
//            }
            q.push(a[l]);
//            printf("11==%d\n", a[l]);
        }
        return true;
    }
    int root = a[l];
    if (a[l + 1] >= root) {

        int mid = h + 1;
        int index = l + 1;
        int preMid = l + 1;
        for (int i = l + 1; i <= h; i++) {
            if (a[i] >= root) {
                index = i;
                preMid = i;
                continue;
            } else {
                mid = i;
                break;
            }
        }

        for (int i = mid; i <= h; i++) {
            if (a[i] < root) {
                index = i;
                if (judge == 1) {
                    return false;
                }
                judge = -1;
                continue;
            } else {
                break;
            }
        }
        if (index != h) {
            return false;
        } else {
            bool isTrue = isBinary(a, l + 1, preMid) && isBinary(a, mid, h);
//            printf("%d", root);
//            if (l != 0) {
//                printf(" ");
//            }else{
//                printf("\n");
//            }
            q.push(a[l]);
//            printf("33==%d\n", a[l]);
            return isTrue;
        }
    } else {
        int mid = h + 1;
        int index = l + 1;
        int preMid = l + 1;
        for (int i = l + 1; i <= h; i++) {
            if (a[i] < root) {
                index = i;
                preMid = i;
                continue;
            } else {
                mid = i;
                break;
            }
        }

        for (int i = mid; i <= h; i++) {
            if (a[i] >= root) {
                index = i;
                if (judge == -1) {
                    return false;
                }
                judge = 1;
                continue;
            } else {
                break;
            }
        }
        if (index != h) {
            return false;
        } else {
            bool isTrue = isBinary(a, l + 1, preMid) && isBinary(a, mid, h);
//            printf("%d", root);
//            if (l != 0) {
//                printf(" ");
//            }else{
//                printf("\n");
//            }
            q.push(a[l]);
//            printf("22==%d\n", a[l]);
            return isTrue;
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);
    int *pre = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }

    if (isBinary(pre, 0, n - 1)) {
        printf("YES\n");
        while (!q.empty()) {
            printf("%d", q.front());
            q.pop();
            if (!q.empty()) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    } else {
        printf("NO\n");
    }


    return 0;
}
