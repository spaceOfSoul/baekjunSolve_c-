#include <stdio.h>

int n,m;
int arr[500][500];
int visited[500][500];
int result;
int maxSize;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

typedef struct pair{
  int x,y;
}pair;

typedef struct queue{
  int front, rear;
  pair queArr[250000];
}queue;

void init(queue *q){
  q->front = 0;
  q->rear = 0;
}
void push(queue *q, int a, int b){
  pair val;
  val.x = a;val.y = b;
  q->queArr[q->rear++] = val;
}
void pop(queue *q){
  q->front++;
}
pair queFront(queue *q){
  return q->queArr[q->front];
}
int empty(queue *q){
  if(q->front==q->rear){
    return 1;
  }
  return 0;
}

void bfs(int r, int c){
  queue que;
  init(&que);
  push(&que,r,c);
  visited[r][c] = 1;
  int count = 0;

  while(!empty(&que)){
    int x = queFront(&que).x;
    int y = queFront(&que).y;
    count++;
    pop(&que);

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(0<=nx&&nx<n&&0<=ny&&ny<m && !visited[nx][ny]){
        if(!arr[nx][ny])
          continue;
        push(&que, nx, ny);
        visited[nx][ny] = 1;
      }
    }
  }
  if(count > maxSize)
    maxSize = count;
}

int main(void) {
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j] && !visited[i][j]){
        result++;
        bfs(i,j);
      }
    }
  }  

  printf("%d\n%d", result, maxSize);
  return 0;
}