#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @element: 栈插入和取出的元素实例
 * @top_ele: 指向栈顶的元素
 */
struct node {
    int element;
    struct node *top_ele;
};

enum {
    STACK_NULL,
    STACK_EMPTY,
    STACK_NOT_EMPTY
};

/**
 * @stack: 需要判空的栈
 * @return: 返回STACK_EMPTY表示栈为空，返回STACK_NOT_EMPTY表示栈不为空，
 *          返回STACK_NULL表示入参stack为空
 */
int is_empty(struct node *stack)
{
    if (stack == NULL) {
        printf("stack is NULL\n");
        return STACK_NULL;
    }

    if (stack->top_ele == NULL) {
        return STACK_EMPTY;
    }

    return STACK_NOT_EMPTY;
}

/**
 * @function：创建一个空的栈
 * @return: 创建成功返回创建好的栈，创建失败返回NULL
 */
struct node *create_stack(void)
{
    struct node *tmp_node;

    tmp_node = malloc(sizeof(struct node));
    if (tmp_node == NULL) {
        printf("node malloc error\n");
        return NULL;
    }

    tmp_node->element = 0;
    tmp_node->top_ele = NULL;

    return tmp_node;
}

/**
 * @stack: 要处理的栈
 * @element: 要入栈的元素
 * @function: 将一个元素入栈
 * @return: 成功返回0，失败返回-1
 */
int push(struct node *stack, int element)
{
    struct node *tmp_node = NULL;

    if (stack == NULL) {
        printf("stack is NULL\n");
        return -1;
    }

    tmp_node = malloc(sizeof(struct node));
    if (tmp_node == NULL) {
        printf("node malloc error\n");
        return -1;
    }

    tmp_node->element = element;
    tmp_node->top_ele = stack->top_ele;
    stack->top_ele = tmp_node;

    return 0;
}

/**
 * @stack: 要处理的栈
 * @function: 将栈顶元素出站
 * @return: 成功返回0，失败返回-1
 *
 */
int pop(struct node *stack)
{
    struct node *tmp_node;

    if (is_empty(stack) != STACK_NOT_EMPTY) {
        printf("stack is empty or NULL\n");
        return -1;
    }

    tmp_node = stack->top_ele;
    stack->top_ele = stack->top_ele->top_ele;
    free(tmp_node);

    return 0;
}

/**
 * @stack: 要处理的栈
 * @function: 打印栈顶元素
 * @return: 成功打印返回0，失败返回-1
 */
int print_top(struct node *stack)
{
    if (is_empty(stack) != STACK_NOT_EMPTY) {
        printf("stack is empty or NULL\n");
        return -1;
    }

    printf("top element is %d\n", stack->top_ele->element);

    return 0;
}

/**
 * @stack: 要处理的栈
 * @function: 打印整个栈
 * @return: 成功打印返回0，失败返回-1
 */
int print_stack(struct node *stack)
{
    if (is_empty(stack) != STACK_NOT_EMPTY) {
        printf("stack is empty or NULL\n");
        return -1;
    }

    while (stack->top_ele != NULL) {
        printf("%d\n", stack->top_ele->element);
        stack = stack->top_ele;
    }

    return 0;
}

/**
 * @stack: 要处理的栈
 * @element: 存储栈顶元素
 * @function: 获取栈顶元素
 * @return: 获取成功返回0，失败返回-1
 */
int get_top(struct node *stack, int *element)
{
    if (is_empty(stack) != STACK_NOT_EMPTY) {
        printf("stack is empty or NULL\n");
        return -1;
    }

    *element = stack->top_ele->element;
    
    return 0;
}

/**
 * @function: 测试用
 */
int main(int argc, char *argv[])
{
    struct node *stack = NULL;
    int ret;
    int tmp_ele;

    stack = create_stack();
    if (stack == NULL) {
        printf("stack create failed\n");
    }

    ret = is_empty(stack);
    printf("ret = %d\n", ret);

    ret = push(stack, 10);
    printf("ret = %d\n", ret);

    ret = pop(stack);
    printf("ret = %d\n", ret);

    ret = is_empty(stack);
    printf("ret = %d\n", ret);

    ret = pop(stack);
    printf("ret = %d\n", ret);

    ret = is_empty(stack);
    printf("ret = %d\n", ret);

    ret = push(stack, 20);
    printf("ret = %d\n", ret);

    print_top(stack);

    push(stack, 30);

    print_top(stack);

    get_top(stack, &tmp_ele);
    printf("tmp ele is: %d\n", tmp_ele);

    push(stack, 100);

    print_stack(stack);

    return 0;
}

