//
// Created by qq985 on 2017/4/15.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct node {
    string head;
    int size;
};

int **graph;
map<string, int> intMap;
map<int, string> strMap;
int *weights;
int *isVisited;
int n, given;
vector<int> hang;
int curHangWeight;
vector<vector<int>> hangs;
vector<node> heads;
int intIndex = 0;


//void dfs(int point) {
//    for (int i = 0; i < 2 * n; i++) {
//        if (graph[point][i] > 0) {
//            curHangWeight += graph[point][i];
//            graph[point][i] = 0;
//            hang.push_back(i);
//            dfs(i);
//            dfs(point);
//        }
//        if (graph[i][point] > 0) {
//            curHangWeight += graph[i][point];
//            graph[i][point] = 0;
//            hang.push_back(i);
//            dfs(i);
//            dfs(point);
//        }
//    }
//}

void dfs(int point) {
//    printf("point=%d\n", point);
    for (int i = 0; i < intIndex; i++) {
        if (isVisited[i] == 0 && graph[i][point] > 0) {
            curHangWeight += graph[i][point];
            graph[i][point] = 0;
            graph[point][i] = 0;
//            printf("i=%d,curWeight=%d\n", i, curHangWeight);
            isVisited[i] = 1;
            dfs(i);
            isVisited[i] = 0;
            hang.push_back(i);
        }
    }
}

bool cmp(int a, int b) {
    return weights[a] > weights[b];
}

bool cmp2(node a, node b) {
    return a.head < b.head;
}

int main() {

    scanf("%d %d", &n, &given);
//    printf("%d %d\n", n, given);
    graph = new int *[n * 2];
    isVisited = new int[n * 2];
    weights = new int[n * 2];
    for (int i = 0; i < n * 2; i++) {
        graph[i] = new int[n * 2]{0};
        isVisited[i] = 0;
        weights[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        string a, b;
        int t;
        cin >> a >> b;
        scanf("%d", &t);
        int aIndex, bIndex;
//        printf("%s %s %d\n", a.c_str(), b.c_str(), t);
        if (intMap.find(a) == intMap.end()) {
            aIndex = intIndex++;
            intMap[a] = aIndex;
            strMap[aIndex] = a;
        } else {
            aIndex = intMap[a];
            strMap[aIndex] = a;
        }
        if (intMap.find(b) == intMap.end()) {
            bIndex = intIndex++;
            intMap[b] = bIndex;
            strMap[bIndex] = b;
        } else {
            bIndex = intMap[b];
            strMap[bIndex] = b;
        }
        weights[aIndex] += t;
        weights[bIndex] += t;
        graph[aIndex][bIndex] += t;
        graph[bIndex][aIndex] += t;
    }

//    for (int j = 0; j < 2 * n; ++j) {
//        for (int i = 0; i < 2 * n; ++i) {
//            printf("%02d ", graph[i][j]);
//        }
//        printf("\n");
//    }
//
//    for (int k = 0; k < 2 * n; ++k) {
//        printf("%d ", weights[k]);
//    }
//    printf("\n");

    for (int i = 0; i < intIndex; i++) {
        hang.clear();
        curHangWeight = 0;
        isVisited[i] = 1;
        dfs(i);
        hang.push_back(i);
//        printf("curWeight=%d\n", curHangWeight);
        if (curHangWeight > given && hang.size() > 2) {
            set<int> s;
            for (vector<int>::iterator j = hang.begin(); j != hang.end(); j++) {
//                printf("%s ", strMap[*j].c_str());
                s.insert(*j);
            }
            hang.clear();
            for (set<int>::iterator j = s.begin(); j != s.end(); j++) {
                isVisited[*j] = 1;
                hang.push_back(*j);
            }
//            printf("\n");
            hangs.push_back(hang);
        }
    }

    printf("%d\n", hangs.size());
    for (vector<vector<int>>::iterator i = hangs.begin(); i != hangs.end(); i++) {
        vector<int> hang = *i;
        sort(hang.begin(), hang.end(), cmp);
//        printf("%s %d\n", strMap[hang[0]].c_str(), hang.size());
        node head;
        head.head = strMap[hang[0]];
        head.size = hang.size();
        heads.push_back(head);
    }

    sort(heads.begin(), heads.end(), cmp2);
    for (vector<node>::iterator i = heads.begin(); i != heads.end(); i++) {
        node head = *i;
        printf("%s %d\n", head.head.c_str(), head.size);
    }

    return 0;
}