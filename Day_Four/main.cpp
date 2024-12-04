#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>
#include <regex>

using namespace std;

bool searchDir(vector<string> input, int row, int col, int dir, char letter){
    vector<char> letters = {'M', 'A', 'S'};
    vector<pair<int, int>> directions = {
            {-1, -1},
            {-1,  0},
            {-1,  1},
            {0,  -1},
            {0,   1},
            {1,  -1},
            {1,   0},
            {1,   1}
    };

    row = row + get<0>(directions[dir]);
    col = col + get<1>(directions[dir]);
    if(row < 0 || col < 0)
        return false;
    if(row >= input.size() || col >= input[row].size())
        return false;
    else if(input[row][col] == letter)
        if(letter == 'S')
            return true;
        else
            return searchDir(input, row, col, dir, letters[find(letters.begin(), letters.end(), letter) - letters.begin()  + 1]);
    else
        return false;
}

long long part1(vector<string> input){
    int sum = 0;
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input[0].size(); j++)
        {
            if(input[i][j] == 'X')
            {
                for(int dir = 0; dir <= 7; dir++)
                {
                    if(searchDir(input, i, j, dir, 'M'))
                    {
                        sum++;
                    }
                }
            }
        }
    }

    return sum;
}

long long part2(vector<string> input){
    int sum = 0;
    vector<pair<int, int>>  checkedCenters;
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input[0].size(); j++)
        {
            if(input[i][j] == 'M')
            {
                if(searchDir(input, i, j, 7, 'A'))
                {
                    pair<int, int> center(i+1, j+1);
                    if(input[i][j+2] == 'M' && (searchDir(input, i, j + 2, 5, 'A')))
                    {
                        if(find(checkedCenters.begin(), checkedCenters.end(), center) == checkedCenters.end())
                        {
                            checkedCenters.push_back(center);
                            sum++;
                        }
                    }

                    if(input[i+2][j] == 'M' && (searchDir(input, i + 2, j, 2, 'A')))
                    {
                        if(find(checkedCenters.begin(), checkedCenters.end(), center) == checkedCenters.end())
                        {
                            checkedCenters.push_back(center);
                            sum++;
                        }
                    }
                }
                if(searchDir(input, i, j, 5, 'A'))
                {
                    pair<int, int> center(i+1, j-1);
                    if(input[i][j-2] == 'M' && (searchDir(input, i, j - 2, 7, 'A')))
                    {
                        if(find(checkedCenters.begin(), checkedCenters.end(), center) == checkedCenters.end())
                        {
                            checkedCenters.push_back(center);
                            sum++;
                        }
                    }

                    if(input[i+2][j] == 'M' && (searchDir(input, i + 2, j, 0, 'A')))
                    {
                        if(find(checkedCenters.begin(), checkedCenters.end(), center) == checkedCenters.end())
                        {
                            checkedCenters.push_back(center);
                            sum++;
                        }
                    }
                }
                if(searchDir(input, i, j, 0, 'A'))
                {
                    pair<int, int> center(i-1, j-1);
                    if(input[i][j-2] == 'M' && (searchDir(input, i, j - 2, 2, 'A')))
                    {
                        if(find(checkedCenters.begin(), checkedCenters.end(), center) == checkedCenters.end())
                        {
                            checkedCenters.push_back(center);
                            sum++;
                        }
                    }

                    if(input[i-2][j] == 'M' && searchDir(input, i - 2, j, 5, 'A'))
                    {
                        if(find(checkedCenters.begin(), checkedCenters.end(), center) == checkedCenters.end())
                        {
                            checkedCenters.push_back(center);
                            sum++;
                        }
                    }
                }
                if(searchDir(input, i, j, 2, 'A'))
                {
                    pair<int, int> center(i-1, j+1);
                    if(input[i][j+2] == 'M' && (searchDir(input, i, j + 2, 0, 'A')))
                    {
                        if(find(checkedCenters.begin(), checkedCenters.end(), center) == checkedCenters.end())
                        {
                            checkedCenters.push_back(center);
                            sum++;
                        }
                    }

                    if(input[i-2][j] == 'M' && searchDir(input, i - 2, j, 7, 'A'))
                    {
                        if(find(checkedCenters.begin(), checkedCenters.end(), center) == checkedCenters.end())
                        {
                            checkedCenters.push_back(center);
                            sum++;
                        }
                    }
                }
            }
        }
    }

    return sum;
}

int main() {
    std::ifstream fileToRead("C:\\Users\\devin\\CLionProjects\\Advent_24\\Day_Four\\dayFourInput.txt");
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
