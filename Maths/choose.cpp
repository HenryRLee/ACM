#include "../header.h"

vvl choose(int num = 100, ll mod = 1000*1000*1000+7)
{
	vvl ret;

	ret.resize(num+1);

	fio(ret.sz)
		ret[i].resize(num+1);

	fio(ret.sz)
		ret[i][0] = 1;

	fi(1, ret.sz)
		fj(1, i+1)
			ret[i][j] = (ret[i-1][j] + ret[i-1][j-1]) % mod;

	return ret;
}
