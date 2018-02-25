#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Rozszyfruj(string zaszyfrowane, int klucz)
{
    string wyjscie = "";

    for(int i = 0; i < zaszyfrowane.size(); ++i)
    {
        wyjscie += (char)(((zaszyfrowane[i] - 65 - (klucz % 26) + 26) % 26) + 65);
    }
    return wyjscie;
}

void Zad6_2(string sciezka)
{
    ifstream plik;
    string slowo = "";
    int klucz = 0;
    
    plik.open(sciezka);

    for(int i = 0; plik.good();++i)
    {
        plik >> slowo;
        plik >> klucz;
        if(!plik >> klucz)
        {
            plik.clear();
            plik.sync();
            cout << "Blad wczytywania klucza" << endl;
        }
        else cout << i << ". " << Rozszyfruj(slowo, klucz) << endl;
    }
    plik.close();
}

int main()
{
    Zad6_2("dane_6_2.txt");
    return 0;
}