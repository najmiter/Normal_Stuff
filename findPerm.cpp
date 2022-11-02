#include <iostream>
#include <cstring>

void printPerm(char s[], int low, int high)
{
    if (low == high)
        std::cout << s << std::endl;
    else
    {
        for (int i = low; i <= high; i++)
        {
            std::swap(s[low], s[i]);
            printPerm(s, low + 1, high);
            std::swap(s[low], s[i]);
        }
    }
}

int main()
{
    char s[] = "ABCD";
    printPerm(s, 0, strlen(s) - 1);
}
