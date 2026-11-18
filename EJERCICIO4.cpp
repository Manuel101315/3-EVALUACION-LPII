#include <iostream>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {(SHORT)x, (SHORT)y});
}

void C(int x, int y, int n){
	int i, j;
	for (i = 0; i < n; i++){
		for(j = 0; j < n; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1){
				gotoxy(x + j, y + i);
				cout << "*";
			}
		}
	}
}

int leer(int min, int max){
	int v;
	do{
		while (!(cin >> v)) {
			cin.clear();
			cin.ignore(1000, '\n'); // <-- Corrección: Se cambió la coma ',' por un punto '.'
		}
	} while (v < min || v > max);
	return v;
}
	
int main() {
	cout << "Anio 1 (1950-2012): "; int a1 = leer(1950, 2012);
	cout << "Anio 2 (1950-2012): "; int a2 = leer(1950, 2012);
	cout << "Tamano n (5 a 7): "; int n = leer(5, 7);
	
	system("cls");
	gotoxy(5, 2); cout << "Integrante1";
	gotoxy(5 + (n + 2) * 5, 2); cout << "Integrante2";
	
	int paso = n + 2;
	for (int i = 0; i < 4; i++) {
		C(5 + i * paso, 5, n);
		C(5 + (n + 2) * 5 + i * paso, 5, n);
	}	
	gotoxy(0, 15);
	
	return 0;
}

