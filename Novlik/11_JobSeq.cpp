#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    char id;
    int start;
    int end;
    int profit;
};

bool compareTasks(const Task& a, const Task& b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Task>& tasks, int n) {
    sort(tasks.begin(), tasks.end(), compareTasks);

    int maxEndTime = 0;
    for (const Task& task : tasks) {
        maxEndTime = max(maxEndTime, task.end);
    }

    vector<char> sequence(maxEndTime + 1, ' ');

    for (const Task& task : tasks) {
        for (int i = task.end; i >= task.start; --i) {
            if (sequence[i] == ' ') {
                sequence[i] = task.id;
                break;
            }
        }
    }

    cout << "Job sequence: ";
    for (char task : sequence) {
        if (task != ' ') {
            cout << task << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of tasks: ";
    cin >> n;

    vector<Task> tasks(n);
    cout << "Enter start, end, and profit for each task:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Task " << i + 1 << ": ";
        cin >> tasks[i].start >> tasks[i].end >> tasks[i].profit;
        tasks[i].id = 'A' + i; 
    }

    jobSequencing(tasks, n);

    return 0;
}

