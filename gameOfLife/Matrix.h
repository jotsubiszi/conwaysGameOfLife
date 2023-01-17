#pragma once
#include "Cell.h"

class Matrix
{
private:
	Cell** element;
	
	const int maxSize = 1250;
	int mLenghtX;
	int mLenghtY;
	
	void setLenghtOfXY(int, int, int);
	char printer(int, int);
	void surrNibor(int, int);
public:
	Matrix();
	
	void allNiborsScan();
	void allPrinter();
	void allNiborsReset();
	void setAllNewStatus();	
	void swapStatus(int, int);
	void randomizer();
	void properRandomizer();
	void setAllFalse();

	int checker(int, int);
};

