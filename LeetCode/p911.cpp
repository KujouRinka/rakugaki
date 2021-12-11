class TopVotedCandidate {
public:
    TopVotedCandidate(const vector<int> &persons, const vector<int> &times)
            : m_data_vec(persons.size()), m_time_table(times) {
        int max_poll = 0;
        auto sz = persons.size();
        vector<int> poll_count(sz);
        for (int i = 0; i < sz; ++i) {
            if (++poll_count[persons[i]] >= max_poll) {
                m_data_vec[i] = persons[i];
                max_poll = poll_count[persons[i]];
            } else {
                m_data_vec[i] = m_data_vec[i - 1];
            }
        }
    }

    int q(int t) {
        return m_data_vec[upper_bound(m_time_table.begin(), m_time_table.end(), t) - m_time_table.begin() - 1];
    }

private:
    vector<int> m_data_vec;
    vector<int> m_time_table;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

