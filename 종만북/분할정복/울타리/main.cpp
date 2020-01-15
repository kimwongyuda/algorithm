
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> h;

int solve(int left, int right)
{
	if (left == right)
		return h[left];
	int mid = (left + right) / 2;

	//각개로 따지기
	int ret = max(solve(left, mid), solve(mid + 1, right));

	//중간의 경우
	int left_ = mid;
	int right_ = mid + 1;

	int height = min(h[left_], h[right_]);
	ret = max(ret, height * (right_ - left_ + 1));

	while (left < left_ || right_ < right_)
	{
		if (right_ < right &&  (left_==left || h[left_-1] < h[right_ + 1]))
		{
			right_++;
			height = min(height, h[right_]);
		}
		else 
		{
			left_--;
			height = min(height, h[left_]);
		}
		ret = max(ret, height*(right_ - left_ + 1));
	}

	return ret;
}

int main() {

	cout << "크기 입력: " << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		h.push_back(num);
	}

	int ret = solve(0, n - 1);
	cout << ret << endl;
	return 0;
}
