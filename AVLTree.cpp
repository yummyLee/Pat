//
// Created by qq985 on 2017/4/19.
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
    int data;
    node *lChild;
    node *rChild;
    int height;

    node(int d) {
        data = d;
        lChild = NULL;
        rChild = NULL;
        height = 1;
    }
};

int getHeight(node *root) {
    if (root == NULL) {
        return 0;
    } else {
        return root->height;
    }
}

void updateHeight(node *&root) {
    root->height = max(getHeight(root->lChild), getHeight(root->rChild)) + 1;
}

void lRotate(node *&root) {
    node *temp = root->rChild;
    root->rChild = temp->lChild;
    temp->lChild = root;
    root = temp;
    updateHeight(root->lChild);
    updateHeight(root);
}

void rRotate(node *&root) {
    node *temp = root->lChild;
    root->lChild = temp->rChild;
    temp->rChild = root;
    root = temp;
    updateHeight(root->rChild);
    updateHeight(root);
}


int getBalancedFactor(node *root) {
    return getHeight(root->lChild) - getHeight(root->rChild);
}

void insert(node *&root, int data) {
    if (root != NULL) {
        if (data < root->data) {
            insert(root->lChild, data);
            updateHeight(root);
            if (getBalancedFactor(root) == 2) {
                //LL
                if (getBalancedFactor(root->lChild) == 1) {
                    rRotate(root);
                }
                //LR
                if (getBalancedFactor(root->lChild) == -1) {
                    lRotate(root->lChild);
                    rRotate(root);
                }
            }
        } else {
            insert(root->rChild, data);
            updateHeight(root);
            printf("root=%d,factor=%d\n", root->data, getBalancedFactor(root));
            if (getBalancedFactor(root) == -2) {
                //RR
                if (getBalancedFactor(root->rChild) == -1) {
                    lRotate(root);
                }
                //RL
                if (getBalancedFactor(root->rChild) == 1) {
                    rRotate(root->rChild);
                    lRotate(root);
                }
            }
        }
    } else {
        root = new node(data);
        return;
    }


}

void inOrder(node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->lChild);
    printf("%d ", root->data);
    inOrder(root->rChild);
}

void layerOrder(node *root) {
    queue<node *> q;
    queue<int> ql;
    q.push(root);
    ql.push(1);

    while (!q.empty()) {
        node *temp = q.front();
        int layer = ql.front();
        q.pop();
        ql.pop();
        printf(" %d-%d ", temp->data, layer);
        if (temp->lChild != NULL) {
            q.push(temp->lChild);
            ql.push(layer + 1);
        }
        if (temp->rChild != NULL) {
            q.push(temp->rChild);
            ql.push(layer + 1);
        }
    }
}

node *createNewTree(node *&root, vector<int> datas) {
    root = new node(datas[0]);
    for (int i = 1; i < datas.size(); i++) {
        insert(root, datas[i]);
        layerOrder(root);
        printf("\n");
    }
}


int main() {

    vector<int> datas = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    node *root;
    createNewTree(root, datas);

}