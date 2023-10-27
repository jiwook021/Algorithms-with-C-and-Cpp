#include <stdio.h>

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
int main()
{
    printf("%d\n", reversebit(12)); //0xb00001100 = 12, 0xb00110000 = 48 
    printf("%d\n", bitExtracted(108,4,3));//0x10101100 , 0x000000110 6
}