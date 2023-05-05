#include "Cell.h"

/// <summary>
/// setter of Cell status
/// </summary>
/// <param name="s">status active or inactive</param>
void Cell::setStatus(bool s)
{
	this->status = s;
}

/// <summary>
/// getter of number of active neighbors
/// </summary>
/// <returns>number of active neighbors</returns>
int Cell::getNiborNum()
{
	return this->niborNum;
}

/// <summary>
/// getter of Cell status
/// </summary>
/// <returns>True / False</returns>
bool Cell::getStatus()
{
	return this->status;
}

/// <summary>
/// sets Coord and status (active / inactive) of object
/// </summary>
/// <param name="x">coord in x axis</param>
/// <param name="y">coord in y axis</param>
/// <param name="stat">status (active / inactive)</param>
void Cell::setData(int x, int y, bool stat)
{
	this->localXY.setCoordComps(x, y);
	this->setStatus(stat);
}

/// <summary>
/// increments number of active neighbors
/// </summary>
void Cell::addNibor()
{
	this->niborNum += 1;
}

/// <summary>
/// setter of neighbor numbers
/// </summary>
/// <param name="num">number to set</param>
void Cell::setNiborNum(int num)
{
	this->niborNum = num;
}
