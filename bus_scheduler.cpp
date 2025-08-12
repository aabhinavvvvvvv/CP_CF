#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Bus {
    int start;
    int end;
    int id;
};

class BusScheduler {
public:
    // Remove buses that are completely covered by another bus
    vector<Bus> removeCoveredBuses(vector<Bus>& buses) {
        if (buses.empty()) return {};
        
        // Sort by start point, then by end point in descending order
        sort(buses.begin(), buses.end(), [](const Bus& a, const Bus& b) {
            if (a.start != b.start) return a.start < b.start;
            return a.end > b.end;
        });
        
        vector<Bus> result;
        int max_end = buses[0].end;
        result.push_back(buses[0]);
        
        for (int i = 1; i < buses.size(); i++) {
            // If current bus is not covered by previous buses
            if (buses[i].end > max_end) {
                result.push_back(buses[i]);
                max_end = buses[i].end;
            }
        }
        
        return result;
    }
    
    // Remove redundant buses that can be replaced by a combination of others
    vector<Bus> removeRedundantBuses(vector<Bus>& buses) {
        if (buses.empty()) return {};
        
        // Sort by start point
        sort(buses.begin(), buses.end(), [](const Bus& a, const Bus& b) {
            return a.start < b.start;
        });
        
        vector<Bus> result;
        result.push_back(buses[0]);
        
        for (int i = 1; i < buses.size(); i++) {
            // Check if current bus extends beyond the last selected bus
            if (buses[i].start > result.back().end) {
                result.push_back(buses[i]);
            } else if (buses[i].end > result.back().end) {
                // Merge overlapping buses
                result.back().end = max(result.back().end, buses[i].end);
            }
        }
        
        return result;
    }
    
    // Print bus information
    void printBuses(const vector<Bus>& buses, const string& title) {
        cout << title << ":" << endl;
        for (const auto& bus : buses) {
            cout << "Bus " << bus.id << ": [" << bus.start << ", " << bus.end << "]" << endl;
        }
        cout << endl;
    }
};

int main() {
    BusScheduler scheduler;
    
    // Example usage
    vector<Bus> buses = {
        {1, 5, 1},
        {2, 4, 2},
        {3, 6, 3},
        {7, 10, 4},
        {8, 9, 5},
        {11, 15, 6},
        {12, 14, 7}
    };
    
    cout << "Original buses:" << endl;
    scheduler.printBuses(buses, "Original");
    
    // Remove covered buses
    vector<Bus> nonCovered = scheduler.removeCoveredBuses(buses);
    scheduler.printBuses(nonCovered, "After removing covered buses");
    
    // Remove redundant buses
    vector<Bus> nonRedundant = scheduler.removeRedundantBuses(buses);
    scheduler.printBuses(nonRedundant, "After removing redundant buses");
    
    return 0;
}
