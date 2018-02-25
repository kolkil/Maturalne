#include <iostream>
#include <fstream>

using namespace std;

void Zad6_1(string sciezka)
{
    ifstream plik;
    int min = 255;
    int max = 0;
    int liczba = 0;

    plik.open(sciezka);

    for(;plik.good();)
    {
        plik >> liczba;
        if(liczba > max) max = liczba;
        if(liczba < min) min = liczba;
    }
    plik.close();
    cout << "Najjasniejszy: " << max << endl << "Najciemniejszy: " << min << endl;
}

int main()
{
    Zad6_1("dane.txt");
    return 0;
}