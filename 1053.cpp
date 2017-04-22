//
// Created by qq985 on 2017/4/14.
//

/**
 * 这题不能对字符串进行排序，因为会出现 "10 2 3"<"3 2 3
 */

#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
    int index;
    int data;
};

int givenWeight;
vector<int> *graph;
map<int, bool> nonLeafMap;
int *weight;
int *isVisited;
vector<int> res;
vector<string> resStr;

bool cmp(string a, string b) {
    return a > b;
}

bool cmp2(int i, int j) {
    return weight[i] > weight[j];
}

void dfs(int point, int curWeight) {
    if (curWeight == givenWeight && !(nonLeafMap.find(point) != nonLeafMap.end())) {
        string str;
        for (vector<int>::iterator i = res.begin(); i != res.end();) {
//            printf("%d", *i);
            char num[20];
            sprintf(num, "%d", *i);
            str += num;
            i++;
            if (i != res.end()) {
//                printf(" ");
                str += " ";
            } else {
//                printf("\n");
            }
        }
//        printf("%s\n", str.c_str());
        resStr.push_back(str);
        return;
    } else if (curWeight > givenWeight) {
        return;
    } else {
        for (vector<int>::iterator i = graph[point].begin(); i != graph[point].end(); i++) {
            if (isVisited[*i] == 0) {
                isVisited[*i] = 1;
                int index = *i;
                res.push_back(weight[*i]);
                dfs(*i, curWeight + weight[*i]);
                res.pop_back();
                isVisited[*i] = 0;
            }
        }
    }
}

int main() {
    int nodeNum;
    int nonLeafNum;

    scanf("%d %d %d", &nodeNum, &nonLeafNum, &givenWeight);
//    printf("%d %d %d\n", nodeNum, nonLeafNum, givenWeight);
    graph = new vector<int>[nodeNum];
    weight = new int[nodeNum];
    isVisited = new int[nodeNum];
    for (int i = 0; i < nodeNum; i++) {
        int w;
        scanf("%d", &w);
        weight[i] = w;
        isVisited[i] = 0;
//        printf("%d ", w);
    }
//    printf("\n");

    for (int i = 0; i < nonLeafNum; i++) {
        int p;
        int n;
        scanf("%d %d", &p, &n);
//        cin >> p >> n;
//        printf("p=%d,n=%d\n", p, n);
        nonLeafMap[p] = true;
        for (int j = 0; j < n; j++) {
            int c;
            scanf("%d", &c);
            graph[p].push_back(c);
        }
        sort(graph[p].begin(), graph[p].end(), cmp2);
    }

//    for (int i = 0; i < nodeNum; i++) {
//        for (vector<int>::iterator j = graph[i].begin(); j != graph[i].end(); j++) {
//            printf("%d ", *j);
//        }
//        printf("\n");
//    }


    res.push_back(weight[0]);
    dfs(0, weight[0]);
//    sort(resStr.begin(), resStr.end(), cmp);

    for (vector<string>::iterator j = resStr.begin(); j != resStr.end(); j++) {
        string s = *j;
        printf("%s\n", s.c_str());
    }

    return 0;
}






//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//int main() {
//
//    int n;
//    scanf("%d", &n);
//    int level = 1;
//    int levelCount = 0;
//    int levelMax = 2;
//    int maxHeight = 1;
//    int maxWidth = 1;
//    for (int i = 2; i <= n + 1;) {
//        int widthCount = 0;
//        int isOdd = 0;
//        bool isCountHeight = false;
//        int zeroCount = 0;
////        cout<<22<<endl;
//        while (levelCount < levelMax) {
////            cout<<111<<endl;
//            int value;
//            scanf("%d", &value);
//            levelCount++;
//            isOdd++;
//            if (value != 0) {
//                widthCount++;
//                if (!isCountHeight) {
//                    maxHeight++;
//                    isCountHeight = true;
//                }
//            } else {
//                zeroCount++;
//            }
//
//            if (isOdd % 2 == 0) {
//                i++;
//                if (i > n + 1) {
//                    break;
//                }
//            }
//        }
//        levelMax = (levelCount ) * 2 - zeroCount * 2;
//        levelCount = 0;
//        if (widthCount > maxWidth) {
//            maxWidth = widthCount;
//        }
//    }
//
//    printf("%d ", maxWidth);
//    printf("%d\n", maxHeight);
//}

