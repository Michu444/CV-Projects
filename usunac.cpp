#include <iostream>

using namespace std;

const int VALUE = 4;

int first[VALUE] = {2, 3, 5, 7};

int numbers[100];

void jakis(int n, int k, int i)
{
    int temp = 1, sum = 0;

    int number = n - k;

    numbers[0] = k;

    while (sum != number)
    {
        if (sum < number)
        {
            numbers[temp] = first[i];
            temp++;
            sum += first[i];
        }

        if (sum > number)
        { // NA DRUGIM MIEJSCU MA BYĆ TA LICZBA PIERWSZA KTÓRA BĘDZIE TAM ZAWSZE!!
            sum -= first[i];
            sum -= first[i];
            temp -= 2;
            i--;
        }

        if (sum == number)
            return;
    }
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;

    for (int i = 0; i < VALUE; i++)
    {
        jakis(n, k, i);

        cout << numbers[0];

        for (int j = 1; j < 10; j++)
        {
            if (numbers[j] > 0)
            {
                cout << " + " << numbers[j];
            }
        }
        cout << endl;
    }

    return 0;
}