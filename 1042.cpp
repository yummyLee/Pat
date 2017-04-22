#include <iostream>
#include <cstdio>

using namespace std;

struct card {
    char c;
    int num;
};

char type[4] = {'S', 'H', 'C', 'D'};

int main() {

    int circle;
    scanf("%d", &circle);
    card cards[55];
    cards[53].c = 'J';
    cards[53].num = 1;
    cards[54].c = 'J';
    cards[54].num = 2;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            cards[i * 13 + j].num = j;
            cards[i * 13 + j].c = type[i];
        }
    }
    int exchange[55];
    for (int i = 1; i < 55; i++) {
        scanf("%d", exchange + i);
    }
    card res[55];
    for (int i = 1; i < 55; i++) {
        int finalPosition = i;
        for (int j = 0; j < circle; j++) {
            finalPosition = exchange[finalPosition];
        }
        res[finalPosition].num = cards[i].num;
        res[finalPosition].c = cards[i].c;
    }

    for (int i = 1; i < 55; i++) {
        printf("%c%d", res[i].c, res[i].num);
        if (i != 54) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    return 0;
}