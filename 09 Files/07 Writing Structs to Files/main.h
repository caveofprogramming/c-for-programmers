#pragma pack(push,1)

typedef struct
{
    float v1;
    char v2;
} data_t;

#pragma pack(pop)

void fill_struct(data_t *s)
{
    s->v1 = 1.234f;
    s->v2 = 'H';
}

void print_struct(data_t *s)
{
    printf("%.3f: %c\n", s->v1, s->v2);
}
