#include "Matrix.h"
#include "Cell.h"
#include <iostream>
#include <cstdlib>
#include<windows.h>

using namespace std;

Matrix::Matrix() 
{
	setLenghtOfXY(0, 0, 2);

	int x = this->mLenghtX;
	int y = this->mLenghtY;

	element = new Cell* [x];
	for (int i = 0; i < x; i++) {
		element[i] = new Cell[y];
		
		for (int j = 0; j < y; j++) {


			// FOR NOW
			element[i][j].setData(i,j,1);
			//element[i][4].setStatus(0);
			//cout <<  i << j << " ";
			
		
		}
		//cout << "\n";
	}
	//cout <<  element[2][2].getStatus();
}

void Matrix::test() 
{
	cout <<element[2][2].getStatus();
}



void Matrix::allNiborsScan()
{
	for (int i = 0; i < this->mLenghtX; i++)
	{
		for (int j = 0; j < this->mLenghtY; j++)
		{
			surrNibor(i, j);
			cout << element[i][j].getNiborNum() << " ";
		}
		cout << "\n";
	}
}


void Matrix::allNiborsReset()
{
	for (int i = 0; i < this->mLenghtX; i++)
	{
		for (int j = 0; j < this->mLenghtY; j++)
		{
			element[i][j].setStatus(0);			
		}
	}
}


void Matrix::surrNibor(int x, int y)
{
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {

			if (i == 0 && j == 0) {
				continue;
			}
			if (x + i < 0 || x + i > mLenghtX - 1 || y + j < 0 || y + j > mLenghtY - 1) {
				continue;
			}

			else if (element[x + i][y + j].getStatus() == 1) { 
				element[x][y].addNibor();
			}
			//cout << x + i << y + j << "\n";
		}
	}
}


void Matrix::setLenghtOfXY(int x, int y, int c)
{
	
	while (c != 1) {
		if (c == 0) {
			cout << "Proszê podac inne wymiary\n";
		}
		cout << "Maxymalny rozmiar tablicy to: " << this->maxSize << "\n";
		cout << "Podaj x: ";
		cin >> y;
		cout << "\n";
		cout << "Podaj y: ";
		cin >> x;
		cout << "\n";
		if (checkSize(x, y) == 1) {
			this->mLenghtX = x;
			this->mLenghtY = y;
		}
		c = checkSize(x, y);
	}
	cout << "Pomyslnie ustawiono rozmiar " << y << "x" << x << "\n";
}


int Matrix::checkSize(int x, int y)
{
	if (x * y <= this->maxSize && x*y > 0) {
		return 1;
	}
	else { 
		return 0; 
	}
	
}

void Matrix::randomizer()
{

	for (int i = 0; i < this->mLenghtX; i++) {
		for (int j = 0; j < mLenghtY; j++) {
			srand((unsigned)time(NULL));

			int random = rand() % 2;

			element[i][j].setStatus(random);
			cout << element[i][j].getStatus();
			Sleep(1);
		}
	}
	


}


int Matrix::getX()
{
	
	return this->mLenghtX;
}


int Matrix::getY()
{
	
	return this->mLenghtY;
}
