#include <iostream>

using namespace std;

const int VALUE = 4;

int first[VALUE] = {2, 3, 5, 7};
int NPRIM = 4;

const int R = 100;

int numbers[R];

void write(int k)
{
    // cout << k;

    for (int i = 0; i < 100; i++)
    {
        if (numbers[i] > 0)
        {
            cout << " + " << numbers[i];
        }
    }
    cout << endl;
}

void clear(int index) // clearuje tablice od index elementu.
{
    for (int i = index; i < R; i++)
    {
        numbers[i] = 0;
    }
}

void algorytm(int k)
{
    int sum = 0, glowna_pierwsza = 0, index_pierwszej = 0, i = 1, ilosc_elem = 0, ile_miejsc = 0, ile_odjac = 0, iteracje = 0;

    int number = k;

    while (NPRIM != 0)
    {
        if (sum == 0)
        {
            ile_miejsc++;
            for (int j = 0; j < ile_miejsc; j++)
            {
                sum += first[index_pierwszej - ile_odjac];
                numbers[j] = first[index_pierwszej - ile_odjac];
                ilosc_elem++;
            }
            i = ile_miejsc;
        }

        if (sum < number)
        {
            numbers[i] = first[0];
            sum += first[0];
            ilosc_elem++;
            i++;
        }

        if (sum > number)
        {
            if (index_pierwszej == 0 || index_pierwszej == 1)
            {
                clear(0);
                sum = 0;
                ilosc_elem = 0;
            }
            else
            {
                clear(0);
                sum = 0;
                ilosc_elem = 0;
                ile_odjac = 1;
            }
        }

        if (sum == number)
        {
            write(k);
            cout << "ILOSC ELEM: " << ilosc_elem << endl;
            if (numbers[1] == first[index_pierwszej])
            {
                clear(0);
                NPRIM--;
                index_pierwszej++;
                glowna_pierwsza = first[index_pierwszej];
                ile_miejsc = 0;
                ilosc_elem = 0;
                ile_odjac = 0;
                sum = 0;
                i = 1;
            }
            else
            {
                sum = 0;
                ilosc_elem = 0;
                ile_miejsc--;
            }
        }
    }
    return;
}

int main()
{
    int n, k;
    cin >> k;

    algorytm(k);

    return 0;
}

/*
#include <iostream>

using namespace std;

const int VALUE = 4;

int first[VALUE] = {2, 3, 5, 7};
int NPRIM = 4;

const int R = 100;

int numbers[R];

void write(int k)
{
    // cout << k;

    for (int i = 0; i < 100; i++)
    {
        if (numbers[i] > 0)
        {
            cout << " + " << numbers[i];
        }
    }
    cout << endl;
}

void clear(int index) // clearuje tablice od index elementu.
{
    for (int i = index; i < R; i++)
    {
        numbers[i] = 0;
    }
}

void algorytm(int k)
{
    int sum = 0, glowna_pierwsza = 0, index_pierwszej = 0, i = 1, ilosc_elem = 0, ile_glownych = 0;

    int number = k;

    while (NPRIM != 0)
    {
        if (sum == 0)
        {
            ile_glownych++;
            for (int j = 0; j < ile_glownych; j++)
            {
                sum += glowna_pierwsza;
                numbers[j] = glowna_pierwsza;
                ilosc_elem++;
            }
        }

        if (sum < number)
        {
            numbers[i] = first[0];
            sum += glowna_pierwsza;
            ilosc_elem++;
            i++;
        }

        if (sum > number)
        {
            clear(0);
            numbers[ile_glownych] = glowna_pierwsza;
            sum = 0;
            ilosc_elem = 0;
            i = 1 + ile_glownych;
        }

        if (sum == number)
        {
            write(k);
            cout << "ILOSC ELEM: " << ilosc_elem << endl;
            clear(0);
            i = 1;
            ilosc_elem = 0;
            sum = 0;
            ile_glownych = 0;
            index_pierwszej++;
            glowna_pierwsza = first[index_pierwszej];
            NPRIM--;
        }
    }
}

int main()
{
    int n, k;
    cin >> k;

    algorytm(k);

    return 0;
}*/
// CIEKAWE