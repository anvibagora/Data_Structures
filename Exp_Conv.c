#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

struct Stack{
    char data[SIZE][SIZE];
    int top;
};

void init(struct Stack *s)
{
    s->top = -1;
}

int isEmpty(struct Stack *s){
    return s->top == -1;
}

int isFull(struct Stack *s){
    return s->top == SIZE - 1;
}

void push(struct Stack *s, char str[]){
    if (isFull(s)){
        printf("Stack Overflow!\n");
        return;
    }
    s->top++;
    strcpy(s->data[s->top], str);
}

void pop(struct Stack *s, char str[]){
    if (isEmpty(s)){
        printf("Stack Underflow!\n");
        return;
    }
    strcpy(str, s->data[s->top]);
    s->top--;
}

void peek(struct Stack *s){
    if (isEmpty(s))
        printf("Stack is Empty!\n");
    else
        printf("Top element: %s\n", s->data[s->top]);
}

void display(struct Stack *s){
    int i;
    if (isEmpty(s)){
        printf("Stack is Empty!\n");
        return;
    }

    printf("\nStack:\n");

    for (i = s->top; i >= 0; i--)
        printf("%s\n", s->data[i]);
}

int precedence(char ch){
    if (ch == '^'){
        return 3;
    }else if (ch == '*' || ch == '/'){
        return 2;
    }else if (ch == '+' || ch == '-'){
        return 1;
    }else{
        return 0;
    }
}

int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '^');
}

