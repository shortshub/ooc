#include <iostream>
#include <string>
using namespace std;
class Complex
{
private:
    int real, img;

public:
    Complex()
    {
        real = 0;
        img = 0;
    }
    void input()
    {
        cout << "Enter the real part: ";
        cin >> real;
        cout << "Enter the imaginary part: ";
        cin >> img;
    }
    void display()
    {
        cout << real << " + " << img << "i" << endl;
    }
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
    Complex operator-(Complex c)
    {
        Complex temp;
        temp.real = real - c.real;
        temp.img = img - c.img;
        return temp;
    }
    Complex operator*(Complex c)
    {
        Complex temp;
        temp.real = real * c.real - img * c.img;
        temp.img = real * c.img + img * c.real;
        return temp;
    }
    Complex operator/(Complex c)
    {
        Complex temp;
        temp.real = (real * c.real + img * c.img) / (c.real * c.real +
                                                     c.img * c.img);
        temp.img = (img * c.real - real * c.img) / (c.real * c.real +
                                                    c.img * c.img);
        return temp;
    }
};
int main()
{
    Complex c1, c2, c3;
    int ch;
    while (1)
    {
        cout << "Which opera on do you wanna perform??" << endl;
        cout << "Addi on-> 1" << endl;
        cout << "Subtrac on-> 2" << endl;
        cout << "Mul plica on-> 3" << endl;
        cout << "Division-> 4" << endl;
        cout << "Exit-> 5" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            c1.input();
            c2.input();
            c3 = c1 + c2;
            c3.display();
            break;
        case 2:
            c1.input();
            c2.input();
            c3 = c1 - c2;
            c3.display();
            break;
        case 3:
            c1.input();
            c2.input();
            c3 = c1 * c2;
            c3.display();
            break;
        case 4:
            c1.input();
            c2.input();
            c3 = c1 / c2;
            c3.display();
            break;
        case 5:
            return 0;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}