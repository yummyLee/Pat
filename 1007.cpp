#include<iostream>
using namespace std;

int main(){

	int n;
	int *num;
	int curStart = 0;
	int curEnd = 0;
	int start = 0;
	int end = 0;
	cin >> n;
	if (n == 0){
		cout << 0 << " " << 0 << " " << 0 << endl;
		system("pause");
		return 0;
	}
	num = new int[n];
	cin >> num[0];

	//牛客没有考虑全为整数的情况
	curStart = num[0];
	curEnd = num[0];


	if (n == 1){
		cout << num[0] << " " << num[0] << " " << num[0] << endl;
		system("pause");
		return 0;
	}
	int curMax = num[0];
	int curSum = num[0];

	for (int i = 1; i < n; i++){
		cin >> num[i];
		if (curSum < 0){
			if (num[i] >= 0){
				curSum = num[i];
				curStart = num[i];
				curEnd = num[i];
			}
			/*else{
				curSum = curSum>num[i] ? curSum : num[i];
				}*/
		}
		else{
			/*if (curSum == 0){
				curStart = num[i];
				}*/
			curSum += num[i];
			curEnd = num[i];
		}
		if (curMax < curSum){
			curMax = curSum;
			end = curEnd;
			start = curStart;
		}
		//cout << curMax << " " << start << " " << end << endl;
	}
	if (curMax < 0){
		cout << 0 << " " << num[0] << " " << num[n - 1] << endl;
	}
	else{
		cout << curMax << " " << start << " " << end << endl;
	}
	system("pause");
	return 0;
}