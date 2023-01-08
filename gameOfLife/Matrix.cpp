#include "Matrix.h"
#include <iostream>
#include <bitset>
#include <windows.h>

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
			element[i][j].setData(i,j,0);
			
		}	
	}
}


void Matrix::allNiborsScan()
{
	for (int i = 0; i < this->mLenghtX; i++){
		for (int j = 0; j < this->mLenghtY; j++){
			surrNibor(i, j);
			cout << printer(i,j) << " ";
		}
		cout << "\n";
	}
}


void Matrix::allNiborsReset()
{
	for (int i = 0; i < this->mLenghtX; i++){
		for (int j = 0; j < this->mLenghtY; j++){
			element[i][j].setNiborNum(0);			
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

		if (cin.fail()) {
			cout << endl << "prosze podac wlasciwe dane" << endl;
			cin.clear();
			cin.ignore();
		}

		cout << "\n";
		cout << "Podaj y: ";
		cin >> x;

		if (cin.fail()) {
			cout << endl << "prosze podac wlasciwe dane" << endl;
			cin.clear();
			cin.ignore();
		}

		cout << "\n";
		if (checker(x, y) == 1) {
			this->mLenghtX = int(x);
			this->mLenghtY = int(y);
		}

		c = checker(int(x), int(y));
	}
	cout << "Pomyslnie ustawiono rozmiar " << y << "x" << x << "\n";
}


int Matrix::checker(int x, int y)
{
	if (x * y <= this->maxSize && x*y > 0) {
		if (x < 0 || y < 0) {
			return 0;
		}
		else
			return 1;
	}
	else { 
		return 0; 
	}
	
}


void Matrix::randomizer()
{
	int x = 15;
	const int a = 32;
	int b = pow(2, 32);
	int random = rand() % b;
	
	string binary = std::bitset<a>(random).to_string();
		
	for (int i = 0; i < this->mLenghtX; i++) {
		for (int j = 0; j < this->mLenghtY; j++) {
			if (binary[x] == '1') {
				element[i][j].setStatus(1);
			}	
			else {
				element[i][j].setStatus(0);
			}
			if (x < a) {
				x++;
			}
			else
				x = 0;
			
		}
	}

}


void Matrix::setAllNewStatus()
{
	for (int i = 0; i < this->mLenghtX; i++) {
		for (int j = 0; j < this->mLenghtY; j++) {
			switch (element[i][j].getNiborNum()) {
			case 2:
				break;
			case 3:
				if (element[i][j].getStatus() == 0) {
					element[i][j].setStatus(1);
				}
				break;
			default:
				if (element[i][j].getStatus() == 1) {
					element[i][j].setStatus(0);
				}
				break;
			}
		}
	}
}


char Matrix::printer(int i, int j)
{
	switch (element[i][j].getStatus()) {
	case 1:
		return 'o';
	case 0:
		return '.';
	}
}


void Matrix::swapStatus(int i, int j)
{
	switch (element[i][j].getStatus()) {
	case 1:
		element[i][j].setStatus(0);
		break;
	case 0:
		element[i][j].setStatus(1);
		break;
	}
}


void Matrix::allPrinter()
{
	for (int i = 0; i < this->mLenghtX; i++) {
		for (int j = 0; j < this->mLenghtY; j++) {
			cout << printer(i, j) << " ";
		}
		cout << endl;
	}
}
