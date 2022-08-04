#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define UNDEFINED_NUM -1
#define INF 2147483647
int **array;
int dijkstra(int r1, int r2)
{

}
int main(void)
{
  int n, e;
  scanf("%d %d", &n, &e);
  array = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i <= n - 1;i++)
  {
    memset(array[i], 0, sizeof(int) * n);
  }
  for (int i = 0; i <= e - 1;i++)
  {
    int input_a, input_b, input_c;
    scanf("%d %d %d", &input_a, &input_b, &input_c);
    array[input_a][input_b] = input_c;
  }
  int v1, v2;
  scanf("%d %d", &v1, &v2);
  int dijkstra_1_v1 = dijkstra(1, v1);
  int dijkstra_1_v2 = dijkstra(1, v2);
  if(dijkstra_1_v1==INF&&dijkstra_1_v2==INF)
  {
    printf("-1");
    return 0;
  }
  int dijkstra_v1_v2 = dijkstra(v1, v2);
  if(dijkstra_v1_v2==INF)
  {
    printf("-1");
    return 0;
  }
  int dijkstra_v1_n = dijkstra(v1, n);
  int dijkstra_v2_n = dijkstra(v2, n);
  if(dijkstra_v1_n==INF&&dijkstra_v2_n==INF)
  {
    printf("-1");
    return 0;
  }
  if(dijkstra_1_v1==INF&&dijkstra_v1_n==INF)
  {
    printf("-1");
    return 0;
  }
  if(dijkstra_1_v2==INF&&dijkstra_v2_n==INF)
  {
    printf("-1");
    return 0;
  }
  long long route1 = dijkstra_1_v1 + dijkstra_v1_v2 + dijkstra_v2_n;
  long long route2 = dijkstra_1_v2 + dijkstra_v1_v2 + dijkstra_v2_n;
  printf("%lld", route1 > route2 ? route2 : route1);
  return 0;
}