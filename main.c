#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[8];
    char content[100];
} File;

typedef struct{
    char name;
    File content[1000];
} Drive;

void ls(Drive *pDr);
char cd();
void create(Drive *pDr);
void cat(Drive *pDr);
void del(Drive *pDr);
void edit(Drive *pDr);
void cname(Drive *pDr);
void replace(Drive *pDr);
void help();

int main(){
    int quit = 0;
    char command[32] = "";
    char address = 'c';
    Drive *pAD;

    Drive c = {'c', {0}};
    Drive d = {'d', {0}};
    Drive e = {'e', {0}};

    while(quit == 0){
        printf("$%c~ ", address);
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        switch(address){
            case 'c':
                pAD = &c;
                break;
            case 'd':
                pAD = &d;
                break;
            case 'e':
                pAD = &e;
                break;
        }

        if(strcmp(command, "ls") == 0){
            ls(pAD);
        }
        else if(strcmp(command, "cd") == 0){
            address = cd();
        }
        else if(strcmp(command, "quit") == 0){
            quit = 1;
        }
        else if(strcmp(command, "create") == 0){
            create(pAD);
        }
        else if(strcmp(command, "cat") == 0){
            cat(pAD);
        }
        else if(strcmp(command, "del") == 0){
            del(pAD);
        }
        else if(strcmp(command, "edit") == 0){
            edit(pAD);
        }
        else if(strcmp(command, "cname") == 0){
            cname(pAD);
        }
        else if(strcmp(command, "replace") == 0){
            replace(pAD);
        }
        else if(strcmp(command, "cls") == 0){
            system("cls");
        }
        else if(strcmp(command, "help") == 0){
            help();
        }
        else{
            printf("\n!INVALID COMMAND!\n\n");
        }
    }

    return 0;
}

void ls(Drive *pDr){
    for(int i = 0; i < sizeof(pDr->content) / sizeof(File); i++){
        if(strlen(pDr->content[i].name) > 0){
            printf("%s\n", pDr->content[i].name);
        }
    }
}

char cd(){
    char drive;
    char temp[8];

    printf("\nEnter the drive you want to enter (c, d, e): ");
    fgets(temp, sizeof(temp), stdin);
    drive = temp[0];
    printf("\n");

    return drive;
}

void create(Drive *pDr){
    char name[8];
    char content[100];

    printf("\nEnter name of file: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    printf("\nEnter content of file: ");
    fgets(content, sizeof(content), stdin);
    content[strlen(content) - 1] = '\0';

    for (int i = 0; i < 1000; i++) {
        if(strlen(pDr->content[i].name) == 0){
            strcpy(pDr->content[i].name, name);
            strcpy(pDr->content[i].content, content);
            printf("File '%s' added.\n", name);
            return;
        }
    }
}

void cat(Drive *pDr){
    char fileName[8];

    printf("\nEnter name of file: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strlen(fileName) - 1] = '\0';

    for(int i = 0; i < 1000; i++){
        if(strcmp(pDr->content[i].name, fileName) == 0){
            printf("title: %s\ncontent: %s\n", pDr->content[i].name, pDr->content[i].content);
            return;
        }
    }
}

void edit(Drive *pDr){
    char fileName[8];
    char content[100];

    printf("\nEnter name of file: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strlen(fileName) - 1] = '\0';

    printf("\nEnter new content of file: ");
    fgets(content, sizeof(content), stdin);
    content[strlen(content) - 1] = '\0';

    for(int i = 0; i < 1000; i++){
        if(strcmp(pDr->content[i].name, fileName) == 0){
            strcat(pDr->content[i].content, content);
            printf("Changes Saved!\n");
            return;
        }
    }
}

void cname(Drive *pDr){
    char fileName[8];
    char content[8];

    printf("\nEnter name of file: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strlen(fileName) - 1] = '\0';

    printf("\nEnter new name of file: ");
    fgets(content, sizeof(content), stdin);
    content[strlen(content) - 1] = '\0';

    for(int i = 0; i < 1000; i++){
        if(strcmp(pDr->content[i].name, fileName) == 0){
            strcpy(pDr->content[i].name, content);
            printf("Changes Saved!\n");
            return;
        }
    }
}

void replace(Drive *pDr){
    char fileName[8];
    char content[100];

    printf("\nEnter name of file: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strlen(fileName) - 1] = '\0';

    printf("\nEnter new content of file: ");
    fgets(content, sizeof(content), stdin);
    content[strlen(content) - 1] = '\0';

    for(int i = 0; i < 1000; i++){
        if(strcmp(pDr->content[i].name, fileName) == 0){
            strcpy(pDr->content[i].content, content);
            printf("Changes Saved!\n");
            return;
        }
    }
}

void del(Drive *pDr){
    char fileName[8];

    printf("\nEnter name of file: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strlen(fileName) - 1] = '\0';

    for(int i = 0; i < 1000; i++){
        if(strcmp(pDr->content[i].name, fileName) == 0){
            memset(pDr->content[i].name, 0, sizeof(pDr->content[i].name));
            memset(pDr->content[i].content, 0, sizeof(pDr->content[i].content));
            printf("File '%s' deleted.\n", fileName);
            return;
        }
    }
}

void help(){
    printf("\nls: list all files\ncd: change directory\ncreate: create new file\ncat: read file\ndel: delete file\nedit: change file contents\ncname: change file name\nreplace: replace file\nhelp: list all commands\n\nenter only commnands without space and dont enter name or anything else\n\n");
}