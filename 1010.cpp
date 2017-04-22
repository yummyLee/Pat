#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){

	char cs1[11];
	char cs2[11];
	int tag;
	int radix;
	cin >> cs1 >> cs2 >> tag >> radix;

	if (tag == 2){
		char cstmp[10];
		strcpy(cstmp, cs1);
		strcpy(cs1, cs2);
		strcpy(cs2, cstmp);
	}

	int len = strlen(cs1);
	long long e = 1;
	long long value = 0;
	for (int i = 0; i < len; i++){
		char c = cs1[i];
		long long digit;
		if (c >= 'a'){
			digit = c - 87;
		}
		else{
			digit = c - 48;
		}
		//cout << "digit=" << c << endl;
		//cout << "value=" << value << endl;
		value = value*radix + digit;
	}

	//for (int j = 0; j < len; j++){
	//	char c = n[tag - 1][j];
	//	long long digit;
	//	if (c >= 'a'){
	//		digit = c - 87;
	//	}
	//	else{
	//		digit = c - 48;
	//	}
	//	cout << digit << " ";
	//}
	//cout << endl;

	int len2 = strlen(cs2);
	int *n2;
	int maxDigit = 0;
	n2 = new int[len2];
	for (int i = 0; i < len2; i++){
		char c = cs2[i];
		if (c >= 'a'){
			n2[i] = c - 87;
		}
		else{
			n2[i] = c - 48;

		}
		if (n2[i]>maxDigit){
			maxDigit = n2[i];
		}
	}

	//cout << "value=" << value << endl;
	//for (int j = 0; j < len2; j++){
	//	cout << n2[j] << " ";
	//}
	//cout << endl;



	//int firstDigitOfn2 = n2[0];
	//long long minResRadixH = value / (n2[0]);
	//long long minResRadixL = value / (n2[0] + 1);
	//long long minResRadixDH = minResRadixH;
	//long long minResRadixDL = minResRadixL;

	//for (int i = 0; i < len2 - 2; i++){
	//	minResRadixDH = floor(sqrt(minResRadixDH));
	//	minResRadixDL = ceil(sqrt(minResRadixDL));
	//}
	long long minResRadixDH = value;
	long long minResRadixDL = maxDigit + 1;

	//cout << "minResRadixDH=" << minResRadixDH << endl;
	//cout << "minResRadixDL=" << minResRadixDL << endl;
	int prevalue = 0;
	long long curvalue = 0;


	long long l = minResRadixDL;
	long long h = value > l ? value : l;
	while (h >= l){
		long long m = (h + l) / 2;

		//cout << "l=" << l << endl;
		//cout << "h=" << h << endl;
		//cout << "m=" << m << endl;

		long long e = 1;
		curvalue = 0;
		//for (int j = len2 - 1; j >= 0; j--){
		//	long long temp = n2[j] * e;
		//	//cout <<"temp"<< temp << endl;
		//	curvalue += (temp);
		//	e *= m;
		//}

		for (int j = 0; j < len2; j++){
			curvalue = curvalue*m + n2[j];

			//这步很关键，防止溢出
			if (curvalue > value){
				h = m - 1;
				break;
			}
			else if (curvalue < 0){
				cout << "Impossible" << endl;
				//system("pause");
				return 0;
			}
		}
		if (curvalue == value){
			cout << m << endl;
			//system("pause");
			return 0;
		}
		if (curvalue < value){
			l = m + 1;
		}

		//cout << "curvalue=" << curvalue << endl;
	}

	//for (int i = (int)minResRadixD; i <= value; i++){
	//	int e = 1;
	//	curvalue = 0;
	//	for (int j = len2 - 1; j >= 0; j--){
	//		long long temp = n2[j] * e;
	//		//cout <<"temp"<< temp << endl;
	//		curvalue += (temp);
	//		e *= i;
	//	}
	//	if (curvalue == value){
	//		printf("%d\n", i);
	//		system("pause");
	//		return 0;
	//	}
	//	else if (curvalue > value){
	//		cout << "i=" << i << endl;
	//		cout << "curvalue="<<curvalue << endl;
	//		cout << "Impossible" << endl;
	//		system("pause");
	//		return 0;
	//	}
	//	//cout << i << endl;
	//}


	cout << "Impossible" << endl;
	//system("pause");
	return 0;
}