#include "../header.h"

// ax == b mod d
int congruence(int a, int b, int d)
{
	if (a == 1)
		return b;

	fio(a+1)
	{
		if ((d * i + b) % a == 0)
			return (d * i + b) / a;
	}

	return -1;
}

// x = r1 + mod m1
// x = r2 + mod m2
// ..
// x = rn + mod m3
int chineseremainder(vi r, vi m)
{
	if (r.sz != m.sz || r.sz == 0)
		return -1;

	int rs = r[0];
	int ms = m[0];

	fi(1, r.sz)
	{
		int a = ms;
		int b = r[i] - rs;
		int m2 = m[i];
		int b2 = congruence(a, b, m2);
		rs = ms * b2 + rs;
		ms = ms * m2;
	}

	return rs;
}

