#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ZeroCzyJeden(string liczba)
{
    int zera = 0;
    int jedynki = 0;

    for(int i = 0; i < liczba.size(); ++i)
    {
        if(liczba[i] == '0') ++zera;
        else ++jedynki; 
    }
    if(zera > jedynki) return 0;
    return 1;
 }

 int Zad4_1(string dopliku)
 {
     ifstream plik;
     int liczbaliczb = 0;
     string liczba = "";
     
     plik.open(dopliku);
     
     for(;plik.good();)
     {
         plik >> liczba;
         if(ZeroCzyJeden(liczba) == 0) ++liczbaliczb;
     }
     
     plik.close();
     return liczbaliczb;
 }

 int main()
 {
     cout << Zad4_1("liczby.txt") << endl;
     return 0;
 }