#include <iostream>
#include <stdexcept>
using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    double fahrenheit;

    try {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> fahrenheit;

        // Check if input is valid
        if (cin.fail()) {
            throw invalid_argument("Invalid input. Please enter a numeric value.");
        }

        // Perform conversion
        double celsius = fahrenheitToCelsius(fahrenheit);

        cout << "Temperature in Celsius: " << celsius << "°C" << endl;
    } catch (const invalid_argument& e) {
        // Catch and display error message for invalid input
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
