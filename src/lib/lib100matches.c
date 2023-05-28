#include <ctype.h>
#include <lib100matches.h>
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
        printf("Это не число!\n");
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

int winner(int* kucha, int queue)
{
    if (*kucha == 0) {
        if (queue == 1) {
            printf("\nПобедил игрок!\n\n");
            return 1;
        } else {
            printf("\nПобедил Бот!\n\n");
            return 2;
        }
    }
    return 0;
}

void queue(int* kucha)
{
    xod_playera(kucha);
    if (winner(kucha, 1) == 0) {
        xod_bota(kucha);
        winner(kucha, 2);
    }
}

int xod_bota(int* kucha)
{
    int bot;
    printf("\nХодит Бот!\n");
    printf("Осталось спичек: %d\n", *kucha);
    if (*kucha <= 10) {
        bot = *kucha;
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
    if (digit_or_not(xod) != 0) {
        info(er_not_number);
        return 1;
    }
    int player;
    player = atoi(xod);
    if (check_diapazon(player) == 1) {
        info(er_not_diapazon);
        return 2;
    }
    if (check_kol_vo(player, kucha) == 1) {
        info(er_too_much);
        return 3;
    }
    return 0;
}

int xod_playera(int* kucha)
{
    fflush(stdin);
    char xod[20];
    printf("\nВаш ход!\n");
    printf("Осталось спичек: %d\n", *kucha);
    printf("Сколько спичек вы берете: ");
    fgets(xod, 20, stdin);
    if (xod[0] == '\n') {
        fgets(xod, 20, stdin);
    }
    if (checks(kucha, xod) != 0) {
        xod_playera(kucha);
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
                queue(&kucha);
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