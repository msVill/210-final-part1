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
        airportData[destination]++; //What's next.. read the file.. for each flight, insert
    }

    file.close();

    return 0;
}