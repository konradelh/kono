#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

const int PLANSZA_SIZE = 4;
char plansza[PLANSZA_SIZE][PLANSZA_SIZE] = {
                                             {'c','c','c','c'},
                                             {' ',' ',' ',' '},
                                             {' ',' ',' ',' '},
                                             {'b','b','b','b'}
                                           };

void wypisz()
{
    system("cls");
    for (int wiersze = 0; wiersze < PLANSZA_SIZE; ++wiersze)
    {
        cout << PLANSZA_SIZE - wiersze;
        for (int kolumny = 0; kolumny < PLANSZA_SIZE; ++kolumny)
        {
            cout << " |" << plansza[wiersze][kolumny];
        }
        cout << " |" << endl;
    }
    cout << "   A  B  C  D " << endl;
}

void swap(char &a, char &b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

void bicie_biale(bool &a)
{
    for (int i = 0; i < PLANSZA_SIZE; ++i)
    {
        if (plansza[i][0] == 'b' && plansza[i][1] == 'b' && plansza[i][2] == ' ' && plansza[i][3] == 'c')
        {
            plansza[i][0] = ' ';
            plansza[i][3] = 'b';
            a = true;
        }
        else if (a == false && plansza[i][3] == 'b' && plansza[i][2] == 'b' && plansza[i][1] == ' ' && plansza[i][0] == 'c')
        {
            plansza[i][3] = ' ';
            plansza[i][0] = 'b';
            a = true;
        }

    }
    for (int j = 0; j < PLANSZA_SIZE; ++j)
    {
        if (a == false && plansza[0][j] == 'b' && plansza[1][j] == 'b' && plansza[2][j] == ' ' && plansza[3][j] == 'c')
        {
            plansza[0][j] = ' ';
            plansza[3][j] = 'b';
            a = true;
        }
        else if (a == false && plansza[3][j] == 'b' && plansza[2][j] == 'b' && plansza[1][j] == ' ' && plansza[0][j] == 'c')
        {
            plansza[3][j] = ' ';
            plansza[0][j] = 'b';
            a = true;
        }
    }
}

bool czy_mozliwe(int a, int b, char e, int c, int d)
{
    if (
        e == '-' && 
        plansza[a][b] == 'c' && plansza[c][d] == ' ' &&
        ((abs(c - a) == 1 && d == b) || (c == a && abs(d - b) == 1)) && 
        a >= 0 && b >= 0 && c >= 0 && d >= 0
        )
        return true;
    else
        return false;
}

bool czy_bicie(char a)
{
    if (a == ':')
        return true;
    else
        return false;
}

bool czy_mozliwe_bicie(int a, int b, char e, int c, int d, int f, int g)
{
    if (
        e == '-' &&
        plansza[a][b] == 'c' && plansza[c][d] == ' ' && plansza[f][g] == 'b' &&
        (
          (abs(c - a) == 2 && d == b && abs(f - a) == 3 && g == b && plansza[(a + c) / 2][b] == 'c')
          ||
          (c == a && abs(d - b) == 2 && abs(g - b) == 3 && f == a && plansza[a][(b + d) / 2] == 'c')
        ) &&
        a >= 0 && b >= 0 && c >= 0 && d >= 0 && f >= 0 && g >= 0
        )
        return true;
    else
        return false;
}

void mozliwe_ruchy()
{
    char mozliwe[PLANSZA_SIZE * 4][5];

    for (int i = 0; i < PLANSZA_SIZE * 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
            mozliwe[i][j] = '-';
    }

    for (int i = 0; i < PLANSZA_SIZE; ++i)
    {
        for (int j = 0; j < PLANSZA_SIZE; ++j)
        {
            if (plansza[i][j] == 'b' && i != (PLANSZA_SIZE - 1) && plansza[i + 1][j] == ' ')
            {
                for (int k = 0; k < PLANSZA_SIZE * 4; ++k)
                {
                    if (mozliwe[k][0] == '-')
                    {
                        mozliwe[k][0] = char(j + 65);
                        mozliwe[k][1] = (PLANSZA_SIZE - i) + '0';
                        mozliwe[k][3] = char(j + 65);
                        mozliwe[k][4] = (PLANSZA_SIZE - i - 1) + '0';
                        break;
                    }
                }
            }
            if (plansza[i][j] == 'b' && i != 0 && plansza[i - 1][j] == ' ')
            {
                for (int k = 0; k < PLANSZA_SIZE * 4; ++k)
                {
                    if (mozliwe[k][0] == '-')
                    {
                        mozliwe[k][0] = char(j + 65);
                        mozliwe[k][1] = (PLANSZA_SIZE - i) + '0';
                        mozliwe[k][3] = char(j + 65);
                        mozliwe[k][4] = (PLANSZA_SIZE - i + 1) + '0';
                        break;
                    }
                }
            }
            if (plansza[i][j] == 'b' && j != (PLANSZA_SIZE - 1) && plansza[i][j + 1] == ' ')
            {
                for (int k = 0; k < PLANSZA_SIZE * 4; ++k)
                {
                    if (mozliwe[k][0] == '-')
                    {
                        mozliwe[k][0] = char(j + 65);
                        mozliwe[k][1] = (PLANSZA_SIZE - i) + '0';
                        mozliwe[k][3] = char(j + 66);
                        mozliwe[k][4] = (PLANSZA_SIZE - i) + '0';
                        break;
                    }
                }
            }
            if (plansza[i][j] == 'b' && j != 0 && plansza[i][j - 1] == ' ')
            {
                for (int k = 0; k < PLANSZA_SIZE * 4; ++k)
                {
                    if (mozliwe[k][0] == '-')
                    {
                        mozliwe[k][0] = char(j + 65);
                        mozliwe[k][1] = (PLANSZA_SIZE - i) + '0';
                        mozliwe[k][3] = char(j + 64);
                        mozliwe[k][4] = (PLANSZA_SIZE - i) + '0';
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < PLANSZA_SIZE * 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cout << mozliwe[i][j];
        }
        cout << endl;
    }

    if (mozliwe[0][0] == '-')
        cout << "WYGRALES!!";
}

int main()
{
    char ruch[8];
    int loop_counter = 0;

    wypisz();

    while (true)
    {
        cin >> ruch;

        int a = PLANSZA_SIZE - (ruch[1] - '0');
        int b = int(ruch[0]) - 65;
        int c = PLANSZA_SIZE - (ruch[4] - '0');
        int d = int(ruch[3]) - 65;
        int e = PLANSZA_SIZE - (ruch[7] - '0');
        int f = int(ruch[6]) - 65;

        if (czy_bicie(ruch[5]))
        {
            if (czy_mozliwe_bicie(a, b, ruch[2], c, d, e, f))
            {
                plansza[a][b] = ' ';
                plansza[e][f] = 'c';
                wypisz();
            }
            else
            {
                wypisz();
                cout << "bledny ruch" << endl;
                continue;
            }
        }
        else
        {
            if (czy_mozliwe(a, b, ruch[2], c, d))
            {
                swap(plansza[a][b], plansza[c][d]);
                wypisz();
            }
            else
            {
                wypisz();
                cout << "bledny ruch" << endl;
                continue;
            }
        }

        bool czy_wykonany_ruch = false;

        bicie_biale(czy_wykonany_ruch);
        
        mozliwe_ruchy();

        ++loop_counter;
    }
}
