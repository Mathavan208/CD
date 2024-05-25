#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char s[100];
    FILE *fp1, *fp2;
    double op1, op2, interstl;
    char result[2], equal, operator;
    char flag1[20] = "//constant";
    
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    
    fscanf(fp1, "%s", s);
    int flag2 = 0;
    
    while (!feof(fp1)) {
        if (strcmp(flag1, s) == 0) {
            flag2 = 1;
        } else {
            flag2 = 0;
        }
        
        if (flag2) {
            // fscanf(fp1, "%s", s);
            // strcpy(result, s);
            // fscanf(fp1, " %c", &equal);
            // fscanf(fp1, " %c", &operator);
            // fscanf(fp1, "%lf %lf", &op1, &op2);
            fscanf(fp1,"%s",s);
            strcpy(result,s);
            fscanf(fp1,"%c",&equal);
            fscanf(fp1,"%c",&operator);
            fscanf(fp1,"%lf %lf",&op1,&op1);
            
            if (isdigit(op1) && isdigit(op2)) {
                switch (operator) {
                    case '+':
                        interstl = op1 + op2;
                        break;
                    case '-':
                        interstl = op1 - op2;
                        break;
                    case '*':
                        interstl = op1 * op2;
                        break;
                    case '/':
                        interstl = op1 / op2;
                        break;
                    default:
                        fprintf(fp2, "Invalid operator\n");
                        break;
                }
                
                fprintf(fp2, "constant folding\n");
                fprintf(fp2, "%s=%.2lf\n", result, interstl);
            } else {
                fprintf(fp2, "Not optimized: %s %c %c %lf %lf\n", result, equal, operator, op1, op2);
            }
        } else {
            fprintf(fp2, "%s ", s);
        }
        
        fscanf(fp1, "%s", s);
    }
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}
