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
		
	cout << "wcisnij ""1"" aby wylosowac stany\nwcisnij ""2"" aby wylosowac wybrana ilosc stanow\nwcisnij ""3"" aby podac je samemu\nalbo cokolwiek by zostawic pusta tablice\n" << endl;
	system("PAUSE");

	if (GetAsyncKeyState('1')) {	
		m.randomizer();
	}
	else if (GetAsyncKeyState('2')) {
		m.properRandomizer();
	}
	else if (GetAsyncKeyState('3')) {
		
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

			if (m.checker(int(x), int(y)) == 1) {
				m.swapStatus(int(y - 1), int(x - 1));
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

		//g³ówny algorytm
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
			m.setAllFalse();
			m.properRandomizer();
			gen = 1;
		}
		Sleep(int(czas));
		system("CLS");
	}
	return 0;
}