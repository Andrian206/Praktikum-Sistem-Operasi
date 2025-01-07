#include <stdio.h>
#include <conio.h> 
#include <string.h>
#include <stdlib.h>
struct{
    char dname[18], fname[18][19];
    int fcnt;
    int dir[3];
} dir[10];
int main(){
    int ch, i, dcnt, k;
    char f[19], d[30]; 
    dcnt = 0;
    while (1){
        printf("\n\n1. Create Directory\t2. Create File\t3. Delete File");
        printf("\n4. Search File\t5. Display\t6. Exit\nEnter your choice :: ");
        scanf("%d", &ch);
        switch (ch){
            case 1: 
                printf("\nEnter name of directory -- ");
                scanf("%s", dir[dcnt].dname);
                dir[dcnt].fcnt = dcnt;
                dcnt++;
                printf("Directory created");
                break;
            case 2: 
                printf("\nEnter name of the directory -- ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++)
                {
                    if (strcmp(d, dir[i].dname) == 0)
                    {
                        printf("Enter name of the file -- ");
                        scanf("%s", dir[i].fname[dir[i].fcnt]);
                        dir[i].fcnt++;
                        printf("File created");
                    }
                }
                if (i == dcnt)
                {
                    printf("Directory %s not found", d);
                }
                break;

            case 3:
                printf("\nEnter name of the directory -- ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++)
                {
                    if (strcmp(d, dir[i].dname) == 0)
                    {
                        printf("Enter file name to delete -- ");
                        scanf("%s", f);
                        for (k = 0; k < dir[i].fcnt; k++)
                        {
                            if (strcmp(f, dir[i].fname[k]) == 0)
                            {
                                for (int j = k; j < dir[i].fcnt - 1; j++)
                                {
                                    strcpy(dir[i].fname[k], dir[i].fname[k + 1]);
                                }
                                dir[i].fcnt--;
                                printf("File deleted\n");
                                goto jmp;
                            }
                        }
                    }
                    printf("File %s not found\n", f);
                    goto jmp;
                }
                printf("Directory %s not found\n", d);
            jmp:
                break;

            case 4: 
                printf("\nEnter name of the directory -- ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++)
                {
                    if (strcmp(d, dir[i].dname) == 0)
                    {
                        printf("Files in directory %s:\n", d);
                        for (k = 0; k < dir[i].fcnt; k++)
                        {
                            printf("%s\n", dir[i].fname[k]);
                        }
                        goto jmp1;
                    }
                }
                printf("Directory %s not found\n", d);
            jmp1:
                break;
            case 5: 
                if (dcnt == 0)
                {
                    printf("No Directory's\n");
                    break;
                }
            else
                {
                    printf("Directory and Files are:\n");
                    for (i = 0; i < dcnt; i++)
                    {
                        printf("%s\n", dir[i].dname);
                        for (k = 0; k < dir[i].fcnt; k++)
                        {
                            printf("%s\n", dir[i].fname[k]);
                        }
                    }
                }
                break;
            case 6: 
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}