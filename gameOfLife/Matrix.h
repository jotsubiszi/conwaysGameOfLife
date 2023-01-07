#pragma once
#include "Cell.h";

class Matrix
{
private:
	int maxSize = 10000;
	int mLenghtX;
	int mLenghtY;

	Cell** element;
	
	
public:
	Matrix();
	//~Matrix();
	
	void allNiborsScan();
	void allNiborsReset();
	void surrNibor(int, int);
	void setLenghtOfXY(int, int, int);

	void test();

	int checkSize(int, int);
	void randomizer();
	int getX();
	int getY();
};

