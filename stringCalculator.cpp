#include <bits/stdc++.h>
using namespace std;

int add(const string &numbers)
{
    if (numbers.empty())
    {
        return 0;
    }
    int sum = 0;
    int len = numbers.length();

    for(int i = 0; i < len; i++){
        sum += numbers[i] - '0';
    }

    return sum;
}

int main()
{
    cout << "Result of empty string: " << add("") << endl;
    cout << "Result of '123': " << add("123") << endl;

    return 0;
}