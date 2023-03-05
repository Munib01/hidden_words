// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ROW_SIZE        15
#define COLUMN_SIZE     15
#define WORDS_SIZE      16

char puzzle[ROW_SIZE][COLUMN_SIZE] = {
    {'a', 'x', 'd', 'u', 'r', 'y', 'h', 'p', 's', 'p', 't', 't', 'i', 'd', 't'},
    {'v', 'n', 'x', 's', 'e', 'c', 'a', 'q', 'c', 'u', 'i', 'u', 'o', 'z', 'p'},
    {'m', 'e', 'r', 'g', 'f', 'w', 'o', 'z', 'i', 's', 'n', 'l', 'k', 'a', 'c'},
    {'v', 's', 'c', 'x', 's', 'e', 's', 'x', 'o', 'f', 'l', 'w', 'z', 'j', 'z'},
    {'v', 't', 'r', 'p', 'n', 'd', 'l', 'p', 'b', 'a', 'c', 'h', 'e', 'b', 'y'},
    {'p', 'r', 'e', 'k', 'a', 'w', 'e', 'c', 'r', 'c', 't', 'x', 'n', 's', 'b'},
    {'f', 'p', 'd', 'm', 'r', 'd', 'l', 'o', 's', 'p', 'e', 'j', 'a', 'q', 't'},
    {'w', 'h', 'i', 'n', 't', 'l', 'y', 'i', 'b', 't', 'c', 'a', 's', 'h', 'n'},
    {'l', 'a', 't', 'c', 'i', 'q', 'n', 'n', 'r', 'i', 'l', 'h', 't', 'y', 'j'},
    {'k', 'r', 'r', 'x', 'o', 'i', 'f', 'k', 'y', 'b', 'w', 'o', 'e', 'w', 'a'},
    {'v', 'c', 'p', 'd', 'u', 'y', 'z', 'k', 'l', 'e', 't', 'n', 'a', 'k', 'w'},
    {'i', 'u', 'e', 'o', 'h', 'k', 'n', 'a', 'b', 'd', 'o', 't', 'a', 'n', 'a'},
    {'f', 'a', 'q', 'h', 'y', 't', 'j', 'b', 'i', 'm', 'y', 'm', 'u', 'd', 's'},
    {'v', 'q', 'z', 'f', 'c', 'j', 'i', 'e', 'e', 'm', 'n', 'k', 'u', 'x', 'l'},
    {'b', 'a', 'l', 'a', 'n', 'c', 'e', 'w', 'e', 'c', 'n', 'u', 'o', 'p', 'b'}
};

char puzzle_solved[ROW_SIZE][COLUMN_SIZE] = {
    {'a', 'x', 'd', 'u', 'r', 'y', 'h', 'p', 's', 'p', 't', 't', 'i', 'd', 't'},
    {'v', 'n', 'x', 's', 'e', 'c', 'a', 'q', 'c', 'u', 'i', 'u', 'o', 'z', 'p'},
    {'m', 'e', 'r', 'g', 'f', 'w', 'o', 'z', 'i', 's', 'n', 'l', 'k', 'a', 'c'},
    {'v', 's', 'c', 'x', 's', 'e', 's', 'x', 'o', 'f', 'l', 'w', 'z', 'j', 'z'},
    {'v', 't', 'r', 'p', 'n', 'd', 'l', 'p', 'b', 'a', 'c', 'h', 'e', 'b', 'y'},
    {'p', 'r', 'e', 'k', 'a', 'w', 'e', 'c', 'r', 'c', 't', 'x', 'n', 's', 'b'},
    {'f', 'p', 'd', 'm', 'r', 'd', 'l', 'o', 's', 'p', 'e', 'j', 'a', 'q', 't'},
    {'w', 'h', 'i', 'n', 't', 'l', 'y', 'i', 'b', 't', 'c', 'a', 's', 'h', 'n'},
    {'l', 'a', 't', 'c', 'i', 'q', 'n', 'n', 'r', 'i', 'l', 'h', 't', 'y', 'j'},
    {'k', 'r', 'r', 'x', 'o', 'i', 'f', 'k', 'y', 'b', 'w', 'o', 'e', 'w', 'a'},
    {'v', 'c', 'p', 'd', 'u', 'y', 'z', 'k', 'l', 'e', 't', 'n', 'a', 'k', 'w'},
    {'i', 'u', 'e', 'o', 'h', 'k', 'n', 'a', 'b', 'd', 'o', 't', 'a', 'n', 'a'},
    {'f', 'a', 'q', 'h', 'y', 't', 'j', 'b', 'i', 'm', 'y', 'm', 'u', 'd', 's'},
    {'v', 'q', 'z', 'f', 'c', 'j', 'i', 'e', 'e', 'm', 'n', 'k', 'u', 'x', 'l'},
    {'b', 'a', 'l', 'a', 'n', 'c', 'e', 'w', 'e', 'c', 'n', 'u', 'o', 'p', 'b'}
};

