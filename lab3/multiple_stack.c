#include <stdio.h>

#define SIZE 50       // Total size of the big array
#define NUM_STACKS 3  // Number of stacks

typedef struct {
    int arr[SIZE];      // Big array to store all stack elements
    int top[NUM_STACKS];  // Array to store top index of each stack
    int start[NUM_STACKS]; // Array to store starting index of each stack
    int stack_size[NUM_STACKS]; // Array to store size of each stack
} MultiStack;

// Function to initialize the multi-stack structure
void initialize(MultiStack *ms, int sizes[]) {
    int offset = 0;

    for (int i = 0; i < NUM_STACKS; i++) {
        ms->start[i] = offset;              // Starting index for each stack
        ms->top[i] = ms->start[i] - 1;      // Initialize top to just before the start
        ms->stack_size[i] = sizes[i];       // Set size for each stack
        offset += sizes[i];                 // Move the offset for the next stack
    }
}

// Function to check if a stack is full
int isFull(MultiStack *ms, int stack_num) {
    return ms->top[stack_num] == (ms->start[stack_num] + ms->stack_size[stack_num] - 1);
}

// Function to check if a stack is empty
int isEmpty(MultiStack *ms, int stack_num) {
    return ms->top[stack_num] < ms->start[stack_num];
}

// Function to push a value to a specific stack
void push(MultiStack *ms, int stack_num, int val) {
    if (isFull(ms, stack_num)) {
        printf("Stack %d is full\n", stack_num + 1);
    } else {
        ms->top[stack_num]++;
        ms->arr[ms->top[stack_num]] = val;
        printf("Pushed %d to Stack %d\n", val, stack_num + 1);
    }
}

// Function to pop a value from a specific stack
int pop(MultiStack *ms, int stack_num) {
    if (isEmpty(ms, stack_num)) {
        printf("Stack %d is empty\n", stack_num + 1);
        return -1;
    } else {
        int val = ms->arr[ms->top[stack_num]];
        ms->top[stack_num]--;
        printf("Popped %d from Stack %d\n", val, stack_num + 1);
        return val;
    }
}

// Function to display the top element of a specific stack
void peek(MultiStack *ms, int stack_num) {
    if (isEmpty(ms, stack_num)) {
        printf("Stack %d is empty\n", stack_num + 1);
    } else {
        printf("Top element of Stack %d is %d\n", stack_num + 1, ms->arr[ms->top[stack_num]]);
    }
}

int main() {
    MultiStack ms;

    // Array to specify the size of each stack
    int sizes[NUM_STACKS] = {20, 15, 10};  // Stack 1: 20 elements, Stack 2: 15, Stack 3: 10

    // Initialize the multi-stack structure with different sizes
    initialize(&ms, sizes);

    int choice, stack_num, val;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        printf("Enter stack number (1-%d): ", NUM_STACKS);
        scanf("%d", &stack_num);
        stack_num--;  // Adjust for 0-based index

        if (stack_num < 0 || stack_num >= NUM_STACKS) {
            printf("Invalid stack number!\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&ms, stack_num, val);
                break;
            case 2:
                pop(&ms, stack_num);
                break;
            case 3:
                peek(&ms, stack_num);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

