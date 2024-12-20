﻿// Konrad El-Hagin 203652 ACiR Gra a la Kono
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PLANSZA_SIZE = 4;

char IMIE_GRACZA[15] = {};
// wypelnienie planszy poczatkowa pozycja
char plansza[PLANSZA_SIZE][PLANSZA_SIZE] = {
                                             {'c','c','c','c'},
                                             {' ',' ',' ',' '},
                                             {' ',' ',' ',' '},
                                             {'b','b','b','b'}
                                           };

// deklaracja tabeli ze wszystkimi zagranymi ruchami
char ruchy[100][9]; 

int KTORY_RUCH = 0; 

// deklaracja zmiennych potrzebnych do zrobienia zegara
time_t czas1, czas2, dlugosc_gry, laczny_czas = 0;

// wypisanie pol planszy i jej obramowki
void wypisz()
{
    system("cls");
    cout << "czarne: " << IMIE_GRACZA << endl;
    cout << "  " << char(201) << char(205) << char(205) << char(205);
    for (int i = 0; i < PLANSZA_SIZE - 1; ++i)
        cout << char(203) << char(205) << char(205) << char(205);
    cout << char(187) << endl;
    for (int wiersze = 0; wiersze < PLANSZA_SIZE; ++wiersze)
    {
        cout << PLANSZA_SIZE - wiersze << ' ';
        for (int kolumny = 0; kolumny < PLANSZA_SIZE; ++kolumny)
        {
            cout << char(186) << ' ' << plansza[wiersze][kolumny] << ' ';
        }
        if (wiersze != 3)
        {
            cout << char(186) << endl;
            cout << "  " << char(204) << char(205) << char(205) << char(205);
            for (int i = 0; i < PLANSZA_SIZE - 1; ++i)
                cout << char(206) << char(205) << char(205) << char(205);
            cout << char(185);
        }
        else
            cout << char(186);
         cout << endl;
    }
    cout << "  " << char(200) << char(205) << char(205) << char(205);
    for (int i = 0; i < PLANSZA_SIZE - 1; ++i)
        cout << char(202) << char(205) << char(205) << char(205);
    cout << char(188) << endl;
    cout << "    A   B   C   D  " << endl;
    cout << "Czas: " << dlugosc_gry - laczny_czas << 's' << endl;
}

