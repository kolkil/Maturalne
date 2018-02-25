#include <iostream>
#include <fstream>

using namespace std;

int DlugoscLinii(int obraz[][320])
{
    int max = 0;

    for(int i = 0; i < 320; ++i)
    {
        int dlugosc = 1;
        for(int k = 0; k < 199; ++k)
        {
            if(obraz[k][i] == obraz[k+1][i]) 
            {
                ++dlugosc;
                if(dlugosc > max) max = dlugosc;
            }
            else
            {
                dlugosc = 1;
            }
        }
    }
    return max;
}

void Zad6_4(string sciezka)
{
    ifstream plik;
    int obraz[200][320];

    plik.open(sciezka);

    for(int i = 0; i < 200; ++i)
    {
        for(int k = 0; k < 320; ++k)
        {
            plik >> obraz[i][k];
        }
    }
    plik.close();
    cout << "Dlugosc najdluzszej linii: " << DlugoscLinii(obraz) << endl;
}

int main()
{
    Zad6_4("dane.txt");
    return 0;
}