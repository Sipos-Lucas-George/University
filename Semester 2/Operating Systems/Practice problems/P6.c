#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

typedef struct{
        int id, n;
        pthread_barrier_t *barrier;
        sem_t *sems;
}data;

void* f(void* arg){
        data info = *((data*)arg);
        printf("Thread %d waiting...\n", info.id);
        int i;
        for (i = 0; i < info.n; ++i){
                sem_wait(&info.sems[i]);
                printf("Thread %d at checkpoint %d...", info.id, i + 1);
                int n = (random() % 101 + 100) * 1000;
                usleep(n);
                sem_post(&info.sems[i]);
        }
        printf("\nThread %d finished...\n", info.id);
        return NULL;
}
int main(int argc, char** argv){
        if(argc != 2){
                perror("Error!\n");
                exit(1);
        }
        int i, n = atoi(argv[1]);
        int m = 1;
        int div = 2;
        sem_t *sems = malloc(sizeof(sem_t) * n);
        for (i = 0; i < n; ++i)
                m *= 2;
        for (i = 0; i < n; ++i){
                sem_init(&sems[i], 0, m/div);
                div *= 2;
        }
        pthread_t *th = malloc(sizeof(pthread_t) * m);
        pthread_barrier_t barrier;
        data *info = malloc(sizeof(data) * m);
        if(pthread_barrier_init(&barrier, NULL, n) < 0){
                perror("Error!\n");
                exit(1);
        }
        srandom(time(0));
        for (i = 0; i < m; ++i){
                info[i].n = n;
                info[i].id = i + 1;
                info[i].barrier = &barrier;
                info[i].sems = sems;
                if(pthread_create(&th[i], NULL, f, (void*)&info[i]) < 0){
                        perror("Error!\n");
                        exit(1);
                }
        }
        for(i = 0; i < m; ++i)
                pthread_join(th[i], NULL);
        pthread_barrier_destroy(&barrier);
        for(i = 0; i < n; ++i)
                sem_destroy(&sems[i]);
        free(sems);
        free(th);
        free(info);
        return 0;
}