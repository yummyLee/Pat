//
// Created by qq985 on 2017/4/13.
//
#include <iostream>
#include <cstdio>

using namespace std;

struct node {
    char data;
    int nextIndex;
};

int main() {
    int begin1, begin2;
    int n;
    node nodes[100000];
    scanf("%d%d%d", &begin1, &begin2, &n);
    for (int i = 0; i < n; i++) {
//        printf("input\n");
        int address;
        char data;
        int next;
        scanf("%d %c %d", &address, &data, &next);
        nodes[address].data = data;
        nodes[address].nextIndex = next;
    }


    int len1 = 1;
    int index1 = begin1;

//    for (int i = 0; i < 8; i++) {
//        printf("index=%d,next=%d\n", index1, nodes[index1].nextIndex);
//        len1++;
//        index1 = nodes[index1].nextIndex;
//    }
    while (nodes[index1].nextIndex != -1) {
        len1++;
        index1 = nodes[index1].nextIndex;
    }
    int len2 = 1;
    int index2 = begin2;
    while (nodes[index2].nextIndex != -1) {
//        printf("1");
        len2++;
        index2 = nodes[index2].nextIndex;
    }

//    printf("len1=%d,len2=%d\n", len1, len2);

    int diff = len1 - len2;
    int cur1 = begin1;
    int cur2 = begin2;
    if (diff < 0) {
        diff = -diff;
        for (int i = 0; i < diff; i++) {
            cur2 = nodes[cur2].nextIndex;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            cur1 = nodes[cur1].nextIndex;
        }
    }

    int suffixBegin = -1;
    while (1) {
        if (cur1 == cur2) {
            suffixBegin = cur1;
            break;
        }
        if (nodes[cur1].nextIndex == -1) {
            break;
        } else {
            cur1 = nodes[cur1].nextIndex;
            cur2 = nodes[cur2].nextIndex;
        }

    }

    if (suffixBegin != -1) {
        printf("%05d\n", suffixBegin);
    } else {
        printf("%d\n", suffixBegin);
    }

    return 0;
}