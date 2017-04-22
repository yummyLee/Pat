//
// Created by qq985 on 2017/4/19.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    int counter = 0;
    while (n != 1) {
        if (n & 1 == 1) {
            n = (3 * n + 1) / 2;
        } else {
            n /= 2;
        }
        counter++;
    }
    printf("%d\n", counter);

    return 0;
}