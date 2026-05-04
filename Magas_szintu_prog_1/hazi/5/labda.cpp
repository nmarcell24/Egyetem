#include <iostream>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{

    int szelesseg = 40, magassag = 15;
    int x = 1, y = 1;
    int dx = 1, dy = 1;

    for (int i = 0; i < szelesseg; i++) {
        gotoxy(i, 0); cout << "-";
        gotoxy(i, magassag - 1); cout << "-";
    }
    for (int i = 0; i < magassag; i++) {
        gotoxy(0, i); cout << "|";
        gotoxy(szelesseg - 1, i); cout << "|";
    }
    gotoxy(0, 0); cout << "+";
    gotoxy(szelesseg - 1, 0); cout << "+";
    gotoxy(0, magassag - 1); cout << "+";
    gotoxy(szelesseg - 1, magassag - 1); cout << "+";

    while (true)
    {

        gotoxy(x, y);
        cout << " ";

        x += dx;
        y += dy;

        if (x <= 1 || x >= szelesseg - 2)
            dx *= -1;
        if (y <= 1 || y >= magassag - 2)
            dy *= -1;

        gotoxy(x, y);
        cout << "O";

        Sleep(80);
    }

    return 0;
}