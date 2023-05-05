#pragma once
#include "Cell.h"

class Matrix
{
private:
	Cell** element;

	const int maxSize = 1250;
	
	int mLenghtX;
	int mLenghtY;
	
	void setLenghtOfXY();
	void surrNibor(int, int);
	
	char printer(int, int);

	int cooNibConverter(int,const int);
	int checker(int, int);
public:
	Matrix();
	
	void allNiborsScan();
	void allPrinter();
	void allNiborsReset();
	void setAllNewStatus();	
	void setAllFalse();
	void swapStatus(int, int);
	void randomizer();
	void properRandomizer();

	int placementChecker(int, int);
};

