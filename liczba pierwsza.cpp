#include <iostream>
#include <vector>
using namespace std;

bool PrimeNumber(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void searchPrime(int n)
{
    vector<int> v;
    for (int i = 0; i <= n; i++)
    {
        if (PrimeNumber(i) == 1)
            v.push_back(i);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
int main()
{
    int n;
    cout << "Podaj liczbe : ";
    cin >> n;
    cout << "Czy liczbna pierwsza?" << endl;
    cout << PrimeNumber(n) << endl;
    cout << "Wszystkie liczby pierwsze mniejsze lub rowne od niej:" << endl;
    searchPrime(n);
}