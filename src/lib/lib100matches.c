#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

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

void digit_or_not(char* xod)
{
    while (isdigit(xod[0]) == 0 && isdigit(xod[1]) == 0) {
        info(er_not_number);
        scanf(" %c%c", &xod[0], &xod[1]);
    }
}

int xod_playera(int* kucha)
{
    char xod[2];
    int player;
    printf("Ваш ход!\n");
    printf("Осталось спичек: %d\n", *kucha);
    printf("Сколько спичек вы берете: ");
    scanf(" %c%c", &xod[0], &xod[1]);
    digit_or_not(xod);
    player = atoi(xod);
    if (player >= 1 && player <= 10) {
        if (*kucha >= player) {
            *kucha -= player;
            if (*kucha == 0) {
                printf("Вы победили!\n");
                return 1;
            }
            return xod_bota(kucha);
        } else {
            info(er_too_much);
        }
    } else {
        info(er_not_diapazon);
    }
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