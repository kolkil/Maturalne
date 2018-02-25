#include <iostream>
#include <fstream>

using namespace std;

int LiczKontrasty(int obraz[][320])
{
    int liczba = 0;

    for(int i = 0; i < 200; ++i)
    {
        for(int k = 0; k < 320; ++k)
        {
            bool CzyZliczono = false;
            if(k > 0 && !CzyZliczono)
                if(obraz[i][k] - obraz[i][k - 1] > 128 || obraz[i][k] - obraz[i][k - 1] < -128) 
                {
                    ++liczba;
                    CzyZliczono = true;
                }
            
            if(k < 318 && !CzyZliczono)
                if(obraz[i][k] - obraz[i][k + 1] > 128 || obraz[i][k] - obraz[i][k + 1] < -128) 
                {
                    ++liczba;
                    CzyZliczono = true;
                }

            if(i > 0 && !CzyZliczono)
                if(obraz[i][k] - obraz[i - 1][k] > 128 || obraz[i][k] - obraz[i - 1][k] < -128)
                {
                    ++liczba;
                    CzyZliczono = true;
                }
            
            if(i < 198 && !CzyZliczono)
                if(obraz[i][k] - obraz[i + 1][k] > 128 || obraz[i][k] - obraz[i + 1][k] < -128) 
                {
                    ++liczba;
                    CzyZliczono = true;
                }
        }
    }

    return liczba;
}

void Zad6_2(string sciezka)
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
    cout << "Liczba konstrastujacych pikseli: " << LiczKontrasty(obraz) << endl;
}

int main()
{
    Zad6_2("dane.txt");
    return 0;
}