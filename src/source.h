#include <stdint.h>
#include <unistd.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isHexDigit(char ch);
int isBinaryDigit(char ch);
int hexCharToInt(char ch);
int hexStringToDecimal(const char *str);
void decimalToHexString(int decimal, char *hexString);
int binaryStringToDecimal(const char *str);
void decimalToBinaryString(int decimal, char *binaryString);

void decimalToBinaryString(int decimal, char *binaryString);
void convertHexToDecimal();
void convertDecimalToHex();
void convertBinaryToDecimal();
void convertDecimalToBinary();