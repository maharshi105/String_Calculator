#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &str, const string &delimiter)
{
    vector<string> tokens;
    regex re(delimiter);
    sregex_token_iterator it(str.begin(), str.end(), re, -1);
    sregex_token_iterator end;
    while (it != end)
    {
        tokens.push_back(*it++);
    }
    return tokens;
}

int add(const string &numbers)
{
    if (numbers.empty())
    {
        return 0;
    }
    int sum = 0;
    string numbersCopy = numbers;

    vector<string> tokens = split(numbersCopy, ",");

    for (const string &token : tokens)
    {
        if (!token.empty())
        {
            int num = stoi(token);
            sum += num;
        }
    }

    return sum;
}

int main()
{
    cout << "Result of empty string: " << add("") << endl;
    cout << "Result of '123': " << add("123") << endl;
    cout << "Result of '1,2,3': " << add("1,2,3") << endl;

    return 0;
}