void reverse(char str[]){
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPostfix(char infix[], char postfix[]){
    struct Stack s;
    char temp[SIZE];
    int i, k = 0;
    char ch;
    init(&s);
    for (i = 0; infix[i] != '\0'; i++){
        ch = infix[i];

        if (ch == ' '){
            continue;
	}
        if (isalnum(ch)){
            postfix[k++] = ch;
        }else if (ch == '(') {
            temp[0] = ch;
            temp[1] = '\0';
            push(&s, temp);
        }else if (ch == ')'){
            while (!isEmpty(&s) && s.data[s.top][0] != '('){
                pop(&s, temp);
                postfix[k++] = temp[0];
            }
            if (!isEmpty(&s)){
                pop(&s, temp);
            }
        }else if (isOperator(ch)){
            while (!isEmpty(&s) && s.data[s.top][0] != '(' &&  precedence(s.data[s.top][0]) >= precedence(ch)) {
                pop(&s, temp);
                postfix[k++] = temp[0];
            }
            temp[0] = ch;
            temp[1] = '\0';
            push(&s, temp);
        }
    }

    while (!isEmpty(&s)){
        pop(&s, temp);
        postfix[k++] = temp[0];
    }

    postfix[k] = '\0';
}

void infixToPrefix(char infix[], char prefix[]){
    char rev[SIZE];
    char postfix[SIZE];
    int i;
    strcpy(rev, infix);
    reverse(rev);
    for (i = 0; rev[i] != '\0'; i++){
        if (rev[i] == '('){
            rev[i] = ')';
        }else if (rev[i] == ')'){
            rev[i] = '(';
   	 }
    }
    infixToPostfix(rev, postfix);
    strcpy(prefix, postfix);
    reverse(prefix);
}

void postfixToInfix(char postfix[], char infix[]){
    struct Stack s;
    char op1[SIZE], op2[SIZE], result[SIZE];
    char temp[SIZE];
    int i;
    init(&s);
    for (i = 0; postfix[i] != '\0'; i++){
        if (postfix[i] == ' '){
            continue;
	}
        if (isalnum(postfix[i])){
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(&s, temp);
        }else if (isOperator(postfix[i])){
            pop(&s, op2);
            pop(&s, op1);
            sprintf(result, "(%s%c%s)", op1, postfix[i], op2);
            push(&s, result);
        }
    }
    pop(&s, infix);
}

void prefixToInfix(char prefix[], char infix[]){
    struct Stack s;
    char op1[SIZE], op2[SIZE], result[SIZE];
    char temp[SIZE];
    int i;
    init(&s);
    for (i = strlen(prefix) - 1; i >= 0; i--){
        if (prefix[i] == ' ')
            continue;
        if (isalnum(prefix[i])){
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(&s, temp);
        }else if (isOperator(prefix[i])){
            pop(&s, op1);
            pop(&s, op2);
            sprintf(result, "(%s%c%s)",  op1, prefix[i], op2);
            push(&s, result);
        }
    }
    pop(&s, infix);
}

void postfixToPrefix(char postfix[], char prefix[]){
    struct Stack s;
    char op1[SIZE], op2[SIZE], result[SIZE];
    char temp[SIZE];
    int i;
    init(&s);
    for (i = 0; postfix[i] != '\0'; i++){
        if (postfix[i] == ' '){
            continue;
        }
        if (isalnum(postfix[i])){
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(&s, temp);
        }else if (isOperator(postfix[i])){
            pop(&s, op2);
            pop(&s, op1);
            sprintf(result, "%c%s%s", postfix[i], op1, op2);
            push(&s, result);
        }
    }
    pop(&s, prefix);
}

void prefixToPostfix(char prefix[], char postfix[]){
    struct Stack s;
    char op1[SIZE], op2[SIZE], result[SIZE];
    char temp[SIZE];
    int i;
    init(&s);
    for (i = strlen(prefix) - 1; i >= 0; i--){
        if (prefix[i] == ' '){
            continue;
	}
        if (isalnum(prefix[i])){
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(&s, temp);
        }else if (isOperator(prefix[i])){
            pop(&s, op1);
            pop(&s, op2);
            sprintf(result, "%s%s%c", op1, op2, prefix[i]);
            push(&s, result);
        }
    }
    pop(&s, postfix);
}

int main()
{
    struct Stack s;

    char infix[SIZE];
    char postfix[SIZE];
    char prefix[SIZE];
    char input[SIZE];
    char result[SIZE];

    int choice;
    char value[SIZE];

    init(&s);

    do
    {
        printf("\n========== STACK MENU ==========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Infix to Postfix\n");
        printf("6. Infix to Prefix\n");
        printf("7. Postfix to Infix\n");
        printf("8. Prefix to Infix\n");
        printf("9. Postfix to Prefix\n");
        printf("10. Prefix to Postfix\n");
        printf("11. Exit\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%s", value);
            push(&s, value);
            printf("Element pushed successfully.\n");
            break;

        case 2:
            pop(&s, value);

            if (!isEmpty(&s) || strlen(value) > 0)
                printf("Popped element: %s\n", value);
            break;

        case 3:
            peek(&s);
            break;

        case 4:
            display(&s);
            break;

        case 5:
            printf("Enter infix expression: ");
            scanf("%s", infix);

            infixToPostfix(infix, postfix);

            printf("Postfix expression: %s\n", postfix);
            break;

        case 6:
            printf("Enter infix expression: ");
            scanf("%s", infix);

            infixToPrefix(infix, prefix);

            printf("Prefix expression: %s\n", prefix);
            break;

        case 7:
            printf("Enter postfix expression: ");
            scanf("%s", postfix);

            postfixToInfix(postfix, result);

            printf("Infix expression: %s\n", result);
            break;

        case 8:
            printf("Enter prefix expression: ");
            scanf("%s", prefix);

            prefixToInfix(prefix, result);

            printf("Infix expression: %s\n", result);
            break;

        case 9:
            printf("Enter postfix expression: ");
            scanf("%s", postfix);

            postfixToPrefix(postfix, result);

            printf("Prefix expression: %s\n", result);
            break;

        case 10:
            printf("Enter prefix expression: ");
            scanf("%s", prefix);

            prefixToPostfix(prefix, result);

            printf("Postfix expression: %s\n", result);
            break;

        case 11:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 11);

    return 0;
}