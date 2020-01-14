#include <iostream>
using namespace std;

//쿼드트리

string reverse(string input, int& index)
{
	if (input[index] == 'b' || input[index] == 'w')
	{
		string ret="";
		ret += input[index];
		return ret;
	}

	index += 1;
	string upleft = reverse(input, index);
	index += 1;
	string upright = reverse(input, index);
	index += 1;
	string downleft = reverse(input, index);
	index += 1;
	string downright = reverse(input, index);

	string ret = "";
	ret += "x" + downleft + downright + upleft + upright;
	return ret;

}


int main() {
	
	cout << "예제 입력(case 1개)" << endl;
	cout << "->";
	string input;
	cin >> input;

	string answer="";
	int index = 0;
	answer = reverse(input, index);

	cout << answer << endl;
	

	return 0;
}