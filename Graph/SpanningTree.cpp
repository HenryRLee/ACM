#include "../header.h"

/*
 * Prim
 * Return with a shortest-path tree
 */
vvp PrimList(vvp adjlist, int r = 0)
{
	set <pii> q;
	vi intree;
	vi key;
	vi parent;
	ll wsum = 0;
	vvp ret;

	intree.resize(adjlist.sz);
	key.resize(adjlist.sz);
	parent.resize(adjlist.sz);
	ret.resize(adjlist.sz);

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
		int w;
		q.erase(q.begin());

		w = top.fs;
		u = top.sd;

		intree[u] = 1;

		p = parent[u];

		if (p != -1)
		{
			ret[p].pb(mp(u, w));
			wsum += w;
		}
		else if (u != r)
		{
			/* Not connected */
			vvp empty;

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


