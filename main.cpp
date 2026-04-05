#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <iomanip>
using namespace std;

int main() {
    // TASK 1: READ
    // create and populate a vector from the file
    int v_read = 0; // time in nanoseconds it takes to read the data into the vector
    vector<string> myVector;

    //  create and populate a list from the file
    int l_read = 0; // time in nanoseconds it takes to read the data into the list
    list<string> myList;

    // create and populate a set from the file
    int s_read = 0; // time in nanoseconds it takes to read the data into the set
    set<string> mySet;

    // TASK 2: SORT
    // sort the vector
    int v_sort = 0; // time in nanoseconds it takes to sort the vector;

    // sort the list
    int l_sort = 0; // time in nanoseconds it takes to sort the list

    // the set is already sorted
    int s_sort = -1;

    // TASK 3: INSERT
    // insert "TESTCODE" in the middle of the vector
    int v_insert = 0; // time in nanoseconds to insert in vector

    // insert "TESTCODE" in the middle of the list
    int l_insert = 0; // time in nanoseconds to insert in list

    // insert "TESTCODE" in the middle of the set
    int s_insert = 0; // time in nanoseconds to insert in set

    // TEST 4: DELETE
    // delete the middle item from the vector
    int v_delete = 0; // time in nanoseconds to delete middle item from vector

    // delete the middle item from the list
    int l_delete = 0; // time in nanoseconds to delete the middle item from list

    // delete the middle item from the set
    int s_delete = 0; // time in nanoseconds to delete the middle item from set


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