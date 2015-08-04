#include "../header.h"

vi sieve(int max = 1000*1000)
{
	vi v;
	vi mark;
	int srt = sqrt(max);

	mark.resize(max+1);

	fi(2, srt+1)
	{
		if (mark[i] == 1)
			continue;

		v.pb(i);

		for (int j=1; j*i<=max; j++)
		{
			mark[j*i] = 1;
		}
	}

	fi(srt+1, max+1)
	{
		if (mark[i] == 0)
			v.pb(i);
	}

	return v;
}

vi prime_representation(ll num, const vi &sv)
{
	vi primes(sv.sz, 0);

	if (num <= 1)
		return primes;

	fio(sv.sz)
	{
		while (num % sv[i] == 0)
		{
			primes[i]++;
			num /= sv[i];
		}

		if (i > num)
			break;
	}

	return primes;
}

ll ndivisors(ll num, const vi &sv)
{
	vi primes = prime_representation(num, sv);
	ll product = 1;

	fio(primes.sz)
		product *= (primes[i] + 1);

	return product;
}


