#include "../header.h"

int BFSList(const vvi &adjlist, int src, int dst)
{
	vi seen;
	vi dist;
	queue <int> q;

	seen.resize(adjlist.sz);
	dist.resize(adjlist.sz);

	seen[src] = 1;
	dist[src] = 0;

	q.push(src);

	while (!q.empty())
	{
		int u;
		u = q.front();
		q.pop();

		fio(adjlist[u].sz)
		{
			int v = adjlist[u][i];

			if (seen[v] == 0)
			{
				/* First seen */
				seen[v] = 1;
				dist[v] = dist[u] + 1;
				
				if (v == dst)
				{
					/* Found */
					return dist[v];
				}
				else
				{
					/* Not found */
					q.push(v);
				}
			}
		}
	}

	return 0;
}

int BFSMatrix(const vvi &matrix, int src, int dst)
{
	vi seen;
	vi dist;
	queue <int> q;

	seen.resize(matrix.sz);
	dist.resize(matrix.sz);

	seen[src] = 1;
	dist[src] = 0;

	q.push(src);

	while (!q.empty())
	{
		int u;
		u = q.front();
		q.pop();

		flo(v, matrix[u].sz)
		{
			if (matrix[u][v] == 1)
			{
				if (seen[v] == 0)
				{
					/* First seen */
					seen[v] = 1;
					dist[v] = dist[u] + 1;

					if (v == dst)
					{
						/* Found */
						return dist[v];
					}
					else
					{
						/* Not found */
						q.push(v);
					}
				}
			}
		}
	}

	return 0;
}
