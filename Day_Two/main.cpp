#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;


vector<int> parseLine(string line){
    vector<int> result;
    int curNum = 0;
    istringstream stream(line);
    while((stream >> curNum))
    {
        result.push_back(curNum);
    }

    return result;
}

long long part1(vector<string> input, vector<int>& acceptedIndexes)
{
    int acceptedStrings = 0;

    for(int i = 0; i < input.size(); i++)
    {
        int curNum = 0;
        int previousNum = 0;
        vector<int> curLine = parseLine(input[i]);
        bool accepted = true;
        for(int j = 0; j < curLine.size(); j++)
        {
            vector<int> sorted = curLine;
            sort(sorted.begin(), sorted.end());
            vector<int> reverse = curLine;
            sort(reverse.begin(), reverse.end());
            std::reverse(reverse.begin(), reverse.end());

            if(curLine != sorted && curLine != reverse)
            {
                accepted = false;
                break;
            }

            previousNum = curNum;
            curNum = curLine[j];

            if(j >= 1)
            {
                if(abs(curNum - previousNum) > 3)
                {
                    accepted = false;
                    break;
                }
                else if(curNum == previousNum)
                {
                    accepted = false;
                    break;
                }
            }
        }
        if(accepted)
        {
            acceptedStrings++;
            acceptedIndexes.push_back(i);
        }
    }

    return acceptedStrings;
}

long long part2(vector<string> input, vector<int> acceptedIndexes)
{
    int acceptedStrings = 0;

    for(int i = 0; i < input.size(); i++) {
        if(find(acceptedIndexes.begin(), acceptedIndexes.end(), i) != acceptedIndexes.end())
        {
            acceptedStrings++;
            continue;
        }
        vector<int> fullLine = parseLine(input[i]);
        for (int j = 0; j < fullLine.size(); j++) {
            vector<int> brokenLine = fullLine;
            if(j == fullLine.size())
            {
                break;
            }
            brokenLine.erase(brokenLine.begin() + j);

            int curNum = 0;
            int previousNum = 0;
            bool brokenAccepted = false;
            for(int k = 0; k < brokenLine.size(); k++)
            {
                vector<int> sorted = brokenLine;
                sort(sorted.begin(), sorted.end());
                vector<int> reverse = brokenLine;
                sort(reverse.begin(), reverse.end());
                std::reverse(reverse.begin(), reverse.end());

                if(brokenLine != sorted && brokenLine != reverse)
                {
                    break;
                }

                previousNum = curNum;
                curNum = brokenLine[k];
                if(k >= 1)
                {
                    if(abs(curNum - previousNum) > 3)
                    {
                        break;
                    }
                    else if(curNum == previousNum)
                    {
                        break;
                    }
                }
                if(k == brokenLine.size() - 1)
                    brokenAccepted = true;
            }
            if(brokenAccepted)
            {
                acceptedStrings++;
                break;
            }
        }
    }

    return acceptedStrings;
}

int main() {
    std::ifstream fileToRead("C:\\Users\\devin\\CLionProjects\\Advent_24\\Day_Two\\dayTwoInput.txt");
    std::vector<std::string> fileToVector;
    std::string currentLine;
    while (getline(fileToRead, currentLine))
    {
        fileToVector.push_back(currentLine);
    }

    vector<int> acceptedIndexes;

    std::cout << part1(fileToVector, acceptedIndexes) << std::endl;
    std::cout << part2(fileToVector, acceptedIndexes);
}
