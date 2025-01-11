# finzo.1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char getRandomChar()
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$?/-_";
    int index = rand() % (sizeof(charset) - 1);
    return charset[index];

}
void generatePassword(int length)
{
    printf("\033[2J\033[H"); 
    printf("\033[1;36m");    
    printf("********* Strong Password Generator dev by finzo ********* \n");
    printf("\033[0m");       
    srand(time(NULL));  
    while (1)
    {
        printf("\033[1;35m"); 
        printf("Generated Password: ");
        printf("\033[1;32m");  
        for (int i = 0; i < length; i++)
        {
            printf("%c", getRandomChar());
        }
        printf("\n");
        printf("\033[0m");  
        printf("\n");
        printf("\033[1;33m");  
        printf("Do you want to generate another password? (y/n): ");
        printf("\033[0m");    
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
    int passwordLength = 10;  
    generatePassword(passwordLength);
    return 0;
}
