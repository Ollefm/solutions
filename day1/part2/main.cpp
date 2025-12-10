#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

void calc(int &start, const string &op, int steps, int &z)
{
    //Brute force
    for (int i = 0; i < steps; i++)
    {
        if (op == "R")
        {
            start++;
        }
        if (op == "L")
        {
            start--;
        }

        if ((start % 100) == 0)
        {
            z++;
        }
    }
}

int process(string input)
{
    ifstream file(input);
    string str;
    int start = 50;
    int z = 0;
    string op = "";
    string num_string = "";

    while (getline(file, str))
    {
        op = str.substr(0, 1);
        num_string = str.substr(1);

        calc(start, op, stoi(num_string), z);
    }

    return z;
}

int main()
{
    cout << "The password is: ";
    // enter filename
    cout << process("input.txt") << endl;
}