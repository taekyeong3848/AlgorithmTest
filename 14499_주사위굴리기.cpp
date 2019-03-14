#include <iostream>

using namespace std;


typedef struct {
	int top;
	int bottom;
	int right;
	int left;
	int front;
	int back;
}Dice;


int N, M, r, c, K;
int** map;
//int* sequence;
Dice dice, tmpDice;

void valueCopy()
{
	tmpDice.right = dice.right;
	tmpDice.bottom = dice.bottom;
	tmpDice.right = dice.right;
	tmpDice.left = dice.left;
	tmpDice.front = dice.front;
	tmpDice.back = dice.back;
}
 

void east()
{
	valueCopy();
	dice.top = tmpDice.left;
	dice.bottom = tmpDice.right;
	dice.right = tmpDice.top;
	dice.left = tmpDice.bottom;
	dice.front = tmpDice.front;
	dice.back = tmpDice.back;
}


void west()
{
	valueCopy();
	dice.top = tmpDice.right;
	dice.bottom = tmpDice.left;
	dice.right = tmpDice.bottom;
	dice.left = tmpDice.top;
	dice.front = tmpDice.front;
	dice.back = tmpDice.back;
}


void north()
{
	valueCopy();
	dice.top = tmpDice.front;
	dice.bottom = tmpDice.back;
	dice.right = tmpDice.right;
	dice.left = tmpDice.left;
	dice.front = tmpDice.bottom;
	dice.back = tmpDice.top;
}


void south()
{
	valueCopy();
	dice.top = tmpDice.back;
	dice.bottom = tmpDice.front;
	dice.right = tmpDice.right;
	dice.left = tmpDice.left;
	dice.front = tmpDice.top;
	dice.back = tmpDice.bottom;
}


void process(int order)
{
	switch (order)
	{
	case 1://동쪽
		c++;
		if (c > M - 1)
		{
			c--;
			return;
		}
		east();
		break;
	case 2://서쪽
		c--;
		if (c < 0)
		{
			c++;
			return;
		}
		west();
		break;
	case 3://북쪽
		r--;
		if (r < 0)
		{
			r++;
			return;
		}
		north();
		break;
	case 4://남쪽
		r++;
		if (r > N - 1)
		{
			r--;
			return;
		}
		south();
		break;
	}

	if (map[r][c] == 0)
		map[r][c] = dice.bottom;
	else
	{
		dice.bottom = map[r][c];
		map[r][c] = 0;
	}
	cout << dice.top << endl;
}


int main()
{
	int order;
	cin >> N >> M >> r >> c >> K;

	map = new int*[N];
	//sequence = new int[K];

	for (int i = 0; i < N; i++)
		map[i] = new int[M];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < K; i++)
	{
		cin >> order;
		process(order);
	}

	return 0;
}
