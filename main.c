#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* breakingRecords(int scores_count, int* scores, int* result_count) {
    int* records_count = malloc(sizeof(int) * 2);
    records_count[0] = 0;
    records_count[1] = 0;

    int most_points = scores[0];
    int least_points = scores[0];

    for (int i = 0; i < scores_count; i++) {
        if (scores[i] > most_points) {
            most_points = scores[i];
            records_count[0]++;
        } else if (scores[i] < least_points) {
            least_points = scores[i];
            records_count[1]++;
        }
    }

    *result_count = 2;
    return records_count;
}

int sockMerchant(int n, int ar_count, int* ar) {
    int totalPairs = 0, count = 1, nbElem = 0, paired = 0, pass = 0;
    int colorsPaired[1000];

    for (int i = 0; i < ar_count - 1; i++) {
        // skip the indices of the colors already paired
        for (int k = 0; k < nbElem; k++) {
            if (colorsPaired[k] == ar[i]) {
                pass = 1;
                break;
            } else
                pass = 0;
        }

        if (pass) continue;

        for (int j = i + 1; j < ar_count; j++) {
            if (ar[i] == ar[j]) {
                count++;
                paired = 1;
            }
        }

        if (paired) {
            colorsPaired[nbElem] = ar[i];
            nbElem++;
        }

        if (count % 2 == 0)
            totalPairs += count / 2;
        else
            totalPairs += (count - 1) / 2;

        count = 1;
        paired = 0;
        pass = 0;
    }

    return totalPairs;
}

char* catAndMouse(int x, int y, int z) {
    if (abs(x - z) == abs(y - z))
        return "Mouse C";
    else if (abs(x - z) < abs(y - z))
        return "Cat A";
    else
        return "Cat B";
}

int migratoryBirds(int arr[], unsigned int size) {
    int freq[6] = {0};
    int max = 1;

    for (int i = 0; i < size; i++) freq[arr[i]]++;

    for (int i = 2; i < 6; i++)
        if (freq[i] > freq[max]) max = i;

    return max;
}

int countingValleys(int n, char* s, unsigned int size) {
    int countValleys = 0, seaLevel = 0;

    for (int i = 0; i < size; i++) {
        if (seaLevel == 0 && s[i] == 'D') {
            seaLevel--;
            int j = i + 1;
            for (j; j < size; j++) {
                if (s[j] == 'U')
                    seaLevel++;
                else
                    seaLevel--;

                if (seaLevel == 0) {
                    countValleys++;
                    break;
                }
            }
            i = j;
        } else if (s[i] == 'U')
            seaLevel++;
        else
            seaLevel--;
    }

    return countValleys;
}

int divisibleSumPairs(int n, int k, int ar[]) {
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ar[i] + ar[j]) % k == 0) count++;
        }
    }

    return count;
}

// Given an array of integers, find and print the maximum number of integers you can
// select from the array such that the absolute difference between any two of the chosen
// integers is less than or equal to 1.
// For example, if your array is, a = [1, 1, 2, 2, 4, 4, 5, 5, 5]
// you can create two subarrays meeting the criterion : [1, 1, 2, 2] and [4, 4, 5, 5, 5].
// The maximum length subarray has 5 elements.
int pickingNumbers(int size, int a[]) {
    int max = 0;

    for (int i = 0; i < size; i++) {
        int temp[size];
        temp[0] = a[i];
        int nb_elem = 1;

        for (int j = 0; j < size; j++) {
            if (i == j) continue;

            bool ok = true;

            for (int k = 0; k < nb_elem; k++) {
                if (abs(a[j] - temp[k]) > 1) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                temp[nb_elem] = a[j];
                nb_elem++;
            }
        }

        if (nb_elem > max) max = nb_elem;
    }

    return max;
}

int picking_numbers_opti(unsigned int size, unsigned int a[]) {
    int count, prev = -1, max = 0;

    // sort(a);

    for (int i = 0; i < size - 1; i++) {
        if (prev == a[i]) continue;

        count = 1;

        for (int j = i + 1; j < size; j++) {
            if (a[j] - a[i] <= 1)
                count++;
            else
                break;
        }

        if (count > max) max = count;

        prev = a[i];
    }

    return max;
}

// Given an array of integers, return indices of the two numbers such that they add up to
// a specific target. You may assume that each input would have exactly one solution, and
// you may not use the same element twice.
void two_sum(int arr[], unsigned int size, int target) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                printf("soltion : %d & %d\n", i, j);
                return;
            }
        }
    }
    printf("no solution found ...");
}

// Given a 32 bit signed integer, reverse its digits.
int reverse(int x) {
    int rev = 0;

    while (x != 0) {
        int pop = x % 10;      // get the last digit of the number
        x /= 10;               // go to the next digit
        rev = rev * 10 + pop;  // add the digit to the begining of the new number
    }

    return rev;
}

// We define a magic square to be an nxn matrix of distinct positive integers from 1 to n²
// where the sum of any row, column, or diagonal of length n is always equal to the same
// number : the magic constant.
// You will be given 3x3 a matrix s of integers in the inclusive range [1, 9].
// We can convert any digit a to any other digit b in the range at cost of |a - b|.
// Given, s convert it into a magic square at minimal cost.
int formingMagicSquare(unsigned int rows, unsigned int cols, unsigned int** s) {}

int main() {
    int test[4] = {2, 7, 11, 15};

    two_sum(test, 4, 17);

    return 0;
}
