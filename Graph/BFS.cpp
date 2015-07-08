#include "../header.h"

int BFSList(vvi list, int src, int dst)
{
	vi seen;
	vi dist;
	queue <int> q;

	seen.resize(list.sz);
	dist.resize(list.sz);

	seen[src] = 1;
	dist[src] = 0;

	q.push(src);

	while (!q.empty())
	{
		int u;
		u = q.front();
		q.pop();

		fio(list[u].sz)
		{
			int v = list[u][i];

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

int BFSMatrix(vvi matrix, int src, int dst)
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
