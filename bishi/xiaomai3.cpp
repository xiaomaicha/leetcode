//////
////// Created by Administrator on 2019/4/21 0021.
//////
////
////

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
bool cmp(vector<int> &n1, vector<int> &n2) {
    int i = 0;
    while (i < n1.size() - 1 && n1[i] == n2[i])
    {
        i++;
    }
    return n1[i] > n2[i];
}
void backtrack(vector<vector<int>> &res, int k, int K, vector<int> &tmp, vector<bool> &visited) {
    if (k == K) {
        res.push_back(tmp);
        return;
    }
    for (int i = 0; i < tmp.size() - 1; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            swap(tmp[i], tmp[i + 1]);
            backtrack(res, k + 1, K, tmp, visited);
            swap(tmp[i], tmp[i + 1]);
            visited[i] = false;
        }
    }
}

int main() {
    int T;
    cin>>T;
    vector<int> K;
    vector<int> N;
    vector<vector<int >> nums(T);
    for (int i = 0; i < T; ++i) {
        int k_,n_,num_;
        cin>>k_>>n_;
        K.push_back(k_);
        N.push_back(n_);
        for (int j = 0; j < n_; ++j) {
            cin>>num_;
            nums[i].push_back(num_);
        }
    }
    for (int i = 0; i < T; i++) {
        vector<bool> visited(N[i], false);

        vector<vector<int>> res;
        res.push_back(nums[i]);
        backtrack(res, 0, K[i], nums[i], visited);
        sort(res.begin(), res.end(), cmp);
        auto ret = res[0];
        for (int j = 0; j < ret.size(); j++) {
            cout << ret[j] << " ";
        }
        cout << endl;
    }
    return 0;
}