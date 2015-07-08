#include "../header.h"

ll MaxFlowMatrix(vvl &matrix, int src, int dst)
{
	vi seen;
	vi parent;
	queue <int> q;

	seen.resize(matrix.sz);
	parent.resize(matrix.sz);

	seen[src] = 1;
	parent[src] = -1;

	q.push(src);

	while (!q.empty())
	{
		int u;
		u = q.front();
		q.pop();

		flo(v, matrix[u].sz)
		{
			if (matrix[u][v] > 0)
			{
				if (seen[v] == 0)
				{
					/* First seen */
					seen[v] = 1;
					parent[v] = u;

					if (v == dst)
					{
						/* Found */
						int p;
						int c;
						ull minflow = -1;

						c = v;

						while ((p = parent[c]) != -1)
						{
							if (matrix[p][c] < minflow)
								minflow = matrix[p][c];
							
							c = p;
						}

						c = v;

						while ((p = parent[c]) != -1)
						{
							matrix[p][c] -= minflow;
							matrix[c][p] += minflow;

							c = p;
						}

						return minflow;
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
