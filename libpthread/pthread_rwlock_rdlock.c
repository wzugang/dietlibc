#include <sched.h>
#include <pthread.h>

int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock) {
  unsigned int n;
  for (n=0;;) {
    int r=pthread_rwlock_tryrdlock(rwlock);
    if (r==0) return r;
    if (n<100) {
      ++n;
      continue;
    }
    sched_yield();
  }
}
