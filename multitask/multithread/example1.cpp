// Passing Arguments to Threads

#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

struct thread_data {
  int thread_id;
  char *message;
};

typedef struct thread_data td;

void *PrintHello(void *threadarg)
{
  td *mydata;
  mydata = (td *) threadarg;

  cout << "Thread ID : " << mydata->thread_id << " Message : " << mydata->message << endl;
}

int main(int argc, char ** argv)
{
  int num_threads = 5;

  if (argc >= 2) {
    num_threads = atoi(argv[1]);
  }

  pthread_t threads[num_threads];
  td tds[num_threads];
  int rc;
  int i;

  for(i = 0; i < num_threads; i++)
  {
    tds[i].thread_id = i;
    tds[i].message = "This is message";
    cout << "main() : creating thread, " << i << endl;
    rc = pthread_create(&threads[i], NULL, PrintHello, (void *) &tds[i]);

    if (rc) {
      cout << "Error: unable to create thread, " << rc << endl;
      exit(-1);
    }
  }
  pthread_exit(NULL);
  
  return 0;
}
