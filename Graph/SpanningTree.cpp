#include "../header.h"


vp PrimList(vvp adjlist, int r = 0)
{
	const int inf = 2e31-1;
	set <pii> q;
	vi intree;
	vi key;
	vi parent;
	ll wsum = 0;
	vp ret;

	intree.resize(adjlist.sz);
	key.resize(adjlist.sz);
	parent.resize(adjlist.sz);

	fio(adjlist.sz)
	{
		if (i == r)
		{
			key[i] = 0;
			q.insert(mp(0, i));
		}
		else
		{
			key[i] = inf;
			q.insert(mp(inf, i));
		}
		parent[i] = -1;
	}

	while (!q.empty())
	{
		pii top = *q.begin();
		int u;
		int p;
		q.erase(q.begin());

		u = top.sd;

		intree[u] = 1;

		p = parent[u];

		if (p != -1)
		{
			ret.pb(mp(p, u));
			wsum += top.fs;
		}
		else if (u != r)
		{
			/* Not connected */
			vp empty;

			wsum = 0;
			return empty;
		}

		fio(adjlist[u].sz)
		{
			int v = adjlist[u][i].fs;
			int d = adjlist[u][i].sd;

			if (intree[v] == 0 && d < key[v])
			{
				parent[v] = u;

				q.erase(q.find(mp(key[v], v)));

				key[v] = d;
				q.insert(mp(key[v], v));
			}
		}
	}

	return ret;
}


