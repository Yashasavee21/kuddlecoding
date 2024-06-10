#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N);
        vector<int> B(N);

        for (int i=0; i<N; i++)
        cin >> A[i];
        for (int i=0; i<N; i++)
        cin >> B[i];

        unordered_map<int,int> minTimeForCategory;

        for (int i=0; i<N; i++) {
            int category = A[i];
            int time = B[i];

            if (minTimeForCategory.find(category) == minTimeForCategory.end())
            minTimeForCategory[category] = time;
            else 
            minTimeForCategory[category] = min(minTimeForCategory[category], time);
        }
        
        if (minTimeForCategory.size() < K) {
            cout << -1 << endl;
            continue;
        }

        vector<int> times;

        for (auto& entry : minTimeForCategory)
        times.push_back(entry.second);

        sort (times.begin(), times.end());

        int minTotalTime = 0;

        for (int i=0; i<K; i++) 
        minTotalTime += times[i];

        cout << minTotalTime << endl;
    }

    return 0;

}
