#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int x, y, i, j;
char Grid[10][10];
void ShowGrid();
void SetGrid();
void FoodSetShow();

void main()
{
	SetGrid();
	FoodSetShow();
	ShowGrid();
}

void ShowGrid()
{
	cout << "+---------------------+" << endl;
	for (i = 0; i < 10; ++i)
	{
		cout << "| ";
		for (j = 0; j < 10; ++j)
		{
			cout << Grid[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "+---------------------+" << endl;
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

void FoodSetShow()
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
