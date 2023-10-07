#include <stdio.h>
#include <string.h>

int st[10005], n,top_ptr;

void push(int n)
{
    st[top_ptr++] = n;
}

int pop()
{

}

int size()
{

}

int empty()
{


}

int top()
{


}


int main()
{
    scanf("%d",&n);
    char* cmd;
  
    for(int i =0;i<n;i++)
    {
        scanf("%s",cmd); 
        if(!(strcmp(cmd,"push")))
        {
            int k;
            scanf("%d",&k);
            push(k)
        }

    }
}