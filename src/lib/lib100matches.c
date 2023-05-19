#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <lib100matches.h>


enum Errors {
    er_not_number,
    er_not_diapazon,
    er_too_much,
};

int info(int error)
{
    switch (error) {
    case er_not_number:
        printf("Это не число!\nВведите число: ");
        return 1;
    case er_not_diapazon:
        printf("Число не входит в диапазон от 1 до 10!\n");
        return 2;
    case er_too_much:
        printf("Спичек осталось меньше, чем вы ввели!\n");
        return 3;
    }
    return 0;
}

int xod_bota(int* kucha)
{
    int bot;
    printf("Ходит Бот!\n");
    printf("Осталось спичек: %d\n", *kucha);
    if (*kucha <= 10) {
        bot = *kucha;
        printf("Он взял: %d\n", bot);
        printf("Бот победил!\n");
        *kucha = 0;
        return 2;
    } else {
        bot = rand() % 10 + 1;
    }
    printf("Он взял: %d\n", bot);
    *kucha -= bot;
    return 0;
}

int digit_or_not(char* xod)
{
    if (isdigit(xod[0]) == 0 && isdigit(xod[1]) == 0) {
        return 1;
    }
    return 0;
}

int check_diapazon(int xod)
{
    if (xod >= 1 && xod <= 10) {
        return 0;
    }
    return 1;
}

int check_kol_vo(int xod, int* kucha)
{
    if (*kucha >= xod) {
        *kucha -= xod;
        return 0;
    }
    return 1;
}

int checks(int* kucha, char* xod)
{
    int ret_dig = digit_or_not(xod);
    while (ret_dig != 0) {
        info(er_not_number);
        fflush(stdin);
        scanf(" %c%c", &xod[0], &xod[1]);
        ret_dig = digit_or_not(xod);
    }
    int player;
    player = atoi(xod);
    if (check_diapazon(player) == 1) {
        info(er_not_diapazon);
        return 1;
    }
    if (check_kol_vo(player, kucha) == 1) {
        info(er_too_much);
        return 2;
    }
    if (*kucha == 0) {
        printf("Вы победили!\n");
        return 1;
    }
    return xod_bota(kucha);
}

int xod_playera(int* kucha)
{
    fflush(stdin);
    char xod[2];
    printf("Ваш ход!\n");
    printf("Осталось спичек: %d\n", *kucha);
    printf("Сколько спичек вы берете: ");
    scanf(" %c%c", &xod[0], &xod[1]);
    checks(kucha, xod);
    return 0;
}

int start()
{
    int kucha;
    char quit;
    printf("Начинаем игру?\n1 - Да; 2 - Нет;\n");
    scanf("%c", &quit);
    while (1) {
        switch (quit) {
        case '2':
            return 1;
        case '1':
            kucha = 100;
            while (kucha > 0) {
                xod_playera(&kucha);
            }
            printf("Начинаем игру?\n1 - Да; 2 - Нет;\n");
            scanf("\n%c", &quit);
            break;
        default:
            printf("Нет такого выбора!\nВаше действие: ");
            scanf(" %c", &quit);
            break;
        }
    }
    return 0;
}