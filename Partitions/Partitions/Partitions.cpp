/*  The program is called partitions.
    The division of the number n is a representation of the sum of positive prime numbers such that n = n1 + n2 + ... + nr , where n1 > n2 > nr , r - index of last part
    
    INPUT: In the first line: the number of consecutive lines. In the following lines after a space: n and k where n is the number to decompose, and k is the prime number at which to begin the split.
    OUTPUT: Partitions separated by + . ( if partition exist )

    EXAMPLE: 

    Input
    3
    12 5
    7 3
    15 11

    Output:

    5+3+2+2
    5+5+2
    3+2+2
    11+2+2


    Made by: Michal Dudziak
    */


#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;
vector<int> combination;

void write() // writing combination
{
    for (int i = 0; i < combination.size(); i++)
    {
        cout << combination[i];

        if (i != combination.size() - 1)
        {
            cout << "+";
        }
    }
    cout << endl;
}

bool if_first(int k) // check if transfered number is prime
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

void find_primes(int number) // finding prime numbers to k
{
    for (int i = 0; i <= number; i++)
    {
        if (if_first(i) == true)
        {
            primes.push_back(i);
        }
    }
}

int check_sum() // check sum of combination
{
    int sum = 0;

    for (int i = 0; i < combination.size(); i++)
    {
        sum += combination[i];
    }
    return sum;
}

int check_min() // finding min index in combination container
{
    int min = combination[0], idx = 0;

    for (int i = 0; i < combination.size(); i++)
    {
        if (min > combination[i])
        {
            min = combination[i];
            idx = i;
        }
    }
    return idx;
}

void end(int choose) // changing numbers to 2 from given index
{

    for (int i = choose; i < combination.size(); i++)
    {

        combination[i] = primes[0];
    }
}

void add_two(int n) // adding 2 to container untill <= k
{
    if (check_sum() + 2 <= n)
    {
        while (check_sum() < n && check_sum() + 1 <= n)
        {
            combination.push_back(primes[0]);
        }
    }
    else
        return;
}

void add(int n, int k)
{
    int number = 0;

    if (combination[combination.size() - 1] < k)
    {
        for (int i = 0; i < primes.size(); i++) // assign higher prime number to first min number
        {
            if (primes[i] == combination[check_min()])
            {
                number = primes[i + 1];
            }
        }

        combination[check_min()] = number;

        if (combination.size() != 1 && combination[combination.size() - 1] != number)
        {
            end(check_min());
        }

        if (check_sum() < n)
        {
            add_two(n);
        }
    }
    else
    {
        return;
    }
}

void check_combination(int n, int k, int option)
{
    if (check_sum() > n && combination[combination.size() - 1] > n - k)
        return;

    if (check_sum() > n)
    {
        combination.pop_back();
        if (check_sum() == n)
            write();
        add(n, k);
        if (check_sum() > n && combination[combination.size() - 1] == primes[primes.size() - 1])
            return;
    }

    if (combination[combination.size() - 1] == primes[primes.size() - 1])
    {
        if (check_sum() == n)
        {
            write();
        }
        return;
    }

    if (check_sum() == n)
    {
        write();
        add(n, k);
    }
}

void algorytm(int n, int k) 
{
    if (if_first(k) == false) // check if k is prime number
    {
        return; 
    }

    combination.push_back(k);

    if (n == k)
    {
        write();
        return;
    }

    add_two(n);

    if (check_sum() == n)
    {
        write();
        add(n, k);
        if (primes[primes.size() - 1] == 2)
            return;
    }

    while (combination.size() != 1)
    {
        if (check_sum() > n && combination[1] >= k && combination.size() < 3 || check_sum() > n && combination[1] > n - k)
            return;

        if (check_sum() == n)
        {
            check_combination(n, k, 2);
        }

        if (combination.size() == 1)
        {
            check_combination(n, k, 2);
            return;
        }
        if (check_sum() > n)
        {
            check_combination(n, k, 2);
            if (check_sum() > n && check_min() == 0)
                return;
            if (check_sum() > n && combination[check_min() - 1] >= k && combination[check_min()] > 3 && combination[check_min() - 1] != k)
                return;
        }

        if (check_sum() < n)
        {
            add(n, k);

            check_combination(n, k, 2);
        }
        if (combination[combination.size() - 1] == k)
            return;
    }
}

int main()
{
    int l, iteration = 0;
    int n, k;

    vector<int> ns;

    vector<int> ks;

    cin >> l;

    while (iteration < l)
    {
        cin >> n >> k;

        if (n > 0 && k > 0)
        {
            ns.push_back(n);
            ks.push_back(k);
        }
        iteration++;
    }

    iteration = 0;

    while (iteration != l)
    {
        if (iteration > l)
            return 0;

        n = ns[iteration];

        k = ks[iteration];

        if (n > 1 && k > 1)
        {
            find_primes(k);

            algorytm(n, k);

            combination.clear();

            primes.clear();
        }

        iteration++;
    }

    return 0;
}