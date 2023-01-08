#include "vector.h"

int main()
{
    vector array;

    Construct(&array, 0, 0);

    push_back(&array, 10LL);
    push_back(&array, 11LL);
    push_back(&array, 12LL);
    push_back(&array, 14LL);
    push_back(&array, 189LL);
    push_back(&array, 19LL);
    push_back(&array, 15LL);
    push_back(&array, 105LL);
    push_back(&array, 1335LL);

    // pop(&array);

    // for (size_t i = 0; i < size(&array); i++)
    // {
    //     printf("\t%lld\n", array.Array[i]);
    // }



    // printf("The front of the vector is = %lld\n", front(&array));
    // printf("The back of the vector is = %lld\n", back(&array));
    // printf("Before shrinking\n");

    // printf("The size of the vector is = %ld\n", size(&array));
    // printf("The capacity of the vector is = %ld\n", capacity(&array));
    shrink_to_fit(&array);
    // printf("After shrinking\n");

    // printf("The size of the vector is = %ld\n", size(&array));
    // printf("The capacity of the vector is = %ld\n", capacity(&array));


    // now if we push an element, the capacity should double the current capacity which is 6. so the next time capacity should become 12. let's test that out!

    push_back(&array, 89);

    forEach(&array);

    // printf("\n\nAfter pushing\n");

    // printf("The size of the vector is = %ld\n", size(&array));
    // printf("The capacity of the vector is = %ld\n", capacity(&array));

    // and indeed it does :D

    Destroy(&array);

    printf("\n");
    

}