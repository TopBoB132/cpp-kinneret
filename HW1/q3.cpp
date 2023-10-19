#include <iostream>
#include <cstring>

using namespace std;

char** words(char* sentence, int* size)
{
    char** word;
    int count = 1;

    for (int i = 0; i < strlen(sentence); i++)
    {
        if (sentence[i] == ' ')
        {
            count++;
        }
    }
    *size = count;
    word = new char*[*size];
    count = 0;

    for (int row = 0, col = 0; row < strlen(sentence); row++)
    {
        char temp[100];
        while (sentence[row] != ' ' && sentence[row] != '\0')
        {
            temp[col] = sentence[row];
            row++;
            col++;
        }

        temp[col] = '\0';
        col = 0;
        word[count] = new char[strlen(temp) + 1];
        strcpy(word[count], temp);
        count++;
    }

    return word;
}

char* doubleWord(char* sentence)
{
    int size = strlen(sentence);
    int doubleSize = size * 2;
    char doubleSentence[100];

    for (int i = 0; i < size; i++)
    {
        doubleSentence[i] = sentence[i];
        doubleSentence[i + size] = sentence[i];
    }
    
    doubleSentence[doubleSize] = '\0';
    delete [] sentence;
    sentence = new char[doubleSize + 1];
    strcpy(sentence, doubleSentence);
    return sentence;
}

void printWords(char** wordArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        wordArray[i] = doubleWord(wordArray[i]);
        cout << wordArray[i] << endl;
        delete[] wordArray[i];
    }
}

int main()
{
    char sentence[] = "This is a test sentence";
    int size;
    char** wordArray = words(sentence, &size);

    // Print the words
    printWords(wordArray, size);

    // Deallocate memory
    delete[] wordArray;

    return 0;
}
