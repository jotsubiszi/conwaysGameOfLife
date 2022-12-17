#include "Cell.h"
#include <iostream>

using namespace std;



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


void Cell::printData()
{
	cout << "x: " << this->localXY.getCoordComponX() << " " << "y: " << this->localXY.getCoordComponY() << " ";
	cout << "status: " << this->getStatus() << " ";
	cout << "niborNum: " << this->getNiborNum();
	cout << '\n';
}


void Cell::setData(int x, int y, bool stat)
{
	this->setStatus(stat);
	this->localXY.setCoordComps(x, y);
}


void Cell::addNibor()
{
	this->niborNum += 1;
}