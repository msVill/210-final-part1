#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

void printAirportsInRange(const map<string, int>& airports, int low, int high);

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

    int maxCount = 0;
    for(const auto& item : airportData) {
        if(item.second > maxCount) {
            maxCount = item.second;
        }
    }

    cout << "Busiest airport(s) with count " << maxCount << ":" << endl;
    for(const auto& item : airportData) {
        if(item.second == maxCount) {
            cout << item.first << " " << item.second << endl;
        }
    }
    cout << endl;

    void printAirportsInRange(const map<string, int>& airports, int low, int high) {
        cout << "Airports with traffic in range [" 
            << low << ", " << high << "]:" << endl;

            for(const auto& item : airports) {
                if(item.second >= low && item.seconf <= high) {
                    cout << item.first << " " << item.second << endl;
                }
            }
    }
    return 0;
}