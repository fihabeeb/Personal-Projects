#include <stdio.h>

int solution(int N) {
    // Implement your solution here
    float num = N;
    int index = 0;
    int binary = 0;
    while (num > 1.0)
    {
        num = num / 2;
        printf("%f ",num);
    }
    printf("%f",num);
    return num;
}

int main()
{
    printf("Answer: %i",solution(9));
}