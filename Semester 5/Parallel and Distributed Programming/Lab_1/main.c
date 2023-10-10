#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const int NR_BILLS = 6;
const int NUMBER_THREADS = 8;
const int NUMBER_MUTEXES = 5;
int N = 0;

typedef struct {
    int *product_ids;
    int *quantities;
    float total_price;
    int size;
} bill;

bill generated_bills[6];

typedef struct {
    char **items;
    int *stocks;
    float *prices;
    pthread_mutex_t *mutexes;
    float *total;
} data;

void generate_bills(int size, data products) {
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

void print_data(data *dt, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%s %d %f\n", dt->items[i], dt->stocks[i], dt->prices[i]);
    }
    printf("%f", *dt->total);
}

void *check_stock(void *info) {
    data dt = *((data *) info);
    return NULL;
}

void *process_bill(void *info) {
    data dt = *((data *) info);
    int i, n;
    pthread_mutex_lock(&dt.mutexes[4]);
    n = N++;
    pthread_mutex_unlock(&dt.mutexes[4]);
    for (i = 0; i < generated_bills[n].size; ++i) {
        int pid = generated_bills[n].product_ids[i], pqt = generated_bills[n].quantities[i];
        if (pid == 0) {
            pthread_mutex_lock(&dt.mutexes[0]);
            if (dt.stocks[pid] > pqt) {
                dt.stocks[pid] -= pqt;
            } else if (dt.stocks[pid] != 0) {
                int difference = pqt - dt.stocks[pid];
                generated_bills[n].total_price -= ((float) difference * dt.prices[pid]);
                generated_bills[n].quantities[i] = dt.stocks[pid];
                dt.stocks[pid] = 0;
            } else {
                generated_bills[n].total_price -= (dt.prices[pid] * (float) pqt);
                generated_bills[n].quantities[i] = 0;
            }
            pthread_mutex_unlock(&dt.mutexes[0]);
        } else if (pid == 1) {
            pthread_mutex_lock(&dt.mutexes[1]);
            if (dt.stocks[pid] > pqt) {
                dt.stocks[pid] -= pqt;
            } else if (dt.stocks[pid] != 0) {
                int difference = pqt - dt.stocks[pid];
                generated_bills[n].total_price -= ((float) difference * dt.prices[pid]);
                generated_bills[n].quantities[i] = dt.stocks[pid];
                dt.stocks[pid] = 0;
            } else {
                generated_bills[n].total_price -= (dt.prices[pid] * (float) pqt);
                generated_bills[n].quantities[i] = 0;
            }
            pthread_mutex_unlock(&dt.mutexes[1]);
        } else {
            pthread_mutex_lock(&dt.mutexes[2]);
            if (dt.stocks[pid] > pqt) {
                dt.stocks[pid] -= pqt;
            } else if (dt.stocks[pid] != 0) {
                int difference = pqt - dt.stocks[pid];
                generated_bills[n].total_price -= ((float) difference * dt.prices[pid]);
                generated_bills[n].quantities[i] = dt.stocks[pid];
                dt.stocks[pid] = 0;
            } else {
                generated_bills[n].total_price -= (dt.prices[pid] * (float) pqt);
                generated_bills[n].quantities[i] = 0;
            }
            pthread_mutex_unlock(&dt.mutexes[2]);
        }
    }
    pthread_mutex_lock(&dt.mutexes[3]);
    *(dt.total) += generated_bills[n].total_price;
    pthread_mutex_unlock(&dt.mutexes[3]);
    return NULL;
}

int main() {
    int i;
    data *data = malloc(sizeof(&data));
    FILE *stock_price = fopen("stock_price.txt", "r");
    if (stock_price == NULL) {
        printf("No such file.");
        return 0;
    }
    int size;
    fscanf(stock_price, "%d", &size);
    data->items = (char **) malloc(sizeof(char *) * size);
    for (i = 0; i < size; ++i) {
        data->items[i] = (char *) malloc(100);
    }
    data->stocks = (int *) malloc(sizeof(int) * size);
    data->prices = (float *) malloc(sizeof(float) * size);
    data->total = (float *) malloc(sizeof(float));
    char items[100];
    int stocks;
    float prices;
    i = 0;
    while (fscanf(stock_price, "%s %d %f", items, &stocks, &prices) == 3) {
        strcpy(data->items[i], items);
        data->stocks[i] = stocks;
        data->prices[i] = prices;
        printf("%s %d %f\n", data->items[i], data->stocks[i], data->prices[i]);
        ++i;
    }

    time_t t;
    srand((unsigned) time(&t));

    generate_bills(size, *data);
    print_generated_bills();

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
    print_data(data, size);

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
