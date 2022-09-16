//First Method
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
        int id;
        char str[100];
}argument;

void* upcase(void* arg) {
        int i;
        argument a = *((argument*)arg);
        for (i = 0; i<strlen(a.str); ++i){
                if (a.str[i] >= 'a' && a.str[i] <='z')
                        a.str[i] += 'A' - 'a';
        }
        printf("Thread %d finished: %s\n", a.id, a.str);
        return NULL;
}

int main(int argc, char *argv[]){
        int i;
        pthread_t *thrds = malloc(argc * sizeof(pthread_t));
        argument *args = malloc(argc * sizeof(argument));
        for (i = 1; i < argc; ++i){
                args[i].id = i;
                strcpy(args[i].str, argv[i]);
                if (0 != pthread_create(&thrds[i], NULL, upcase, (void*)&args[i]))
                        perror("Error on create thread");
        }
        for (i = 1; i < argc; ++i)
                pthread_join(thrds[i], NULL);
        free(thrds);
        free(args);
        return 0;
}

//Second Method
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

typedef struct {
        int id;
        char* str;
}data;

void* f(void* argument){
        data info = *((data*)argument);
        int i;
        for (i = 0; i < strlen(info.str); ++i){
                if(info.str[i] >= 'a' && info.str[i] <= 'z')
                        info.str[i] -= 32;
        }
        printf("Thread %d finished: %s\n", info.id, info.str);
        return NULL;
}

int main(int argc, char** argv){
        if(argc < 2){
                perror("Not enough arguments!\n");
                exit(1);
        }
        int i;
        pthread_t *thrs = malloc(sizeof(pthread_t) * (argc - 1));
        data *info = malloc(sizeof(data) * (argc - 1));
        for(i = 0; i < argc - 1; ++i){
                info[i].id = i + 1;
                info[i].str = argv[i + 1];
                if(pthread_create(&thrs[i], NULL, f, (void*)&info[i]) < 0){
                        perror("Error!\n");
                        exit(1);
                }
        }
        for (i = 0; i < argc - 1; ++i)
                pthread_join(thrs[i], NULL);
        free(thrs);
        free(info);
        return 0;
}