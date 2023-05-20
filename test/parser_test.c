#include <ctest.h>
#include <lib100matches.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SQR(x) (x) * (x)

CTEST(digit, check_digit)
{
    char* xod = "5";
    const int expect = 0;
    int res = digit_or_not(xod);
    ASSERT_EQUAL(expect, res);
}
CTEST(good_diapazon, check_good_diapazon)
{
    int xod = 8;
    const int expect = 0;
    int res = check_diapazon(xod);
    ASSERT_EQUAL(expect, res);
}
CTEST(bad_diapazon, check_bad_diapazon)
{
    int xod = -1;
    const int expect = 1;
    int res = check_diapazon(xod);
    ASSERT_EQUAL(expect, res);
}
CTEST(digit_or_not, check_digit_or_not)
{
    char* xod = "h";
    const int expect = 1;
    int res = digit_or_not(xod);
    ASSERT_EQUAL(expect, res);
}