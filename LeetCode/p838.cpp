class Solution {
public:
    string pushDominoes(string dominoes) {
        int p_left = -1, p_right = -1;
        auto sz = dominoes.size();

        int scanner = 0;
        while (scanner < sz) {
            // step1: locate
            // step2: flip
            while (scanner < sz && isalpha(dominoes[scanner]))
                ++scanner;
            p_left = scanner - 1;
            while (scanner < sz && !isalpha(dominoes[scanner]))
                ++scanner;
            p_right = scanner;
            if (p_left == -1 && p_right == sz) {
                break;
            } else if (p_left == -1) {
                if (dominoes[p_right] == 'L')
                    fill(dominoes.begin(), dominoes.begin() + p_right, 'L');
            } else if (p_right == sz) {
                if (dominoes[p_left] == 'R')
                    fill(dominoes.begin() + p_left + 1, dominoes.end(), 'R');
            } else if (dominoes[p_left] == dominoes[p_right]) {
                fill(dominoes.begin() + p_left + 1, dominoes.begin() + p_right, dominoes[p_left]);
            } else if (dominoes[p_left] == 'L' && dominoes[p_right] == 'R') {
                // pass
            } else {
                int tl = p_left + 1, tr = p_right - 1;
                while (tl < tr) {
                    dominoes[tl++] = 'R';
                    dominoes[tr--] = 'L';
                }
            }
        }
        return dominoes;
    }
};

