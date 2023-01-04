#pragma once
#include "Coord.h"

class Cell
{
private:
	Coord localXY;

	int niborNum = 0;
	
	bool status = false;
	bool nextStatus = false;

public:
	void setData(int, int, bool);
	void setStatus(bool);
	void setNiborNum(int);

	void addNibor();
	
	int getNiborNum();
	bool getStatus();
	
	void printData();
};

