#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <mutex>

#define TASK_NUM 8
#define POLY_SIZE 1000
#define MAX_DEPTH 3

std::vector<int> multiply_regular(const std::vector<int> &poly1, const std::vector<int> &poly2) {
    std::vector<int> result(poly1.size() + poly2.size() - 1, 0);

    for (size_t i = 0; i < poly1.size(); ++i) {
        for (size_t j = 0; j < poly2.size(); ++j) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }

    return result;
}

std::vector<int> multiply_parallel(const ::std::vector<int> &poly1, const std::vector<int> &poly2) {
    std::vector<int> result(poly1.size() + poly2.size() - 1, 0);
    std::vector<std::thread> threads(TASK_NUM);
//	std::vector<std::mutex> mutexes(poly1.size() + poly2.size() - 1);

    auto task = [&](int offset) -> void {
        for (int i = offset; i < poly1.size(); i += TASK_NUM) {
            for (int j = 0; j < poly2.size(); ++j) {
                int s = i + j;
                int sum = result[s] + poly1[i] * poly2[j];
//				mutexes[s].lock();
                result[s] = sum;
//				mutexes[s].unlock();
            }
        }
    };

    for (int i = 0; i < TASK_NUM; ++i) {
        threads[i] = std::thread(task, i);
    }

    for (int i = 0; i < TASK_NUM; ++i) {
        threads[i].join();
    }

    return result;
}

static int mod(int L) {
    if (L >= 1000000009) {
        return L % 1000000009;
    } else if (L < 0) {
        return ((L % 1000000009) + 1000000009) % 1000000009;
    } else {
        return L;
    }
}

static std::vector<int> multiply_poly(std::vector<int> A, std::vector<int> B, int n) {
    std::vector<int> prod(2 * n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prod[i + j] = mod(prod[i + j] + A[i] * B[j]);
        }
    }
    return prod;
}

std::vector<int> karatsuba(const std::vector<int> &a, const std::vector<int> &b) {
    size_t n = a.size();
    size_t k = n / 2;

    std::vector<int> z(2 * n, 0);

    if (n <= 32) {
        z = multiply_poly(a, b, (int) (a.size()));
        return z;
    } else {
        std::vector<int> aR(k), bL(k), bR(k), aL(k);
        std::vector<int> aLaR(k), bLbR(k);

        for (int i = 0; i < k; ++i) {
            aL[i] = a[i];
            aR[i] = a[i + k];
            bL[i] = b[i];
            bR[i] = b[i + k];

            aLaR[i] = mod(aL[i] + aR[i]);
            bLbR[i] = mod(bL[i] + bR[i]);
        }

        std::vector<int> p1 = karatsuba(aL, bL);
        std::vector<int> p2 = karatsuba(aR, bR);
        std::vector<int> p3 = karatsuba(aLaR, bLbR);

        std::vector<long> productMiddle(n, 0);

        for (int j = 0; j < n - 1; ++j) {
            productMiddle[j] = mod(p3[j] - p1[j] - p2[j]);
        }

        for (size_t j = 0, middleOffset = k; j < n - 1; ++j) {
            z[j] = mod(z[j] + p1[j]);
            z[j + n] = mod(z[j + n] + p2[j]);
            z[j + middleOffset] = mod((int) (z[j + middleOffset] + productMiddle[j]));
        }
        return z;
    }
}

std::vector<int> karatsuba_parallel(const std::vector<int> &a, const std::vector<int> &b, int depth = 0) {
    size_t n = a.size();
    size_t k = n / 2;

    std::vector<int> z(2 * n, 0);

    if (n <= 32) {
        z = multiply_poly(a, b, (int) (a.size()));
        return z;
    } else {
        std::vector<int> aR(k), bL(k), bR(k), aL(k);
        std::vector<int> aLaR(k), bLbR(k);

        for (int i = 0; i < k; ++i) {
            aL[i] = a[i];
            aR[i] = a[i + k];
            bL[i] = b[i];
            bR[i] = b[i + k];

            aLaR[i] = mod(aL[i] + aR[i]);
            bLbR[i] = mod(bL[i] + bR[i]);
        }

        std::vector<int> p1;
        std::vector<int> p2;
        std::vector<int> p3;

        if (depth == MAX_DEPTH) {
            p1 = karatsuba(aL, bL);
            p2 = karatsuba(aR, bR);
            p3 = karatsuba(aLaR, bLbR);
        } else {
            std::thread t1([&]() { p1 = karatsuba_parallel(aL, bL, depth + 1); });
            std::thread t2([&]() { p2 = karatsuba_parallel(aR, bR, depth + 1); });
            p3 = karatsuba_parallel(aLaR, bLbR, depth + 1);

            t1.join();
            t2.join();
        }

        std::vector<long> productMiddle(n, 0);

        for (int j = 0; j < n - 1; ++j) {
            productMiddle[j] = mod(p3[j] - p1[j] - p2[j]);
        }

        for (size_t j = 0, middleOffset = k; j < n - 1; ++j) {
            z[j] = mod(z[j] + p1[j]);
            z[j + n] = mod(z[j + n] + p2[j]);
            z[j + middleOffset] = mod((int) (z[j + middleOffset] + productMiddle[j]));
        }
        return z;
    }
}

template<typename Func, typename... Args>
double measureTime(Func func, Args &&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}


int main() {
    std::vector<int> poly1;
    for (int i = 0; i < POLY_SIZE; ++i) {
        poly1.push_back((int) (random() % 1000));
    }

    std::vector<int> poly2;
    for (int i = 0; i < POLY_SIZE; ++i) {
        poly2.push_back((int) (random() % 1000));
    }

    std::cout << "Regular multiply:   " << measureTime(multiply_regular, poly1, poly2) << " seconds\n";
    std::cout << "Parallel multiply:  " << measureTime(multiply_parallel, poly1, poly2) << " seconds\n";
    std::cout << "Karatsuba:          " << measureTime(karatsuba, poly1, poly2) << " seconds\n";
    std::cout << "Karatsuba parallel: " << measureTime(karatsuba_parallel, poly1, poly2, 0) << " seconds";
}