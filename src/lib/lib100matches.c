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

int start()
{
    int kucha = 100, player = 0, bot = 0;
    int quit;
    printf("Начинаем игру?\n1 - Да; 2 - Нет;\n");
    scanf("%d", &quit);
    if (quit == 2)
        return 1;
    if (quit == 1) {
        while (kucha > 0) {
            printf("Ваш ход!\n");
            printf("Осталось спичек: %d\n", kucha);
            printf("Сколько спичек вы берете: ");
            scanf("%d", &player);
            if (player >= 1 && player <= 10) {
                if (kucha >= player) {
                    kucha -= player;
                    printf("Ходит Бот!\n");
                    printf("Осталось спичек: %d\n", kucha);
                    if (kucha <= 10) {
                        bot = kucha;
                    } else {
                        bot = rand() % 10;
                    }
                    if (kucha != 0) {
                        printf("Он взял: %d\n", bot);
                        kucha -= bot;
                        if (kucha == 0)
                            printf("Бот победил!\n");
                    } else {
                        printf("Вы победили!\n");
                    }
                } else {
                    printf("Спичек осталось меньше, чем вы ввели!\n");
                }
            } else {
                printf("Не входит в диапазон от 1 до 10\n");
            }
        }
    }
    return 0;
}