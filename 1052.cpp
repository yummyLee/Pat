//
// Created by qq985 on 2017/4/13.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
    int address;
    int data;
    int next;
    bool flag;

    node() {
        flag = false;
    }
};

bool cmp(node a, node b) {
    if (a.flag == false || b.flag == false) {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}

int main() {

    node nodes[100000];
    int n, headIndex;
    scanf("%d %d", &n, &headIndex);
    for (int i = 0; i < n; i++) {
        int address;
        int data;
        int next;
        scanf("%d %d %d", &address, &data, &next);
        nodes[address].address = address;
        nodes[address].data = data;
        nodes[address].next = next;
    }

    int index = headIndex;
    int count = 0;
    while (index != -1) {
        count++;
        nodes[index].flag = true;
        index = nodes[index].next;
    }

    if (count == 0) {
        printf("%d %d\n", 0, -1);
        return 0;
    }

    sort(nodes, nodes + 100000, cmp);
    nodes[count - 1].next = -1;
    printf("%d %05d\n", count, nodes[0].address);

    for (int i = 0; i < count; i++) {
        printf("%05d %d", nodes[i].address, nodes[i].data);
        if (i != count - 1) {
            printf(" %05d\n", nodes[i + 1].address);
        } else {
            printf(" %d\n", -1);
        }
    }


//    for (int i = 0; i < n - 1; i++) {
//        int pre = headIndex;
//        int preData = nodes[pre].data;
//        for (int j = 1; j < n - i; j++) {
//            int cur = nodes[pre].next;
//            int curData = nodes[cur].data;
//            if (curData < preData) {
//                nodes[cur].data = preData;
//                nodes[pre].data = curData;
//            }
//            pre = cur;
//            preData = nodes[cur].data;
//        }
//    }



    return 0;
}