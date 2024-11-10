#include <iostream>
#include <limits>
#include <string>
using namespace std;

//This code is made by @lathea
//This code is for the purpose of learning and education

//Creating a 2nd Basic Calculator in abstraction and encapsulation

//abstraction
class Calculator
{
    public:
    virtual double operation(double num1, double num2) = 0;
};

//interface
class Addition: public Calculator
{
    public:

    virtual double operation(double num1,double num2) override
    {
        return num1+num2;
    }
};

class Subtraction: public Calculator
{
    public:
    virtual double operation(double num1,double num2) override
    {
        return num1-num2;
    }
};

class Multiplication: public Calculator
{
    public:
    virtual double operation(double num1,double num2) override
    {
        return num1*num2;
    }
};

class Division: public Calculator
{
    public:
    virtual double operation(double num1,double num2) override
    {
        if (num2 == 0) {
            cout << "Error: Division by zero is not allowed." << endl;
            return 0;
        }
        return num1/num2;
    }
};

// function to accept only numbers
int getValidatedInt(const string& prompt) {
    int num;
    while (true) {
        cout << prompt;
        cin >> num;
        if (cin.fail()) {
            cin.clear(); // clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid integer." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard any extra input
            return num;
        }
    }
}

// Function to prompt for continuation of the same operation
bool askRepeat() {
    char choice;
    while (true) {
        cout << "\nWould you like to repeat this operation? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') return true;
        if (choice == 'n' || choice == 'N') return false;
        cout << "\nInvalid choice. Please enter 'y' or 'n'." << endl;
    }
}

int main()
{
Addition add;
Subtraction sub;
Multiplication mul;
Division div;
int choice;
double answer;
bool repeat = true;

do
{
    printf("========== C A L C U L A T O R ==========\n");

    printf(
        "\n M E N U\n"
        "1 - Addition\n"
        "2 - Subtraction\n"
        "3 - Multiplication\n"
        "4 - Division\n"
        "5 - Exit\n"
    );

    choice = getValidatedInt("Input number from 1 to 5: ");

            if (choice < 1 || choice > 5) {
            cout << "\nInvalid choice, please choose a number between 1 and 5 only." << endl;
            continue;
        }

        if (choice == 5) {
            cout << "Exiting..." << endl;
            repeat = false;
            break;
        }

        bool continueOperation;
        do{

        int num1 = getValidatedInt("Input the first number: ");
        int num2 = getValidatedInt("Input the second number: ");

    switch (choice)
    {
        case 1:
            //Placeholder for addition
        {
            printf("========== A D D I T I O N ==========\n");
            answer = add.operation(num1,num2);
            cout << "Result: " << answer << endl;
            break;
        }

        case 2:
            //Placeholder for subtraction
        {
            printf("========== S U B T R A C T I O N ==========\n");
            answer = sub.operation(num1,num2);
            cout << "Result: " << answer << endl;
            break;
        }

        case 3:
            // Placeholder for multiplication
        {
            printf("========== M U L T I P L I C A T I O N ==========\n");
            answer = mul.operation(num1,num2);
            cout << "Result: " << answer << endl;
            break;
        }
         
        case 4:
            // Placeholder for division
            {
            printf("========== D I V I S I O N ==========\n");
            answer = div.operation(num1,num2);
            cout << "Result: " << answer << endl;
            break;
            }
    }
    // Ask user if they want to continue
    continueOperation = askRepeat();
    
    }while(continueOperation);
    }while(repeat);
}