const char *words[WORDS_SIZE] = {
    "balance",
    "bank",
    "cash",
    "check",
    "coin",
    "credit",
    "debit",
    "deposit",
    "dollar",
    "loan",
    "money",
    "paws",
    "pounce",
    "sunwest",
    "transfer",
    "withdraw"
};

void display_words()
{
    for(int i=0;i<WORDS_SIZE;i++)
    {
        printf("    %s  \n", words[i]);
    }
}

void display_pattern()
{
    for(int i=0;i<ROW_SIZE;i++)
    {
        for(int j=0;j<COLUMN_SIZE;j++)
        {
            printf("%c  ", puzzle_solved[i][j]);
        }
        printf("\n");
    }    
}

void rev_str(char *str1)  
{  
    // declare variable  
    int i, len, temp;  
    len = strlen(str1); // use strlen() to get the length of str string  
        
    // use for loop to iterate the string   
    for (i = 0; i < len/2; i++)  
    {  
        // temp variable use to temporary hold the string  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  

int check_str_index(char* str, char* substr)
{ 
    bool isPresent = false;
    int i=0;
    int j=0;
    for (i = 0; str[i] != '\0'; i++) {
        isPresent = false;
        for (j = 0; substr[j] != '\0'; j++) {
            if (str[i + j] != substr[j]) {
                isPresent = false;
                break;
            }
            isPresent = true;
        }
        if (isPresent) {
            break;
        }
    }
     
    if (isPresent) {
        return i;
    }
    return -1;
}

void row_capitalize_puzzle(int row, int column, int str_length)
{
    // printf("checkpoint_2,         %d, %d, %d    ",row, column, str_length);
    for(int i=0;i<str_length;i++)
    {
        // printf("checkpoint 3, %c,   %c\n", puzzle[row+i][column], puzzle[row+i][column] - 32);
        puzzle_solved[row][column+i] = puzzle[row][column+i] - 32;
    }
    printf("%s", puzzle[row]);
}

void column_capitalize_puzzle(int row, int column, int str_length)
{
    // printf("checkpoint_2,         %d, %d, %d    ",row, column, str_length);
    for(int i=0;i<str_length;i++)
    {
        // printf("checkpoint 3, %c,   %c\n", puzzle[row+i][column], puzzle[row+i][column] - 32);
        puzzle_solved[row+i][column] = puzzle[row+i][column] - 32;
    }
    printf("%s", puzzle[row]);
}

void row_wise_check()
{
    int str_length=0;
    int str_index=-1;
    char puzzle_str[COLUMN_SIZE*2];
    char word[COLUMN_SIZE];
    char inverted_word[COLUMN_SIZE];

    for(int i=0;i<ROW_SIZE;i++)
    {
        for(int j=0;j<COLUMN_SIZE;j++)
        {
            puzzle_str[j]=puzzle[i][j];
        }
        printf("%d, string  = %s, %ld   ", i, puzzle_str, strlen(puzzle_str));
        for (int k=0;k<WORDS_SIZE;k++)
        {
            strcpy(word, words[k]);
            str_index = check_str_index(puzzle_str, word);
            if(str_index!=-1)
            {
                printf("checkpoint_1    %s      ", word);
                row_capitalize_puzzle(i,str_index,strlen(word));
            }
            strcpy(inverted_word, word);
            rev_str(inverted_word);
            str_index = check_str_index(puzzle_str, inverted_word);
            if(str_index!=-1)
            {
                printf("inverted_word: %s", inverted_word);
                printf("checkpoint_1    %s      ", word);
                row_capitalize_puzzle(i,str_index,strlen(word));
            }
        }
        printf("\n");
    }  
}

void column_wise_check()
{
    printf("in colunm wise check\n");
    int str_length=0;
    int str_index=-1;
    char puzzle_str[ROW_SIZE*2];
    char word[ROW_SIZE];
    char inverted_word[ROW_SIZE];

    for(int i=0;i<COLUMN_SIZE;i++)
    {
        for(int j=0;j<ROW_SIZE;j++)
        {
            puzzle_str[j]=puzzle[j][i];
        }
        printf("%d, string  = %s, %ld   ", i, puzzle_str, strlen(puzzle_str));
        for (int k=0;k<WORDS_SIZE;k++)
        {
            strcpy(word, words[k]);
            str_index = check_str_index(puzzle_str, word);
            if(str_index!=-1)
            {
                printf("checkpoint_1    %s      ", word);
                column_capitalize_puzzle(str_index,i,strlen(word));
            }
            strcpy(inverted_word, word);
            rev_str(inverted_word);
            str_index = check_str_index(puzzle_str, inverted_word);
            if(str_index!=-1)
            {
                printf("inverted_word: %s", inverted_word);
                printf("checkpoint_1    %s      ", word);
                column_capitalize_puzzle(str_index,i,strlen(word));
            }
        }
        printf("\n");
    }  
}


int main() {
    // Write C code here
    printf("Original pattern\n");
    display_pattern();
    printf("\nHidden Words\n");
    display_words();

    row_wise_check();
    column_wise_check();

    printf("\n\nPattern after finding the hidden words\n");
    display_pattern();
    return 0;
}