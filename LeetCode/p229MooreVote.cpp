class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<pair<int, int>> candidates;
        candidates.emplace_back(0, 0);
        candidates.emplace_back(0, 0);
        for (int poll: nums) {
            checkCandidate(candidates, poll);
        }

        vector<int> result;
        for (auto &p: candidates) {
            if (p.second > 0) {
                int count = 0;
                for (int i: nums) {
                    if (p.first == i)
                        ++count;
                }
                if (count > nums.size() / 3)
                    result.push_back(p.first);
            }
        }
        return result;
    }

private:
    static void checkCandidate(vector<pair<int, int>> &candidates, int poll) {
        int pos = isInCandidates(candidates, poll);
        if (pos != -1) {
            ++candidates[pos].second;
        } else {
            pos = findZero(candidates);
            if (pos == -1) {
                for (auto &p: candidates)
                    --p.second;
            } else {
                candidates[pos].first = poll;
                candidates[pos].second = 1;
            }
        }
    }

    static int isInCandidates(vector<pair<int, int>> &candidates, int poll) {
        for (int i = 0; i < candidates.size(); ++i) {
            if (candidates[i].first == poll)
                return i;
        }
        return -1;
    }

    static int findZero(vector<pair<int, int>> &candidates) {
        for (int i = 0; i < candidates.size(); ++i) {
            if (candidates[i].second == 0)
                return i;
        }
        return -1;
    }
};
