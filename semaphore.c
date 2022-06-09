#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>

#define SEMAPHORE_NAME "Bazyaeva"

int main(int argc, char ** argv) 
{
   sem_t *sem;
   if (argc != 2) 
   {
      if ((sem = sem_open(SEMAPHORE_NAME, O_CREAT, 0770, 0)) == SEM_FAILED)
      {
         fprintf(stderr, "ERROR Bazyaeva's semaphor opening");
         return 1;
      }
      printf("sem_open. Bazyaeva's semaphore is taken.\nWaiting for it to be dropped.\n");
      if (sem_wait(sem) < 0)
         fprintf(stderr, "ERROR Bazyaeva's sem_wait");
      if (sem_close(sem) < 0)
         fprintf(stderr , "Bazyaeva's sem_close ERROR");
      return 0;
   }
   else
   {
      printf("Dropping Bazyaeva's semaphore...\n");
      if ((sem = sem_open(SEMAPHORE_NAME, 0)) == SEM_FAILED)
      {
         fprintf(stderr, "Bazyaeva's sem_open ERROR");
         return 1;
      }
      sem_post(sem);
      printf("Bazyaeva's sem_post. Bazyaeva's semaphore dropped. \n");
      return 0;
   }
}