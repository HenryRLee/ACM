#include "../header.h"

/*
 * Bellman Ford
 * Return with a shortest-path tree
 */
vvp BellmanFordList(vvp adjlist, int src = 0)
{
	vi d(adjlist.sz, 1e9);
	vi p(adjlist.sz, -1);
	vvp ret;

	d[src] = 0;

	fio(adjlist.sz - 1)
	{
		fjo(adjlist.sz)
		{
			fko(adjlist[j].sz)
			{
				int u = j;
				int v = adjlist[j][k].fs;
				int w = adjlist[j][k].sd;

				if (d[v] > d[u] + w)
				{
					d[v] = d[u] + w;
					p[v] = u;
				}
			}
		}
	}

	fio(adjlist.sz)
	{
		fjo(adjlist[i].sz)
		{
			int u = i;
			int v = adjlist[i][j].fs;
			int w = adjlist[i][j].sd;

			if (d[v] > d[u] + w)
			{
				/* Return with an empty adjlist */
				vvp empty;

				return empty;
			}
		}
	}

	ret.resize(adjlist.sz);

	fio(p.sz)
	{
		if (p[i] != -1)
		{
			int v = i;
			int u = p[i];
			int w = d[v] - d[u];

			ret[u].pb(mp(v, w));
		}
	}

	return ret;
}
