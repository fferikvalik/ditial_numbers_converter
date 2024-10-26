#include "source.h"

int main() {
    int choice;

    printf("Выберите операцию:\n");
    printf("1 - Конвертация из 16 в 10\n");
    printf("2 - Конвертация из 10 в 16\n");
    printf("3 - Конвертация из 2 в 10\n");
    printf("4 - Конвертация из 10 в 2\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            convertHexToDecimal();
            break;
        case 2:
            convertDecimalToHex();
            break;
        case 3:
            convertBinaryToDecimal();
            break;
        case 4:
            convertDecimalToBinary();
            break;
        default:
            printf("Некорректный выбор. Завершение программы.\n");
            break;
    }

    return 0;
}