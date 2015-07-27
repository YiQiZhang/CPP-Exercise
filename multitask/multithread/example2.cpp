// joining threads
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void *wait(void *t)
{
	int i;
	long tid;

	tid = (long)t;

	sleep(1);
	cout << "Sleeping in thread " << endl;
	cout << "Thread with id : " << tid << " ...exiting " << endl;
	pthread_exit(NULL);
}

int main(int argc, char** argv)
{
	int num_threads = 5;
	if (argc >= 2) {
		num_threads = atoi(argv[1]);
	}

	int rc;
	int i;
	pthread_t threads[num_threads];
	pthread_attr_t attr;
	void *status;

	// Initialize and set thread joinable
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for( i = 0; i < num_threads; i++) {
		cout << "main() : creating thread, " << i << endl;
		rc = pthread_create(&threads[i], NULL, wait, (void *)i );
		if (rc) {
			cout << "Error: unable to create thread, " << rc << endl;
			exit(-1);
		} 
	}

	// free attribute and wait for the othre threads
	pthread_attr_destroy(&attr);
	for( i = 0; i < num_threads; i++) {
		rc = pthread_join(threads[i], &status);
		if (rc) {
			cout << "Error: unable to join, " << rc << endl;
			exit(-1);
		}
		cout << "Main: completed thread id :" << i;
		cout << "  exiting with status: " << status << endl;
	}

	cout << "Main: program exiting." << endl;
	pthread_exit(NULL);
	return 0;
}