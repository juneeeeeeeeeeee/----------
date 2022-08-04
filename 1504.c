#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define UNDEFINED_NUM -1
#define INF 2147483647
int **array;
int n;
int dijkstra(int r1, int r2)
{
  int *dist = (int *)malloc(sizeof(int) * (n+1));
  int *queue = (int *)malloc(sizeof(int) * (n+1));
  memset(queue, UNDEFINED_NUM, sizeof(int) * (n+1));
  dist[r1] = 0;
  int queue_num = 1;
  for (int i = 1; i <= n;i++)
  {
    if(i==r1)
    {
      queue[1] = i;
    }
    else
    {
      dist[i] = INF;
      queue[queue_num+1] = i;
      queue_num = queue_num + 1;
    }
  }
  while (queue[1] != UNDEFINED_NUM)
  {
    int u = queue[1];
    queue[1] = queue[queue_num];
    queue_num = queue_num - 1; // pseudo queue에서 값 뽑아내기
    for (int i = queue_num; i > 1; i = i / 2)
    {
      if (dist[queue[i]] < dist[queue[i / 2]])
      {
        int temp = queue[i];
        queue[i] = queue[i / 2];
        queue[i / 2] = temp;
      }
    }
    for (int i = 1; i <= n; i++)
    {
      if (array[u][i] != 0) // connected
      {
        int dist_thingy = dist[u] + array[u][i];
        if (dist_thingy < dist[i])
        {
          dist[i] = dist_thingy;
        }
      }
    }
  }
  return dist[r2];
}
int main(void)
{
  int e;
  scanf("%d %d", &n, &e);
  array = (int **)malloc(sizeof(int *) * (n+1));
  for (int i = 0; i <= n;i++)
  {
    array[i] = (int *)malloc(sizeof(int) * (n+1));
    memset(array[i], 0, sizeof(int) * (n+1));
  }
  for (int i = 0; i <= e - 1; i++)
  {
    int input_a, input_b, input_c;
    scanf("%d %d %d", &input_a, &input_b, &input_c);
    array[input_a][input_b] = input_c;
    array[input_b][input_a] = input_c;
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
  long long route2 = dijkstra_1_v2 + dijkstra_v1_v2 + dijkstra_v1_n;
  printf("%lld", route1 > route2 ? route2 : route1);
  return 0;
}