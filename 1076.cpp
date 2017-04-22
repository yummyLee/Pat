//
// Created by qq985 on 2017/4/15.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<int> *graph;
int n, level;
int *isVisited;

set<int> s;

void dfs(int point, int curlevel) {
    printf("point=%d,curlevel=%d\n", point, curlevel);
    if (curlevel > level) {
        return;
    }
    for (vector<int>::iterator i = graph[point].begin(); i != graph[point].end(); i++) {
        if (isVisited[*i] == 0) {
            s.insert(*i);
            isVisited[*i] = 1;
            dfs(*i, curlevel + 1);
            isVisited[*i] = 0;
        }
    }
}

void bfs(int potint) {
    queue<int> q;
    queue<int> levelQueue;
    q.push(potint);
    levelQueue.push(0);
    while (!q.empty()) {
        int p = q.front();
        int curlevel = levelQueue.front();
        q.pop();
        levelQueue.pop();
        for (vector<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++) {
            if (isVisited[*i] == 0 && curlevel < level) {
                isVisited[*i] = 1;
//                printf("p=%d,insert--%d,curlevel=%d\n", p, *i, curlevel);
                s.insert(*i);
                q.push(*i);
                levelQueue.push(curlevel + 1);
            }
        }
    }
}

int main() {

    int queryNum, queryIndex;
    scanf("%d %d", &n, &level);
    n++;
    graph = new vector<int>[n];
    isVisited = new int[n];
    for (int i = 1; i < n; i++) {
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; ++j) {
            int index;
            scanf("%d", &index);
            graph[index].push_back(i);
        }
    }

//    for (int k = 1; k < n; ++k) {
//        vector<int> temp = graph[k];
//        printf("k=%d\n", k);
//        for (vector<int>::iterator m = temp.begin(); m != temp.end(); m++) {
//            printf("%d ", *m);
//        }
//        printf("\n");
//    }

    scanf("%d", &queryNum);
    for (int i = 0; i < queryNum; i++) {
        scanf("%d", &queryIndex);
//        printf("index=%d\n", queryIndex);
        for (int j = 1; j < n; j++) {
            isVisited[j] = 0;
        }
        isVisited[queryIndex] = 1;

        s.clear();
        bfs(queryIndex);
//        for (set<int>::iterator j = s.begin(); j != s.end(); j++) {
//            printf("%d", *j);
//        }
//        printf("\n");
        s.erase(queryIndex);
        printf("%d\n", s.size());
    }

    return 0;
}