#include "../header.h"

/*
 * Checking function for binary search
 */
bool check(ll x)
{
	return (x <= 100);
}

ll bsearch(ll minx, ll maxx)
{
	ll l = minx;
	ll r = maxx;

	while (l < r)
	{
		ll mid = (l + r) / 2;

		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}

	if (check(l))
		return l;
	else
		return (l - 1);
}

int main(void)
{
	cout << bsearch(0, 1e18) << endl;
}
