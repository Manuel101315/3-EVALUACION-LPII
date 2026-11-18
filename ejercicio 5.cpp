#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD c = {(short)x, (short)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void digito(int d, int x, int y, int n) {
    int m = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool b = false;
            if (d == 0) b = (i == 0 || i == n - 1 || j == 0 || j == n - 1);
            else if (d == 1) b = (j == n - 1);
            else if (d == 2) b = (i == 0 || i == m || i == n - 1 || (j == n - 1 && i < m) || (j == 0 && i > m));
            else if (d == 3) b = (i == 0 || i == m || i == n - 1 || j == n - 1);
            else if (d == 4) b = (i == m || j == n - 1 || (j == 0 && i < m));
            else if (d == 5) b = (i == 0 || i == m || i == n - 1 || (j == 0 && i < m) || (j == n - 1 && i > m));
            else if (d == 6) b = (i == 0 || i == m || i == n - 1 || j == 0 || (j == n - 1 && i > m));
            else if (d == 7) b = (i == 0 || j == n - 1);
            else if (d == 8) b = (i == 0 || i == m || i == n - 1 || (j == 0 || j == n - 1));
            else if (d == 9) b = (i == 0 || i == m || i == n - 1 || (j == n - 1 || (j == 0 && i < m)));
            
            if (b) {
                gotoxy(x + j, y + i);
                cout << "*";
            }
        }
    }
}

void anio(int a, int x, int y, int n) {
    int sep = n + 2;
    digito(a / 1000, x, y, n);                  
    digito((a / 100) % 10, x + sep, y, n);      
    digito((a / 10) % 10, x + (sep * 2), y, n); 
    digito(a % 10, x + (sep * 3), y, n);       
}

int main() {
    int n = 7; 

    
    for (int a = 1950; a <= 2012; a++) {
        system("cls"); 
        
      
        gotoxy(5, 2);
        cout << "MOSTRANDO ANIO: " << a;
        
       
        anio(a, 5, 5, n);
        
        Sleep(200); 
    }

    gotoxy(0, n + 8);
    cout << "\nFin de la secuencia.\n";
return 0;
}


