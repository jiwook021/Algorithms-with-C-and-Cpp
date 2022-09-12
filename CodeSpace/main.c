#include <stdio.h>
#include <stdlib.h>

void tile_edges(int *tiles, int width, int height)
{
   for(int i=0;i<width*height;i++){
     
        if(i<width)
        {
            tiles[i] = 1;
        }else if(i%width==0 || (i+1)%width==0)
        {
            tiles[i] = 1;
        }else if(i>=width*(height-1))
        {
            tiles[i] = 1;
        }
        else
        { 
        tiles[i] = 0;
        }
    }
}
 
#ifndef RunTests
int main()
{
  
}
#endif