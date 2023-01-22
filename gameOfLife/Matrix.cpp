#include "Matrix.h"
#include <iostream>
#include <windows.h>
#include <bitset>
#include <chrono>
#include <random>

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


int Matrix::cooNibConverter(int coord,const int lenght)
{
	if (coord > 0 && coord < lenght) {
		return coord;
	}
	else if (coord <= -1) {
		return lenght - 1;
	}
	else if (coord >= lenght) {
		return 0;
	}
}


void Matrix::surrNibor(int x, int y)
{
	int xNib;
	int yNib;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			xNib = x + i;
			yNib = y + j;
			if (i == 0 && j == 0) {
				continue;
			}
			else if (element[cooNibConverter(xNib, mLenghtX)][cooNibConverter(yNib, mLenghtY)].getStatus() == 1) {
				element[x][y].addNibor();
			}
		}
	}
}


void Matrix::setLenghtOfXY(int x, int y, int c)
{
	
	while (c != 1) {
		system("CLS");
		if (c == 0) {
			cout << "Prosze podac inne wymiary\n";
		}
		cout << "Maksymalna ilosc elementow to: " << this->maxSize << "\n";
		cout << "Podaj x: ";
		cin >> y;

		if (cin.fail()) {
			cout << endl << "prosze podac wlasciwe dane" << endl;
			cin.clear();
			cin.ignore();
			continue;
		}

		cout << "\n";
		cout << "Podaj y: ";
		cin >> x;

		if (cin.fail()) {
			cout << endl << "prosze podac wlasciwe dane" << endl;
			cin.clear();
			cin.ignore();
			continue;
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
	if (x * y <= this->maxSize && x > 0 && y > 0) {
		return 1;
	}
	else { 
		return 0; 
	}	
}


int Matrix::placementChecker(int x, int y)
{
	if (x < 0 || y < 0 || x > this->mLenghtX - 1 || y > this->mLenghtY - 1) {
		return 0;
	}
	else {
		return 1;
	}
}


void Matrix::randomizer()
{
	int x = 15;
	const int a = 64;
	
	srand(chrono::steady_clock::now().time_since_epoch().count());
	
	mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
	int random = mt();

	string binary = std::bitset<a>(random).to_string();
		
	for (int i = 0; i < this->mLenghtX; i++) {
		for (int j = 0; j < this->mLenghtY; j++, x++) {
			if (x > a) {
				random = mt();
				binary = std::bitset<a>(random).to_string();
				x = 0;
			}
			if (binary[x] == '1') {
				element[i][j].setStatus(1);
				
			}			
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


void Matrix::allPrinter()
{
	for (int i = 0; i < this->mLenghtX; i++) {
		for (int j = 0; j < this->mLenghtY; j++) {
			cout << printer(i, j) << " ";
		}
		cout << endl;
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


void Matrix::properRandomizer()
{
	int howMuch = 0;
	cout << "\npodaj ilosc: ";
	cin >> howMuch;

	while ((howMuch > (this->mLenghtX * this->mLenghtY)) || (howMuch <= 0)) {
		cout << "zle dane podaj jeszcze raz: ";
		cin >> howMuch;
		if (cin.fail()) {
			cout << endl << "prosze podac wlasciwe dane" << endl;
			cin.clear();
			cin.ignore();
			howMuch = 0;
		}
	}
	cout << "pomyslnie wybralo ilosc!\n";
	system("PAUSE");

	srand(chrono::steady_clock::now().time_since_epoch().count());
	mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

	int randomX = mt() % this->mLenghtX;
	int randomY= mt() % this->mLenghtY;	
	
	for (int i = 1; i <= howMuch; i++) {
		randomX = mt() % this->mLenghtX;
		randomY = mt() % this->mLenghtY;
		if (randomX < 0) {
			randomX = randomX * (-1);
			
		}
		if (randomY < 0) {
			randomY = randomY * (-1);

		}
		if (element[randomX][randomY].getStatus() == 0) {
			element[randomX][randomY].setStatus(1);
		}
		else {
			i--;
		}
	}
}


void Matrix::setAllFalse()
{
	for (int i = 0; i < this->mLenghtX; i++) {
		for (int j = 0; j < this->mLenghtY; j++) {
			element[i][j].setStatus(0);
		}
	}
}