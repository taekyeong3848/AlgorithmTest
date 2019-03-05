#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> arr;
vector<int> answer;

bool decision(int candidate)
{
	string candi;
	string tmp = to_string(candidate);
	string bigOrSmall;
	if (tmp.length == arr.size())
	{
		candi += "0";
		candi += tmp;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		bigOrSmall = arr[i];
	
		if (bigOrSmall == "<")
		{
			if (answer[i] < answer[i + 1])
				continue;
			else
				return false;
		}
		else
		{
			if (answer[i] > answer[i + 1])
				continue;
			else
				return false;
		}
	}
	return true;
}


int main()
{
	int k;
	string tmp;

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}


	return 0;
}