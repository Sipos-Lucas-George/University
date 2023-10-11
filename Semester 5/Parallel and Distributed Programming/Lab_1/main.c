#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define B 1000
#define T 11

const int NR_BILLS = B;
const int NUMBER_THREADS = T;
const int NUMBER_MUTEXES = 5;
int NUMBER_OF_CHECKS = 1;
int THREAD[T - T / 3];
int THREAD_INDEX = 0;
int N = 0;
int size;

typedef struct {
    int *product_ids;
    int *quantities;
    float total_price;
    int size;
} bill;

bill generated_bills[B];

typedef struct {
    char **items;
    int *stocks;
    float *prices;
    pthread_mutex_t *mutexes;
    float *total;
} data;

void generate_bills(data products) {
    int i;
    for (i = 0; i < NR_BILLS; ++i) {
        int number_of_products = rand() % size + 1;
        generated_bills[i].size = number_of_products;
        generated_bills[i].product_ids = malloc(sizeof(int) * number_of_products);
        generated_bills[i].quantities = malloc(sizeof(int) * number_of_products);
        --number_of_products;
        float total = 0;
        int pid = rand() % size;
        while (number_of_products != -1) {
            generated_bills[i].product_ids[number_of_products] = pid;
            generated_bills[i].quantities[number_of_products] = rand() % 9 + 1;
            total += (products.prices[pid] * (float) generated_bills[i].quantities[number_of_products]);
            pid = (pid + 1) % size;
            --number_of_products;
        }
        generated_bills[i].total_price = total;
    }
}

void print_generated_bills() {
    int i, j;
    float total = 0;
    for (i = 0; i < NR_BILLS; ++i) {
        printf("%d-------------------------\n", i + 1);
        for (j = 0; j < generated_bills[i].size; ++j) {
            printf("%d %d\n", generated_bills[i].product_ids[j], generated_bills[i].quantities[j]);
        }
        total += generated_bills[i].total_price;
        printf("%f\n\n", generated_bills[i].total_price);
    }
    printf("Total: %f\n\n", total);
}

void print_data(data *dt) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%s %d %f\n", dt->items[i], dt->stocks[i], dt->prices[i]);
    }
    printf("%f\n", *dt->total);
}

void *check_stock(void *info) {
    data dt = *((data *) info);
    int i, checks = 0;
    printf("Check Number %d:\n", NUMBER_OF_CHECKS);
    ++NUMBER_OF_CHECKS;
    for (i = 0; i < size; ++i) {
        if (dt.stocks[i] == 0) {
            printf("The store is out of %s\n", dt.items[i]);
            ++checks;
        }
    }
    if (checks == 0)
        printf("The stock is still full");
    printf("\n");
    return NULL;
}

void *process_bill(void *info) {
    data dt = *((data *) info);
    int i, n, j;
    pthread_mutex_lock(&dt.mutexes[4]);
    j = N;
    N += THREAD[THREAD_INDEX++];
    n = N;
    pthread_mutex_unlock(&dt.mutexes[4]);
    float sum = 0;
    for (; j < n; ++j) {
        for (i = 0; i < generated_bills[j].size; ++i) {
            int pid = generated_bills[j].product_ids[i], pqt = generated_bills[j].quantities[i];
            if (pid == 0) {
                pthread_mutex_lock(&dt.mutexes[0]);
                if (dt.stocks[pid] > pqt) {
                    dt.stocks[pid] -= pqt;
                } else if (dt.stocks[pid] != 0) {
                    int difference = pqt - dt.stocks[pid];
                    generated_bills[j].total_price -= ((float) difference * dt.prices[pid]);
                    generated_bills[j].quantities[i] = dt.stocks[pid];
                    dt.stocks[pid] = 0;
                } else {
                    generated_bills[j].total_price -= (dt.prices[pid] * (float) pqt);
                    generated_bills[j].quantities[i] = 0;
                }
                pthread_mutex_unlock(&dt.mutexes[0]);
            } else if (pid == 1) {
                pthread_mutex_lock(&dt.mutexes[1]);
                if (dt.stocks[pid] > pqt) {
                    dt.stocks[pid] -= pqt;
                } else if (dt.stocks[pid] != 0) {
                    int difference = pqt - dt.stocks[pid];
                    generated_bills[j].total_price -= ((float) difference * dt.prices[pid]);
                    generated_bills[j].quantities[i] = dt.stocks[pid];
                    dt.stocks[pid] = 0;
                } else {
                    generated_bills[j].total_price -= (dt.prices[pid] * (float) pqt);
                    generated_bills[j].quantities[i] = 0;
                }
                pthread_mutex_unlock(&dt.mutexes[1]);
            } else {
                pthread_mutex_lock(&dt.mutexes[2]);
                if (dt.stocks[pid] > pqt) {
                    dt.stocks[pid] -= pqt;
                } else if (dt.stocks[pid] != 0) {
                    int difference = pqt - dt.stocks[pid];
                    generated_bills[j].total_price -= ((float) difference * dt.prices[pid]);
                    generated_bills[j].quantities[i] = dt.stocks[pid];
                    dt.stocks[pid] = 0;
                } else {
                    generated_bills[j].total_price -= (dt.prices[pid] * (float) pqt);
                    generated_bills[j].quantities[i] = 0;
                }
                pthread_mutex_unlock(&dt.mutexes[2]);
            }
        }
        sum += generated_bills[j].total_price;
    }
    pthread_mutex_lock(&dt.mutexes[3]);
    *(dt.total) += sum;
    pthread_mutex_unlock(&dt.mutexes[3]);
    printf("Total price for thread number %lu is %f\n", pthread_self(), sum);
    return NULL;
}

