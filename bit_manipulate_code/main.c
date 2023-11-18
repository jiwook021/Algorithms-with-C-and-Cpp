#include <stdio.h>
#include <stdbool.h>

char reversebit(char input)
{
    char output = 0;
    int sz= sizeof(input)*8;
    for(int i = sz; i>0;i--)
    {
        if(input & 1<<i)   //00001100    // 00000100 = 4
        {
            output |= 1<<(sz-1-i); // 8-3-1  = 00000000 |= 00010000 = 00010000, // 8-3-1  = 00010000 |= 00001000 = 00011000,  
        }
    }
    return output; 
}
int bitExtracted(int number, int k, int s)
{
    //1<<e 10000-1 = 1111 &  00001011 = 1011
    return (((1 << k) - 1) & (number >> (s - 1)));
}

unsigned int swapBits(unsigned int n, int p1, int p2) {
    /* Move p1'th to rightmost side */
    unsigned int bit1 = (n >> p1) & 1;
    /* Move p2'th to rightmost side */
    unsigned int bit2 = (n >> p2) & 1;
    /* XOR the two bits */
    unsigned int x = (bit1 ^ bit2);
    /* Put the xor bit back to their original positions */
    x = (x << p1) | (x << p2);//바꿔주는 연산자
    /* XOR 'n' with 'x' */
    unsigned int result = n ^ x;
    return result;
}
void swap()
{
    unsigned int n = 28; // Binary: 11100
                        //      x ^ 01001
                        //          10101 =21
    int p1 = 0, p2 = 3;
    // Swap bits in 'n' at position 'p1' and 'p2'
    unsigned int result = swapBits(n, p1, p2);
    printf("Result after swapping bits: %u \n", result);
}

int reverseDigits(int num) {
    int reversedNum = 0;
    while (num != 0) {
        reversedNum = reversedNum * 10 + num % 10; //3 321
        num /= 10;//12,1 
    }
    return reversedNum;
}

int isPalindrome(int num) {
    if (num < 0) {
        // 음수는 팰린드롬이 아님
        return -1;
    }
    int reversed = reverseDigits(num);
    return num == reversed;
}

void reversedigit()
{
    int num = 123;
    int result = reverseDigits(num);
    printf("원래의 숫자: %d\n", num);
    printf("뒤집힌 숫자: %d\n", result);
    return;
}
void pelindrome()
{
    int num = 12321;
    if (isPalindrome(num)) {
        printf("%d 는 팰린드롬입니다.\n", num);
    } else {
        printf("%d 는 팰린드롬이 아닙니다.\n", num);
    }
}
double power(double a, int x) {
    double result = 1.0;
    for (int i = 0; i < x; ++i) {
        result *= a;
    }
    return result;
}
typedef struct {
    int x;  // 왼쪽 아래 꼭짓점의 x 좌표
    int y;  // 왼쪽 아래 꼭짓점의 y 좌표
    int width;
    int height;
} Rectangle;



// 최소값을 계산하는 함수
int min(int a, int b) {
    return (a < b) ? a : b;
}

// 최대값을 계산하는 함수
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 두 직사각형의 교차 영역을 계산하는 함수
bool intersect(Rectangle r1, Rectangle r2, Rectangle *intersection) {
    // 두 직사각형이 교차하는지 확인
    int xOverlap = min(r1.x + r1.width, r2.x + r2.width) - max(r1.x, r2.x);
    int yOverlap = min(r1.y + r1.height, r2.y + r2.height) - max(r1.y, r2.y);

    if (xOverlap > 0 && yOverlap > 0) {
        // 교차 영역 계산
        intersection->x = max(r1.x, r2.x);
        intersection->y = max(r1.y, r2.y);
        intersection->width = xOverlap;
        intersection->height = yOverlap;
        return true;
    }

    // 교차하지 않는 경우
    return false;
}

void intersectionofRectangle()
{
    Rectangle r1 = {0, 0, 4, 4};
    Rectangle r2 = {2, 2, 4, 4};
    Rectangle intersection;

    if (intersect(r1, r2, &intersection)) {
        printf("교차 영역: x = %d, y = %d, width = %d, height = %d\n",
               intersection.x, intersection.y, intersection.width, intersection.height);
    } else {
        printf("교차하지 않습니다.\n");
    }
}
int main()
{
    // printf("%d\n", reversebit(12)); //0xb00001100 = 12, 0xb00110000 = 48 
    // printf("%d\n", bitExtracted(108,4,3));//0x10101100 , 0x000000110 6
    //swap();
    //reversedigit();
}