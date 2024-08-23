#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#define SIZE 100

void MainMenu();
void LDS();
void NLDS();

//strings
int String();
int lengthString (char str[]);
void copyString(char str[], char str2[]);
void compareString(char str[]);
void concatenateString(char str[]);
void appendString(char str[]);
void traverseString(char str[SIZE]);
void insertString(char str[]);
void deletionString(char str[]);
void substring(char str[]);

//stacks
struct Node {
    int data;
    struct Node* next;
};

struct StackArray {
    int capacity;
    int top;
    int* array;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void pushLinkedList(struct Node** head, int data);
int popLinkedList(struct Node** head);
int peekLinkedList(struct Node** head);
int isEmptyLinkedList(struct Node** head);
void displayLinkedList(struct Node** head);
void evaluateLinkedList(struct Node** head);

struct StackArray createArrStack(int capacity) {
    struct StackArray stack;
    stack.capacity = capacity;
    stack.top = -1;
    stack.array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int Stacks(); 
int stack_linkedList(); 
int stack_arr();

void pushArr(struct StackArray* stack, int data);
int popArr(struct StackArray* stack);
int peekArr(struct StackArray* stack);
int isFullArr(struct StackArray* stack);
int isEmptyArr(struct StackArray* stack);
void displayArray(struct StackArray* stack);
int getPrecedence(char op);
void evaluateInfixArr(struct StackArray* stack, char* infix);
void evaluatePostfixArr(struct StackArray* stack, char* postfix);
void infixToPostfix(struct StackArray* operatorStack, char* infix, char* postfix);
void infixToPostfixLinkedList(struct Node** operatorStack, char* infix, char* postfix);
void evaluatePostfixLinkedList(struct Node** stack, char* postfix);
void evaluateInfixLinkedList(struct Node** stack, char* infix);

//array
void array(); 
int deletionArr (int [], int); 
void insertionArr (int[], int, int); 
void searchArr (int[], int); 
void sortArr (int[], int); 
void reverseArr (int [], int); 

//linked list
void LinkedList(); 
struct Node1 {
    int data;
    struct Node1* next;
};
void traverseLinkedList(struct Node1* head);
void insertNode(struct Node1** head, int data, int position);
void deleteNode(struct Node1** head, int position);
void searchNode(struct Node1* head, int key);


int main() {
    MainMenu();
    return 0;
}

void MainMenu() {
    char choice;
    printf("\n\n\t\t\t\t\t ---------------------------------------------");
    printf("\n\n\t\t\t\t\t |                                           |");
    printf("\n\n\t\t\t\t\t | Welcome to Data Structures and Algorithms |");
    printf("\n\n\t\t\t\t\t |                                           |");
    printf("\n\n\t\t\t\t\t ---------------------------------------------");

    printf("\n\n\t\t\t\t\t ---------------------------------------------");
    printf("\n\n\t\t\t\t\t |                                           |");
    printf("\n\n\t\t\t\t\t |            M A I N  M E N U               |");
    printf("\n\n\t\t\t\t\t |                                           |");
    printf("\n\n\t\t\t\t\t ---------------------------------------------");
    printf("\n\n\t\t\t\t\tA. Linear Data Structures\n\t\t\t\t\tB. Non-Linear Data Structure\n\t\t\t\t\tC. Quit\n");
    do {
        printf("\n\t\t\t\t\t\t\t\tPlease choose a letter: ");
        if (scanf(" %c", &choice) != 1) {
            printf("Invalid input. Please enter a letter.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
            continue;
        }
        switch (toupper(choice)) {
        case 'A':
            system("cls");
            LDS();
            break;

        case 'B':
            system("cls");
            NLDS();
            break;

        case 'C':
            system("cls");
            exit(0);
            break;

        default:
            system("cls");
            printf("\n\t\t\tInvalid! Try again.\n");
            Sleep(2000);
            system("cls");
            MainMenu();
            break;
        }
    } while (1);
}

void LDS() {
    int choice;
    do {
        printf("\n\t\t\t\t\t ---------------------------------------------");
        printf("\n\t\t\t\t\t |                                           |");
        printf("\n\t\t\t\t\t |          Linear Data Structures           |");
        printf("\n\t\t\t\t\t |                                           |");
        printf("\n\t\t\t\t\t ---------------------------------------------");
        printf("\n\t\t\t\t\t ---------------------------------------------");
        printf("\n\t\t\t\t\t |                                           |");
        printf("\n\t\t\t\t\t |            M A I N  M E N U               |");
        printf("\n\t\t\t\t\t |                                           |");
        printf("\n\t\t\t\t\t ---------------------------------------------");
        printf("\n\n\t\t\t\t\t\t1. String\n\t\t\t\t\t\t2. Arrays\n\t\t\t\t\t\t3. Linked List\n\t\t\t\t\t\t4. Stacks\n\t\t\t\t\t\t5. Queues\n\t\t\t\t\t\t6. Back to Main Menu");
        printf("\n\n\t\t\t\t\t\tPlease choose a number: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            system("cls");
            String();
            break;

        case 2:
            system("cls");
            array(); 
            break;

        case 3:
            system("cls");
            LinkedList(); 
            break;

        case 4:
            system("cls");
            Stacks(); 
            break;
        case 5:
            system("cls");
            break;

        case 6:
            system("cls");
            Sleep(2000);
            MainMenu();
            break;

        default:
            system("cls");
            printf("\n\n\n\n\t\t\t\t\t\t\tInvalid! Try again.\n");
            Sleep(2000);
            system("cls");
            LDS();
            break;
        }
    } while (choice < 6);
    printf("\n");
}

void NLDS() {
    int choice;
    do {
        printf("\n\t\t\t\t\t ---------------------------------------------");
        printf("\n\t\t\t\t\t |                                           |");
        printf("\n\t\t\t\t\t |        Non Linear Data Structures         |");
        printf("\n\t\t\t\t\t |                                           |");
        printf("\n\t\t\t\t\t ---------------------------------------------");
        printf("\n\t\t\t\t\t ---------------------------------------------");
        printf("\n\t\t\t\t\t |                                           |");
        printf("\n\t\t\t\t\t |            M A I N  M E N U               |");
        printf("\n\t\t\t\t\t |                                           |");
        printf("\n\t\t\t\t\t ---------------------------------------------");
        printf("\n\n\t\t\t\t\t\t1. Graphs\n\t\t\t\t\t\t2. Trees\n\t\t\t\t\t\t3. Back to Main Menu");
        printf("\n\n\t\t\t\t\t\tPlease choose a number: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            system("cls");
            break;

        case 2:
            system("cls");
            break;

        case 3:
            system("cls");
            Sleep(2000);
            MainMenu();
            break;

        default:
            system("cls");
            printf("\n\t\t\tInvalid! Try again.\n");
            Sleep(2000);
            system("cls");
            NLDS();
            break;
        }
    } while (choice < 3);
    printf("\n");
}

int String() {
    char str[SIZE];
    char str2[SIZE];
    int numChoice;
    int stop = 0;

    printf("\nEnter a string: ");
    scanf(" %[^\n]100s", str);

    while (stop == 0) {
        printf("\n\t\t\t\t\tEnter what you want to do: \n");
        printf("\n\t\t\t\t\t\t\t1. Traverse the string\n\t\t\t\t\t\t\t2. Insert a character in the string\n\t\t\t\t\t\t\t 3. Delete a character in the string\n\t\t\t\t\t\t\t 4. Concatenate a second string to the first string\n\t\t\t\t\t\t\t 5. Find the length of the string\n\t\t\t\t\t\t\t 6. Create a substring out of the current string\n\t\t\t\t\t\t\t 7. Append a string to the current string\n\t\t\t\t\t\t\t 8. Copy the string\n\t\t\t\t\t\t\t 9. Compare the string to another string\n\t\t\t\t\t\t\t 10. Close the program\n");
        printf("\nPlease enter your choice here: ");
        scanf("%d", &numChoice);

        switch (numChoice) {
        case 1:
            traverseString(str);
            break;

        case 2:
            insertString(str);
            break;

        case 3:
            deletionString(str);
            break;

        case 4:
            concatenateString(str);
            break;

        case 5:
            printf("\nSize of the string: %d\n", lengthString(str));
            break;

        case 6:
            substring(str);
            break;

        case 7:
            appendString(str);
            break;

        case 8:
            copyString(str, str2);
            break;

        case 9:
            compareString(str);
            break;

        case 10:
            printf("\nThank you for using the program.");
            stop = 1;
            break;

        default:
            printf("\nInvalid choice.\n");
        }
    }
    return 0;
}

void copyString(char str[], char str2[]){
    getchar();
    str2 = strcpy(str2, str);
    printf("Another string value now contains the string: %s", str2);
}

void compareString(char str[]){
    getchar();
    char str2[SIZE];
    printf("\nPlease enter another string to compare to the first string here: ");
    scanf("%[^\n]100s", str2);

    int same = strcmp(str, str2);

    if(same == 0)
        printf("\nThe two strings are equal");

    else
        printf("\nThey are not equal");
}

void concatenateString(char str[]){
    getchar();
    char str2[SIZE];
    printf("\nPlease enter another string to append to the first string here: ");
    scanf("%[^\n]100s", str2);

    str = strcat(str,str2);
}

int lengthString(char str[SIZE]) {
    int size = 0;

    while (str[size] != '\0') {
        size++;
    }
    return size;
}

void appendString(char str[]){
    getchar();
    char ch;

    printf("\nPlease enter a character to append to the String here: ");
    scanf("%c", &ch);

    int size = (lengthString(str) - 1);
    
	int i;
    for(i = 0; i <= size; i++){
        if(i == size){
            str[i + 1] = ch;
            str[(i + 1) + 1] = '\0';
        }
    }
}

void traverseString(char str[SIZE]) {
	int i;
    for (i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
}

void insertString(char str[]){
    int position;
    char ch;
    printf("\nEnter the character to be inserted in the string: ");
    scanf(" %c", &ch);
    printf("\nEnter the position at which character %c is to be inserted: ", ch);
    scanf(" %d", &position);
    int size = lengthString(str);
    if (position < 0 || position > size) {
        printf("\nInvalid position for insertion.");
        return;
    }

    int i;
	for (i = size; i >= position; i--) {
        str[i + 1] = str[i];
    }
    str[position] = ch;
    printf("\nThe new string: %s", str);
}

void deletionString(char str[]) {
    int size = lengthString(str);
    int position;
    printf("\nEnter the position at which the character is to be deleted: ");
            scanf(" %d", &position);
    while (position < 0 || position >= size) {
        printf("\nInvalid position for deletion.\n");
        printf("\nPlease enter a valid position: ");
        scanf("%d", &position);
        return;
    }
    
	int i;
    for (i = position; i < size; i++) {
        str[i] = str[i + 1];
    }
    printf("\nThe new string: %s", str);
}

void substring(char str[]){
    int from, to;
    int size = lengthString(str);

    printf("\nPlease enter the index where the substring will start: ");
    scanf("%d", &from);

    printf("\nPlease enter the index where the substring will end: ");
    scanf("%d", &to);

    if(from >= 0 && from < to && to <= size){
        printf("\nThis is the substring: ");
        int i;
        for(i = from; i <= to; i++){
            printf("%c", str[i]);
        }

        printf("\n");
    }
    
    else 
        printf("\tInvalid substring position/s.\n");
}

int Stacks() {
    int ch;

    do {
        printf("\n\n\t\t\t\t\tStack Operations");
        printf("\n\t\t\t\t\tMain Menu");
        printf("\n\t\t\t\t\t\t1. Array\n\t\t\t\t\t\t2. Linked List\n\t\t\t\t\t\t3. Quit");
        printf("\n\t\t\t\t\t\t\tPlease choose a number: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                system("cls");
                stack_arr();
                break;

            case 2:
                system("cls");
                stack_linkedList();
                break;

            case 3:
                system("cls");
                exit(0);
                break;

            default:
                system("cls");
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (ch != 3);
}


int stack_arr() {
    char ch;
    int capacity, data;
    struct StackArray ArrayStack;

    printf("\n\n\n\n\t\t\tEnter the capacity of the Array Stack: ");
    scanf("%d", &capacity);

    ArrayStack = createArrStack(capacity);

    while (1) {
        system("cls");
        displayArray(&ArrayStack);
        printf("\n\n\t\t\t\t\tArray Stack Operations");
        printf("\n\t\t\t\t\tMenu");
        printf("\n\t\t\t\t\t\tA. Push\n\t\t\t\t\t\tB. Pop\n\t\t\t\t\t\tC. Peek\n\t\t\t\t\t\tD. Evaluate expression");
        printf("\n\t\t\t\t\t\t\tPlease choose a letter (X to exit): ");
        scanf(" %c", &ch);
        system("cls");

        if (toupper(ch) == 'X') {
            break;
        }

        switch (toupper(ch)) {
            case 'A':
                system("cls");
                printf("\n\n\n\n\t\t\tEnter element to push in the stack: ");
                scanf("%d", &data);
                pushArr(&ArrayStack, data);
                printf("Pushed: %d", data);
                break;

            case 'B':
                system("cls");
                printf("Popped: %d", popArr(&ArrayStack));
                break;

            case 'C':
                system("cls");
                printf("Peeked: %d", peekArr(&ArrayStack));
                break;

            case 'D':
                system("cls");
                char infixExpression[100];
                char postfixExpression[100];
                printf("\n\n\n\n\t\t\tEnter infix expression: ");
                scanf(" %99[^\n]", infixExpression);
                evaluateInfixArr(&ArrayStack, infixExpression);
                break;

            default:
                system("cls");
                printf("\n\t\t\tInvalid option! Please try again.\n");
                break;
        }
        
    }

    return 0;
}

int stack_linkedList() {
    char ch;
    int data;
    struct Node* LinkListStack = createNode(0);

    while (1) {
	    system("cls");    
        displayLinkedList(&LinkListStack); 
        printf("\n\n\t\t\t\t\tLinked List Stack Operations");
        printf("\n\t\t\t\t\tMenu");
        printf("\n\t\t\t\t\t\tA. Push\n\t\t\t\t\t\tB. Pop\n\t\t\t\t\t\tC. Peek\n\t\t\t\t\t\tD. Evaluate Expression");
        printf("\n\t\t\t\t\t\t\tPlease choose a letter (X to exit): ");
        scanf(" %c", &ch);
        system("cls");

        if (toupper(ch) == 'X') {
            break;
        }

        switch (toupper(ch)) {
            case 'A':
            	system("cls");
                printf("\n\n\n\n\t\t\tEnter element to push in the stack: ");
                scanf("%d", &data);
                pushLinkedList(&LinkListStack, data);
                printf("Pushed: %d", data); 
                break;

            case 'B':
            	system("cls");
                printf("Popped: %d\n", popLinkedList(&LinkListStack));
                break;

            case 'C':
            	system("cls");
                printf("Peeked: %d\n", peekLinkedList(&LinkListStack));
                break;
                
			case 'D': 
			    system("cls");
			    char infixExpression[100];
			    printf("\n\n\n\n\t\t\tEnter infix expression: ");
			    scanf(" %99[^\n]", infixExpression);
			    evaluateInfixLinkedList(&LinkListStack, infixExpression);
			    break; 
				
            default:
            	system("cls");
                printf("\n\t\t\tInvalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; 
}

void infixToPostfix(struct StackArray* operatorStack, char* infix, char* postfix) {
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; ++i) {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            --i;
        } else if (infix[i] == '(') {
            pushArr(operatorStack, '(');
        } else if (infix[i] == ')') {
            while (!isEmptyArr(operatorStack) && peekArr(operatorStack) != '(') {
                postfix[j++] = popArr(operatorStack);
                postfix[j++] = ' ';
            }
            popArr(operatorStack);
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!isEmptyArr(operatorStack) && getPrecedence(peekArr(operatorStack)) >= getPrecedence(infix[i])) {
                postfix[j++] = popArr(operatorStack);
                postfix[j++] = ' ';
            }
            pushArr(operatorStack, infix[i]);
        }
    }

    while (!isEmptyArr(operatorStack)) {
        postfix[j++] = popArr(operatorStack);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}

void evaluatePostfixArr(struct StackArray* stack, char* postfix) {
    int i, operand = 0;

    for (i = 0; postfix[i] != '\0'; ++i) {
        if (isdigit(postfix[i])) {
            while (isdigit(postfix[i])) {
                operand = operand * 10 + (postfix[i] - '0');
                ++i;
            }
            --i;
            pushArr(stack, operand);
            operand = 0;
        } else if (postfix[i] == ' ') {
            continue;
        } else {
            int operand2 = popArr(stack);
            int operand1 = popArr(stack);

            switch (postfix[i]) {
                case '+':
                    pushArr(stack, operand1 + operand2);
                    break;
                case '-':
                    pushArr(stack, operand1 - operand2);
                    break;
                case '*':
                    pushArr(stack, operand1 * operand2);
                    break;
                case '/':
                    pushArr(stack, operand1 / operand2);
                    break;
            }
        }
    }
    
    if (!isEmptyArr(stack)) {
        printf("Result: %d\n", peekArr(stack));
    } else {
        printf("Error: Empty stack after evaluation.\n");
    }
}

void evaluateInfixArr(struct StackArray* stack, char* infix) {
    char postfix[100];
    infixToPostfix(stack, infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    evaluatePostfixArr(stack, postfix);
}

void pushArr(struct StackArray* stack, int data) {
    if (isFullArr(stack)) {
        printf("Array Stack Overflow!\n");
        return;
    }
    stack->array[++stack->top] = data;
}

int popArr(struct StackArray* stack) {
    if (isEmptyArr(stack)) {
        printf("Array Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int peekArr(struct StackArray* stack) {
    if (isEmptyArr(stack)) {
        printf("Array Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top];
}

int isFullArr(struct StackArray* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmptyArr(struct StackArray* stack) {
    return stack->top == -1;
}

void displayArray(struct StackArray* stack) {
    printf("\n\n\t\t\tArray Stack: ");
    int i; 
    for (i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}


void pushLinkedList(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

int popLinkedList(struct Node** head) {
    if (*head == NULL) {
        printf("Linked List Underflow\n");
        return -1;
    }

    int pop = (*head)->data;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return pop;
}

int peekLinkedList(struct Node** head) {
    if (*head == NULL) {
        printf("Linked List is empty\n");
        return -1;
    }
    return (*head)->data;
}

int isEmptyLinkedList(struct Node** head) {
    return *head == NULL;
}

void displayLinkedList(struct Node** head) {
    printf("\n\n\t\t\tLinked List Stack: ");
    struct Node* current = *head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void infixToPostfixLinkedList(struct Node** operandStack, char* infix, char* postfix) {
    struct Node* operatorStack = createNode(0);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; ++i) {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            --i;
        } else if (infix[i] == '(') {
            pushLinkedList(&operatorStack, '(');
        } else if (infix[i] == ')') {
            while (!isEmptyLinkedList(&operatorStack) && peekLinkedList(&operatorStack) != '(') {
                postfix[j++] = popLinkedList(&operatorStack);
                postfix[j++] = ' ';
            }
            popLinkedList(&operatorStack);
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!isEmptyLinkedList(&operatorStack) && getPrecedence(peekLinkedList(&operatorStack)) >= getPrecedence(infix[i])) {
                postfix[j++] = popLinkedList(&operatorStack);
                postfix[j++] = ' ';
            }
            pushLinkedList(&operatorStack, infix[i]);
        }
    }

    while (!isEmptyLinkedList(&operatorStack)) {
        postfix[j++] = popLinkedList(&operatorStack);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}

void evaluateInfixLinkedList(struct Node** stack, char* infix) {
    char postfix[100];
    infixToPostfixLinkedList(stack, infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    evaluatePostfixLinkedList(stack, postfix);
} 

void evaluatePostfixLinkedList(struct Node** stack, char* postfix) {
    int i, operand = 0;

    for (i = 0; postfix[i] != '\0'; ++i) {
        if (isdigit(postfix[i])) {
            while (isdigit(postfix[i])) {
                operand = operand * 10 + (postfix[i] - '0');
                ++i;
            }
            --i;
            pushLinkedList(stack, operand);
            operand = 0;
        } else if (postfix[i] == ' ') {
            continue;
        } else {
            int operand2 = popLinkedList(stack);
            int operand1 = popLinkedList(stack);

            switch (postfix[i]) {
                case '+':
                    pushLinkedList(stack, operand1 + operand2);
                    break;
                case '-':
                    pushLinkedList(stack, operand1 - operand2);
                    break;
                case '*':
                    pushLinkedList(stack, operand1 * operand2);
                    break;
                case '/':
                    pushLinkedList(stack, operand1 / operand2);
                    break;
            }
        }
    }
    
   
    if (!isEmptyLinkedList(stack)) {
        printf("Result: %d\n", peekLinkedList(stack));
    } else {
        printf("Error: Empty stack after evaluation.\n");
    }
}

void array (){
		 int size, i, choice, range;   
	 
	 printf("\n\n\t\t\tEnter the size of the array: "); 
	 scanf("%d", &size); 
	 
	 int array[size];
	 
	 printf("\n\t\t\tEnter %d numbers to fill the array: ", size); 
	 for (i=0; i<size; i++){
	 	scanf("%d", &array[i]); 
		 } 
		 
	do{
	printf("\n\t\t\t\t\tPress any key to clear the screen.\n");
	getch();
	system("cls");
	 printf("\n\n\t\t\tEnter you want to do: \n"); 
	 printf("\t\t\t\t1. Delete an element in the array\n \t\t\t\t2. Insert an element in the array\n \t\t\t\t3. Search an element in the array\n \t\t\t\t4. Sort the array\n \t\t\t\t5. Reverse the array\n \t\t\t\t6.Exit\n\t\t\t");
	 scanf("%d", &choice); 
	
	 switch (choice)
	 {
	 	case 1:
		 	printf("\n\t\t\t\t\tPress any key to clear the screen.\n");
			getch();
			system("cls");  
	 		size = deletionArr (array, size);
	 		break; 
	 		
	 	case 2: 
	 		printf("\n\t\t\t\t\tPress any key to clear the screen.\n");
			getch();
			system("cls");
	 		range = sizeof(array)/sizeof(array[0]);
		 	insertionArr (array, size, range); 
			break;
			 
		case 3:
			printf("\n\t\t\t\t\tPress any key to clear the screen.\n");
			getch();
			system("cls");
			searchArr (array, size); 
			break; 
			
		case 4:
			printf("\n\t\t\t\t\tPress any key to clear the screen.\n");
			getch();
			system("cls");
			sortArr (array, size);
			break;
			
		case 5: 
			printf("\n\t\t\t\t\tPress any key to clear the screen.\n");
			getch();
			system("cls");
			reverseArr (array, size);
			
		case 6:
			printf("\n\t\t\t\t\tPress any key to clear the screen.\n");
			getch();
			choice = 6;
			system("cls");  
			break; 
			
		default: 
			printf("\n\t\t\t\t\tPress any key to clear the screen.\n");
			getch();
			system("cls");
			printf("\n\t\t\tInvalid! Try again\n");
			break; 
	 }
	 printf("\n");
}while (choice!=6); 
}

int deletionArr (int array [], int size){
	int i=0, index; 
	
	printf("\n\n\t\t\tThe array contains: "); 
	for (i=0; i<size; i++){
		printf("%d ", array[i]);  
	} 
	
	printf("\n\t\t\t\tNote: The index starts at 0");
	printf("\n\n\t\t\tEnter the index of the element you want to delete: "); 
	scanf("%d", &index);
	
	if (index<0||index>=size){
		printf("\n\t\t\t\tError! Accessing array out of bound."); 
	}
	else {
		for (i=index; i<size-1; i++){
			array[i]=array[i+1]; 
		}
		size--;
	}
 		
	printf("\n\n\t\t\tAfter deleting the element in index %d, the array now contains: ", index); 
	for(i=0; i<size; i++){
		printf("%d ", array[i]); 
	}
	
	return size;   
}
	
void insertionArr(int array[], int size, int range) {
    int i, element, index;
    char choice;
    
    printf("\n\n\t\t\tThe array contains: "); 
	for (i=0; i<size; i++){
		printf("%d ", array[i]);  
	}

    if (range==size) {
        printf("\n\n\t\t\tThe array is full. Do you want to proceed with deleting an element? (Y/N): ");
        scanf("%c", &choice);
            if (choice == 'Y' || choice == 'y') {
                deletionArr (array, size); 
                goto jump;
            } 
			else if (choice == 'N' || choice == 'n') {
                exit(0); 
            }
    } else {
    	jump: 
        printf("\n\n\t\t\tEnter the value of the element you want to insert in the array: ");
    	scanf("%d", &element);
        
        printf("\n\t\t\tEnter the index you want to insert element %d: ", element);
        scanf("%d", &index);
        
        if (index<0 || index >size){
        	printf("\n\t\t\tError! Accessing array out of bound.");
		}
		else{
        for (i = size - 1; i >= index; i--) {
            array[i + 1] = array[i];
        }
        array[index] = element;

        printf("\n\t\t\tAfter inserting %d in index %d, the array now contains: ", element, index);
        for (i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
}
}
}

void searchArr (int array[], int size){
	int i, key, count=0;
	
	printf("\n\n\t\t\tThe array contains: "); 
	for (i=0; i<size; i++){
		printf("%d ", array[i]);  
	}
	
	printf("\n\n\t\t\tEnter the element you want to search: "); 
	scanf("%d", &key); 
	
	for (i=0; i<size; i++){
		if (array[i]==key){
			printf("\n\n\n\t\t\tElement %d is located at index %d.", key, i);
			count=1; 
		}
	}
	if (count==NULL){
		printf("Element %d is not present in the array", key); 
	} 
	 
}

void sortArr (int array [], int size){
	int temp, k, j, i;
	
	printf("\n\n\t\t\tThe array contains: "); 
	for (i=0; i<size; i++){
		printf("%d ", array[i]);  
	}
	
	for (k=0; k<size-1; k++){
		for (j=0; j<size-k-1; j++){
			if (array[j]>array[j+1]){
				temp=array[j]; 
				array[j]=array[j+1]; 
				array[j+1]=temp; 
			} 
		}
	}
	
	printf("\n\n\t\t\tThe sorted array is: "); 
	for (i=0; i<size; i++){
		printf("%d ", array[i]); 
	}
}

void reverseArr (int array [], int size){
	int i, num; 
	
	printf("\n\n\t\t\tThe array contains: "); 
	for (i=0; i<size; i++){
		printf("%d ", array[i]);  
	}
	
	for (i=0; i<size/2; i++){
		num=array[i];
		array[i]=array[size-i-1]; 
		array[size-i-1]=num;
	}

	printf("\n\n\t\t\t\tThe reversed array is: ");
	for (i=0; i<size; i++){
		printf("%d ", array[i]); 
	}
}

void LinkedList () {
    struct Node1* head = NULL;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Traverse the linked list\n");
        printf("2. Insert a node at a specific position\n");
        printf("3. Delete a node from a specific position\n");
        printf("4. Search for an element in the linked list\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverseLinkedList(head);
                break;
            case 2: {
                int data, position;
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertNode(&head, data, position);
                break;
            }
            case 3: {
                int position;
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            }
            case 4: {
                int key;
                printf("Enter the element to search for: ");
                scanf("%d", &key);
                searchNode(head, key);
                break;
            }
            case 5:
                while (head != NULL) {
                    struct Node1* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
}

void traverseLinkedList(struct Node1* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node1* current = head;
    printf("Linked list elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertNode(struct Node1** head, int data, int position) {
    struct Node1* newNode = (struct Node1*)malloc(sizeof(struct Node1));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted at position %d.\n", position);
        return;
    }

    struct Node1* current = *head;
    int i;
    for (i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position. Insertion failed.\n");
    } else {
        newNode->next = current->next;
        current->next = newNode;
        printf("Node inserted at position %d.\n", position);
    }
}

void deleteNode(struct Node1** head, int position) {
    if (*head == NULL) {
        printf("Linked list is empty. Deletion failed.\n");
        return;
    }

    struct Node1* temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", position);
        return;
    }

    struct Node1* prev = NULL;
    int i;
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position. Deletion failed.\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", position);
    }
}

void searchNode(struct Node1* head, int key) {
    struct Node1* current = head;
    int position = 1;
    while (current != NULL && current->data != key) {
        current = current->next;
        position++;
    }

    if (current == NULL) {
        printf("Element %d not found in the linked list.\n", key);
    } else {
        printf("Element %d found at position %d.\n", key, position);
    }
}

