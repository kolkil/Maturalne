#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Rozszyfruj(string zaszyfrowane, int klucz)       //funkcja z pliku 6_2.cpp
{
    string wyjscie = "";

    for(int i = 0; i < zaszyfrowane.size(); ++i)
    {
        wyjscie += (char)(((zaszyfrowane[i] - 65 - (klucz % 26) + 26) % 26) + 65);
    }
    return wyjscie;
}

bool CzyOK(string slowo, string szyfr)
{
    for(int i = 0; i < 26; ++i)
    {
        if(slowo == Rozszyfruj(szyfr, i)) return true;
    }
    return false;
}

void Zad6_3(string sciezka)
{
    ifstream plik;
    ofstream wyjscie("wyniki_6_3.txt");
    string slowo = "";
    string szyfr = "";

    plik.open(sciezka);
    
    int licz = 0;
    for(int i = 0; plik.good(); ++i)
    {
        plik >> slowo;
        plik >> szyfr;
        if(!CzyOK(slowo, szyfr))
        {
            cout << i << ". " << slowo << endl;
            wyjscie << slowo << endl;
            ++licz;
        }
    }
    cout << licz << endl;

    plik.close();
    wyjscie.close();
}

int main()
{
    Zad6_3("dane_6_3.txt");
    return 0;
}