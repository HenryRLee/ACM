#include "../header.h"

int DFSListOne(vvi adjlist, int src, int dst)
{
	stack <int> st;
	vi seen;
	int time = 0;
	bool cyclic = false;

	seen.resize(adjlist.sz);

	st.push(src);

	while (!st.empty())
	{
		int u;

		u = st.top();

		if (seen[u] == 1)
		{
			/* Finish */

			st.pop();
			continue;
		}
		else
		{
			seen[u] = 1;
		}

		fjo(adjlist[u].sz)
		{
			int v = adjlist[u][j];

			if (v == dst)
			{
				/* Found */

				return 1;
			}

			if (seen[v] == 0)
			{
				/* Not discovered */
				st.push(v);
			}
		}
	}

	return 0;
}

int DFSListForrest(vvi adjlist)
{
	vi disc;
	vi fin;
	stack <int> st; 
	bool cyclic = false;
	int time = 0;

	disc.resize(adjlist.sz);
	fin.resize(adjlist.sz);

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

						return -1;
					}
				}
			}
		}
	}

	return 0;
}

list <int> TopologicalSort(vvi adjlist)
{
	vi disc;
	vi fin;
	stack <int> st; 
	bool cyclic = false;
	list <int> ret;
	int time = 0;

	disc.resize(adjlist.sz);
	fin.resize(adjlist.sz);

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
					ret.push_front(u);

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

						break;
					}
				}
			}
		}
	}

	if (!cyclic)
	{
		return ret;
	}
	else
	{
		/* Return an empty list */
		list <int> empty;

		return empty;
	}
}

