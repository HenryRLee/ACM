#include "../header.h"

vvi SCCList(const vvi &adjlist)
{
	vi disc;
	vi fin;
	vi seen;
	stack <int> st; 
	bool cyclic = false;
	int time = 0;
	vvi gt;
	vi sorted;
	vvi ret;

	disc.resize(adjlist.sz);
	fin.resize(adjlist.sz);
	seen.resize(adjlist.sz);

	/* First DFS */
	fio(adjlist.sz)
	{
		if (disc[i] == 0)
		{
			/* Not discovered */
			st.push(i);

			while (!st.empty())
			{
				int u;

				u = st.top();

				if (disc[u] > 0 && fin[u] == 0)
				{
					/* Finish */

					fin[u] = ++time;

					sorted.pb(u);

					st.pop();
					continue;
				}
				else if (disc[u] == 0)
				{
					disc[u] = ++time;
				}
				else if (fin[u] > 0)
				{
					st.pop();
					continue;
				}

				fjo(adjlist[u].sz)
				{
					int v = adjlist[u][j];

					if (disc[v] == 0)
					{
						/* Not discovered */
						st.push(v);
					}
					else if (fin[v] == 0)
					{
						/* Cyclic */
						cyclic = true;
					}
				}
			}
		}
	}

	/* Get the transpose graph */
	gt.resize(adjlist.sz);

	fio(adjlist.sz)
	{
		fjo(adjlist[i].sz)
		{
			int v = adjlist[i][j];
			gt[v].pb(i);
		}
	}

	/* Second DFS */
	fvd(i, sorted)
	{
		if (seen[sorted[i]] == 0)
		{
			vi scc;
			st.push(sorted[i]);

			while (!st.empty())
			{
				int u = st.top();

				if (seen[u] == 1)
				{
					st.pop();
					continue;
				}
				else
				{
					scc.pb(u);
					seen[u] = 1;
				}

				fjo(gt[u].sz)
				{
					int v = gt[u][j];
					if (seen[v] == 0)
					{
						st.push(v);
					}
				}
			}

			ret.pb(scc);
		}

	}

	return ret;
}

/*
 * Merge a SCC into a vertice
 */
vvi MapSCC(const vvi &adjlist)
{
	vvi retlist;
	vvi scc = SCCList(adjlist);

	vi vmap(adjlist.sz);

	retlist.resize(scc.sz);

	fio(scc.sz)
	{
		fjo(scc[i].sz)
		{
			int v = scc[i][j];

			vmap[v] = i;
		}
	}

	fio(adjlist.sz)
	{
		fjo(adjlist[i].sz)
		{
			int u = vmap[i];
			int v = vmap[adjlist[i][j]];

			if (u != v)
				retlist[u].pb(v);
		}
	}

	return retlist;
}

vvi WCCList(vvi adjlist)
{
	vi seen;
	vvi ret;
	stack <int> st;

	/* Turn direted graph to undirected graph */
	fio(adjlist.sz)
	{
		fjo(adjlist[i].sz)
		{
			adjlist[adjlist[i][j]].pb(i);
		}
	}

	seen.resize(adjlist.sz);

	/* DFS */
	fio(adjlist.sz)
	{
		if (seen[i] == 0)
		{
			vi wcc;
			st.push(i);

			while (!st.empty())
			{
				int u = st.top();

				if (seen[u] == 1)
				{
					st.pop();
					continue;
				}
				else
				{
					wcc.pb(u);
					seen[u] = 1;
				}

				fjo(adjlist[u].sz)
				{
					int v = adjlist[u][j];
					if (seen[v] == 0)
					{
						st.push(v);
					}
				}
			}

			ret.pb(wcc);
		}
	}

	return ret;
}


