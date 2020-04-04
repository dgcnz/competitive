#include <algorithm>

#define NMAX 10000

using namespace std;

int parent[NMAX];
int ssize[NMAX];

void make_set(int v)
{
    parent[v] = v;
    ssize[v]  = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (ssize[a] < ssize[b])
            swap(a, b);
        parent[b] = a;
        ssize[a] += ssize[b];
    }
}
