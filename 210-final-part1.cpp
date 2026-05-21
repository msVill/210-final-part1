#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;


int main() {
    map<string, int> airportData;
    
    ifstream file("210-final-1-SP26.txt");

    if(!file) {
        cout << "Error: Can't open file" << endl;
        return 1;
    }

    string origin, destination;
    while (file >> origin >> destination) {
        airportData[origin]++;
        airportData[destination]++; 
    }

    file.close();

    cout << "All airport traffic counts:" << endl;
    for(const auto& item : airportData) {
        cout << item.first << " " << item.second << endl;
    }
    cout << endl;

    return 0;
}