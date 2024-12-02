#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

struct twoLists{
    vector<int> sideOne;
    vector<int> sideTwo;
};

twoLists parseInput(vector<string> fileVector){
    vector<int> sideOne;
    vector<int> sideTwo;
    for(int i = 0; i < fileVector.size(); i++)
    {
        istringstream line(fileVector[i]);
        string side1;
        string side2;
        line >> side1 >> side2;

        sideOne.push_back(stoll(side1));
        sideTwo.push_back(stoll(side2));
    }

    twoLists final(sideOne, sideTwo);
    return final;
}



long long part1(twoLists input)
{
    ranges::sort(input.sideOne);
    ranges::sort(input.sideTwo);

    long long sum = 0;
    for(int i = 0; i < input.sideOne.size(); i++)
    {
        sum += abs(input.sideOne[i] - input.sideTwo[i]);
    }

    return sum;
}

long long part2(twoLists input)
{
    map<long long, long long> map;
    for(int i = 0; i < input.sideTwo.size(); i++)
    {
        map[input.sideTwo[i]]++;
    }

    long long sum = 0;
    for(int i = 0; i < input.sideOne.size(); i++)
    {
        sum += (input.sideOne[i] * map[input.sideOne[i]]);
    }

    return sum;
}

int main() {
    std::ifstream fileToRead("C:\\Users\\devin\\CLionProjects\\Advent_24\\Day_1\\day1Input.txt");
    std::vector<std::string> fileToVector;
    std::string currentLine;
    while (getline(fileToRead, currentLine))
    {
        fileToVector.push_back(currentLine);
    }

    twoLists finalInput = parseInput(fileToVector);

    std::cout << part1(finalInput) << std::endl;
    std::cout << part2(finalInput);
}
