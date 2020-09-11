# You are given two kangaroos on a number line ready to jump in the positive direction.
# The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump.
# The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump.
# You have to figure out a way to get both kangaroos at the same location at the same time as part of the show.


def kangaroo(x1, v1, x2, v2):
    if (x1 < x2 and v1 > v2) or (x1 > x2 and v1 < v2):
        y = (float(x2) - float(x1)) / (float(v1) - float(v2))
        return (y % 1 == 0)

    return False


# Lily has a chocolate bar that she wants to share with Ron for his birthday.
# Each of the squares has an integer on it.
# She decides to share a contiguous segment of the bar selected such that the length of the segment
# matches Ron's birth month and the sum of the integers on the squares is equal to his birth day.
# You must determine how many ways she can divide the chocolate.
def birthday(s, d, m):
    count = 0

    for i in range(len(s) - m+1):
        total = 0
        for n in range(m):
            total += s[i+n]

        if (total == d):
            count += 1

    return count


# Given a year y, find the date of the 256th day of that year
# according to the official Russian calendar during that year.
def dayOfProgrammer(year):
    if (year < 1918):  # Julian
        if (year % 4 == 0):
            return "12.09." + str(year)
        else:
            return "13.09." + str(year)

    elif (year > 1918):  # Gregorian
        if (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)):
            return "12.09." + str(year)
        else:
            return "13.09." + str(year)

    else:  # year == 1918
        return "26.09.1918"


# Brie’s Drawing teacher asks her class to open their books to a page number.
# Brie can either start turning pages from the front of the book or from the back of the book.
# She always turns pages one at a time.
# When she opens the book, page is always on the right side
# Given n and p find the minimum number of pages Brie must turn in order to arrive at page p.
def pageCount(n, p):
    count = 0

    if p > n / 2:
        page = n
        while page != p:
            if p % 2 == 0 and page == p+1:
                break
            if page % 2 == 0:
                count += 1
            page -= 1
    else:
        page = 1
        while page != p:
            if p % 2 != 0 and page == p-1:
                break
            if page % 2 != 0:
                count += 1
            page += 1

    return count


# Your job is to change the string s using a non-negative integer n.
# Each bit in n will specify whether or not to swap the case for each alphabetic character in s. When you get to the last bit of n, circle back to the first bit. If the bit is 1, swap the case. If its 0, don't swap the case.
# You should skip the checking of bit when a non-alphabetic character is encountered, but they should be preserved in their original positions.
def swap(s,n):
    j = 2
    str_bin = str(bin(n))
    for (i, c) in enumerate(s):
        if c.isalpha():
            if str_bin[j] == '1':
                s = s[:i] + c.swapcase() + s[i + 1:]
            j += 1
            if j == len(str_bin):
                j = 2

    return s

swap('Hello world!', 11) # 'heLLO wORLd!'
