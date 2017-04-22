#include<iostream>
using namespace std;

int main()
{
	int n;
	int cur = 0;
	int next = 0;
	int total = 0;
	cin >> n;
	while (n--){
		cin >> next;
		if (next > cur){
			total += ((next - cur) * 6 + 5);
		}
		else{
			total += ((cur - next) * 4 + 5);
		}
		cur = next;
	}
	cout << total << endl;
	return 0;
}