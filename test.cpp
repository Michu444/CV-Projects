#include <iostream>

using namespace std;

string temp = "NIC";

int first{2, 3, 5, 7, 11, 13, 17, 19};

float ile_dwojek(int n)
{
    int ilosc = 0, liczba = 0;

    while (liczba != n)
    {
        if (n % 2 == 0)
        {
            liczba += 2;
            ilosc++;
        }
        else
        {
            n -= 1;
            temp = "ODJETE JEDEN";
        }
    }

    return ilosc;
}

int main()
{
    int n;

    cin >> n;

    cout << "Dwojek jest: " << ile_dwojek(n) << " " << temp;

    return 0;
}

// 2 3 5 7 11 13 17 ...