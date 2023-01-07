#pragma once
#include "Cell.h";

class Matrix
{
private:
	Cell** element;
	
	const int maxSize = 1250;
	int mLenghtX;
	int mLenghtY;
	
public:
	Matrix();
	
	void allNiborsScan();
	void allNiborsReset();
	void allPrinter();
	void setAllNewStatus();
	void setLenghtOfXY(int, int, int);
	void swapStatus(int, int);
	void randomizer();
	void surrNibor(int, int);
	
	int checker(int, int);
	
	char printer(int, int);

};

