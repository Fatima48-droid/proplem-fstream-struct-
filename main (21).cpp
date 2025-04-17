#include <iostream>
#include <fstream>
using namespace std;

struct MenuSystem {
    string name;
    int age;
    int grades[3];
};

int main() {
    MenuSystem MS[5] = {
        {"ahmed", 21, {99, 99, 99}},
        {"Mohamed", 23, {88, 88, 88}},
        {"yassin", 25, {77, 77, 77}},
        {"sama", 20, {66, 66, 66}},
        {"asmaa", 24, {55, 55, 55}}
    };

    int AVG[5];  

    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += MS[i].grades[j];
        }
        AVG[i] = sum / 3;
    }

    int Max = 0;
    for (int i = 1; i < 5; i++) {
        if (AVG[i] > AVG[Max]) {
            Max = i;
        }
    }

    cout << "The student with the highest average"<<endl;
    cout << "Name = " << MS[Max].name << endl;
    cout << "Age = " << MS[Max].age << endl;

   
    ofstream file("menusystemcpp.txt");
    if (file.is_open()) {
        for (int i = 0; i < 5; i++) {
            file << "Student " << i + 1 << endl;
            file << "Name = " << MS[i].name << endl;
            file << "Grades = ";
            for (int j = 0; j < 3; j++) {
                file << MS[i].grades[j] << " ";
            }
            file << endl;
            file << "Age = " << MS[i].age << endl;
            file << "Average = " << AVG[i] << endl;
            
        }
        file.close();
    } 

    return 0;
}