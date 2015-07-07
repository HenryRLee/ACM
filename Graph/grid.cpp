#include "../header.h"

void didj(vvi grid, int n, int m)
{
	int di[] = {1, 0, -1, 0};
	int dj[] = {0, 1, 0, -1};

	fio(n)
	{
		fjo(m)
		{
			/* Code for this cell */

			fko(4)
			{
				if (cbound(i+di[k], 0, n-1) && cbound(j+dj[k], 0, m-1))
				{
					/* Code for the neighbours */
				}
			}
		}
	}
}
