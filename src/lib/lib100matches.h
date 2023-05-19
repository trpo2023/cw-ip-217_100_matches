#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

enum Errors;

int info(int error);

int start();
int xod_bota(int* kucha);
int digit_or_not(char* xod);
int check_diapazon(int xod);
int check_kol_vo(int xod, int* kucha);
int checks(int* kucha, char* xod);
int xod_playera(int* kucha);