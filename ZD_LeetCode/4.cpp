class Solution {
public:
	double findMedianSortedArrays( const vector<int> &A, const vector<int> &B ){
		int	m = A.size();
		int	n = B.size();
		int total = m + n;
		if (total & 0x1)
			return(find_kth( A.begin(), m, B.begin(), n, total / 2 + 1 ) );
		else
			return( (find_kth( A.begin(), m, B.begin(), n, total / 2 )
				 + find_kth( A.begin(), m, B.begin(), n, total / 2 + 1 ) ) / 2.0);
	}
private:
	static int find_kth( std::vector<int>::const_iterator A, int m,
			     std::vector<int>::const_iterator B, int n, int k )	{
		if (m > n)
			return(find_kth( B, n, A, m, k ) );
		if (m == 0)
			return(*(B + k - 1) );
		if (k == 1)
			return(min( *A, *B ) );
		int ia = min( k / 2, m ), ib = k - ia;
		if (*(A + ia - 1) < *(B + ib - 1))
			return(find_kth( A + ia, m - ia, B, n, k - ia ) );
		else if (*(A + ia - 1) > *(B + ib - 1))
			return(find_kth( A, m, B + ib, n - ib, k - ib ) );
		else
			return(A[ia - 1]);
	}
};