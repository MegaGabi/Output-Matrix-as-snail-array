#include <iostream>
#include <vector>

void showVector(const std::vector<int>& toShow)
{
    for(const auto& el: toShow)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) 
{
    std::vector<int> result;
    
    int minW = -1, minH = 0, maxW = snail_map[0].size(), maxH = snail_map.size();
    int StepX = 1, StepY = 0;
    int i = 0, j = 0;
    
    while (minW < maxW && minH < maxH)
    {
        if(StepX == 1 && j >= maxW)
        {
            --j;
            StepX = 0;
            StepY = 1;
            --maxW;
        }
        else if(StepX == -1 && j <= minW)
        {
            ++j;
            StepX = 0;
            StepY = -1;
            ++minW;
        }
        else if(StepY == 1 && i >= maxH)
        {
            --i;
            StepX = -1;
            StepY = 0;
            --maxH;
        }
        else if(StepY == -1 && i <= minH)
        {
            ++i;
            StepX = 1;
            StepY = 0;
            ++minH;
        }
        else
        {
            result.push_back(snail_map[i][j]);
        }
        j+=StepX;
        i+=StepY;
    }
    return result;
}

int main()
{
    std::vector<std::vector<int>> v = {{1,2,3}, {8,9,4}, {7,6,5}};
    showVector(snail(v));
    return 0;
}