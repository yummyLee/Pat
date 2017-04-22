#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int *circle;
int n;
int m;

int main() {

    scanf("%d", &n);
    circle = new int[n + 1];
    int sum = 0;
    circle[0] = 0;
    for (int i = 1; i <= n; i++) {
        int len;
        scanf("%d", &len);
        sum += len;
        circle[i] = sum;
    }
    int queryCount;
    scanf("%d", &queryCount);

//    for(int i=0;i<=n;i++){
//        printf("%d ",circle[i]);
//    }
//    printf("\n");
//    printf("sum=%d\n",sum);
    for (int i = 0; i < queryCount; i++) {
        int s, d;
        scanf("%d%d", &s, &d);
        if (s > d) {
            int temp = s;
            s = d;
            d = temp;
        }
        int res = min(circle[d - 1] - circle[s - 1], sum - (circle[d - 1] - circle[s - 1]));
//        printf("circle-diff=%d\n",circle[d-1]-circle[s-1]);
        printf("%d\n", res);
    }
    return 0;
}

