#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char hex[22][17]={"0x3a", "0x0b", "0x05", "0x1d" ,"0x17", "0x19", "0x12", "0x11", "0x0a", "0x19", "0x45",
"0x19", "0x12", "0x06", "0x0b", "0x06", "0x45", "0x27" ,"0x03", "0x04", "0x10", "0x01"};
    long long decimal, place;
    int i = 0, val, len;
    char end_product[22];

    decimal = 0;
    place = 1;

    /* Input hexadecimal number from user */
    
    //gets(hex);

    /* Find the length of total number of hex digit */
    

    /*
     * Iterate over each hex digit
     */
     int row = sizeof(hex) / sizeof(hex[0]);



    
for(int j=0; j<row;j++){ 
    
    len = strlen(hex[0]);
    len--;
    char proba=hex[j];
    
    for(i=0; hex[j][i]!='\0'; i++)
    {
         
         char proba_1=hex[j][i];
        
        if(hex[j][i]>='0' && hex[j][i]<='9')
        {
            val = hex[j][i] - 48;
        }
        else if(hex[j][i]>='a' && hex[j][i]<='f')
        {
            val = hex[j][i] - 97 + 10;
        }
        else if(hex[j][i]>='A' && hex[j][i]<='F')
        {
            val = hex[j][i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }
   
    i=0;
    
    printf("%d.Decimal number = %lld\n",j, decimal);
    char c=decimal;
    end_product[j]=c;
    printf("Char of number = %c\n",end_product[j]);
    decimal=0;
}

    return 0;
}