#include <iostream>
using namespace std;

//����Ʈ��

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
	
	cout << "���� �Է�(case 1��)" << endl;
	cout << "->";
	string input;
	cin >> input;

	string answer="";
	int index = 0;
	answer = reverse(input, index);

	cout << answer << endl;
	

	return 0;
}