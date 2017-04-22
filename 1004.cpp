#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char cs1[11];
	char cs2[11];
	int tag;
	int radix;
	cin >> cs1 >> cs2 >> tag >> radix;

	if (tag == 2) {
		char cstmp[11];
		strcpy(cstmp, cs1);
		strcpy(cs1, cs2);
		strcpy(cs2, cstmp);
	}

	//这个没有加上之前始终过不了pat的case 10
	if (strcmp(cs1, cs2) == 0){
		cout << radix << endl;
		return 0;
	}

	int len = strlen(cs1);
	long long value = 0;
	for (int i = 0; i < len; i++) {
		char c = cs1[i];
		long long digit;
		if (c >= 'a') {
			digit = c - 87;
		}
		else {
			digit = c - 48;
		}
		value = value * radix + digit;
		if (value < 0) {
			cout << "Impossible" << endl;
			//system("pause");
			return 0;
		}
	}

	int len2 = strlen(cs2);
	int *n2;
	int maxDigit = 0;
	n2 = new int[len2];
	for (int i = 0; i < len2; i++) {
		char c = cs2[i];
		if (c >= 'a') {
			n2[i] = c - 87;
		}
		else {
			n2[i] = c - 48;

		}
		if (n2[i] > maxDigit) {
			maxDigit = n2[i];
		}
	}

	long long minResRadixDL = maxDigit + 1;
	long long curvalue = 0;
	long long l = minResRadixDL;
	long long h = value > l ? value : l;
	while (h >= l) {
		long long m = (h + l) / 2;
		curvalue = 0;
		for (int j = 0; j < len2; j++) {
			curvalue = curvalue * m + n2[j];
			//这步很关键，防止溢出
			if (curvalue > value) {
				h = m - 1;
				break;
			}
			else if (curvalue < 0) {
				cout << "Impossible" << endl;
				//system("pause");
				return 0;
			}
		}
		if (curvalue == value) {
			cout << m << endl;
			//system("pause");
			return 0;
		}
		if (curvalue < value) {
			l = m + 1;
		}
		//cout << "curvalue=" << curvalue << endl;
	}
	cout << "Impossible" << endl;
	//system("pause");
	return 0;
}