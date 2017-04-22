//
// Created by qq985 on 2017/4/2.
//

#include <iostream>
#include <cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;

int cmpChar(char a[9], char b[9]) {
	bool isEqual = true;
	for (int i = 0; i < 9; i++) {
		if (a[i] > b[i]) {
			return 1;
		}
		else if (a[i] < b[i]) {
			return -1;
		}
	}
	return 0;
}

int main() {

	int n;
	cin >> n;
	char headUser[16];
	char tailUser[16];
	char minTime[9] = "24:00:00";
	char maxTime[9] = "00:00:00";
	char curUser[16];
	char curInTime[9];
	char curOutTime[9];
	while (n--) {
		cin >> curUser >> curInTime >> curOutTime;
		int i = cmpChar(curInTime, minTime);
		if (i < 0) {
			strcpy(minTime, curInTime);
			strcpy(headUser, curUser);
		}
		int j = cmpChar(curOutTime, maxTime);
		if (j > 0) {
			strcpy(maxTime, curOutTime);
			strcpy(tailUser, curUser);
		}
	}

	cout << headUser << " " << tailUser << endl;
	system("pause");

	return 0;
}
