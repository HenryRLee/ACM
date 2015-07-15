#include "../header.h"

vvi MatrixToList(vvi matrix)
{
	vvi adjlist;

	adjlist.resize(matrix.sz);

	fio(matrix.sz)
	{
		fjo(matrix[i].sz)
		{
			if (matrix[i][j] > 0)
			{
				adjlist[i].pb(j);
			}
		}
	}

	return adjlist;
}

void PrintList(vvi adjlist)
{
	cout << "Adjlist" << endl;
	fio(adjlist.sz)
	{
		cout << "[" << i << "] ";
		fjo(adjlist[i].sz)
		{
			cout << adjlist[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
