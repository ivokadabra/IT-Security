#include <stdio.h>
#include <string.h>
#include <math.h>
 
void decToHexa(int n)
{
    int org=n;
    // char array to store hexadecimal number
    char hexaDeciNum[100];
 
    // counter for hexadecimal number array
    int i = 0;
    while (n != 0) {
        // temporary variable to store remainder
        int temp = 0;
 
        // storing remainder in temp variable.
        temp = n % 16;
 
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
 
        n = n / 16;
    }
 
    // printing hexadecimal number array in reverse order
    printf("for the number %d is ",org);  
    for (int j = i - 1; j >= 0; j--){
        printf("%c", hexaDeciNum[j]);   
    }
}




int main()
{   
    int alt=12;
    int arr[10];
    for(int i=0;i<10;i++){
    
    int neu=(11+alt)%26;
    printf("%d ",neu);
    arr[i]=neu;
    alt=neu;

}
printf("\n");

for(int k=0;k<10;k++){
  decToHexa(arr[k]);
  printf("\n");
}

    return 0;
}