/*
 * RW is a library for read and write files in binary mode
 * It parse a vector of any types(includes your own data types)
 *  to file and read it in binary mode
 * NOTE That you must avoid dynamic memory allocation in
 *  your data type that you want to use in vector
 *  for example you can't read and write well a class that have strings
 *  in binary mode. instead use char* with a constant size
 * 
 * Author: Amir Mohamadi
 * Under GPL v3.0 license
*/
#ifndef RW_H
#define RW_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::fstream;
using std::vector;
using std::string;


class RW
{
  private:
    string file;

  public:
    RW(string s);
    void setFile(string);

    template <typename T>
    void parseToVec(vector<T> &); // Parse binary file data to vector      

    template <typename T>
    void parseToFile(vector<T> &); // Parse vector to binary file
};


RW::RW(string s)
{
  this->file = s;
}

void RW::setFile(string s)
{
  this->file = s;
}

template <typename T>
void RW::parseToVec(vector<T> &list)
{
    // Define and open the file
    fstream db;
    try
    {
        db.open(this->file, std::ios::binary | std::ios::in);

        // Reading data
        T temp;
        int counter = 0; // Used in seekg

        while (true)
        {
            // Go to the correct position
            db.seekg(sizeof(T) * counter, std::ios::beg);
            // Reading data from db to T (T can be a class)
            db.read((char *)&temp, sizeof(T));
            
            // Check end of file
            if (db.eof()) break;

            counter++;

            // psuh temp to the list
            list.push_back(temp);
        }
        // Close file
        db.close();
    }
    catch (const std::ifstream::failure &e)
    {
        std::cout << "Couldn't open the file " << this->file << std::endl;
    }
}

template <typename T>
void RW::parseToFile(vector<T> &list)
{
    // Define and open the file
    fstream db;

    try
    {
      db.open(this->file, std::ios::binary | std::ios::out);

      // Writing data to db
      db.write((char *)(&list[0]), list.size() * sizeof(T));

      // Close file
      db.close();
    }
    catch (const std::ifstream::failure &e)
    {
        std::cout << "Couldn't open the file " << this->file << std::endl;
    }
}

#endif
