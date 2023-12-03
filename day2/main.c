#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>

int main(void){
    

    FILE *fp = fopen("in2.txt", "r");
    if(fp == NULL){
        printf("error opening file !");
        return EXIT_FAILURE;
    }


    ssize_t bytes;
    size_t len;
    char *line;
    char *tok;
    char *gamePointer;
    char *gameInnerPoiner;
    char *matchPointer;
    int id_sum = 0;
    int id_pow_sum = 0;
    int i = 1;
    while((bytes = getline(&line, &len,fp)) != EOF){
        int m_red = 0;
        int m_blue = 0;
        int m_green = 0;

        bool game_psbl= true;
        tok = strtok_r(line, ":", &gamePointer);
        tok = strtok_r(NULL, ":", &gamePointer);
        
        tok = strtok_r(tok, ";", &gameInnerPoiner);
        while(tok != NULL){
            int n1 = 0;
            char c1[10];
            char *tok2 = strtok_r(tok, ",", &matchPointer);
            while(tok2 != NULL){
                sscanf(tok2, "%d%s", &n1, c1);
                if(strcmp(c1, "red")== 0){
                    if(n1 > 12){
                        game_psbl = false;
                    }
                    if(n1 > m_red){
                        m_red = n1;
                    }
                }else if(strcmp(c1, "blue") == 0){
                    if(n1 > 14){
                        game_psbl = false;
                    }
                    if(n1 > m_blue){
                        m_blue = n1;
                    }
                }else if(strcmp(c1, "green") == 0){
                    if(n1 > 13){
                        game_psbl = false;
                    }
                    if(n1 > m_green){
                        m_green = n1;
                    }

                }
                printf("%d %s, ", n1, c1);
                tok2 = strtok_r(NULL, ",", &matchPointer);
            }

            tok = strtok_r(NULL, ";", &gameInnerPoiner);
            printf("; ");
        }

        printf("has max %d r, %d g, %d b\n\n", m_red, m_green, m_blue);
        id_pow_sum += m_red*m_blue*m_green;
        if(game_psbl){
            id_sum +=i;
        }
        i++;
    }
    
    printf("\n\n\nPart1: %d\n", id_sum);
    printf("Part2: %d", id_pow_sum);

    return EXIT_SUCCESS;
}