#include "../header.h"

vl newmap(vl v)
{
	vl tmp = v;
	int size;

	sort(all(tmp));

	size = unique(all(tmp)) - tmp.begin();

	fvi(i, v)
	{
		v[i] = lower_bound(tmp.begin(), tmp.begin()+size, v[i]) - tmp.begin();
	}

	return v;
}
