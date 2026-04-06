#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int main() {
    // get the contents of the file into an input stream object
    ifstream inFile;
    string code;
    inFile.open("codes.txt");
    
    // TASK 1: READ
    // create and populate a vector from the file
    int v_read = 0; // time in nanoseconds it takes to read the data into the vector
    vector<string> myVector;
    // start timing
    auto start = high_resolution_clock::now();
    // read from the file into vector
    while (!inFile.eof()){
        getline(inFile, code);
        myVector.push_back(code);
    }
    // end timing
    auto end = high_resolution_clock::now();
    // calculate duration
    auto duration = duration_cast<nanoseconds>(end - start);
    v_read = duration.count();
    
    //  create and populate a list from the file
    int l_read = 0; // time in nanoseconds it takes to read the data into the list
    list<string> myList;
    inFile.clear(); 
    inFile.seekg(0, ios::beg);
    // start timing
    start = high_resolution_clock::now();
    // read from file into list
    while (!inFile.eof()){
        getline(inFile, code);
        myList.push_back(code);
    }
    // end timing
    end = high_resolution_clock::now();
    // calculate duration
    duration = duration_cast<nanoseconds>(end - start);
    l_read = duration.count();

    // create and populate a set from the file
    int s_read = 0; // time in nanoseconds it takes to read the data into the set
    set<string> mySet;
    inFile.clear(); 
    inFile.seekg(0, ios::beg);
    // start timing
    start = high_resolution_clock::now();
    // read from file into set
    while (!inFile.eof()){
        getline(inFile, code);
        mySet.insert(code);
    }
    // end timing
    end = high_resolution_clock::now();
    // calculate duration
    duration = duration_cast<nanoseconds>(end - start);
    s_read = duration.count();

    // done reading from file
    inFile.close();

    // TASK 2: SORT
    // sort the vector
    int v_sort = 0; // time in nanoseconds it takes to sort the vector;
    // start timing
    start = high_resolution_clock::now();
    // sort vector
    sort(myVector.begin(), myVector.end());
    // end timing
    end = high_resolution_clock::now();
    // calculate duration
    duration = duration_cast<nanoseconds>(end - start);
    v_sort = duration.count();

    // sort the list
    int l_sort = 0; // time in nanoseconds it takes to sort the list
    // start timing
    start = high_resolution_clock::now();
    // sort list
    myList.sort();
    // end timing
    end = high_resolution_clock::now();
    // calculate duration
    duration = duration_cast<nanoseconds>(end - start);
    l_sort = duration.count();

    // the set is already sorted
    int s_sort = -1;

    // TASK 3: INSERT
    // insert "TESTCODE" in the middle of the vector
    int v_insert = 0; // time in nanoseconds to insert in vector
    // start timing
    start = high_resolution_clock::now();
    // insert item in the middle
    vector<string>::iterator v_mid = myVector.begin() + (myVector.size() / 2); // points to the middle item
    myVector.emplace(v_mid, "TESTCODE");
    // end timing
    end = high_resolution_clock::now();
    // calculate duration
    duration = duration_cast<nanoseconds>(end - start);
    v_insert = duration.count();

    // insert "TESTCODE" in the middle of the list
    int l_insert = 0; // time in nanoseconds to insert in list
    // start timing
    start = high_resolution_clock::now();
    // insert item in the middle
    list<string>::iterator l_mid = myList.begin();
    // make l_mid point to middle item
    for(int i = 0; i < myList.size() / 2; ++i)
        advance(l_mid, 1);
    myList.emplace(l_mid, "TESTCODE");
    // end timing
    end = high_resolution_clock::now();
    // calculate duration
    duration = duration_cast<nanoseconds>(end - start);
    l_insert = duration.count();

    // insert "TESTCODE" in the set
    int s_insert = 0; // time in nanoseconds to insert in set
    // start timing
    start = high_resolution_clock::now();
    // insert item in the middle
    mySet.insert("TESTCODE");
    // end timing
    end = high_resolution_clock::now();
    // calculate duration
    duration = duration_cast<nanoseconds>(end - start);
    s_insert = duration.count();

    // TEST 4: DELETE
    // delete the middle item from the vector
    int v_delete = 0; // time in nanoseconds to delete middle item from vector
    // start timing
    start = high_resolution_clock::now();
    // delete item from the middle
    // v_mid still points to the middle one
    myVector.erase(v_mid);
    // end timing
    end = high_resolution_clock::now();
    // calculate duration
    duration = duration_cast<nanoseconds>(end - start);
    v_delete = duration.count();

    // delete the middle item from the list
    int l_delete = 0; // time in nanoseconds to delete the middle item from list
    // start timing
    start = high_resolution_clock::now();
    // delete item from the middle
    // l_mid still points to the middle one
    myList.erase(l_mid);
    // end timing
    end = high_resolution_clock::now();
    // calculate duration
    duration = duration_cast<nanoseconds>(end - start);
    l_delete = duration.count();

    // delete the middle item from the set
    int s_delete = 0; // time in nanoseconds to delete the middle item from set
    // start timing
    start = high_resolution_clock::now();
    // delete item from the middle
    // create an iterator for the set
    set<string>::iterator s_mid = mySet.begin();
    // make s_mid point to middle item
    for(int i = 0; i < mySet.size() / 2; ++i)
        advance(s_mid, 1);
    mySet.erase(s_mid);
    // end timing
    end = high_resolution_clock::now();
    // calculate duration
    duration = duration_cast<nanoseconds>(end - start);
    s_delete = duration.count();

    // display the results
    cout << setw(10) << "Operation" << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    cout << setw(10) << "Read" << setw(10) << v_read << setw(10) << l_read << setw(10) << s_read << endl;
    cout << setw(10) << "Sort" << setw(10) << v_sort << setw(10) << l_sort << setw(10) << s_sort << endl;
    cout << setw(10) << "Insert" << setw(10) << v_insert << setw(10) << l_insert << setw(10) << s_insert<< endl;
    cout << setw(10) << "Delete" << setw(10) << v_delete << setw(10) << l_delete << setw(10) << s_delete << endl;
    
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/