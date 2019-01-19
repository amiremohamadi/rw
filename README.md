# RW
> A minimal library to parse and work with binary stored files in C++ (read and write lib)

With Rwlib you can write a list of datatypes (includes your own data types!) in binary mode to a file or read from a file.
<br/>
Read and write (from/to classes and structs) easier than any time!

## How to use
* Include rw.h to your cpp file
```c++
#include "rw.h"
```
* For example we have and struct like this:
```c++
struct Student {
    char name[10];
    int age;
    int id;
};
```
* And we have a vector of Students:
```c++
vector<Student> list;
```
* Now create an object of RW:
```c++
RW rw("my_students.bin");
```
it will create a file with name "my_students.bin"
* Read and Write data with these two simple commands:
```c++
rw.parseToFile(list);
rw.parseToVec(list);
```

## ToDo
- [ ] Many Things!
