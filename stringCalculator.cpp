#include <bits/stdc++.h>
using namespace std;
class StringCalculator
{
public:
    StringCalculator() : delimiter(",\n") {}

    int add(const string &numbers)
    {
        if (numbers.empty())
        {
            return 0;
        }

        string numbersCopy = numbers;

        vector<string> tokens = split(numbersCopy, delimiter);
        int sum = 0;
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

private:
    string delimiter;

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
};

int main()
{
    StringCalculator calculator;

    cout << "Result of empty string: " << calculator.add("") << endl;
    cout << "Result of '1': " << calculator.add("1") << endl;
    cout << "Result of '1,2,3': " << calculator.add("1,2,3") << endl;
    cout << "Result of '1\\n2,3': " << calculator.add("1\n2,3") << endl;
    return 0;
}
