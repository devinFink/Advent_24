#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>
#include <regex>

using namespace std;

long long part1(vector<string> input) {
    regex multiply("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
    long long sum = 0;
    for(int i = 0; i < input.size(); i++)
    {
        auto multiply_begin = sregex_iterator(input[i].begin(), input[i].end(), multiply);
        auto multiply_end = sregex_iterator();
        for (sregex_iterator j = multiply_begin; j != multiply_end; j++)
        {
            smatch match = *j;
            string strMatch = match.str();

            int first_parenth = strMatch.find("(");
            int comma = strMatch.find(',');
            int second_parenth = strMatch.find(")");

            string first_num = strMatch.substr(first_parenth + 1, comma - first_parenth - 1);
            string second_num = strMatch.substr(comma + 1, second_parenth - comma - 1);
            int left = stoi(first_num);
            int right = stoi(second_num);

            sum += left * right;
        }
    }

    return sum;
}

long long part2(vector<string> input) {
    regex multiply("mul\\([0-9]{1,3},[0-9]{1,3}\\)|do\\(\\)|don't\\(\\)");
    long long sum = 0;
    bool enabled = true;
    for(int i = 0; i < input.size(); i++)
    {
        auto multiply_begin = sregex_iterator(input[i].begin(), input[i].end(), multiply);
        auto multiply_end = sregex_iterator();
        for (sregex_iterator j = multiply_begin; j != multiply_end; j++)
        {
            smatch match = *j;
            string strMatch = match.str();

            if(strMatch == "do()")
            {
                enabled = true;
                continue;
            }
            else if(strMatch == "don't()")
            {
                enabled = false;
                continue;
            }

            if(enabled)
            {
                int first_parenth = strMatch.find("(");
                int comma = strMatch.find(',');
                int second_parenth = strMatch.find(")");

                string first_num = strMatch.substr(first_parenth + 1, comma - first_parenth - 1);
                string second_num = strMatch.substr(comma + 1, second_parenth - comma - 1);
                int left = stoi(first_num);
                int right = stoi(second_num);

                sum += left * right;
            }
        }
    }
    return sum;
}

int main() {
    std::ifstream fileToRead("C:\\Users\\devin\\CLionProjects\\Advent_24\\Day_Three\\DayThreeInput.txt");
    std::vector<std::string> fileToVector;
    std::string currentLine;
    while (getline(fileToRead, currentLine))
    {
        fileToVector.push_back(currentLine);
    }

    vector<int> acceptedIndexes;

    std::cout << part1(fileToVector) << std::endl;
    std::cout << part2(fileToVector);
}
