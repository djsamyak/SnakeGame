#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace std;

int x, y, i, j, BodySize = 1, flag = 0;
char Grid[10][10];
char ch;
int si, sj;
void ShowGrid();
void SetGrid();
void FoodLoc();
void BodyUpdate(int si, int sj);
void SpawnLoc(int & si,int & sj);

void main()
{
	SetGrid();
	FoodLoc();
	SpawnLoc(si, sj);
	ShowGrid();
	while (flag != 1)
	{
		BodyUpdate(si, sj);
	}
}

void ShowGrid()
{
	cout << " +-0-1-2-3-4-5-6-7-8-9-+" << endl;		//DEBUG
	cout << " +---------------------+" << endl;
	for (i = 0; i < 10; ++i)
	{
		cout << i << "| ";							//DEBUG
		for (j = 0; j < 10; ++j)
		{
			cout << Grid[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << " +---------------------+" << endl;
}

void SetGrid()
{
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			Grid[i][j] = ' ';
		}
	}
}

void FoodLoc()
{
	srand(time(NULL)); 
	i= (rand() % 10) + (rand() % 3);
	j= (rand() % 15) + (rand() % 5);
	if (i >= 10)
	{
		i = (rand() % 10);
	}
	if (j >= 10)
	{
		j = (rand() % 10);
	}
	Grid[i][j] = '@';
}

void SpawnLoc(int &si, int &sj)
{
	srand(time(NULL));
	si = (rand() % 15) + (rand() % 5);
	sj = (rand() % 10) + (rand() % 3);
	if (si >= 10)
	{
		si = (rand() % 10);
	}
	if (sj >= 10)
	{
		sj = (rand() % 10);
	}
	Grid[si][sj] = 'o';
}

void BodyUpdate(int si, int sj)
{
UpdateLoop:
	cout << "I=" << si << " J=" << sj << endl;		//DEBUG
	cin >> ch;
	system("cls");
	switch (ch)
	{
	case 'w':
	{
		{
			Grid[si][sj] = ' ';
			Grid[si-1][sj] = 'o';
			ShowGrid();
			--si;
			if (getchar())
				goto UpdateLoop;
		}
	}
	break;
	case 'a':
	{
		{
			Grid[si][sj] = ' ';
			Grid[si][sj-1] = 'o';
			ShowGrid(); 
			--sj;
			if (getchar())
				goto UpdateLoop;
		}
	}
	break;
	case 's':
	{			
		{
			Grid[si][sj] = ' ';
			Grid[si + 1][sj] = 'o';
			ShowGrid();
			++si;
			if (getchar())
				goto UpdateLoop;
		}
	}
	break;
	case 'd':
	{
		{
			Grid[si][sj] = ' ';
			Grid[si][sj+1] = 'o';
			ShowGrid();
			++sj;
			if (getchar())
				goto UpdateLoop;
		}
	}
	break;
	default: goto UpdateLoop;
	}
}