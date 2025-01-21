#password generator and strength checker
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
char getRandomChar()
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$?/-_";
    int index = rand() % (sizeof(charset) - 1);
    return charset[index];
}
int checkPasswordStrength(const char *password)
{
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
            hasUpper = 1;
        else if (islower(password[i]))
            hasLower = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
        else if (strchr("!@#$%^&*()-_=+[]{}|;:'\",.<>?/\\", password[i]))
            hasSpecial = 1;//finzo Bhote
    }
    int score = hasUpper + hasLower + hasDigit + hasSpecial;
    if (length >= 12 && score == 4)
        return 3; // Strong
    else if (length >= 8 && score >= 3)
        return 2; // Medium
    else
        return 1; //weak
}
void evaluatePassword(const char *password)
{
    int strength = checkPasswordStrength(password);

    printf("\nPassword: %s\n", password);

    if (strength == 3)
        printf("Strength: \033[1;32mStrong\033[0m\n");
    else if (strength == 2)
        printf("Strength: \033[1;33mMedium\033[0m\n");
    else
        printf("Strength: \033[1;31mWeak\033[0m\n");
}

void generatePassword(int length)
{
    printf("\033[2J\033[H"); 
    printf("\033[1;36m");    
    printf("********* Strong Password Generator and Strength Checker by finzo ********* \n");
    printf("\033[0m");       
    char password[256]; 
    while (1)
    {
        for (int i = 0; i < length; i++)
        {
            password[i] = getRandomChar();
        }
        password[length] = '\0'; 
        printf("\033[1;35mGenerated Password: \033[1;32m%s\033[0m\n", password);
        evaluatePassword(password);
        printf("\n\033[1;33mDo you want to generate another password? (y/n): \033[0m");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N')
        {
            break;
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL)); 
    int passwordLength;
    printf("\033[1;34m");
    printf("Enter the desired password length: ");
    printf("\033[0m");
    scanf("%d", &passwordLength);
    if (passwordLength < 1)
    {
        printf("\033[1;31m");
        printf("Password length must be greater than 0!\n");
        printf("\033[0m");
        return 1;
    }
    generatePassword(passwordLength);
    return 0;
}











