#include <iostream>
#include <string>
#include <cstring>
using namespace std;

static int d = 0;

class Hotel {
public:
    string cust_name;
    int cust_id;
    int age;
    double income;
    char city[20];
    char room_type;

    void accept() {
        cout << "Enter customer ID: ";
        cin >> cust_id;
        cout << "Enter customer name: ";
        cin >> cust_name;
        getage();
        getincome();
        getcity();
        getroom_type();
    }

    void getage() {
        try {
            cout << "Enter age: ";
            cin >> age;
            if (age < 18 || age > 55)
                throw age;
            else
                d++;
        } catch (int) {
            cout << "Exception found: Age should be between 18 and 55" << endl;
        }
    }

    void getcity() {
        try {
            cout << "Enter city you live in: ";
            cin >> city;
            string res = "Pune";
            string res2 = "Mumbai";
            if (strcmp(city, res.c_str()) != 0 && strcmp(city, res2.c_str()) != 0)
                throw city;
            else
                d++;
        } catch (char*) {
            cout << "Exception found: City should be Pune or Mumbai" << endl;
        }
    }

    void getincome() {
        try {
            cout << "Enter monthly income: ";
            cin >> income;
            if (income < 50000 || income > 100000)
                throw income;
            else
                d++;
        } catch (double) {
            cout << "Exception found: Income should be between 50000 and 100000" << endl;
        }
    }

    void getroom_type() {
        try {
            cout << "Enter room type (D for Delux, S for Super Delux): ";
            cin >> room_type;
            if (room_type != 'D' && room_type != 'S')
                throw room_type;
            else
                d++;
        } catch (...) {
            cout << "Exception found: Room type should be Delux or Super Delux" << endl;
        }
    }

    void display() {
        if (d == 4) {
            cout << "Customer ID is: " << cust_id << endl;
            cout << "Customer name is: " << cust_name << endl;
            cout << "Customer age is: " << age << endl;
            cout << "City is: " << city << endl;
            cout << "Room type is: " << room_type << endl;
            cout << "Customer income is: " << income << endl;
        } else {
            cout << "Customer data is invalid" << endl;
        }
    }
};

int main() {
    Hotel H1;
    H1.accept();
    H1.display();
    return 0;
}
