#include "Matrix.h"
#include <iostream>
#include <windows.h>
#include <bitset>
#include <chrono>
#include <random>

using namespace std;

/// <summary>
/// Constructor that makes 2D array of Cell objects
/// </summary>
Matrix::Matrix() 
{
	setLenghtOfXY();

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

/// <summary>
/// This function goes through 2D array of Cell, and sets amounts of active neighbors
/// </summary>
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

/// <summary>
/// sets to all Cell amount of active neighbors to 0
/// </summary>
void Matrix::allNiborsReset()
{
	for (int i = 0; i < this->mLenghtX; i++){
		for (int j = 0; j < this->mLenghtY; j++){
			element[i][j].setNiborNum(0);			
		}
	}
}

/// <summary>
/// this function changes coordinates to check,
/// so if there is active Cell on border of array,
/// this function will make Cell on the other side of array, its neighbor
/// </summary>
/// <param name="coord">coord of current checking neighbor, in x or y axis</param>
/// <param name="lenght">lenght of x or y axis</param>
/// <returns>coord in x or y axis on other side of array, if needed</returns>
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

/// <summary>
/// looks and sets a number of active neighbors around current Cell
/// </summary>
/// <param name="x">X int in Coord object of current Cell</param>
/// <param name="y">Y int in Coord object of current Cell</param>
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

/// <summary>
/// sets lenght of x and y axis
/// </summary>
void Matrix::setLenghtOfXY()
{
	int x = 0;
	int y = 0;
	int c = 2;

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

/// <summary>
/// checks if x*y is grater than 0 and lower than maxSize
/// </summary>
/// <param name="x">user input of x axis</param>
/// <param name="y">user input of y axis</param>
/// <returns>True / False</returns>
int Matrix::checker(int x, int y)
{
	if (x * y <= this->maxSize && x > 0 && y > 0) {
		return 1;
	}
	else { 
		return 0; 
	}	
}

/// <summary>
/// checks if user input is grater than 0 and lower than lenght of array in x or y axis
/// </summary>
/// <param name="x">user input of x axis</param>
/// <param name="y">user input of y axis</param>
/// <returns>True / False</returns>
int Matrix::placementChecker(int x, int y)
{
	if (x < 0 || y < 0 || x > this->mLenghtX - 1 || y > this->mLenghtY - 1) {
		return 0;
	}
	else {
		return 1;
	}
}

/// <summary>
/// sets random amount of active Cell objects
/// </summary>
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

/// <summary>
/// Function that checks if current Cell object should be active or inactive
/// </summary>
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

/// <summary>
/// checks if Cell is active
/// </summary>
/// <param name="i">coord of Cell in x axis</param>
/// <param name="j">coord of Cell in y axis</param>
/// <returns>'o' if active
/// '.' if inactive</returns>
char Matrix::printer(int i, int j)
{
	switch (element[i][j].getStatus()) {
	case 1:
		return 'o';
	case 0:
		return '.';
	}
}

/// <summary>
/// prints all Cell status as 'o' if active or '.' if inactive
/// </summary>
void Matrix::allPrinter()
{
	for (int i = 0; i < this->mLenghtX; i++) {
		for (int j = 0; j < this->mLenghtY; j++) {
			cout << printer(i, j) << " ";
		}
		cout << endl;
	}
}

/// <summary>
/// if current Cell status is inactive function swaps status to active and vice versa 
/// </summary>
/// <param name="i">x axis of Cell</param>
/// <param name="j">y axis of Cell</param>
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

/// <summary>
/// user inputs amount of active Cell objects
/// after that function chooses random Coord of Cell object to set status to active
/// </summary>
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

/// <summary>
/// changes all Cell objects status to inactive
/// </summary>
void Matrix::setAllFalse()
{
	for (int i = 0; i < this->mLenghtX; i++) {
		for (int j = 0; j < this->mLenghtY; j++) {
			element[i][j].setStatus(0);
		}
	}
}