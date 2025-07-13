
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct User {
    int id;
    double bandwidth;     // Demand
    double utility;       // Priority score
    double utilityPerBW;  // uᵢ / bᵢ
    double allocated = 0.0;
    double usedFraction = 0.0;

    User(int i, double b, double u) {
        id = i;
        bandwidth = b;
        utility = u;
        utilityPerBW = utility / bandwidth;
    }
};

// Greedy allocation function (Fractional Knapsack)
double allocateBandwidth(vector<User>& users, double capacity) {
    // Sort users by utility per bandwidth in descending order
    sort(users.begin(), users.end(),
         [](const User& a, const User& b) { return a.utilityPerBW > b.utilityPerBW; });

    double totalUtility = 0.0;
    double remaining = capacity;

    for (auto& user : users) {
        if (user.bandwidth <= remaining) {
            // Give full bandwidth
            user.allocated = user.bandwidth;
            user.usedFraction = 1.0;
            totalUtility += user.utility;
            remaining -= user.bandwidth;
        } else {
            // Throttle — give partial
            user.allocated = remaining;
            user.usedFraction = remaining / user.bandwidth;
            totalUtility += user.utility * user.usedFraction;
            remaining = 0;
            break;  // No more capacity
        }
    }
    return totalUtility;
}

int main() {
    double capacity = 100.0;

    // Format: {User ID, Bandwidth Demand, Utility}
    vector<User> users = {
        User(1, 40, 80),  // Density: 2.0
        User(2, 30, 90),  // Density: 3.0
        User(3, 60, 100)  // Density: 1.67
    };

    double totalUtility = allocateBandwidth(users, capacity);

    cout << fixed << setprecision(2);
    cout << "Total ISP Capacity: " << capacity << " units\n";
    cout << "Total Utility Achieved: " << totalUtility << "\n\n";

    cout << left << setw(8) << "User" << setw(12) << "Bandwidth" << setw(10) << "Utility"
         << setw(12) << "Allocated" << setw(12) << "% Given"
         << "Utility Gained\n";
    cout << string(65, '-') << "\n";

    for (const auto& u : users) {
        double gained = u.utility * u.usedFraction;
        cout << left << setw(8) << u.id << setw(12) << u.bandwidth << setw(10) << u.utility
             << setw(12) << u.allocated << setw(12) << u.usedFraction * 100 << gained << "\n";
    }

    return 0;
}
