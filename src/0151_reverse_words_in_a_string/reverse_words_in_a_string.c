#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _List
{
    char *str;
    struct _List *next;
    struct _List *prev;
} List;

List *split(char *s, int *wordCount, int *size)
{
    *wordCount = 0;
    *size = 0;

    List *head = NULL;
    List *p = head;
    int i = 0;
    for (; i < strlen(s);)
    {
        if (s[i] == ' '/* || s[i] == '\n' || s[i] == '\t'*/)
        {
            i++;
            continue;
        }

        char str[1024] = {0};
        memset(str, 0, sizeof(str));
        int idx = 0;
        while (i < strlen(s) && !(s[i] == ' ' /*|| s[i] == '\n' || s[i] == '\t'*/))
        {
            str[idx++] = s[i];
            i++;
        }
        if (strlen(str) > 0)
        {
            (*wordCount)++;
            (*size) += strlen(str);
            if (NULL == head)
            {
                head = (List *)malloc(sizeof(List));
                head->next = NULL;
                head->prev = NULL;
                head->str = (char *)malloc(strlen(str) + 1);
                strcpy(head->str, str);
                p = head;
            }
            else
            {
                p->next = (List *)malloc(sizeof(List));
                p->next->next = NULL;
                p->next->prev = p;
                p->next->str = (char *)malloc(strlen(str) + 1);
                strcpy(p->next->str, str);
                p = p->next;
            }
        }
    }
    return head;
}

char *reverseWords(char *s)
{
    int wordCount = 0;
    int size = 0;
    List* words = split(s, &wordCount, &size);
    List* tail = words;

    // size + 1 是字符串长度和 1个字节'\0' ; wordCount - 1是空格数量
    int resultSize = size + 1 + wordCount - 1 ;
    char* result = (char *)malloc(resultSize);
    memset(result, 0, resultSize);
    for( ;tail->next != NULL; tail = tail->next) {
    }

    // 从链表末尾开始遍历
    int pos = 0;
    for(List *p = tail; p != NULL;)
    {
        memcpy(result + pos, p->str, strlen(p->str));
        pos += strlen(p->str);
        if(p->prev != NULL) {
            result[pos] = ' ';
            pos++;
        }

        // 释放List内存
        List *tmp = p;
        p = p->prev;
        free(tmp);
        tmp = NULL;
    }

    return result;
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    if(NULL == fp) {
        printf("open input.txt error\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int totalSize = ftell(fp);
    char *str = (char *)malloc(totalSize + 1);
    memset(str, 0, sizeof(totalSize + 1));
    fseek(fp, 0, SEEK_SET);
    int pos = 0;
    while(1)
    {
        int size = fread(str + pos, 1, 1024, fp);
        pos += size;
        if(0 == size) {
            break;
        }
    }

    // 如果最后一个字符是\n
    if('\n' == str[pos-1]) str[pos-1] = '\0';

    char *result = reverseWords(str);

    FILE *fpOut = fopen("output.txt", "w");
    if(NULL == fpOut) {
        printf("create file error\n");
        return 3;
    }

    fprintf(fpOut, "%s", result);
    fclose(fpOut);

    // printf("%s\n", result);
    // 释放内存
    free(str);
    free(result);
    result = NULL;

    return 0;
}