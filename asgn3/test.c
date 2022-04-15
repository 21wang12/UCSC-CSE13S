#include "queue.h"
#include "quick.h"
#include "stack.h"
#include <assert.h> //For assert()
#include <stdio.h>

#define N 15
int main() {
  /** @brief unit test for Queue
  Queue *q = queue_create(10);
  queue_print(q);
  for(int64_t i= 0;i <11;i++){
          printf("push %ld %s\n",i,enqueue(q,i)?"true":"false");
  }
  queue_print(q);
  for(int64_t i= 0;i <11;i++){
          int64_t x;
          printf("pop %s ",dequeue(q,&x)?"true":"false");
          printf("%ld\n",x);
  }
  queue_delete(&q);
  assert(q==NULL);
  */

  /** @brief unit test for pointer and sizeof()
  int a = 10;
  int A[1] = {1} ;
  printf("%p %p %lu %d %d\n",(void *)&a,(void *)(&a+1),sizeof(int),a,(&a)[1]);
  printf("%p %p %lu %d %d\n",(void *)A,(void
  *)(&A+1),sizeof(int*),A[0],*(&A)[1]);
  */

  uint32_t num[N] = {9, 6, 11, 3, 5, 12, 8, 7, 10, 15, 14, 4, 1, 13, 2};
  // print unsorted arr
  for (int i = 0; i < N; i++)
    printf("%d  ", num[i]);
  printf("\n");

  /** @brief unit test for quick sort with stack
  *   @status pass
      quick_sort_stack(num, N);
  */

  /**  @brief unit test for quick sort with queue
  	*  @status pass
  quick_sort_queue(num, N);
  */
  
  // print sorted arr
  for (int i = 0; i < N; i++)
  printf("%d  ", num[i]);
  printf("\n");

  return 0;
}