// zamiana dwoch zmiennych (pol planszy, zeby wykonac ruch)
void swap(char &a, char &b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

// zapisanie ruchu do tablicy trzymajacej wszystkie zagrane ruchy w grze
void zapisanie_do_ruchy(char(&zapis)[9])
{
    for (int i = 0; i < 9; ++i)
    {
        if (zapis[i] == '\0')
            break;
        if (KTORY_RUCH < 100)
        {
            ruchy[KTORY_RUCH][i] = zapis[i];
        }
    }
    KTORY_RUCH += 1;
}

// silnik wykonuje bicie, jezeli to mozliwe 
void bicie_biale(bool &a)
{
    char ruch_do_zapisu[9] = {'*','*','*','*','*','*','*','*'};

    for (int i = 0; i < PLANSZA_SIZE; ++i)
    {
        if (plansza[i][0] == 'b' && plansza[i][1] == 'b' && plansza[i][2] == ' ' && plansza[i][3] == 'c')
        {
            plansza[i][0] = ' ';
            plansza[i][3] = 'b';

            ruch_do_zapisu[0] = 'A';
            ruch_do_zapisu[1] = (PLANSZA_SIZE - i) + '0';
            ruch_do_zapisu[2] = '-';
            ruch_do_zapisu[3] = 'C';
            ruch_do_zapisu[4] = (PLANSZA_SIZE - i) + '0';
            ruch_do_zapisu[5] = ':';
            ruch_do_zapisu[6] = 'D';
            ruch_do_zapisu[7] = (PLANSZA_SIZE - i) + '0';
            zapisanie_do_ruchy(ruch_do_zapisu);
            a = true;
            wypisz();
        }
        else if (a == false && plansza[i][3] == 'b' && plansza[i][2] == 'b' && plansza[i][1] == ' ' && plansza[i][0] == 'c')
        {
            plansza[i][3] = ' ';
            plansza[i][0] = 'b';

            ruch_do_zapisu[0] = 'D';
            ruch_do_zapisu[1] = (PLANSZA_SIZE - i) + '0';
            ruch_do_zapisu[2] = '-';
            ruch_do_zapisu[3] = 'B';
            ruch_do_zapisu[4] = (PLANSZA_SIZE - i) + '0';
            ruch_do_zapisu[5] = ':';
            ruch_do_zapisu[6] = 'A';
            ruch_do_zapisu[7] = (PLANSZA_SIZE - i) + '0';
            zapisanie_do_ruchy(ruch_do_zapisu);
            a = true;
            wypisz();
        }

    }
    for (int j = 0; j < PLANSZA_SIZE; ++j)
    {
        if (a == false && plansza[0][j] == 'b' && plansza[1][j] == 'b' && plansza[2][j] == ' ' && plansza[3][j] == 'c')
        {
            plansza[0][j] = ' ';
            plansza[3][j] = 'b';

            ruch_do_zapisu[0] = char(j + 65);
            ruch_do_zapisu[1] = '4';
            ruch_do_zapisu[2] = '-';
            ruch_do_zapisu[3] = char(j + 65);
            ruch_do_zapisu[4] = '2';
            ruch_do_zapisu[5] = ':';
            ruch_do_zapisu[6] = char(j + 65);
            ruch_do_zapisu[7] = '1';
            zapisanie_do_ruchy(ruch_do_zapisu);
            a = true;
            wypisz();
        }
        else if (a == false && plansza[3][j] == 'b' && plansza[2][j] == 'b' && plansza[1][j] == ' ' && plansza[0][j] == 'c')
        {
            plansza[3][j] = ' ';
            plansza[0][j] = 'b';

            ruch_do_zapisu[0] = char(j + 65);
            ruch_do_zapisu[1] = '1';
            ruch_do_zapisu[2] = '-';
            ruch_do_zapisu[3] = char(j + 65);
            ruch_do_zapisu[4] = '3';
            ruch_do_zapisu[5] = ':';
            ruch_do_zapisu[6] = char(j + 65);
            ruch_do_zapisu[7] = '4';
            zapisanie_do_ruchy(ruch_do_zapisu);
            a = true;
            wypisz();
        }
    }
}

/* sprawdzenie, czy ruch (niebedacy biciem) jest poprawny
a, b, c, d to wspolrzedne pol podanych przez gracza
e tylko do sprawdzenia, czy gracz napisal myslnik miedzy pierwszymi dwoma polami */
bool czy_mozliwe(int a, int b, char e, int c, int d)
{
    if (
        e == '-' && 
        plansza[a][b] == 'c' && plansza[c][d] == ' ' &&
        ((abs(c - a) == 1 && d == b) || (c == a && abs(d - b) == 1)) && 
        a >= 0 && b >= 0 && c >= 0 && d >= 0 &&
        a <= 3 && b <= 3 && c <= 3 && d <= 3
        )
        return true;
    else
        return false;
}

// sprawdzenie, czy wpisany przez gracza ruch jest biciem
bool czy_bicie(char a)
{
    if (a == ':')
        return true;
    else
        return false;
}

/*
sprawdzenie, czy bicie jest poprawne
a, b, c, d, f, g to wspolrzedne pol podanych przez gracza
e tylko do sprawdzenia, czy gracz napisal myslnik miedzy pierwszymi dwoma polami
*/
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

// wykonanie ruchu bialych (niebedacego biciem) i sprawdzenie czy czarny wygral
void ruch_bialych(bool &czy_wykonany_ruch, bool &czy_koniec)
{
    char mozliwe[PLANSZA_SIZE * 4][5];
    char do_zapisu[9] = {'*','*','*','*','*','*','*','*'};
    bool gdzie_bija_czarne[PLANSZA_SIZE][PLANSZA_SIZE] = {}; //tabela z polami, ktore moga zbic czarne
    bool gdzie_mozliwe_bicia[PLANSZA_SIZE][PLANSZA_SIZE] = {}; //tabela z polami, na ktore trzeba pojsc, aby przygotowac bicie

    // wypelnienie gdzie_bija_czarne[][] i gdzie_mozliwe_bicia[][]
    for (int i = 0; i < PLANSZA_SIZE; ++i)
    {
        for (int j = 0; j < PLANSZA_SIZE; ++j)
        {
            if ((i == 0 && plansza[2][j] == 'c' && plansza[3][j] == 'c' && plansza[1][j] == ' ') ||
                (i == (PLANSZA_SIZE - 1) && plansza[i - 2][j] == 'c' && plansza[i - 3][j] == 'c' && plansza[i - 1][j] == ' ') ||
                (j == 0 && plansza[i][2] == 'c' && plansza[i][3] == 'c' && plansza[i][1] == ' ') ||
                (j == (PLANSZA_SIZE - 1) && plansza[i][j - 2] == 'c' && plansza[i][j - 3] == 'c' && plansza[i][j - 1] == ' '))
                gdzie_bija_czarne[i][j] = 1;
            if ((i == 0 && plansza[1][j] == 'b' && plansza[2][j] == ' ' && plansza[3][j] == 'c') ||
                (i == (PLANSZA_SIZE - 1) && plansza[i - 1][j] == 'b' && plansza[i - 2][j] == ' ' && plansza[i - 3][j] == 'c') ||
                (j == 0 && plansza[i][1] == 'b' && plansza[i][2] == ' ' && plansza[i][3] == 'c') ||
                (j == (PLANSZA_SIZE - 1) && plansza[i][j - 1] == 'b' && plansza[i][j - 2] == ' ' && plansza[i][j - 3] == 'c'))
                gdzie_mozliwe_bicia[i][j] = 1;
        }
    }

    // wypelnienie mozliwe[][] samymi myslnikami
    for (int i = 0; i < PLANSZA_SIZE * 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
            mozliwe[i][j] = '-';
    }

    // znalezienie mozliwych ruchow i wpisanie ich do mozliwe[][]
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

    
    /* wykonanie ruchu bialych przez komputer prioretytezujac najlepsze ruchy wedlug kryteriow
      -czy ruch uniemozliwia strate pionka
      -czy ruch nie podstawia pionka
      -czy ruch przygotowywuje bicie w nastepnej turze
    */
    
    // gdy jest mozliwy ruch wychodzacy spod bicia, nie podchodzacy pod bicie i przygotowywujacy bicie w nastepnej turze
    for (int k = 0; k < PLANSZA_SIZE * 4; ++k)
    {
        if (czy_wykonany_ruch == true || mozliwe[0][0] == '-')
            break;
        else if (mozliwe[k][0] != '-')
        {
            int a = PLANSZA_SIZE - (mozliwe[k][1] - '0');
            int b = int(mozliwe[k][0]) - 65;
            int c = PLANSZA_SIZE - (mozliwe[k][4] - '0');
            int d = int(mozliwe[k][3]) - 65;

            if (gdzie_bija_czarne[a][b] == 1 && gdzie_bija_czarne[c][d] != 1 && gdzie_mozliwe_bicia[c][d] == 1)
            {
                for (int i = 0; i < 5; ++i)
                {
                    do_zapisu[i] = mozliwe[k][i];
                }
                zapisanie_do_ruchy(do_zapisu);
                swap(plansza[a][b], plansza[c][d]);
                czy_wykonany_ruch = true;
                wypisz();
            }
        }
    }

    // gdy jest mozliwy ruch wychodzacy spod bicia, nie podchodzacy pod bicie, ale tez nie przygotowywujacy bicia w nastepnej turze
    for (int k = 0; k < PLANSZA_SIZE * 4; ++k)
    {
        if (czy_wykonany_ruch == true || mozliwe[0][0] == '-')
            break;
        else if (mozliwe[k][0] != '-')
        {
            int a = PLANSZA_SIZE - (mozliwe[k][1] - '0');
            int b = int(mozliwe[k][0]) - 65;
            int c = PLANSZA_SIZE - (mozliwe[k][4] - '0');
            int d = int(mozliwe[k][3]) - 65;

            if (gdzie_bija_czarne[a][b] == 1 && gdzie_bija_czarne[c][d] != 1)
            {
                for (int i = 0; i < 5; ++i)
                {
                    do_zapisu[i] = mozliwe[k][i];
                }
                zapisanie_do_ruchy(do_zapisu);
                swap(plansza[a][b], plansza[c][d]);
                czy_wykonany_ruch = true;
                wypisz();
            }
        }
    }

    // gdy jest mozliwy ruch nie wychodzacy spod bicia, nie podchodzacy pod bicie i przygotowywujacy bicie w nastepnej turze
    for (int k = 0; k < PLANSZA_SIZE * 4; ++k)
    {
        if (czy_wykonany_ruch == true || mozliwe[0][0] == '-')
            break;
        else if (mozliwe[k][0] != '-')
        {
            int a = PLANSZA_SIZE - (mozliwe[k][1] - '0');
            int b = int(mozliwe[k][0]) - 65;
            int c = PLANSZA_SIZE - (mozliwe[k][4] - '0');
            int d = int(mozliwe[k][3]) - 65;

            if (gdzie_bija_czarne[a][b] != 1 && gdzie_bija_czarne[c][d] != 1 && gdzie_mozliwe_bicia[c][d] == 1)
            {
                for (int i = 0; i < 5; ++i)
                {
                    do_zapisu[i] = mozliwe[k][i];
                }
                zapisanie_do_ruchy(do_zapisu);
                swap(plansza[a][b], plansza[c][d]);
                czy_wykonany_ruch = true;
                wypisz();
            }
        }
    }

    // gdy jest mozliwy ruch nie wychodzacy spod bicia, nie podchodzacy pod bicie, ale tez nie przygotowywujacy bicia w nastepnej turze
    srand(time(NULL));
    for (int k = rand() % (PLANSZA_SIZE * 4); k < PLANSZA_SIZE * 4; k = rand() % (PLANSZA_SIZE * 4))
    {
        if (czy_wykonany_ruch == true || mozliwe[0][0] == '-')
            break;
        else if (mozliwe[k][0] != '-')
        {
            int a = PLANSZA_SIZE - (mozliwe[k][1] - '0');
            int b = int(mozliwe[k][0]) - 65;
            int c = PLANSZA_SIZE - (mozliwe[k][4] - '0');
            int d = int(mozliwe[k][3]) - 65;

            if (gdzie_bija_czarne[a][b] != 1 && gdzie_bija_czarne[c][d] != 1)
            {
                for (int i = 0; i < 5; ++i)
                {
                    do_zapisu[i] = mozliwe[k][i];
                }
                zapisanie_do_ruchy(do_zapisu);
                swap(plansza[a][b], plansza[c][d]);
                czy_wykonany_ruch = true;
                wypisz();
            }
        }
    }

    // jezeli zadna inna opcja nie jest mozliwa losowy ruch
    for (int k = rand() % (PLANSZA_SIZE * 4); k < PLANSZA_SIZE * 4; k = rand() % (PLANSZA_SIZE * 4))
    {
        if (czy_wykonany_ruch == true || mozliwe[0][0] == '-')
            break;
        else if (mozliwe[k][0] != '-')
        {
            int a = PLANSZA_SIZE - (mozliwe[k][1] - '0');
            int b = int(mozliwe[k][0]) - 65;
            int c = PLANSZA_SIZE - (mozliwe[k][4] - '0');
            int d = int(mozliwe[k][3]) - 65;

            for (int i = 0; i < 5; ++i)
            {
                do_zapisu[i] = mozliwe[k][i];
            }
            zapisanie_do_ruchy(do_zapisu);
            swap(plansza[a][b], plansza[c][d]);
            czy_wykonany_ruch = true;
            wypisz();
        }
    }

    /* wypisanie mozliwe[][] dla testow
    
    for (int i = 0; i < PLANSZA_SIZE * 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cout << mozliwe[i][j];
        }
        cout << endl;
    }
    */

    // warunek wygranej
    if (mozliwe[0][0] == '-')
        czy_koniec = true;
}

//funkcja do cofania ruchow
void undo(int ile_razy, bool czy_usunac)
{
    for (int i = 0; i < ile_razy; ++i)
    {
        int a = PLANSZA_SIZE - (ruchy[KTORY_RUCH - 1][1] - '0');
        int b = int(ruchy[KTORY_RUCH - 1][0]) - 65;
        int c = PLANSZA_SIZE - (ruchy[KTORY_RUCH - 1][4] - '0');
        int d = int(ruchy[KTORY_RUCH - 1][3]) - 65;
        int e = PLANSZA_SIZE - (ruchy[KTORY_RUCH - 1][7] - '0');
        int f = int(ruchy[KTORY_RUCH - 1][6]) - 65;

        if (ruchy[KTORY_RUCH - 1][5] != ':')
            swap(plansza[c][d], plansza[a][b]);
        else
        {
            if (plansza[abs((a + c) / 2)][abs((b + d) / 2)] == 'b')
            {
                plansza[a][b] = 'b';
                plansza[e][f] = 'c';
            }
            if (plansza[abs((a + c) / 2)][abs((b + d) / 2)] == 'c')
            {
                plansza[a][b] = 'c';
                plansza[e][f] = 'b';
            }
        }
        if (czy_usunac == true)
        {
            for (int i = 0; i < 8; ++i)
                ruchy[KTORY_RUCH - 1][i] = '*';
        }
        KTORY_RUCH -= 1;
    }
}

//przeciwienstwo undo
void do_przodu(int ile_razy)
{
    for (int i = 0; i < ile_razy; ++i)
    {
        int a = PLANSZA_SIZE - (ruchy[KTORY_RUCH][1] - '0');
        int b = int(ruchy[KTORY_RUCH][0]) - 65;
        int c = PLANSZA_SIZE - (ruchy[KTORY_RUCH][4] - '0');
        int d = int(ruchy[KTORY_RUCH][3]) - 65;
        int e = PLANSZA_SIZE - (ruchy[KTORY_RUCH][7] - '0');
        int f = int(ruchy[KTORY_RUCH][6]) - 65;

        if (ruchy[KTORY_RUCH][5] != ':')
            swap(plansza[a][b], plansza[c][d]);
        else
        {
            if (plansza[abs((a + c) / 2)][abs((b + d) / 2)] == 'b')
            {
                plansza[a][b] = ' ';
                plansza[e][f] = 'b';
            }
            if (plansza[abs((a + c) / 2)][abs((b + d) / 2)] == 'c')
            {
                plansza[a][b] = ' ';
                plansza[e][f] = 'c';
            }
        }
        KTORY_RUCH += 1;
    }
}

void wypisz_ruchy()
{
    for (int i = 0; i < 100; ++i)
    {
        if (ruchy[i][0] != '*')
            cout << endl << i + 1 << ": ";
        for (int j = 0; j < 8; ++j)
        {
            if (ruchy[i][j] != '*')
                cout << ruchy[i][j];
        }
    }
}

int main()
{
    bool czy_koniec = false;
    char ruch[9];
    cout << "INSTRUKCJA" << endl;
    cout << "Gracze na zmiane wykonuja kolejne ruchy. W jednym ruchu dowolnie wybrany pion moze przejsc na sasiednie pole wolne poziomo lub pionowo w dowolna strone. Bicie pionow przeciwnika odbywa sie po linii prostej, poprzez przeskoczenie pionem bijacym przez sasiadujacy wlasny pion na wolne pole przed nim a nastepnie przesuniecie pionka skaczacego (bijacego) na pierwsze pole zajete przez wrogi pion w linii skoku. Pion ten zostaje wowczas zabity i zdjety z planszy. Ruchy podawaj WIELKIMI literami i pisz myslniki i dwukropki w odpowiednich miejscach. Gra konczy sie, gdy ktorys z graczy nie ma zadnych pionkow, wszystkie jego pionki sa otoczone lub skonczyl mu sie czas." << endl;
    cout << endl << "Podaj swoje imie: ";
    cin >> IMIE_GRACZA;
    cout << "Podaj dlugosc gry (w sekundach): ";
    cin >> dlugosc_gry;
    wypisz();

    // wypelnienie ruchy[][] gwiazdkami
    for (int i = 0; i < 100; ++i) 
    {
        for (int j = 0; j < 8; ++j)
        {
            ruchy[i][j] = '*';
        }
    }

    while (true)
    {
        czas1 = time(NULL); //pomiar czasu przed ruchem gracza

        cout << "Podaj ruch (jezeli chcesz cofnac ruch wpisz 'undo': ";
        cin >> ruch;

        czas2 = time(NULL); //pomiar czasu po ruchu gracza

        laczny_czas += difftime(czas2, czas1); //czas zuzyty przez gracza od poczatku gry

        
        if (ruch[0] != 'u' && ruch[1] != 'n' && ruch[2] != 'd' && ruch[3] != 'o')
        {
            // zamiana charow podanych przez gracza na wspolrzedne pol
            int a = PLANSZA_SIZE - (ruch[1] - '0');
            int b = int(ruch[0]) - 65;
            int c = PLANSZA_SIZE - (ruch[4] - '0');
            int d = int(ruch[3]) - 65;
            int e = PLANSZA_SIZE - (ruch[7] - '0');
            int f = int(ruch[6]) - 65;

            // wykonanie ruchu wpisanego przez gracza, jezeli jest mozliwy
            if (czy_bicie(ruch[5]))
            {
                if (czy_mozliwe_bicie(a, b, ruch[2], c, d, e, f))
                {
                    plansza[a][b] = ' ';
                    plansza[e][f] = 'c';
                    wypisz();
                    zapisanie_do_ruchy(ruch);
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
                    zapisanie_do_ruchy(ruch);
                }
                else
                {
                    wypisz();
                    cout << "bledny ruch" << endl;
                    continue;
                }
            }

            // RUCH KOMPUTERA
            bool czy_wykonany_ruch = false;

            bicie_biale(czy_wykonany_ruch);

            ruch_bialych(czy_wykonany_ruch, czy_koniec);

            //warunek przegranej
            int ile_bialych = 0;
            int ile_bialych_nie_moze_sie_ruszyc = 0;
            for (int i = 0; i < PLANSZA_SIZE; ++i)
            {
                for (int j = 0; j < PLANSZA_SIZE; ++j)
                {
                    if (plansza[i][j] == 'c')
                        ++ile_bialych;
                    if (plansza[i][j] == 'c' &&
                        (i + 1 >= PLANSZA_SIZE || plansza[i + 1][j] != ' ') &&
                        (i - 1 < 0 || plansza[i - 1][j] != ' ') &&
                        (j + 1 >= PLANSZA_SIZE || plansza[i][j + 1] != ' ') &&
                        (j - 1 < 0 || plansza[i][j - 1] != ' '))
                        ++ile_bialych_nie_moze_sie_ruszyc;
                }
            }
            if (ile_bialych_nie_moze_sie_ruszyc == ile_bialych || ile_bialych == 0 || laczny_czas >= dlugosc_gry)
            {
                cout << "Przegrales :(" << endl;
                break;
            }

            //warunek wygranej
            if (czy_koniec == true)
            {
                cout << "WYGRALES!!!" << endl;
                break;
            }
        }
        else
        {
            undo(2, true);
            wypisz();
        }
        
    }
    wypisz_ruchy();

    while (true)
    {
        int pozycja;
        cout << endl << "Podaj pozycje, do ktorej chcesz sie przeniesc, jezeli chcesz skonczyc napisz '-1': ";
        cin >> pozycja;
        if (pozycja == -1)
            break;
        if (pozycja < KTORY_RUCH)
            undo(KTORY_RUCH - pozycja, false);
        if (pozycja > KTORY_RUCH)
            do_przodu(pozycja - KTORY_RUCH);
        wypisz();
        wypisz_ruchy();
    }
    return 0;
}
