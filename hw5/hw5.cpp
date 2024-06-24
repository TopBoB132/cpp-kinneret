#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "date.h"
#include "cake.h"
#include "musseCake.h"
#include "birthdayCake.h"

Cake** cakeArr = nullptr;
int cakeLength = 0;

Date dateInput() {
    int year, month, day;
    cout << "Enter a year: ";
    cin >> year;
    cout << "\nEnter a month: ";
    cin >> month;
    cout << "\nEnter a day: ";
    cin >> day;

    return Date(day, month, year);
}

Cake* cakeInput() {
    Date dt = dateInput();
    
    int diameter, storage;
    double height, price;
    bool glutenFree;

    cout << "Enter the diameter: ";
    cin >> diameter;
    cout << "\nEnter the height: ";
    cin >> height;
    cout << "\nEnter the price: ";
    cin >> price;
    cout << "\nPick storage type, 1. for Refrigerator, 2. for nothing: ";
    cin >> storage;
    cout << "\nGluten Free? (1 for true, 0 for false): ";
    cin >> glutenFree;

    return new Cake(dt, diameter, height, price, storage, glutenFree);
}

void appendNewCake(Cake* cake) {
    Cake** tmp = new Cake*[cakeLength + 1];

    for (int i = 0; i < cakeLength; i++) {
        tmp[i] = cakeArr[i];
    }

    tmp[cakeLength] = cake;
    delete[] cakeArr;
    cakeArr = tmp;
    cakeLength++;
}

void createCake() {
    appendNewCake(cakeInput());
}
void createBirthdayCake() {
    Date dt = dateInput();

    int diameter, storage;
    double height, price;
    bool glutenFree;

    cout << "Enter the diameter: ";
    cin >> diameter;
    cout << "\nEnter the height: ";
    cin >> height;
    cout << "\nEnter the price: ";
    cin >> price;
    cout << "\nPick storage type, 1. for Refrigerator, 2. for nothing: ";
    cin >> storage;
    cout << "\nGluten Free? (1 for true, 0 for false): ";
    cin >> glutenFree;

    // Make sure to input the text on a new line to avoid capturing previous newline character
    cout << "Enter a text for the birthday cake: ";
    string text;
    cin >> ws; // A call to ws to consume whitespaces if necessary
    getline(cin, text);

    BirthdayCake* bc = new BirthdayCake(dt, diameter, height, price, storage, glutenFree, text.c_str());
    appendNewCake(bc);
}

void createMusseCake() {
    Date dt = dateInput();

    int diameter, storage;
    double height, price;
    bool glutenFree;

    cout << "Enter the diameter: ";
    cin >> diameter;
    cout << "\nEnter the height: ";
    cin >> height;
    cout << "\nEnter the price: ";
    cin >> price;
    cout << "\nPick storage type, 1. for Refrigerator, 2. for nothing: ";
    cin >> storage;
    cout << "\nGluten Free? (1 for true, 0 for false): ";
    cin >> glutenFree;

    // Make sure to input the taste on a new line to avoid capturing previous newline character
    cout << "Enter a taste for the mousse cake: ";
    string taste;
    cin >> ws; // A call to ws to consume whitespaces if necessary
    getline(cin, taste);

    MusseCake* mc = new MusseCake(dt, diameter, height, price, storage, glutenFree, taste.c_str());
    appendNewCake(mc);
}


void printAllCakes() {
    for (int i = 0; i < cakeLength; i++) {
        cout << *(cakeArr[i]) << endl;
    }
}

int main() {
    int op;
    do {
        cout << "1 for Cake\n2 for BirthdayCake\n3 for MusseCake\n4 to print all cakes\n5 to exit" << endl;
        cin >> op;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, try again." << endl;
            continue;
        }

        switch (op) {
            case 1:
                createCake();
                break;
            case 2:
                createBirthdayCake();
                break;
            case 3:
                createMusseCake();
                break;
            case 4:
                printAllCakes();
                break;
            default:
                cout << op << " is not a valid option" << endl;
                continue;
        }
    } while (op != 5);

    cout << "bye bye!" << endl;

    for (int i = 0; i < cakeLength; i++) {
        delete cakeArr[i];
    }

    delete[] cakeArr;
    
    return 0;
}
