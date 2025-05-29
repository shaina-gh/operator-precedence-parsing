#include <stdio.h>
#include <string.h>

int main() {
    char stack[20], ip[20], opt[10][10][1], ter[10];
    int i, j, k, n, col, row, top = 0;

    // Initialize stack and input
    for(i = 0; i < 20; i++) {
        stack[i] = '\0';
        ip[i] = '\0';
    }

    // Initialize precedence table
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            opt[i][j][0] = '\0';
        }
    }

    printf("Enter the number of terminals: ");
    scanf("%d", &n);

    printf("\nEnter the terminals: ");
    scanf("%s", ter);

    printf("\nEnter the table values:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Enter the value for %c %c: ", ter[i], ter[j]);
            scanf("%s", opt[i][j]);
        }
    }

    printf("\n**** OPERATOR PRECEDENCE TABLE ****\n");
    for(i = 0; i < n; i++) {
        printf("\t%c", ter[i]);
    }
    printf("\n");
    for(i = 0; i < n; i++) {
        printf("%c", ter[i]);
        for(j = 0; j < n; j++) {
            printf("\t%c", opt[i][j][0]);
        }
        printf("\n");
    }

    stack[top] = '$';

    printf("\nEnter the input string: ");
    scanf("%s", ip);
    strcat(ip, "$");

    i = 0;
    printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
    printf("\n%s\t\t\t%s\t\t\t", stack, ip);

    while(i <= strlen(ip)) {
        // Get precedence indices
        for(k = 0; k < n; k++) {
            if(stack[top] == ter[k]) col = k;
            if(ip[i] == ter[k]) row = k;
        }

        // Accept if both are $
        if(stack[top] == '$' && ip[i] == '$') {
            printf("String is accepted\n");
            break;
        }

        // No relation
        if(opt[col][row][0] == '-') {
            printf("No precedence relation, continuing\n");
            break;
        }
        else if(opt[col][row][0] == '<' || opt[col][row][0] == '=') {
            stack[++top] = ip[i];
            printf("Shift %c", ip[i]);
            i++;
        }
        else if(opt[col][row][0] == '>') {
            while(stack[top] != '<' && top > 0) {
                --top;
            }
            top = top - 1;
            printf("Reduce");
        }
        else {
            printf("String is not accepted due to invalid precedence\n");
            break;
        }

        // Display current stack and input
        printf("\n");
        for(k = 0; k <= top; k++) {
            printf("%c", stack[k]);
        }
        printf("\t\t\t");
        for(k = i; k < strlen(ip); k++) {
            printf("%c", ip[k]);
        }
        printf("\t\t\t");
    }

    return 0;
}
