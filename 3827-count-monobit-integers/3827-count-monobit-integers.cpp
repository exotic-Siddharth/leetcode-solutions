class Solution {
public:
    bool isMonobit(int x) {
        int bit = x & 1;
        while (x > 0) {
  if ((x & 1) != bit)
                return false;
      x >>= 1;
        }
            return true;
    }

    int countMonobit(int n) {
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (isMonobit(i))
                cnt++;
        }
        return cnt;
    }
};
