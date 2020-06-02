def kangaroo(x1, v1, x2, v2):
    if (x1 < x2 and v1 > v2) or (x1 > x2 and v1 < v2):
        y = (float(x2) - float(x1)) / (float(v1) - float(v2))
        return (y % 1 == 0)

    return False


def birthday(s, d, m):
    count = 0

    for i in range(len(s) - m+1):
        total = 0
        for n in range(m):
            total += s[i+n]

        if (total == d):
            count += 1

    return count


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


def pageCount(n, p):
    count = 0

    if (p > n / 2):
        page = n
        while (page != p):
            if (p % 2 == 0 and page == p+1):
                break
            if (page % 2 == 0):
                count += 1
            page -= 1
    else:
        page = 1
        while (page != p):
            if (p % 2 != 0 and page == p-1):
                break
            if (page % 2 != 0):
                count += 1
            page += 1

    return count


print(kangaroo(0, 2, 5, 3))
