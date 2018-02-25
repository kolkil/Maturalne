#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool CzyWieksza(string a, string b)     //czy a > b?
{
    if(a.size() > b.size()) return true;
    else if(a.size() < b.size()) return false;
    else                                //kiedy a.size() == b.size()
    {
        for(int i = 0; i < a.size(); ++i)
        {
            if(a[i] != '1' && b[i] == '1') return false;
            if(a[i] == '1' && b[i] != '1') return true;
        }
    }
    return false;
}

bool CzyMniejsza(string a, string b)    //czy a < b?
{
    if(a.size() < b.size()) return true;
    else if(a.size() > b.size()) return false;
    else                                //kiedy a.size() == b.size()
    {
        for(int i = 0; i < a.size(); ++i)
        {
            if(a[i] != '1' && b[i] == '1') return true;
            if(a[i] == '1' && b[i] != '1') return false;
        }
    }
    return 0;
}

void Zad4_3(string sciezka)
{
    ifstream plik;
    string liczba;
    string najmniejsza = "";
    string najwieksza = "";
    int idmax = 0;
    int idmin = 0;

    plik.open(sciezka);

    for(int i = 0; plik.good(); ++i)        //numerując wiersze od zera
    {
        plik >> liczba;
        if(i == 0)
        {
            najmniejsza = liczba;
            najwieksza = liczba;
        }
        else
        {
            if(CzyMniejsza(liczba, najmniejsza) == 1) 
            {
                najmniejsza = liczba;
                idmin = i;
            }
            if(CzyWieksza(liczba, najwieksza) == 1) 
            {
                najwieksza = liczba;
                idmax = i;
            }
        }
    }
    plik.close();

    cout << "ID MAX:" << idmax << endl << "ID MIN:" << idmin << endl;
}

int main()
{
    Zad4_3("liczby.txt");
    return 0;
}