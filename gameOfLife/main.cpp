#include <iostream>
#include <windows.h>
#include "Matrix.h"

using namespace std;


int main() 
{	
	int gen = 1;
	int x;
	int y;
	int czas;

	Matrix m;
		
	cout << "wcisnij ""A"" aby wylosowac stany\nwcisnij ""S"" aby wylosowac wybrana ilosc stanow\nwcisnij ""D"" aby podac je samemu\nalbo cokolwiek by zostawic pusta tablice\n" << endl;
	
	system("PAUSE");
	
	if (GetAsyncKeyState('A')) {	
		m.randomizer();
	}
	else if (GetAsyncKeyState('S')) {
		m.properRandomizer();
	}
	else if (GetAsyncKeyState('D')) {
		
		while (!(GetAsyncKeyState(VK_SPACE))) {
			system("CLS");
			x = 0;
			y = 0;
			cout << "podaj x: ";
			cin >> x;

			if (cin.fail()) {	
				cout << endl << "prosze podac wlasciwe dane" << endl;
				cin.clear();
				cin.ignore();
				continue;
			}

			cout << endl;
			cout << "podaj y: ";
			cin >> y;

			if (cin.fail()) {
				cout << endl << "prosze podac wlasciwe dane" << endl;
				cin.clear();
				cin.ignore();
				continue;
			}

			cout << endl;
			
			if (m.placementChecker(x, y) == 1) {
				m.swapStatus(y, x);
			}
			else {
				cout << "zle dane!" << endl;
			}
			m.allPrinter();

			cout << "aby zakonczyc wsisnij spacje" << endl;

			system("PAUSE");
		}
	}


	system("CLS");

	cout << "podaj odstep czasowy pomiedzy generacjami: ";
	cin >> czas;
	cout << "\nwcisnij spacje podczas symulacji aby aby zapauzowac symulacje i wyswietlic opcje\n";

	system("PAUSE");

	while (!GetAsyncKeyState(VK_ESCAPE)) {

		
		m.allNiborsScan();
		m.setAllNewStatus();
		cout << "\ngeneracja: " << gen; 
		m.allNiborsReset();
		

		gen++;


		if (GetAsyncKeyState(VK_SPACE)) {
			cout << "\n1. wciœnij spacje by przejsc jedna generacje dalej \n2. wcisnij dowolny klawisz by symulacja dzialala sama";
			cout <<"\n3. wcisnij klawisz ""N"" aby wylosowac nowa symulacje \n4. wcisnij klawisz escape by zakonczyc symulacje \n";
			cout << "5. wcisnij klawisz ""M"" aby zadac nowa ilosc stanow\n";
			system("PAUSE");
		}	
		if (GetAsyncKeyState('N')) {
			m.setAllFalse();
			m.randomizer();
			gen = 1;
		}
		if (GetAsyncKeyState('M')) {
			cin.clear();
			fflush(stdin);
			m.setAllFalse();
			m.properRandomizer();
			gen = 1;
		}
		Sleep(int(czas));
		system("CLS");
	}
	return 0;
}