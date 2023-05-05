#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

enum Errors {
    er_not_number,
    er_not_diapazon,
    er_too_much,
};

int info(int error);

int start();