#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;
//menu function by Amir
void menu(int &bot) {
    for (int i = 0; i < 5; i++) {
        cout << endl;
    }
    cout << "\t***Student Marks Management***\n\n\n";
    cout << "\t--------------------------\n\n";
    cout << ">> Please choose a task :\n";
    cout << "\tc - Calculate total marks\n";
    cout << "\ta - Calculate average\n";
    cout << "\th - Find highest mark\n";
    cout << "\tl - Find lowest mark\n";
    cout << "\ts - All shown above and stored in a file\n";
    cout << "\te - Exit program (Change user if more then one student)\n\n";
    for (int i = 0; i < 5; i++) {
        cout << endl;
    }
    cout << "\t>> ";
    bot += 1;
}
//average function made by Muhammed
double avg(double marks[50], double times) {
    double sum = 0;
    for (int i = 0; i < times; i++) {
        sum += marks[i];
    }
    return sum / times;
}
//total function made by Muhammed
double sum(double marks[50], double times) {
    double total = 0;
    for (int i = 0; i < times; i++) {
        total += marks[i];
    }
    return total;
}
//find lowest function made by Rayyan
double low(double marks[50], double times) {
    double low = marks[0];
    for (int i = 0; i < times; i++) {
        if (marks[i] < low) {
            low = marks[i];
        }
    }
    return low;
}
//find highest function made by Rayyan
double high(double marks[50], double times) {
    double high = marks[0];
    for (int i = 0; i < times; i++) {
        if (marks[i] > high) {
            high = marks[i];
        }
    }
    return high;
}
void changetoLow(char &ch) {
    cout << "Please enter the the quiz that you want to change it's marks";
}
//student struct with name Muhammed
struct student {
    string name;
    long long int studentID;
    double marks[50];
};
int main() {
    int manyStu,times;
    char ch, ch_out;
    string fileName;
    ofstream outfile;
    ifstream infile;
    int bot=0; //used to know how many times menu function was invoked
    //opening menu made by Hadi
    cout << "\t***Student Marks Management***\n";
    cout << "\t----------------------------------------------------\n\n";
    cout << ">> How many students do you want to enter?\n" << "\t>>";
    cin >> manyStu; 
    //pointer that points to the address of student[manystu] to dedicate memeory immediately 
    student* students = new student[manyStu];
    for (int k =0;k<manyStu;k++) {
        //input student name Hadi
        cout << ">> Please enter you name: ";
        cin >> students[k].name;
        cin.ignore();
        cout << "Please enter your student ID: ";
        cin >> students[k].studentID;
        cin.ignore();
        //loop for entering how many quizes taken by Hadi
        do {
            cout << "\n>> Please enter how many quizes have you taken: ";
            cin >> times;
            //if statement used so if the user entered invalid input or inputed more then 50
            if (times <= 0 || times > 50) {
                cout << "\n>> Invalid input please enter correct input\n\n";
            }
        } while (times <= 0);
        //input of marks using a file made by Omar
        cout << ">> Do you want to input the marks using a file (Please include path directory) choose yes or no (y or n): \n" << "\t>> ";
        cin >> ch;
        ch_out = tolower(ch);
        cin.ignore();
        //if statement used to let the user choose to input the marks manually or by using a file
        if (ch_out == 'y') {
            getline(cin, fileName); //to input the name and path of the file by using getline so spaces can be included
            infile.open(fileName, ios::in); //opens input file that the user entered
            // if statement used to know if the file was opened or not
            if (infile.is_open()) {
                for (int i = 0; i < times; i++) {
                    infile >> students[k].marks[i];
                }
            }
            //if the file was not oppend correctly the user inputs the marks manually
            else {
                cout << "File was not opened correctly";
                for (int i = 0; i < times; i++) {
                    cout << "\n>> Please enter quiz " << i + 1 << " marks: ";
                    cin >> students[k].marks[i];
                }
            }
        }
        //if the user choose to input the marks manually
        else {
            for (int i = 0; i < times; i++) {
                cout << "\n>> Please enter quiz " << i + 1 << " marks: ";
                cin >> students[k].marks[i];
            }
        }
        //menu function and it being loop by Amir and choice selection using switch made by Omar
        do { //do while loop used so the user can switch between choices and if the user enter invalid input
            menu(bot); //menu function being called
            cin >> ch;
            ch_out = tolower(ch);
            //switch statement to choose from the menu
            switch (ch_out) {
                case 'c': { //case c which calculates the total marks by calling sum function 
                    cout << "\nThe total of all marks is: " << sum(students[k].marks, times) << endl << "Name: " << students[k].name << endl << students[k].studentID << endl;
                    break;
                }
                case 'a': { //case a which calculates the average mark by calling avg function 
                    cout << "\nThe average of all marks is: " << avg(students[k].marks, times) << endl << "Name: " << students[k].name << endl << students[k].studentID << endl;
                    break;
                }
                case 'h': { //case h which finds the highest mark by calling high function
                    cout << "\nThe highest mark is: " << high(students[k].marks, times) << endl << "Name: " << students[k].name << endl << students[k].studentID << endl;
                    break;
                }
                case 'l': { //case l which finds the lowest mark by calling low function
                    cout << "\nThe lowest mark is: " << low(students[k].marks, times) << endl << "Name: " << students[k].name << endl << students[k].studentID << endl;
                    break;
                }
                case 's': { //case s which calls the sum and avg and high and low functions and stores them in a file made by Rayyan
                    cin.ignore();
                    //if statement used to check if the user already opened the file before if not the user can input a name and a path for the output file
                    if (!outfile.is_open()) {
                    cout << "Enter the file name you want (it must include .txt at the end): ";
                    getline(cin,fileName); //to input the name and path of the file by using getline so spaces can be included
                
                        outfile.open(fileName, ios::out); //opens the output file named by the user
                    }
                    //the sum and avg and high and low functions being called and being stored in the file
                    outfile <<"Name: " << students[k].name << endl <<"Student ID: "<<students[k].studentID<<endl << "\nThe total of all marks is: " << sum(students[k].marks, times) << endl;
                    outfile << "\nThe average of all marks is: " << avg(students[k].marks, times) << endl;
                    outfile << "\nThe highest mark is: " << high(students[k].marks, times) << endl;
                    outfile << "\nThe lowest mark is: " << low(students[k].marks, times) << endl;
                    break;
                }
                case 'e': { //case e is the the exit program or change student if the user enter more then 1 student
                    if (manyStu > 1 && k < manyStu) { //changes student if the user inputed more then 1 student
                        cout << "\nChanging Student\n";
                    }
                    else { //ends program if the user didn't input more then 1 student or after completing all students
                        cout << "\nEnding program, good bye\n";
                    }
                    break;
                }
                default: { //default case used if the user inputed the invalid input
                    cout << "\nInvalid input\n";
                    break;
                }
            }
        } while (ch_out != 'e');
        infile.close(); //closes input of current file
    }
    outfile.close(); //closes the output file
    cout << "The menu function was invoked " << bot << " times";
    return 0;
}
//compiled and debugged by Hadi