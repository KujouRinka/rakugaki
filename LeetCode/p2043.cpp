class Bank {
public:
    Bank(const vector<long long> &balance) : _balance(balance) {}
    
    bool transfer(int account1, int account2, long long money) {
        if (!(checkAccount(account1) && checkAccount(account2)))
            return false;
        lock_guard<mutex> g(mu);
        if (_balance[account1 - 1] < money)
            return false;
        _balance[account1 - 1] -= money;
        _balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!checkAccount(account))
            return false;
        lock_guard<mutex> g(mu);
        _balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!checkAccount(account))
            return false;
        lock_guard<mutex> g(mu);
        if (_balance[account - 1] < money)
            return false;
        _balance[account - 1] -= money;
        return true;
    }

private:
    vector<long long> _balance;
    mutex mu;

    inline bool checkAccount(int acc) {
        return acc > 0 && acc <= _balance.size();
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

