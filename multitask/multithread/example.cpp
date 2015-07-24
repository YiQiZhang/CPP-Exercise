#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

void *PrintHello(void *tid)
{
   long tmp = (long)tid;
   cout << "Hello World! Thread ID, " << tmp << endl;
   pthread_exit(NULL);
}

int main (int argc, char ** argv)
{
   int num_threads;

   if(argc >= 2) {
     num_threads = atoi(argv[1]);
   } else {
     num_threads = 5;
   }

   pthread_t threads[num_threads];
   int rc;
   int i;
   for( i=0; i < num_threads; i++ ){
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, 
                          PrintHello, (void *)i);
      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
