//
// Created by qq985 on 2017/4/1.
//

#include <iostream>
#include<stack>
#include<queue>

using namespace std;

int main() {
	char *c = new char[102];
	int i = 0;
	int res = 0;
	int sign = 1;
	while (cin >> c[i]){
		//cout << c[i] << " " << endl;
		res += (c[i++] - 48);
		if (res / sign > 0){
			sign *= 10;
		}
	}
	if (sign != 1){
		sign /= 10;
	}
	queue<int> q;
	//cout << res << endl;
	while (sign != 0){
		int num = res / sign;
		//cout << num << endl;
		q.push(num);
		res -= (num*sign);
		sign /= 10;
	}
	while (!q.empty()){
		//cout << q.front() << endl;
		switch (q.front()){
		case 0:
			cout << "zero";
			break;
		case 1:
			cout << "one";
			break;
		case 2:
			cout << "two";
			break;
		case 3:
			cout << "three";
			break;
		case 4:
			cout << "four";
			break;
		case 5:
			cout << "five";
			break;
		case 6:
			cout << "six";
			break;
		case 7:
			cout << "seven";
			break;
		case 8:
			cout << "eight";
			break;
		case 9:
			cout << "nine";
			break;
		default:
			break;
		}
		q.pop();
		if (!q.empty()){
			cout << " ";
		}
		else{
			cout << endl;
		}
	}
	cout << endl;



	system("pause");



	return 0;
}




//#include<iostream>
//using namespace std;
//
//void f(int i, int b = 1, int a = 2){
//
//	cout << i << " " << b << " " << a << endl;
//
//}
//
//int main(){
//
//	f(4);
//	f(4, 5);
//
//	system("pause");
//	return 0;
//}