#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int *mins;
    int top;     // index of next insertion in data
    int mtop;    // index of next insertion in mins
    int cap;     // capacity
} MinStack;

static void ms_init(MinStack *s, int cap) {
    s->data = (int *)malloc(sizeof(int) * cap);
    s->mins  = (int *)malloc(sizeof(int) * cap);
    s->top = 0;
    s->mtop = 0;
    s->cap = cap;
}

static int ms_empty(const MinStack *s) { return s->top == 0; }

static void ms_push(MinStack *s, int x) {
    // Assume total pushes won't exceed cap per problem constraints
    s->data[s->top++] = x;
    if (s->mtop == 0 || x <= s->mins[s->mtop - 1]) {
        s->mins[s->mtop++] = x;
    }
}

static void ms_pop(MinStack *s) {
    if (s->top == 0) return; // ignore if empty
    int v = s->data[s->top - 1];
    s->top--;
    if (s->mtop > 0 && v == s->mins[s->mtop - 1]) {
        s->mtop--;
    }
}

static int ms_top(const MinStack *s) {
    return s->data[s->top - 1];
}

static int ms_get_min(const MinStack *s) {
    return s->mins[s->mtop - 1];
}

static void ms_free(MinStack *s) {
    free(s->data);
    free(s->mins);
    s->data = s->mins = NULL;
    s->top = s->mtop = s->cap = 0;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    MinStack st;
    ms_init(&st, n > 0 ? n : 1);

    for (int i = 0; i < n; ++i) {
        int t; 
        if (scanf("%d", &t) != 1) t = 0;
        if (t == 1) {
            int x; 
            scanf("%d", &x);
            ms_push(&st, x);
        } else if (t == 2) {
            ms_pop(&st);
        } else if (t == 3) {
            if (!ms_empty(&st)) {
                printf("%d\n", ms_top(&st));
            }
        } else if (t == 4) {
            if (!ms_empty(&st)) {
                printf("%d\n", ms_get_min(&st));
            }
        } else {
            // ignore unknown command
        }
    }

    ms_free(&st);
    return 0;
}