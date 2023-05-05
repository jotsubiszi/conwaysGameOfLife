#include "Coord.h"

/// <summary>
/// setter of Coord parameters
/// </summary>
/// <param name="x">coord in x axis</param>
/// <param name="y">coord in y axis</param>
void Coord::setCoordComps(int x, int y)
{
	this->X = x;
	this->Y = y;
}

/// <summary>
/// getter of X int in Coord object
/// </summary>
/// <returns>x coord</returns>
int Coord::getCoordComponX()
{
	return this->X;
}

/// <summary>
/// getter of Y int in Coord object
/// </summary>
/// <returns>y coord</returns>
int Coord::getCoordComponY()
{
	return this->Y;
}
