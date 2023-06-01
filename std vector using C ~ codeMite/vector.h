#include <stdio.h>
#include <stdlib.h>
// #include <inttypes.h> // not needed for clang

typedef struct
{
    size_t Size, Capacity;
    int64_t *Array;
} vector;

vector *Construct(vector *self, size_t _size, int64_t _value)
{
    self->Size = self->Capacity = _size;
    self->Array = (int64_t*)malloc(sizeof(int64_t) * self->Capacity);
    for (size_t i = 0; i < _size; i++)
        self->Array[i] = _value;
    return self;    
}

void push_back(vector *self, int64_t _data)
{
    if (!self->Size)
    {
        self->Size = self->Capacity = 1;
        self->Array = (int64_t *)malloc(sizeof(int64_t) * self->Capacity);
        self->Array[0] = _data;
    }
    else if (self->Size == self->Capacity)
    {
        self->Capacity *= 2;
        int64_t *pkr_mery_ko = (int64_t *)malloc(sizeof(int64_t) * self->Capacity);
        for (size_t i = 0; i < self->Size; i++)
            pkr_mery_ko[i] = self->Array[i];

        free(self->Array);
        self->Array = pkr_mery_ko;
        self->Array[self->Size++] = _data;        
    }
    else self->Array[self->Size++] = _data;
}

size_t size(vector *self)
{
    return self->Size;
}

size_t capacity(vector *self)
{
    return self->Capacity;
}

void pop(vector *self)
{
    if (!self->Size) return;
    self->Array[--self->Size] = 0;
}

int64_t front(vector *self)
{
    if (self->Size) return self->Array[0];
    else return -1; // for empty vector
}

int64_t back(vector *self)
{
    if (self->Size) return self->Array[self->Size - 1];
    else return -1; // for empty vector
}

void shrink_to_fit(vector *self)
{
    if (!self->Size || self->Size == self->Capacity) return;
    
    int64_t *pkr_mery_ko = (int64_t *)malloc(sizeof(int64_t) * self->Size); // because shrinking does that
    for (size_t i = 0; i < self->Size; i++)
            pkr_mery_ko[i] = self->Array[i];
    
    free(self->Array);
    self->Array = pkr_mery_ko;
    self->Capacity = self->Size;
}

void *Destroy(vector *self)
{
    free(self->Array);
    self->Array = NULL;
    return self->Array;
}

void forEach(vector *self)
{
    if (!self->Size) return;
    printf("\n\n======= DISPLAYING THE VECTOR =======\n\n\n");
    for (size_t i = 0; i < self->Size; i++)
        printf("\t %ld.\t%lld\n", i + 1, self->Array[i]);

    printf("\n\n===== THE END OF VECTOR =====\n\n\n");
}
