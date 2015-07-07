#include "../header.h"

ll gcd(ll a, ll b)
{
	ll c;

	while (a != 0)
	{
		c = a;
		a = b % a;
		b = c;
	}

	return b;
}


