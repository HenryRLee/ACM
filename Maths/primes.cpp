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

