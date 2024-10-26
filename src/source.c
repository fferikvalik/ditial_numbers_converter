#include "source.h"

// Проверка, является ли символ допустимым шестнадцатеричным
int isHexDigit(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f');
}

// Проверка, является ли символ допустимым двоичным
int isBinaryDigit(char ch) {
    return ch == '0' || ch == '1';
}

// Преобразование символа шестнадцатеричного числа в число
int hexCharToInt(char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    else if (ch >= 'A' && ch <= 'F') return ch - 'A' + 10;
    else if (ch >= 'a' && ch <= 'f') return ch - 'a' + 10;
    else return -1;
}

// Преобразование строки шестнадцатеричного числа в десятичное
int hexStringToDecimal(const char *str) {
    int result = 0;
    int i = (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) ? 2 : 0;

    while (str[i] != '\0') {
        if (!isHexDigit(str[i])) return -1;
        result = result * 16 + hexCharToInt(str[i]);
        i++;
    }
    return result;
}

// Преобразование десятичного числа в шестнадцатеричное (в строке)
void decimalToHexString(int decimal, char *hexString) {
    sprintf(hexString, "0x%X", decimal);
}

// Преобразование строки двоичного числа в десятичное
int binaryStringToDecimal(const char *str) {
    int result = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (!isBinaryDigit(str[i])) return -1;
        result = result * 2 + (str[i] - '0');
        i++;
    }
    return result;
}

// Преобразование десятичного числа в двоичное (в строке)
void decimalToBinaryString(int decimal, char *binaryString) {
    int index = 0;
    do {
        binaryString[index++] = (decimal % 2) ? '1' : '0';
        decimal /= 2;
    } while (decimal > 0);
    binaryString[index] = '\0';

    // Разворачиваем строку для правильного отображения двоичного числа
    for (int j = 0; j < index / 2; ++j) {
        char temp = binaryString[j];
        binaryString[j] = binaryString[index - j - 1];
        binaryString[index - j - 1] = temp;
    }
}

// Функция для конвертации из 16 в 10
void convertHexToDecimal() {
    char input[17];
    int decimalValue;
    
    printf("Введите 16-битное число в шестнадцатеричном формате (например, 0x1A3F): ");
    scanf("%16s", input);
    decimalValue = hexStringToDecimal(input);
    if (decimalValue == -1) {
        printf("Некорректный ввод.\n");
    } else {
        printf("Десятичное представление: %d\n", decimalValue);
    }
}

// Функция для конвертации из 10 в 16
void convertDecimalToHex() {
    int decimalValue;
    char hexString[10];
    
    printf("Введите десятичное число: ");
    scanf("%d", &decimalValue);
    decimalToHexString(decimalValue, hexString);
    printf("Шестнадцатеричное представление: %s\n", hexString);
}

// Функция для конвертации из 2 в 10
void convertBinaryToDecimal() {
    char input[17];
    int decimalValue;
    
    printf("Введите 16-битное число в двоичном формате (например, 1010): ");
    scanf("%16s", input);
    decimalValue = binaryStringToDecimal(input);
    if (decimalValue == -1) {
        printf("Некорректный ввод.\n");
    } else {
        printf("Десятичное представление: %d\n", decimalValue);
    }
}

// Функция для конвертации из 10 в 2
void convertDecimalToBinary() {
    int decimalValue;
    char binaryString[17];
    
    printf("Введите десятичное число: ");
    scanf("%d", &decimalValue);
    decimalToBinaryString(decimalValue, binaryString);
    printf("Двоичное представление: %s\n", binaryString);
}