int main() {
    int i;
    data *data = malloc(sizeof(&data));
    FILE *stock_price_file = fopen(
            "/home/lucas/ubumbu/university/UNI/Semester 5/Parallel and Distributed Programming/Lab_1/stock_prices.txt",
            "r");
    if (stock_price_file == NULL) {
        printf("No such file.");
        return 0;
    }

    fscanf(stock_price_file, "%d", &size);
    char* c = stock_price_file->_IO_read_ptr;
    data->items = (char **) malloc(sizeof(char *) * size);
    for (i = 0; i < size; ++i) {
        data->items[i] = (char *) malloc(100);
    }
    i = 0;
    data->stocks = (int *) malloc(sizeof(int) * size);
    data->prices = (float *) malloc(sizeof(float) * size);
    stock_price_file->_IO_read_ptr = c;
    while (fscanf(stock_price_file, "%s %d %f", data->items[i], &data->stocks[i], &data->prices[i]) == 3) {
        printf("%s %d %f\n", data->items[i], data->stocks[i], data->prices[i]);
        ++i;
    }
    data->total = (float *) malloc(sizeof(float));

    time_t t;
    srand((unsigned) time(&t));

    generate_bills(*data);
    print_generated_bills();

    int number_of_working_treads = NUMBER_THREADS - NUMBER_THREADS / 3;
    int number_of_bills = NR_BILLS / number_of_working_treads;
    for (i = 0; i < number_of_working_treads; ++i) {
        THREAD[i] = number_of_bills;
    }
    THREAD[number_of_working_treads - 1] = NR_BILLS - (THREAD[0] * (number_of_working_treads - 1));

    pthread_t *threads = malloc(sizeof(pthread_t) * NUMBER_THREADS);
    pthread_mutex_t *mutexes = malloc(sizeof(pthread_mutex_t) * NUMBER_MUTEXES);
    for (i = 0; i < NUMBER_MUTEXES; ++i) {
        if (0 > pthread_mutex_init(&mutexes[i], NULL)) {
            perror("Error on creating mutexes");
            exit(1);
        }
    }
    data->mutexes = mutexes;
    *(data->total) = 0;
    for (i = 0; i < NUMBER_THREADS; ++i) {
        if ((i + 1) % 3 == 0) {
            if (0 != pthread_create(&threads[i], NULL, check_stock, (void *) data))
                perror("Error on create thread");
            continue;
        }
        if (0 != pthread_create(&threads[i], NULL, process_bill, (void *) data))
            perror("Error on create thread");
    }
    for (i = 0; i < NUMBER_THREADS; ++i) {
        if (0 > pthread_join(threads[i], NULL)) {
            perror("Error waiting for thread");
        }
    }

    print_generated_bills();
    print_data(data);
    check_stock((void *) data);

    for (i = 0; i < NUMBER_MUTEXES; i++) {
        pthread_mutex_destroy(&mutexes[i]);
    }
    free(data);
    free(threads);
    free(mutexes);
    for (i = 0; i < NR_BILLS; ++i) {
        free(generated_bills[i].quantities);
        free(generated_bills[i].product_ids);
    }
    return 0;
}