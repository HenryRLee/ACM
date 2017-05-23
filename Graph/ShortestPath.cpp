#include "../header.h"

/*
 * Bellman Ford
 * Return with a shortest-path tree
 */
vvp BellmanFordList(const vvp &adjlist, int src = 0)
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


/*
 * Dijkstra
 * Return with a shortest-path tree
 * Using a set data structure
 */
vvp DijkstraListWithSet(const vvp &adjlist, int src = 0)
{
	vi key(adjlist.sz, inf);
	vi parent(adjlist.sz, -1);
	set <pii> q;
	vvp ret(adjlist.sz);
	ll wsum = 0;

	fio(adjlist.sz)
	{
		if (i == src)
		{
			q.insert(mp(0, i));
		}
		else
		{
			q.insert(mp(inf, i));
		}
	}

	key[src] = 0;

	while (!q.empty())
	{
		pii top = *q.begin();
		int u;
		int p;
		int w;
		q.erase(q.begin());

		w = top.fs;
		u = top.sd;

		p = parent[u];

		if (p != -1)
		{
			ret[p].pb(mp(u, w));
			wsum += w;
		}

		fio(adjlist[u].sz)
		{
			int v = adjlist[u][i].fs;
			int d = adjlist[u][i].sd;

			if (key[v] > key[u] + d)
			{
				parent[v] = u;

				q.erase(q.find(mp(key[v], v)));

				key[v] = d + key[u];
				q.insert(mp(key[v], v));
			}
		}
	}

	return ret;
}

int DijkstraList(const vvp & adjlist, int src, int dst)
{
	int n = adjlist.sz;
	vi dist(n, inf);
	priority_queue <pii, vp, greater<pii> > q;

	dist[src] = 0;
	q.push(mp(0, src));

	fio(n-1)
	{
		if (q.empty())
			break;

		int key = q.top().fs;
		int u = q.top().sd;
		q.pop();

		fjo(adjlist[u].sz)
		{
			int v = adjlist[u][j].fs;
			int c = adjlist[u][j].sd;

			if (c + key < dist[v])
			{
				dist[v] = c + key;
				q.push(mp(dist[v], v));
			}
		}
	}

	return dist[dst];
}
