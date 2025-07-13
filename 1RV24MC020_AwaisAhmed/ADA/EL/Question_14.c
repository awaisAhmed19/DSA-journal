#include <bits/stdc++.h>
using namespace std;

struct meeting {
    int startTime, endTime, pos;
};

// Comparator to sort by ending time
bool compare(meeting m1, meeting m2) { return m1.endTime < m2.endTime; }

// Function for finding maximum meetings in one room
vector<meeting> maxMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<meeting> meets(n);

    cout << "📅 Initial Meeting List:\n";
    for (int i = 0; i < n; i++) {
        meets[i].startTime = start[i];
        meets[i].endTime = end[i];
        meets[i].pos = i + 1;
        cout << "Meeting " << meets[i].pos << ": [" << start[i] << ", " << end[i] << "]\n";
    }

    sort(meets.begin(), meets.end(), compare);

    cout << "\n📊 After Sorting by End Time:\n";
    for (int i = 0; i < n; i++) {
        cout << "Meeting " << meets[i].pos << ": [" << meets[i].startTime << ", "
             << meets[i].endTime << "]\n";
    }

    vector<meeting> selected;
    int currTime = -1;

    cout << "\n✅ Selecting Meetings:\n";
    for (int i = 0; i < n; i++) {
        if (meets[i].startTime > currTime) {
            currTime = meets[i].endTime;
            selected.push_back(meets[i]);
            cout << "✔️ Chose Meeting " << meets[i].pos << ": [" << meets[i].startTime << ", "
                 << meets[i].endTime << "]\n";
        } else {
            cout << "❌ Skipped Meeting " << meets[i].pos << ": [" << meets[i].startTime << ", "
                 << meets[i].endTime << "]\n";
        }
    }

    return selected;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    vector<meeting> res = maxMeetings(start, end);

    cout << "\n🏁 Final Selected Meetings (Non-overlapping):\n";
    for (auto m : res) {
        cout << "Meeting " << m.pos << ": [" << m.startTime << ", " << m.endTime << "]\n";
    }

    return 0;
}
