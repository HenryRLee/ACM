#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define fl(i, b, e)		for (int i=(int)(b); i<(int)(e); i++)
#define fld(i, b, e)		for (int i=(int)(b)-1; i>=(int)(e); i--)
#define flo(i, e)		fl(i, 0, e)
#define fi(b, e)	fl(i, b, e)
#define fio(e)	fi(0, e)
#define fj(b, e)	fl(j, b, e)
#define fjo(e)	fj(0, e)
#define fk(b, e)	fl(k, b, e)
#define fko(e)	fk(0, e)
#define fvi(i, v)	fl(i, 0, v.size())
#define fvd(i, v)	fld(i, v.size(), 0)
#define pb	push_back
#define sz	size()
#define mp	make_pair
#define fs	first
#define sd	second
#define all(x)	(x).begin(), (x).end()
#define sqr(x)	((x)*(x))
#define newline		printf("\n")

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef vector <vi> vvi;
typedef vector <vl> vvl;
typedef pair <int, int> pii;
typedef vector <pii> vp;
typedef vector <vp> vvp;

const int inf = 2147483647;

inline bool cbound(int x, int b, int e)
{
	return ((x >= b) && (x <= e));
}

inline int getint()
{
	int a;
	cin >> a;
	return a;
}

inline ll getll()
{
	ll a;
	cin >> a;
	return a;
}

inline double getdouble()
{
	double a;
	cin >> a;
	return a;
}

template <class T>
inline void debugv(vector <T> v)
{
	fio(v.sz)
		cout << v[i] << " ";
	cout << endl;
}

template <class T>
inline void debugvv(vector < vector <T> > vv)
{
	fio(vv.sz)
		debugv(vv[i]);
	cout << endl;
}

int main(void)
{

	return 0;
}

