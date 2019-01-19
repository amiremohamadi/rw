#include <iostream>
#include <vector>
#include "rw.h"
using namespace std;

struct Student {
    char name[10];
    int age;
    int id;
};

int main() {
    vector<Student> list;

    list.push_back(Student{"amir", 19,21});
    list.push_back(Student{"ehsan", 24,29});
    list.push_back(Student{"fateme", 9,2});
    list.push_back(Student{"zahra", 18,33});

    RW rw("my_students.bin");
    rw.parseToFile(list); // Parse student specifications to file

    list.clear(); // Flush list
    // Now the list is emty!
    cout << list.size() << endl; // Prints zero!

    rw.parseToVec(list); // Parse data to list
    for (auto i : list)
        cout << i.id << ": " << i.name << ", " << i.age << endl;
    
    return 0;
}
