#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Given an array of integers, find the sum of its elements.
int simpleArraySum(int a[], unsigned int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) sum += a[i];

    return sum;
}

// Calculate and print the sum of the elements in an array,keeping in mind that some of
// those integers may be quite large.
long aVeryBigSum(long a[], unsigned int size) {
    long long int sum = 0;

    for (int i = 0; i < size; i++) sum += a[i];

    return sum;
}

// Alice and Bob each created one problem for HackerRank. A reviewer rates the two
// challenges, awarding points on a scale from 1 to 100 for three categories: problem
// clarity, originality, and difficulty.
// We define the rating for Alice's challenge to be the triplet a = (a[0], a[1], a[2])
// and the rating for Bob's challenge to be the triplet b = (b[0], b[1], b[2]).
// Your task is to find their comparison points by comparing a[0] with b[0], a[1] with
// b[1], and a[2] with b[2].
// If a[i] > b[i], then Alice is awarded 1 point.
// If a[i] < b[i], then Bob is awarded 1 point.
// If a[i] = b[i], then neither person receives a point.
int* compareTriplets(int a[], int b[], unsigned int size) {
    int* result = malloc(sizeof(int) * 2);
    result[0] = 0;
    result[1] = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] > b[i])
            result[0]++;
        else if (a[i] < b[i])
            result[1]++;
    }

    return result;
}

// Given a square matrix, calculate the absolute difference between the sums of its
// diagonals.
unsigned int diagonalDifference(int** a, unsigned int size) {
    int sum_diag1 = 0, sum_diag2 = 0;

    int j = size - 1;
    for (int i = 0; i < size; i++) {
        sum_diag1 += a[i][i];
        sum_diag2 += a[i][j];
        j--;
    }

    return abs(sum_diag1 - sum_diag2);
}

// Given an array of integers, calculate the fractions of its elements that are positive,
// negative, and are zeros.
void plusMinus(int a[], unsigned int size) {
    int pos_count = 0, neg_count = 0, zero_count = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] > 0)
            pos_count++;
        else if (a[i] < 0)
            neg_count++;
        else
            zero_count++;
    }

    printf("pos : %f\nneg : %f\nzero : %f", (float)pos_count / (float)size,
           (float)neg_count / (float)size, (float)zero_count / (float)size);
}

// Print a staircase of size n using # symbols and spaces.
void staircase(unsigned int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) printf(" ");
        for (int j = 0; j < i; j++) printf("#");
        printf("\n");
    }
}

// You are in charge of the cake for your niece's birthday and have decided the cake will
// have one candle for each year of her total age. When she blows out the candles, she’ll
// only be able to blow out the tallest ones.
unsigned int birthday_cake_candles(unsigned int a[], unsigned int size) {
    unsigned int candles_count = 1, max = a[0];

    for (int i = 1; i < size; i++) {
        if (i > max)
            max = i;
        else if (i == max)
            candles_count += 1;
    }

    return candles_count;
}

// HackerLand University has the following grading policy :
// Every student receives a grade in the inclusive range from to 0 to 100.
// Any grade less than 40 is a failing grade.
// Sam is a professor at the university and likes to round each student's grade according
// to these rules:
// If the difference between the garde and the next multiple 5 of is less than 3, round up
// to the next multiple of 5.
// If the value of garde is less than 38, no rounding occurs as the result will still be a
// failing grade.
void gradingStudents(unsigned int grades[], unsigned int size) {
    for (int i = 0; i < size; i++) {
        if (grades[i] < 38)
            continue;
        else
            grades[i] = grades[i] % 5 < 3 ? grades[i] : grades[i] + (5 - (grades[i] % 5));
    }
}

// Maria plays college basketball and wants to go pro. Each season she maintains a record
// of her play. She tabulates the number of times she breaks her season record for most
// points and least points in a game.
// Given Maria's scores for a season, find and print the number of times she breaks her
// records for most and least points scored during the season.
int* breakingRecords(int scores[], unsigned int size) {
    int* records_count = malloc(sizeof(int) * 2);
    records_count[0] = 0;
    records_count[1] = 0;

    int most_points = scores[0];
    int least_points = scores[0];

    for (int i = 1; i < size; i++) {
        if (scores[i] > most_points) {
            most_points = scores[i];
            records_count[0]++;
        } else if (scores[i] < least_points) {
            least_points = scores[i];
            records_count[1]++;
        }
    }

    return records_count;
}

// You are given an array a of integers and a positive integer k.
// Find the number of (i, j) pairs where i < j and a[i] + a[j] is divisible by k.
unsigned int divisibleSumPairs(unsigned int a[], unsigned int size, unsigned int k) {}

int sockMerchant(int a[], unsigned int size, int n) {
    int totalPairs = 0, count = 1, nbElem = 0, paired = 0, pass = 0;
    int colorsPaired[1000];

    for (int i = 0; i < size - 1; i++) {
        // skip the indices of the colors already paired
        for (int k = 0; k < nbElem; k++) {
            if (colorsPaired[k] == a[i]) {
                pass = 1;
                break;
            } else
                pass = 0;
        }

        if (pass) continue;

        for (int j = i + 1; j < size; j++) {
            if (a[i] == a[j]) {
                count++;
                paired = 1;
            }
        }

        if (paired) {
            colorsPaired[nbElem] = a[i];
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

// Given an array of integers, find and print the maximum number of integers you can
// select from the array such that the absolute difference between any two of the chosen
// integers is less than or equal to 1.
// For example, if your array is, a = [1, 1, 2, 2, 4, 4, 5, 5, 5]
// you can create two subarrays meeting the criterion : [1, 1, 2, 2] and [4, 4, 5, 5, 5].
// The maximum length subarray has 5 elements.
int pickingNumbers(int a[], int size) {
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

int picking_numbers_opti(unsigned int a[], unsigned int size) {
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
int formingMagicSquare(unsigned int rows, unsigned int cols, unsigned int** s) {
    // TODO
}

void display(int a[], unsigned int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }
    printf("\n");
}

int main() {
    // int test1[3] = {2, 7, 11};
    // int test2[3] = {2, 7, 11};
    // int* result = compareTriplets(test1, test2, 3);
    // display(result, 2);

    // staircase(6);

    int test[4] = {73, 67, 38, 33};
    gradingStudents(test, 4);
    display(test, 4);

    return 0;
}
