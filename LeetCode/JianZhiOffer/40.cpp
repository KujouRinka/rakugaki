class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0)
            return {};
        priority_queue<int> hp;
        for (int i = 0; i < k; ++i)
            hp.push(arr[i]);
        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < hp.top()) {
                hp.pop();
                hp.push(arr[i]);
            }
        }
        vector<int> result;
        result.reserve(hp.size());
        while (!hp.empty()) {
            result.push_back(hp.top());
            hp.pop();
        }
        return result;
    }
};

