#include <iostream>

using namespace std;

bool IsArithmeticProgression(int *pointerArr, int size = 3)
{
    int d = pointerArr[1] - pointerArr[0];
    for (int i = 1; i < size-1; i++) 
    {
        if(d != pointerArr[i+1] - pointerArr[i])
        {
            return false;
        }
    }
    
    return true;
}

bool IsArithmeticProgression(char *pointerArr, int size = 3)
{
    int d = pointerArr[1] - pointerArr[0];
    for (int i = 1; i < size-1; i++) 
    {
        if(d != pointerArr[i+1] - pointerArr[i])
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    int numbers[] = {3, 5, 7, 9, 11};
    char chars[] = {'A', 'C' , 'E'};

    bool result1 = IsArithmeticProgression(numbers, 5);
    bool result2 = IsArithmeticProgression(chars);
    
    cout << "result1: " << result1 << endl;
    cout << "result2: " << result2 << endl;

    return 0;
}
