#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> activities = { "Swimming", "Running", "Football" };
int totalCount = 0;

void generateSchedules(int n, vector<string> current) {
    if ((int)current.size() == n) {
        for (string l : current) {
            cout << l << " ";
        }
        cout << endl;
        totalCount++;
        return;
    }

    if (current.empty()) {
        for (int i = 0; i < 3; i++) {
            current.push_back(activities[i]);
            generateSchedules(n, current);
            current.pop_back();
        }
    }
    else {
        if (current.back() == activities[0]) {
            current.push_back(activities[1]);
            generateSchedules(n, current);
            current.pop_back();

            current.push_back(activities[2]);
            generateSchedules(n, current);
            current.pop_back();
        }
        else if (current.back() == activities[1]) {
            current.push_back(activities[0]);
            generateSchedules(n, current);
            current.pop_back();

            current.push_back(activities[2]);
            generateSchedules(n, current);
            current.pop_back();
        }
        else if (current.back() == activities[2]) {
            current.push_back(activities[0]);
            generateSchedules(n, current);
            current.pop_back();

            current.push_back(activities[1]);
            generateSchedules(n, current);
            current.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> schedule;
    generateSchedules(n, schedule);
    cout << "COUNT: " << totalCount << endl;
}
