#include <iostream>
#include <fstream>    
#include <cctype> 

using namespace std;


class FileHandler {
private:
    fstream file;   
    string fileName;

public:
    FileHandler(string name) : fileName(name) {}

    
    void writeToFile() {
        file.open(fileName, ios::out); 
        if (!file) {
            cout << "Error opening file for writing!" << endl;
            return;
        }
        string content;
        cout << "Enter text to write to the file (BOOK.txt):" << endl;
        getline(cin, content);  
        file << content;       
        file.close();           
    }

    void readAndDisplayFile() {
        file.open(fileName, ios::in);  
        if (!file) {
            cout << "Error opening file for reading!" << endl;
            return;
        }
        cout << "\nContents of the file (" << fileName << "):" << endl;
        string line;
        while (getline(file, line)) {
            cout << line << endl;  
        }
        file.close();              
    }

   
    int countUppercase() {
        file.open(fileName, ios::in);
        if (!file.is_open()) {
            cout << "Error opening file for reading!" << endl;
            return 0;
        }
        char ch;
        int count = 0;
        while (file.get(ch)) {
            if (isupper(ch)) count++; 
        }
        file.close();
        return count;
    }

   
    int countLetters() {
        file.open(fileName, ios::in);
        if (!file) {
            cout << "Error opening file for reading!" << endl;
            return 0;
        }
        char ch;
        int count = 0;
        while (file.get(ch)) {
            if (isalpha(ch)) count++; 
        }
        file.close();
        return count;
    }

    
    int countSpaces() {
        file.open(fileName, ios::in);
        if (!file) {
            cout << "Error opening file for reading!" << endl;
            return 0;
        }
        char ch;
        int count = 0;
        while (file.get(ch)) {
            if (isspace(ch)) count++; 
        }
        file.close();
        return count;
    }

    int countVowels() {
        file.open(fileName, ios::in);
        if (!file) {
            cout << "Error opening file for reading!" << endl;
            return 0;
        }
        char ch;
        int count = 0;
        while (file.get(ch)) {
            ch = tolower(ch); 
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                count++; 
            }
        }
        file.close();
        return count;
    }
};

int main() {
    FileHandler fileHandler("C:\\Users\\MAHNISH\\Desktop\\cpp\\operator.cpp\\BOOK.txt");

    fileHandler.writeToFile();

    fileHandler.readAndDisplayFile();

   

int choice,q=1;
    while(1){ 
    printf("        FILE OPERATIONS        \n");
    cout<<"1.uppercase letters"<<endl;
    cout<<"2.total leters"<<endl;
    cout<<"3.white spaces"<<endl;
    cout<<"vowels"<<endl;
    cout<<"exiting..."<<endl;
    cout<<"\n";
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    switch (choice){
        case 1: cout << "\nUppercase letters: " << fileHandler.countUppercase() << endl;
                break;
        case 2: cout << "Total letters: " << fileHandler.countLetters() << endl;
                break;
        case 3: cout << "White spaces: " << fileHandler.countSpaces() << endl;
                break;
        case 4: cout << "Vowels: " << fileHandler.countVowels() << endl;
                break;
        case 5: printf("exit\n");
                
                break;                                
        default: printf("invalid choice\n");
                break;                         
    }
     cout<<"press 1 to continue "<<endl;
     cin>>q;
     if (q != 1) break;
  }

    return 0;
}


