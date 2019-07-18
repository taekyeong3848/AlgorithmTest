#include <iostream>
#include <map>

using namespace std;


typedef struct shark {
	int r;//row
	int c;//colum
	int s;//speed
	int d;//direction
	int z;//size
}Shark;

typedef struct sharkmap {
	int id;//상어별 구분자(1부터 시작)
	Shark curPosS;//칸에 존재하는 상어 
}SharkMap;

map<int, Shark> sharkList;//각 turn별 상어들의 리스트
SharkMap **fishMap;//어장

int R, C, M;//Row, Column, 상어의 수
int result;


void sharkCatch(int column)//turn에 해당하는 column
{
	for (int i = 1; i < R + 1; i++)//해당하는 열 탐색
	{
		if (fishMap[i][column].id != 0)
		{
			result += fishMap[i][column].curPosS.z;
			sharkList.erase(fishMap[i][column].id);
			fishMap[i][column].id = 0;
			return;
		}
	}
}


void sharkMove()
{
	int curId;
	Shark curShark;

	for (int i = 1; i < R + 1; i++)
		for (int j = 1; j < C + 1; j++)
			fishMap[i][j].id = 0;//fishMap id 기준으로 초기화

	for (auto it = sharkList.begin(); it != sharkList.end(); it++)
	{
		curId = it->first;
		curShark = it->second;


	}
}


int main()
{
	cin >> R >> C >> M;

	fishMap = new SharkMap*[R + 1];
	for (int i = 0; i < R + 1; i++)
		fishMap[i] = new SharkMap[C + 1];

	for (int i = 0; i < M; i++)
	{
		Shark tmp;
		cin >> tmp.r >> tmp.c >> tmp.s >> tmp.d >> tmp.z;
		sharkList.insert(make_pair(i + 1, tmp));
	}

	for (int i = 1; i < C + 1; i++)//1부터 C까지 이동
	{
		sharkCatch(i);
		sharkMove();
	}

	return 0;
}