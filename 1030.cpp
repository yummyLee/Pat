//
// Created by qq985 on 2017/4/16.
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

struct node {
    int index;
    int distance;
    int cost;

    node(int pIndex, int pDistance, int pCost) {
        index = pIndex;
        distance = pDistance;
        cost = pCost;
    }
};

const int MAXW = 25000000;
int N, M, S, D;
int **weight;
int **cost;
int *curWeight;
int *curCost;
bool *isVisited;
int *pre;

int main() {

    scanf("%d%d%d%d", &N, &M, &S, &D);
    weight = new int *[N];
    cost = new int *[N];
    curWeight = new int[N];
    curCost = new int[N];
    isVisited = new bool[N];
    pre = new int[N];
    for (int i = 0; i < N; i++) {
        weight[i] = new int[N];
        cost[i] = new int[N];
        curCost[i] = MAXW;
        curWeight[i] = MAXW;
        isVisited[i] = false;
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            weight[k][i] = MAXW;
        }
    }
    for (int i = 0; i < M; i++) {
        int p1, p2, iDis, iCost;
        scanf("%d%d%d%d", &p1, &p2, &iDis, &iCost);
        weight[p1][p2] = iDis;
        weight[p2][p1] = iDis;
        cost[p1][p2] = iCost;
        cost[p2][p1] = iCost;
    }

//    for (int k = 0; k < N; ++k) {
//        for (int i = 0; i < N; ++i) {
//            printf("%d ", weight[k][i]);
//        }
//        printf("\n");
//    }

    curWeight[S] = 0;
    curCost[S] = 0;
    pre[S] = -1;

    for (int i = 0; i < N; i++) {

        int u = -1;
        int min = MAXW;
//        for (int j = 0; j < N; j++) {
//            printf("%d ", curWeight[j]);
//        }
//        printf("\n");

        for (int j = 0; j < N; j++) {
            if (!isVisited[j] && curWeight[j] < min) {
                min = curWeight[j];
                u = j;
            }
        }

//        printf("u=%d\n", u);
        if (u == -1) {
            break;
        }

        isVisited[u] = true;

        for (int j = 0; j < N; j++) {
            if (!isVisited[j] && weight[u][j] != MAXW) {
                if (curWeight[j] > curWeight[u] + weight[u][j]) {
                    curWeight[j] = curWeight[u] + weight[u][j];
                    curCost[j] = curCost[u] + cost[u][j];
                    pre[j] = u;
                } else if (curWeight[j] == curWeight[u] + weight[u][j]) {
                    if (curCost[j] > curCost[u] + cost[u][j]) {
                        curCost[j] = curCost[u] + cost[u][j];
                        pre[j] = u;
                    }
                }
            }
        }
    }

    stack<int> s;
    int point = D;
    while (point != -1) {
        s.push(point);
        point = pre[point];
    }

    while (!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }

    printf("%d %d\n", curWeight[D], curCost[D]);

    return 0;
}