#include "Cell.h"


void Cell::setStatus(bool s)
{
	this->status = s;
}


int Cell::getNiborNum()
{
	return this->niborNum;
}


bool Cell::getStatus()
{
	return this->status;
}


void Cell::setData(int x, int y, bool stat)
{
	this->localXY.setCoordComps(x, y);
	this->setStatus(stat);
}


void Cell::addNibor()
{
	this->niborNum += 1;
}


void Cell::setNiborNum(int num)
{
	this->niborNum = num;
}
