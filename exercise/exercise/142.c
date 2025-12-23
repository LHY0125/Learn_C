#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    char name[32];
    char gender[4];
    char birth[16];
    int zip;
    char addr[64];
    long long qq;
    long long phone;
    struct Node *next;
} Node;

static void read_rec(Node *p)
{
    char g[8];
    scanf("%d %31s %7s %15s %d %63s %lld %lld", &p->id, p->name, g, p->birth, &p->zip, p->addr, &p->qq, &p->phone);
    strcpy(p->gender, g);
}

static void print_rec(Node *p)
{
    printf("%d %s %s %s %d %s %lld %lld\n", p->id, p->name, p->gender, p->birth, p->zip, p->addr, p->qq, p->phone);
}

int main(void)
{
    int cnt; if (scanf("%d", &cnt) != 1) return 0;
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < cnt; ++i)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        read_rec(p); p->next = NULL;
        if (!head) head = tail = p; else { tail->next = p; tail = p; }
    }
    int op; scanf("%d", &op);
    if (op == 1)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        read_rec(p); p->next = NULL;
        if (!head) head = tail = p; else { tail->next = p; tail = p; }
        printf("The records is:\n");
        int sz = 0; for (Node *q = head; q; q = q->next) ++sz;
        Node **arr = (Node **)malloc((size_t)sz * sizeof(Node *));
        int idx = 0; for (Node *q = head; q; q = q->next) arr[idx++] = q;
        for (int i = sz - 1; i >= 0; --i) print_rec(arr[i]);
        free(arr);
    }
    else if (op == 2)
    {
        int did; scanf("%d", &did);
        Node *prev = NULL, *cur = head;
        while (cur && cur->id != did) { prev = cur; cur = cur->next; }
        if (cur)
        {
            if (prev) prev->next = cur->next; else head = cur->next;
            if (tail == cur) tail = prev;
            free(cur);
        }
        printf("The records is:\n");
        int sz = 0; for (Node *q = head; q; q = q->next) ++sz;
        Node **arr = (Node **)malloc((size_t)sz * sizeof(Node *));
        int idx = 0; for (Node *q = head; q; q = q->next) arr[idx++] = q;
        for (int i = sz - 1; i >= 0; --i) print_rec(arr[i]);
        free(arr);
    }
    else if (op == 3)
    {
        int fid; scanf("%d", &fid);
        Node *cur = head;
        while (cur && cur->id != fid) cur = cur->next;
        if (cur) print_rec(cur); else printf("not found\n");
    }
    else if (op == 4)
    {
        printf("The records is:\n");
        int sz = 0; for (Node *q = head; q; q = q->next) ++sz;
        Node **arr = (Node **)malloc((size_t)sz * sizeof(Node *));
        int idx = 0; for (Node *q = head; q; q = q->next) arr[idx++] = q;
        for (int i = sz - 1; i >= 0; --i) print_rec(arr[i]);
        free(arr);
    }
    for (Node *q = head; q; ) { Node *nq = q->next; free(q); q = nq; }
    return 0;
}