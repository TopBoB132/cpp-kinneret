#include <iostream>
using namespace std;

double WeightedAverage(int nums[], double weighted[])
{
    double sumWAndNumber = 0;
    double sumW = 0;
    
    for (int i = 0; i < sizeof(nums); i++) 
    {
        sumWAndNumber += weighted[i] * nums[i];
        sumW += weighted[i];
    }
    
    return sumWAndNumber / sumW;
}

int main()
{
    
    int nums[] = {2, 3, 4, 5};
    double weighted[] = {0.2, 0.3, 0.4, 0.5};
    
    cout << "result: " << WeightedAverage(nums, weighted);

    return 0;
}
