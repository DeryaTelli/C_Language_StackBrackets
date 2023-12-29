#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct node {
    char data;
    struct node *next;
} Node;

typedef struct {
    Node *top;
    int cnt;
} Stack;


Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->cnt = 0;
    return stack;
}


void push(Stack* stack, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->cnt++;
}

char pop(Stack* stack) {
    if (stack->top == NULL) {
        return '\0'; 
    }
    Node* temp = stack->top;
    char popped = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->cnt--;
    return popped;
}

bool areBracketsBalanced(char* brackets) {
    Stack* stack = createStack();

    for (int i = 0; brackets[i] != '\0'; i++) {
        if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{') {
            push(stack, brackets[i]);
        } else if (brackets[i] == ')' || brackets[i] == ']' || brackets[i] == '}') {
            if (stack->top == NULL) {
                free(stack);
                return false;
            }
            char top = pop(stack);
            if ((brackets[i] == ')' && top != '(') ||
                (brackets[i] == ']' && top != '[') ||
                (brackets[i] == '}' && top != '{')) {
                free(stack);
                return false;
            }
        }
    }

    bool isBalanced = (stack->top == NULL);
    free(stack);
    return isBalanced;
}


int main() {
    char brackets1[] = "{[()]}";
    char brackets2[] = "{[()]";
     if (areBracketsBalanced(brackets1)) {
       printf("true\n");
    } else {
       printf("false\n");
    }
     if (areBracketsBalanced(brackets2)) {
       printf("true\n") ;
    } else {
       printf("false\n");
    }

    return 0;
}
