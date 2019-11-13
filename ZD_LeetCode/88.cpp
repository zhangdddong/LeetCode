class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int ia = m - 1, ib = n - 1, i = m + n - 1;
        while (ia >= 0 && ib >= 0)
            A[i--] = A[ia] > B[ib] ? A[ia--] : B[ib--];
        while (ib >= 0)
            A[i--] = B[ib--];
    }
};
