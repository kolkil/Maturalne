#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool czy2(string liczba)
{
    if(liczba[liczba.size() - 1] == '1') return false;
    return true;
}

bool czy8(string liczba)
{
    if(liczba[liczba.size() - 1] == '1') return false;
    if(liczba.size() < 4) return false;
    for(int i = liczba.size() - 1; i > liczba.size() - 4; --i)
    {
        if(liczba[i] == '1') return false;
    }
    return true;
}

void Zada4_2(string sciezka)
{
    ifstream plik;
    string liczba;
    int przezosiem = 0;
    int przezdwa = 0;
    
    plik.open(sciezka);
    
    while(plik.good())
    {
        plik >> liczba;
        if(czy2(liczba)) ++przezdwa;
        if(czy8(liczba)) ++przezosiem;
    }
    
    plik.close();
    cout << "Przez 8:" << przezosiem << endl << "Przez 2:" << przezdwa << endl;
}

int main()
{
    Zada4_2("liczby.txt");
    return 0;
}