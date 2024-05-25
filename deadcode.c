#include<stdio.h>
#include<string.h>
#include<conio.h>

struct deadcode
{
    char l;
    char r[20];
} op[10], pr[10];

void main() {
    int i, j, k, l;
    int n;
    char temp;
    char *p;

    printf("Enter the number of values:");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        op[i].l = getche();
        scanf("%s", op[i].r);
    }

    int z = 0;
    for (k = 0; k < n - 1; k++) {
        temp = op[k].l;
        for (l = 0; l < n; l++) {
            p = strchr(op[l].r, temp);
            if (p) {
                pr[z].l = op[k].l;  // Corrected index from i to k
                strcpy(pr[z].r, op[k].r);  // Corrected index from i to k
                z++;
                break; // Break once found to avoid duplicates
            }
        }
    }

    pr[z].l = op[n - 1].l;
    strcpy(pr[z].r, op[n - 1].r);
    z++;

    printf("\nAfter Dead Code Elimination:\n");
    for (i = 0; i < z; i++) {
        printf("%c%s\n", pr[i].l, pr[i].r);
    }
    int a,b;
    int res;
    for(a=0;a<z;a++){
        for(b=a+1;b<z;b++){
            res=strcmp(pr[a].r,pr[b].r);
            if(pr[a].l==pr[b].l||!res){
                   pr[a].l='\0';
                   strcpy(pr[a].r,'\0');
            }

        }
    }
    int d;
    for (d = 0; d < z; d++) {
        printf("%c%s\n", pr[d].l, pr[d].r);
    }

}
