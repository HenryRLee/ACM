#include "../header.h"

/*
 * Checking function for binary search
 */
bool check(ll x, const vi &array)
{
	/*
	 * If the element you want is on the right side, you can still use
	 * this comparison, but remember to change the less/less or equal sign.
	 * In the end, increment the result by 1.
	 *
	 * For example, you want the number strictly greater than 100,
	 * use array[x] <= 100, and increment the final result by 1.
	 */
	if (array[x] <= 100)
		return true;
	else
		return false;
}

template <class ...Args>
ll bsearch(ll minx, ll maxx, Args&& ... args)
{
	ll l = minx;
	ll r = maxx;

	while (l < r)
	{
		ll mid = (l + r) / 2;

		if (check(mid, forward<Args>(args)...))
			l = mid + 1;
		else
			r = mid - 1;
	}

	if (check(l, forward<Args>(args)...))
		return l;
	else
		return (l - 1);
}

int main(void)
{
	int a[] = {0, 2, 4, 8, 16, 32, 64, 100, 128, 256, 512};
	vi array(a, a + sizeof(a)/sizeof(int));

	cout << bsearch(0, sizeof(a)/sizeof(int), array) << endl;
}
