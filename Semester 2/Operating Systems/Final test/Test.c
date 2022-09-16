#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
        int n;
        char* file;
}data;

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void* f(void* arg){
        data info = *((data*)arg);
        pthread_mutex_lock(&lock);
        int a, b = 0;
        if(info.n <= b){
                char* file = info.file;
                FILE* fd = fopen(file, "r");
                fscanf(fd, "%d %d", &a, &b);
                fclose(fd);
                info.n = a;
                while(info.n <= b){
                        info.n += a;
                        if(info.n > b)
                                pthread_cond_wait(&cond1, &lock);
                }
        }
        else{
                printf("Value %d...\n", info.n);
                pthread_cond_signal(&cond1);
        }
        pthread_mutex_unlock(&lock);
        return NULL;
}

int main(int argc, char** argv){
        printf("asdasdasd");
        if(argc < 2){
                perror("PA!\n");
                exit(1);
        }
        int size = argc - 1;
	int size2 = argc - 1;
        size2 *= 2;
        printf("1...");
        pthread_t *th = malloc(sizeof(pthread_t) * size2);
        data * info = malloc(sizeof(data) * size);

        int i;
        for (i = 0; i < size; ++i){
                info[i].n = 0;
                info[i].file = argv[i + 1];
                if(pthread_create(&th[i], NULL, f, (void*)&info[i]) < 0){
                        perror("Error!\n");
                        exit(1);
                }
                sleep(1);
                pthread_create(&th[size+i+1], NULL, f, (void*)&info[i]);
        }
        for (i = 0; i < size2; ++i)
                pthread_join(th[i], NULL);
        free(th);
        free(info);
        return 0;
}