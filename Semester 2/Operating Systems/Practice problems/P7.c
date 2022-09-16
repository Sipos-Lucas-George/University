//First Methode
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int done = 1;
int num = 1;
void* foo(){
        pthread_mutex_lock(&lock);
        if(done == 1){
                done = 2;
                printf("Waiting on condition variable cond1\n");
                pthread_cond_wait(&cond1, &lock);
        }
        else{
                printf("Signaling condition variable cond1\n");
                pthread_cond_signal(&cond1);
        }
        pthread_mutex_unlock(&lock);
        printf("Return thread %d\n", num);
        ++num;
        return NULL;
}

int main(int argc, char** argv){
        pthread_t t1, t2;
        pthread_create(&t1, NULL, foo, NULL);
        sleep(1);
        pthread_create(&t2, NULL, foo, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        return 0;
}

//Second Method
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct{
        int id;
        int* done;
        pthread_mutex_t *mutex;
        pthread_cond_t *condition;
}data;

void* f(void* arg){
        data info = *((data*)arg);
        pthread_mutex_lock(info.mutex);
        if(*info.done == 1){
                *info.done = 2;
                printf("Waiting for the second thread to unlock the condition!\n");
                sleep(2);
                pthread_cond_wait(info.condition, info.mutex);
        }
        else{
                printf("Gonna unlock first thread!\n");
                sleep(2);
                pthread_cond_signal(info.condition);
        }
        printf("Thread %d arrived at mutex unlock!\n", info.id);
        pthread_mutex_unlock(info.mutex);
        return NULL;
}

int main(int argc, char** argv){
        pthread_mutex_t mutex;
        pthread_cond_t condition;
        pthread_t *th = malloc(sizeof(pthread_t) * 2);
        data *info = malloc(sizeof(data) * 2);
        int i;
        int* done = malloc(sizeof(int));
        if(pthread_mutex_init(&mutex, NULL) < 0){
                perror("Error!\n");
                exit(1);
        }
        if(pthread_cond_init(&condition, NULL) < 0){
                perror("Error!\n");
		exit(1);
        }
        *done = 1;
        for (i = 0; i < 2; ++i){
                info[i].done = done;
                info[i].id = i + 1;
                info[i].mutex = &mutex;
                info[i].condition = &condition;
                if(pthread_create(&th[i], NULL, f, (void*)&info[i]) < 0){
                        perror("Error!\n");
                        exit(1);
                }
        }
        pthread_join(th[0], NULL);
        pthread_join(th[1], NULL);
        free(info);
        free(th);
        return 0;
}