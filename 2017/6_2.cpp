#include <iostream>
#include <fstream>

using namespace std;

bool CzySymetryczny(int wiersz[], int rozmiar)
{
    for(int i = 0; i < rozmiar / 2; ++i)
    {
        if(wiersz[i] != wiersz[319 - i]) return false;
    }
    return true;
}

void Zad6_2(string sciezka)
{
    ifstream plik;
    int liczba = 0;
    int wiersz[320] = {0};

    plik.open(sciezka);

    for(int i = 0;plik.good(); ++i)
    {   
        if(i > 0 && i % 320 == 0)
        {
            if(!CzySymetryczny(wiersz, 320)) ++liczba;
        }
        plik >> wiersz[i % 320];
    }
    plik.close();
    cout << "Liczba wierszy do usuniecia: " << liczba << endl;
}

int main()
{
    Zad6_2("dane.txt");
    return 0;
}