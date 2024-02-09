#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;

    // Input the numbers and the operation
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;

    // Perform the operation based on the user's choice
    double result;
    switch(operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            // Check if the second number is not zero to avoid division by zero
            if (num2 != 0)
                result = num1 / num2;
            else {
                cout << "Error: Division by zero!\n";
                return 1; // Exit with an error code
            }
            break;
        default:
            cout << "Invalid operation!\n";
            return 1; // Exit with an error code
    }

    // Output the result
    cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;

    return 0; // Exit successfully
}
