#include <iostream>
#include <limits> 
#include <string>

using namespace std;

//This code is made by @lathea
//This code is for the purpose of learning and education

//Creating a Basic Calculator using a class

class Calculator 
{
    private:
    int num1, num2;

    public:
    // Constructor to initialize values
    Calculator() : num1(0), num2(0) {}

    // Computing addition
    double addition(int num1, int num2) 
    {
        return static_cast<double>(num1) + static_cast<double>(num2); 
    }

    //computing for subtraction
    double subtraction(int num1, int num2)
    {
        return static_cast<double>(num1) - static_cast<double>(num2);
    }

    //computing for multiplication
    double multiplication(int num1, int num2)
    {
        return static_cast<double>(num1) * static_cast<double>(num2);
    }

    //computing for division
    double division(int num1, int num2)
    {
        if (num2 == 0) {
            cout << "Error: Division by zero is not allowed." << endl;
            return 0;
        }
        return static_cast<double>(num1) / static_cast<double>(num2);
    }

};

// Function that only accepts number and not accept letters or letter with numbers
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

int main()
{
    Calculator calcu;
    int choice;
    bool restart = true;
    double result;
    
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

    // Get user choice 
    choice = getValidatedInt("Input number from 1 to 5: ");

            if (choice < 1 || choice > 5) {
            cout << "Invalid choice, please choose a number between 1 and 5 only." << endl;
            continue;
        }

        if (choice == 5) {
            cout << "Exiting..." << endl;
            restart = false;
            break;
        }
    // Get two numbers from user
        int num1 = getValidatedInt("Input the first number: ");
        int num2 = getValidatedInt("Input the second number: ");

    switch (choice)
    {
        case 1:
            //placeholder for addition
        {
            printf("========== A D D I T I O N ==========\n");
            double result = calcu.addition(num1, num2);
            cout << "Result: " << result << endl;
            break;
        }

        case 2:
            //placeholder for subtraction
        {
            printf("========== S U B T R A C T I O N ==========\n");
            double result = calcu.subtraction(num1, num2);
            cout << "Result: " << result << endl;
            break;
        }

        case 3:
            //placeholder for multiplication
        {
            printf("========== M U L T I P L I C A T I O N ==========\n");
            double result = calcu.multiplication(num1, num2);
            cout << "Result: " << result << endl;
            break;
        }
         
        case 4:
            // Placeholder for division
            {
            printf("========== D I V I S I O N ==========\n");
            double result = calcu.division(num1, num2);
            cout << "Result: " << result << endl;
            break;
            }
    }
    }while(restart);

    return 0;
}
