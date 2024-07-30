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
        if (numbersCopy.substr(0, 2) == "//")
        {
            int delimiterEnd = numbersCopy.find('\n');
            delimiter = numbersCopy.substr(2, delimiterEnd - 2);
            numbersCopy = numbersCopy.substr(delimiterEnd + 1);
        }

        vector<string> tokens = split(numbersCopy, delimiter);
        int sum = 0;
        vector<int> negativeNumbers;

        for (const string &token : tokens)
        {
            if (!token.empty())
            {
                int num = stoi(token);
                if (num < 0)
                {
                    negativeNumbers.push_back(num);
                }
                sum += num;
            }
        }
        if (!negativeNumbers.empty())
        {
            ostringstream oss;
            oss << "Negatives not allowed: ";
            for (int i = 0; i < negativeNumbers.size(); ++i)
            {
                if (i != 0)
                {
                    oss << ", ";
                }
                oss << negativeNumbers[i];
            }
            throw runtime_error(oss.str());
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
    try
    {
        cout << "Result of empty string: " << calculator.add("") << endl;
        cout << "Result of '1': " << calculator.add("1") << endl;
        cout << "Result of '1,2,3': " << calculator.add("1,2,3") << endl;
        cout << "Result of '1\\n2,3': " << calculator.add("1\n2,3") << endl;
        cout << "Result of '//;\n1;2': " << calculator.add("//;\n1;2") << endl;
        cout << "Result of '-1,2,3': " << calculator.add("-1,2,3") << endl;
    }
    catch (const runtime_error &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}