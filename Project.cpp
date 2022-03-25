#include <iostream>

using namespace std;

const int MAX = 10000;

int pierwsza[MAX];
int druga[MAX];
int first[MAX];
int sum_first = 0; // ilość liczb pierwszych do number_to_unfold

void read(int lines) // zapis liczb wprowadzanych w tablicach
{
    for (int i = 0; i < lines; i++)
    {
        cin >> pierwsza[i];
        cin >> druga[i];
    }
}

bool if_first(int k) // funkcja od szukania liczby pierwszej
{

    if (k < 2)
        return false;

    for (int i = 2; i < k; i++)
    {
        if (k % i == 0)
        {
            if (i == k)
                return true;
            else
                return false;
        }
    }
    return true;
}

void first_in_unfold(int k, int number_to_unfold) // funkcja szukająca liczb pierwszych do liczby rozkładanej włącznie z nią jeżeli jest pierwsza
{
    int n = 0; // indeks liczby pierwszej w tablicy liczb pierwszych 9 first[]

    for (int i = 0; i <= number_to_unfold; i++)
    {

        if (if_first(i) == true)
        {
            first[n] = i;
            sum_first += 1;
            n++;
        }
    }
}

int main() // 1 13 7
{
    int lines;            // liczba kolejnych linii z liczbami
    int number_to_unfold; // n - k = number_to_unfold ( liczba do rozłożenia )
    int required_number;  // od algorytmu wypisywania ?!

    cin >> lines;

    read(lines); // wczytanie wartosci poszczegolnej linii

    number_to_unfold = pierwsza[0] - druga[0];

    first_in_unfold(druga[0], number_to_unfold);

    for (int i = 0; i < sum_first; i++) // check test
    {
        cout << first[i] << " ";
    }
    cout << "    " << sum_first << "      " << druga[0] << " + " << number_to_unfold << " ...";

    return 0;
}

/*for (int i = 0; i < sum_first; i++) // algorytm łączenia w pary
    {
        if (first[i] > 0)
        {
            while (required_number != number_to_unfold)
            {
                if (required_number < number_to_unfold)
                {
                    required_number += first[i];
                }
                else if (required_number > number_to_unfold)
                {
                    required_number -= first[i];
                    required_number += first[i + 1];
                }

                tablica[k] == first[i];
                k++;
            }
        }
    }*/