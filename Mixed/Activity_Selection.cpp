#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int id;
    int start;
    int finish;
};

void Swap(Activity &a, Activity &b) {
    Activity temp = a;
    a = b;
    b = temp;
}

void sorter(vector<Activity> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].finish < arr[mini].finish)
                mini = j;
        }
        Swap(arr[i], arr[mini]);
    }
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> arr(n);

    cout << "Enter activity start and finish times:\n";

    for (int i = 0; i < n; i++) {
        arr[i].id = i + 1;

        cout << "Activity A" << i + 1 << " (start finish): ";
        cin >> arr[i].start >> arr[i].finish;
    }

    sorter(arr);

    vector<Activity> selected;
    int lastFinish = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i].start >= lastFinish) {
            selected.push_back(arr[i]);
            lastFinish = arr[i].finish;
        }
    }

    cout << "\nSelected Activities:\n";

    for (int i = 0; i < selected.size(); i++) {
        cout << "A" << selected[i].id
             << " : (" << selected[i].start
             << ", " << selected[i].finish << ")\n";
    }

    return 0;
}
