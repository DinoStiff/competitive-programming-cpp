#include "lib0927.h"
#include <iostream>
#include <vector>
using namespace std;

namespace {
void fatal(const string& msg) {
    cerr << msg << endl;
    exit(0);
}

void ensureImpl(bool condition, const char* conditionStr) {
    if (condition)
        return;
    fatal("Wrong Answer: " + string(conditionStr));
}
const int maxL = 120;
void check_string(string s) {
    ensureImpl((int)s.size() <= maxL, "Too long");
    for (char c:s) ensureImpl(c == 'G' || c == 'O', "Wrong charset");
}
}

int main() {
    srand(time(NULL));
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    init();
    vector<string> enc;
    int times = k;
    int maxlen = 0;
    for (int p = 0;p < n;p++) {
        string msg = Anon(nums[p], k);
        cout << "Number: " << nums[p] << "\n";
        cout << "Anon sends: " << msg << "\n";
        check_string(msg);
        int len = msg.size();
        for (int i = 0;i < times;i++) {
            vector<int> pos;
            for (int j = 0;j < len-1;j++) {
                if (msg[j] == 'G' && msg[j+1] == 'O') pos.push_back(j);
            }
            if (pos.size() == 0) continue;
            int idx = rand() % pos.size(); 
            swap(msg[pos[idx]], msg[pos[idx]+1]);
            cout << "            ";
            for (int j = 0;j < len;j++) {
                if (j == pos[idx] || j == pos[idx]+1) cout << msg[j];
                else cout << " ";
            }
            cout << "\n";
        }
        enc.push_back(msg);
        cout << "After 8e7:  " << msg << "\n";
        maxlen = max(maxlen, (int)enc[p].size());
        int ans = Baluteshih(enc[p], k);
        cout << "Baluteshih returns " << ans << "\n";
        ensureImpl(ans == nums[p], "Not correct");
        cout << "\n";
    }
    cout << "Accepted: " << maxlen << "\n";
}
