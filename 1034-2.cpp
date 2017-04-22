//
// Created by qq985 on 2017/4/16.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct node {
    string name;
    int index;
    int time;
};

int *weights;
int *isVisited;
int n, given;
vector<node> *graph;
map<string, int> intMap;
map<int, string> strMap;

int curWeight;

void dfs(int point) {
    for (vector<node>::iterator j = graph[point].begin(); j != graph[point].end(); j++) {

    }
}


int main() {

    scanf("%d %d", &n, &given);
    int nodeCount = 0;
    graph = new vector<node>[2 * n];

    int intIndex = 0;
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
        node temp, temp2;
        temp.name = a;
        temp.index = aIndex;
        temp.time = t;
        temp2.name = b;
        temp2.time = t;
        temp2.index = bIndex;
        bool isfound = false;
        for (vector<node>::iterator j = graph[aIndex].begin(); j != graph[aIndex].end(); j++) {
            node &tempNode = *j;
            if (b.compare(tempNode.name) == 0) {
                isfound = true;
                tempNode.time += t;
            }
        }
        for (vector<node>::iterator j = graph[bIndex].begin(); j != graph[bIndex].end(); j++) {
            node &tempNode = *j;
            if (a.compare(tempNode.name) == 0) {
                tempNode.time += t;
            }
        }
        if (!isfound) {
            graph[aIndex].push_back(temp2);
            graph[bIndex].push_back(temp);
        }
    }

//    for (int i = 0; i < intIndex; i++) {
//        for (int j = 0; j < graph[i].size(); j++) {
//            node temp = graph[i][j];
//            printf("%s ", temp.name.c_str());
//        }
//        printf("\n");
//    }
    for(int i)


    return 0;
}