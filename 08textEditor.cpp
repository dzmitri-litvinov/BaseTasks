/**
0123 4
AB 2\0
"., !:"

+1) символ - буква, след. - буква: записыв символ
+2) символ - буква, след. - сепаратор: записыв символ, закрыв слово
+3) символ - сепаратор, след. - буква: ничего
+4) символ - сепаратор, след. - сепаратор: ничего
+5)символ - буква, след. - \0: записыв символ, закрыв слово



***/

#include <iostream>
using namespace std;
#define N 256
#define N_WORD 32

bool isSeparator(char c);
int strLen(char str[]);
void strCat(char str1[], char str2[]);
void strCpy(char str1[], char str2[]);
int strCmp(char str1[], char str2[]);
void emptyTextArray(char textSplitted[N][N_WORD]);
void deleteDoubleSpace(char textSplitted[N][N_WORD], int textUnits);
void deleteRepeateWord(char textSplitted[N][N_WORD], int textUnits);
void replaceHyphenWithDash(char textSplitted[N][N_WORD], int textUnits);
void splitText(char text[N], char textSplitted[N][N_WORD]);
int calcTextUnits(char textSplitted[N][N_WORD]);
void combainSplits(char textResult[N], char textSplitted[N][N_WORD], int textUnits);

int main()
{
    char text[N], textResult[N] = "";
    char textSplitted[N][N_WORD];
    int textUnits = 0;

    cout << "Input text: ";
    cin.getline(text, N);

    emptyTextArray(textSplitted);
    splitText(text, textSplitted);
    textUnits = calcTextUnits(textSplitted);

    deleteRepeateWord(textSplitted, textUnits);
    deleteDoubleSpace(textSplitted, textUnits);
    replaceHyphenWithDash(textSplitted, textUnits);

    combainSplits(textResult, textSplitted, textUnits);
    cout << "Result: \"" << textResult << "\"";

    return 0;
}

bool isSeparator(char c)
{
    char separator[] = "., !:-";

    for (int i = 0; separator[i] != '\0'; i++)
        if (c == separator[i])
            return true;
    return false;
}

int strLen(char str[])
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }

    return len;
}

void strCat(char str1[], char str2[])
{
    int len1 = strLen(str1);
    int i;

    for (i = 0; str2[i] != '\0'; i++)
    {
        str1[len1 + i] = str2[i];
    }

    str1[len1 + i] = '\0';
}

void strCpy(char str1[], char str2[])
{
    int i;

    for (i = 0; str2[i] != '\0'; i++)
    {
        str1[i] = str2[i];
    }

    str1[i] = '\0';
}

int strCmp(char str1[], char str2[])
{
    int i = 0;

    for (i = 0; ; i++)
    {
        if (str1[i] > str2[i])
            return 1;

        if (str1[i] < str2[i])
            return -1;

        if (str1[i] == '\0' and str2[i] == '\0')
            return 0;
    }
}

void deleteDoubleSpace(char textSplitted[N][N_WORD], int textUnits)
{
    int i = 0, j = 0, counter = 1;

    while (counter > 0) {
        counter = 0;

        for (i = 0; i < textUnits; i++) {
            if (textSplitted[i][0] != ' ' or textSplitted[i][0] == '\0')
                continue;

            j = i + 1;

            while (textSplitted[j][0] == '\0')
                j++;

            if (textSplitted[j][0] == ' ') {
                textSplitted[j][0] = '\0';
                counter++;
            }
        }
    }
}

void deleteRepeateWord(char textSplitted[N][N_WORD], int textUnits)
{
    int i = 0, j = 0, counter = 1;

    while (counter > 0){
        counter = 0;

        for (i = 0; i < textUnits; i++) {
            if (textSplitted[i][0] == ' ' or textSplitted[i][0] == '\0')//?
                continue;

            j = i + 1;

            while (textSplitted[j][0] == ' ' or textSplitted[j][0] == '\0')//? add break if j == N
                j++;

            if (strCmp(textSplitted[i], textSplitted[j]) == 0) { 
                textSplitted[j - 1][0] = '\0';
                textSplitted[j][0] = '\0';
                counter++;
            }
        }
    }
}

void replaceHyphenWithDash(char textSplitted[N][N_WORD], int textUnits)
{
    int i = 0, j = 0, k = 1;

    for (i = 0; i < textUnits; i++) {
        if (textSplitted[i][0] != '-' or textSplitted[i][0] == '\0')
            continue;

        j = i + 1;
        while (textSplitted[j][0] == '\0')
            j++;

        k = i - 1;
        if (k < 0) continue;
        while (textSplitted[k][0] == '\0')
        {
            k--;
            if (k < 0) break;
        }
            

        if (textSplitted[j][0] == ' ' and textSplitted[k][0] == ' ') {
            textSplitted[i][1] = '-';
            textSplitted[i][2] = '\0';
        }
    }
    
}

void emptyTextArray(char textSplitted[N][N_WORD])
{
    for (int i = 0; i < N; i++)
        textSplitted[i][0] = '\0';
}

void splitText(char text[N], char textSplitted[N][N_WORD])
{
    char word[N] = "";
    int i = 0, iw = 0, iSp = 0;

    for (i = 0; text[i] != '\0'; i++) {
        if (!isSeparator(text[i])) {
            word[iw] = text[i];
            iw++;
            if (isSeparator(text[i + 1]) or text[i + 1] == '\0') {
                word[iw] = '\0';
                iw = 0;
                cout << word << endl;
            }
        }

        if (isSeparator(text[i])) {
            if (word[0] != '\0') {
                strCpy(textSplitted[iSp], word);
                iSp++;
                word[0] = '\0';
            }

            textSplitted[iSp][0] = text[i];
            textSplitted[iSp][1] = '\0';
            iSp++;
        }

        if (text[i + 1] == '\0') {
            if (word[0] != '\0') {
                strCpy(textSplitted[iSp], word);
                iSp++;
                word[0] = '\0';
            }
        }
    }
}

int calcTextUnits(char textSplitted[N][N_WORD])
{
    int textUnits = 0;
    for (textUnits = 0; textSplitted[textUnits][0] != '\0'; textUnits++) {}

    return textUnits;
}

void combainSplits(char textResult[N], char textSplitted[N][N_WORD], int textUnits)
{
    for (int i = 0; i < textUnits; i++) {
        strCat(textResult, textSplitted[i]);
    }
}