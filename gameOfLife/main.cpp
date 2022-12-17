#include <iostream>
#include <stdlib.h>
#include "Cell.h"
//#include "Matrix.h"


using namespace std;

int main() 
{	
	int x;
	int y;
	Cell m[10][10];

	for (x = 0; x <= 9; x++)
	{
		for (y = 0; y <= 9; y++)
		{
			cout << x << y << " ";
			m[x][y].setData(x, y, y);
		}
		cout << '\n';
	}

	for (x = 0; x <= 9; x++) {
		for (y = 0; y <= 9; y++) {

			if ((8 >= x && x >= 1) && (8 >= y && y >= 1)) {
				for (int i = -1; i <= 1; i++) {
					for (int j = -1; j <= 1; j++) {

						if (i == 0 && j == 0) {
							continue;

						}

						else {

							if (m[x + i][y + j].getStatus() == 1) {
								m[x][y].addNibor();

							}
						}
					}
				}
			}

			//									corner
			if (x == 0 && y == 0) {
				for (int i = 0; i <= 1; i++) {
					for (int j = 0; j <= 1; j++) {

						if (i == 0 && j == 0) {
							continue;

						}

						else {

							if (m[x + i][y + j].getStatus() == 1) {
								m[x][y].addNibor();

							}
						}
					}
				}
			}

			//									corner
			if (x == 9 && y == 0) {
				for (int i = -1; i <= 0; i++) {
					for (int j = 0; j <= 1; j++) {

						if (i == 0 && j == 0) {
							continue;

						}

						else {

							if (m[x + i][y + j].getStatus() == 1) {
								m[x][y].addNibor();

							}
						}
					}
				}
			}

			//									corner
			if (x == 0 && y == 9) {
				for (int i = 0; i <= 1; i++) {
					for (int j = -1; j <= 0; j++) {

						if (i == 0 && j == 0) {
							continue;

						}

						else {

							if (m[x + i][y + j].getStatus() == 1) {
								m[x][y].addNibor();

							}
						}
					}
				}
			}

			//									corner
			if (x == 9 && y == 9) {
				for (int i = -1; i <= 0; i++) {
					for (int j = -1; j <= 0; j++) {

						if (i == 0 && j == 0) {
							continue;

						}

						else {

							if (m[x + i][y + j].getStatus() == 1) {
								m[x][y].addNibor();

							}
						}
					}
				}
			}
		}
	}

	for (x = 0; x <= 9; x++) {
		for (y = 0; y <= 9; y++) {
			cout << m[x][y].getNiborNum() << " ";
		}
		cout << '\n';
	}

	for (x = 0; x <= 9; x++) {
		for (y = 0; y <= 9; y++) {
			m[x][y].printData();
		}

	}

	
	return 0;
}