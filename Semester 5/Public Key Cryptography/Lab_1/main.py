import time


# Euclidian algorithm using the rest of a division until one of them is 0
def euclidean_gcd(a, b):
    while b:
        a, b = b, a % b
    return a


# Recursive euclidian algorithm using the rest of a division until one of them is 0
def euclidean_recursive_gcd(a, b):
    if b == 0:
        return a
    else:
        return euclidean_recursive_gcd(b, a % b)


# Euclidian algorithm subtracting from the bigger number until they are equal
def subtraction_gcd(a, b):
    while a != b:
        if a > b:
            a -= b
        else:
            b -= a
    return a


# Normal GCD using a loop from the smallest number to 1
def normal_gcd(a, b):
    for index in range(min(a, b), 0, -1):
        if a % index == 0 and b % index == 0:
            return index


if __name__ == "__main__":
    # list of the numbers used for GCD functions, as follows:
    # (i, i+1), (i+1, i+2), ..., (i+n-1, i+n)
    list_of_numbers = [2, 5, 10, 20, 8, 56, 21, 30, 25, 75, 15]

    # For every function, got the exact time before entering the loop
    # and after the loop is done print the difference between times
    print("euclidean_gcd")
    test_time = time.time()
    for i in range(len(list_of_numbers) - 1):
        print("Test", str(i + 1) + ": gcd(" + str(list_of_numbers[i]) + ", " + str(list_of_numbers[i + 1]) + ") =",
              euclidean_gcd(list_of_numbers[i], list_of_numbers[i + 1]))
    print(time.time() - test_time, "seconds", end="\n\n")

    print("euclidean_recursive_gcd")
    test_time = time.time()
    for i in range(len(list_of_numbers) - 1):
        print("Test", str(i + 1) + ": gcd(" + str(list_of_numbers[i]) + ", " + str(list_of_numbers[i + 1]) + ") =",
              euclidean_recursive_gcd(list_of_numbers[i], list_of_numbers[i + 1]))
    print(time.time() - test_time, "seconds", end="\n\n")

    print("subtraction_gcd")
    test_time = time.time()
    for i in range(len(list_of_numbers) - 1):
        print("Test", str(i + 1) + ": gcd(" + str(list_of_numbers[i]) + ", " + str(list_of_numbers[i + 1]) + ") =",
              subtraction_gcd(list_of_numbers[i], list_of_numbers[i + 1]))
    print(time.time() - test_time, "seconds", end="\n\n")

    print("normal_gcd")
    test_time = time.time()
    for i in range(len(list_of_numbers) - 1):
        print("Test", str(i + 1) + ": gcd(" + str(list_of_numbers[i]) + ", " + str(list_of_numbers[i + 1]) + ") =",
              normal_gcd(list_of_numbers[i], list_of_numbers[i + 1]))
    print(time.time() - test_time, "seconds")
