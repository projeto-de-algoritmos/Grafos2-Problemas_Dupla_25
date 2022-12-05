#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX_INICIO 750
#define MAX_FINAL 1000
#define POT(x) ((x)*(x))

int T, N, M, E;
int sc = 0;
int set[MAX_INICIO];

#define SET(x)                 find_set((x))
#define MESCLAR(x, y)            if (SET((x)) != SET((y))) { set[find_set(x)] = find_set(y); sc --; }
#define FAST_MESCLAR(fs_x, fs_y) { set[(fs_x)] = (fs_y); sc --; }
#define INIT_SET(_i)           for (_i = 0; _i < N; _i++) { set[_i] = _i; } sc = N-1;

struct coordenadas
{
    int x, y;
};
struct coordenadas c[MAX_INICIO];

struct edge{
    int inicio;
    int fim;
    int meio;
};
struct edge e[MAX_INICIO * (MAX_INICIO-1) / 2];
struct edge * pe[MAX_INICIO * (MAX_INICIO-1) / 2];


int kruskal();
int find_set(int i);
bool compara(const struct edge * a, const struct edge * b);

#if 0
int compara(const void *a, const void *b)
{
    return (*(struct edge**)a)->meio - (*(struct edge**)b)->meio;
}
#endif





int main()
{
    int i, j;
    int in0, in1;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (i = 0; i < N; i++)
        {
            scanf("%d %d", &c[i].x, &c[i].y);
        }

        E = 0;
        for (i = 0; i < N; i++)
            for (j = i+1; j < N; j++)
            {
                e[E].inicio = i;
                e[E].fim = j;
                e[E].meio = POT(c[i].x - c[j].x) + POT(c[i].y - c[j].y);
                pe[E] = &e[E];
                E++;
            }

        sort(pe, pe+E, compara);

        INIT_SET(i);
        scanf("%d", &M);
        for (i = 0; i < M; i++)
        {
            scanf("%d %d", &in0, &in1);
            MESCLAR(in0-1, in1-1);
        }

        kruskal();

        if (T)
            printf("\n");
    }

    return 0;
}


int kruskal()
{
    int i, p_inicio, p_fim, build = 0;

    for (i = 0; i < E && sc > 0; i++)
    {
        if ((p_inicio = SET(pe[i]->inicio)) != (p_fim = SET(pe[i]->fim)))
        {
            FAST_MESCLAR(p_inicio, p_fim);
            printf("%d %d\n", pe[i]->inicio+1, pe[i]->fim+1);
            build ++;
        }
    }

    if (build == 0)
    {
        printf("No new highways need\n");
    }

    return sc == 0;
}

bool compara(const struct edge * a, const struct edge * b)
{
    return a->meio < b->meio;
}

int find_set(int i)
{
    if (set[i] == i)
        return i;
    else
       return (set[i] = find_set(set[i]));
}


