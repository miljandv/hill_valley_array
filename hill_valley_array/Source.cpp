#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A) {
	int num = 0;
	int fall = 0, rise = 0, start = 1,lf=0,lr=0;
	for (int i = 0; i < A.size()-1; i++) {
		if (A[i] > A[i + 1]) { fall++; lf = 1; }
		else if (A[i] < A[i + 1]) { rise++; lr = 1; }
		if (start && (rise!=0 || fall!=0)) { start = 0; num++; }
		if (rise != 0 && fall != 0) { 
			if(!lr)rise=0;
			if(!lf)fall=0;
			lf = lr = 0;
			num++;
		}
		lf = lr = 0;
	}
	if ((rise != 0 || fall != 0)) { num++; }
	return (num==0 && A.size()!=0)?1:num;
}

int main() {
	vector<int> A1{ 2, 2, 3, 4, 3, 3, 2, 2, 1, 1, 2, 5 };
	vector<int> A{2, 2, 3, 4, 3, 3, 2, 2, 1, 1, 2, 5, 4, 3, 2, 1, 2, 1};
	vector<int> B{ 2,1,2,1 };
	vector<int>	C{ 2,2 };
	cout << solution(A);
}