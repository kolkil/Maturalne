#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Szyfruj(string slowo, int klucz)
{
    string wyjscie = "";

    for(int i = 0; i < slowo.size(); ++i)
    {
        wyjscie += (char)(((slowo[i] - 65 + klucz) % 26) + 65);
    }
    return wyjscie;
}

void Zad6_1(string sciezka, int klucz)
{
    ifstream plik;
    string slowo = "";
    plik.open(sciezka);

    for(;plik.good();)
    {
        plik >> slowo;
        cout << Szyfruj(slowo, klucz) << endl;
    }
    plik.close();
}

int main()
{
    Zad6_1("dane_6_1.txt", 107);
    return 0;
}