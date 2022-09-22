#include "stdio.h"
#include "setjmp.h"

jmp_buf jmp;
int val;
#define TRY if((val = setjmp(jmp)) == 0)
#define CATCH(num) else if (val == num)
#define THROW(num) longjmp(jmp,num)

char equal(char s1[],char s2[], int i){
   i = 0;
    while(1)
    {
        if (s1[i] != s2[i])
        {

       
            THROW(1);
        }

        
        else if(s1[i] == s2[i])
        {
       
            THROW(2);  
        }
        i++;
  return 1;
     }
    
}

        

int main(int argc, char const *argv[])
{
    

    TRY
    {
    int i;
    char s1[] = "1";
    char s2[] = "A";
    equal(s1,s2,i);
    }
    CATCH(1){
        printf("\n Khac nhau");
    }
    CATCH(2){
        printf("\n Giong nhau");
    }
    
    return 0;
}
