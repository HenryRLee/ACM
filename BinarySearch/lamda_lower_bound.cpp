// https://www.codechef.com/SNCKQL17/problems/SNAKEEAT
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define fl(i, b, e)		for (int i=(int)(b); i<(int)(e); i++)
#define fld(i, b, e)		for (int i=(int)(b)-1; i>=(int)(e); i--)
#define flo(i, e)		fl(i, 0, e)
#define fi(b, e)	fl(i, b, e)
#define fio(e)	fi(0, e)
#define fj(b, e)	fl(j, b, e)
#define fjo(e)	fj(0, e)
#define fk(b, e)	fl(k, b, e)
#define fko(e)	fk(0, e)
#define fvi(i, v)	fl(i, 0, v.size())
#define fvd(i, v)	fld(i, v.size(), 0)
#define pb	push_back
#define sz	size()
#define mp	make_pair
#define fs	first
#define sd	second
#define all(x)	(x).begin(), (x).end()
#define sqr(x)	((x)*(x))
#define bc(x) __builtin_popcount(x)
#define newline		printf("\n")

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef vector <vi> vvi;
typedef vector <vl> vvl;
typedef pair <int, int> pii;
typedef vector <pii> vp;
typedef vector <vp> vvp;

const int inf = 2147483647;

inline bool cbound(int x, int b, int e)
{
	return ((x >= b) && (x <= e));
}

inline int getint()
{
	int a;
	cin >> a;
	return a;
}

inline ll getll()
{
	ll a;
	cin >> a;
	return a;
}

inline double getdouble()
{
	double a;
	cin >> a;
	return a;
}

template <class T>
inline void debugv(vector <T> v)
{
	fio(v.sz)
	{
		printf("(%d)", i);
		cout << v[i] << " ";
	}
	cout << endl;
}

template <class T>
inline void debugvv(vector < vector <T> > vv)
{
	fio(vv.sz)
	{
		printf("[%d]", i);
		debugv(vv[i]);
	}
	cout << endl;
}

inline void msg(string str)
{
	cout << "=== " + str + " ===" << endl;
}

template <class T>
class FakeArray {
public:
	typedef T value_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef const T* const_pointer;
	typedef const T& const_reference;

	class iterator {
	public:
		typedef T value_type;
		typedef random_access_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef const T* const_pointer;
		typedef const T& const_reference;

		bool operator==(const iterator & other) { return value == other.value; }
		bool operator!=(const iterator & other) { return value != other.value; }
		reference operator*() { return value; }
		pointer operator->() { return &value; }
		iterator& operator++() { ++value; return *this; }
		iterator operator++(int)
		{
			iterator tmp(*this);
			operator++();
			return tmp;
		}
		iterator& operator--() { --value; return *this; }
		iterator operator--(int)
		{
			iterator tmp(*this);
			operator--();
			return tmp;
		}
		friend iterator operator+(iterator lhs, int rhs) {
			lhs.value += rhs;
			return lhs;
		}
		friend iterator operator+(int lhs, iterator rhs) {
			rhs.value += lhs;
			return rhs;
		}
		iterator& operator+=(const int dist) {
			value += dist;
			return *this;
		}
		friend iterator operator-(iterator lhs, int rhs) {
			lhs.value -= rhs;
			return lhs;
		}
		friend difference_type operator-(const iterator& lhs, const iterator& rhs) {
			return difference_type(lhs.value - rhs.value);
		}
		iterator& operator-=(const int dist) {
			value -= dist;
			return *this;
		}
		bool operator<(const iterator& other) { return value < other.value; }
		bool operator<=(const iterator& other) { return value <= other.value; }
		bool operator>(const iterator& other) { return value > other.value; }
		bool operator>=(const iterator& other) { return value >= other.value; }
		reference operator[](int dist) {
			value += dist;
			return value;
		}
		friend void swap(iterator &lhs, iterator &rhs) {
			swap(lhs.value, rhs.value);
		}
		iterator() { }
	private:
		value_type value;
		iterator(const value_type & v) { value = v; }
		friend FakeArray;
	};

	FakeArray(value_type start, value_type end)
   		: start_(start), end_(end) { }

	iterator begin() { return iterator(start_); }
	iterator end() { return iterator(end_); }

private:
	value_type start_;
	value_type end_;
};

/*
 * Checking function for binary search
 */
bool check(ll x, const vi &array, int k, const vl & presum)
{
	/*
	 * check if length x can fit k elements
	 */

	int n = array.sz;

	// # of elements less than k
	int lt = lower_bound(array.begin(), array.end(), x) - array.begin();
	int consuming = n - k;

	if (lt <= consuming)
		return true;

	int m = lt - consuming;

	// sum from array[consuming] to array[lt-1]
	ll sum = presum[lt] - presum[consuming];

	if ((sum + consuming) >= (x * m))
		return true;
	else
		return false;
}

ll bsearch(ll minx, ll maxx, const vi &array, int k, const vl & presum)
{
	ll l = minx;
	ll r = maxx;

	while (l < r)
	{
		ll mid = (l + r) / 2;

		if (check(mid, array, k, presum))
			l = mid + 1;
		else
			r = mid - 1;
	}

	if (check(l, array, k, presum))
		return l;
	else
		return (l - 1);
}


int main(void)
{
	int t;

	FakeArray<int> fa(1, 1100*1000*1000+7);
	
	cin >> t;

	fl(cs, 0, t)
	{
		int n, q;
		vi va;

		cin >> n >> q;

		fio(n)
		{
			va.pb(getint());
		}

		sort(all(va));

		vl presum(n+1);

		presum[0] = 0;

		fio(n)
		{
			presum[i+1] = presum[i] + va[i];
		}

		vi ans(n+1);

		fi(1, n+1)
		{
			//ans[i] = bsearch(1, 1100*1000*1000+7, va, i, presum);

			auto tmp = lower_bound(fa.begin(), fa.end(), 0,
					[&va, i, &presum] (const int &x, const int &y) -> bool {
						/*
						 * check if length x can fit k elements
						 */

						int n = va.sz;
						int k = i;

						// # of elements less than k
						int lt = lower_bound(va.begin(), va.end(), x) - va.begin();
						int consuming = n - k;

						if (lt <= consuming)
							return true;

						int m = lt - consuming;

						// sum from array[consuming] to array[lt-1]
						ll sum = presum[lt] - presum[consuming];

						if ((sum + consuming) >= ((ll)x * m))
							return true;
						else
							return false;

					}
			);

			ans[i] = *tmp - 1;
		}

		ans[0] = 1100*1000*1000+7;

		fio(q)
		{
			int qi;

			cin >> qi;

			int nsnake = upper_bound(ans.begin(), ans.end(), qi, greater<int>()) - ans.begin();
			cout << nsnake - 1 << endl;
		}
	}

	return 0;
}

