#include <iostream>

using namespace std;

int first[8] = {2, 3, 5, 7};

int numbers[10];

int i = 3;

void ile_dwojek(int unfold)
{
    int sum = 7, s = 0;

    if (sum == unfold)
    {
        cout << unfold;
    }
    if (sum < unfold)
    {
        sum += first[i];
    }
    if (sum > unfold)
    {
        i--;
        return;
    }
}

int main()
{

    while (ile_dwojek(10) == unfold)
        ile_dwojek(10);

    for (int i = 0; i < 6; i++)
    {
        cout << numbers[i];
    }

    return 0;
}

// 2 3 5 7 11 13 17 ...