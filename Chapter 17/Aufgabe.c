#include<stdio.h>
#include <stdint.h>  

int main(){
  int64_t arr[5]={0x53A9,0xAA32,0x1FF6, 0x5569};
  int64_t result[5];
  for (int i=0; i< sizeof(arr)/sizeof(arr[0]); i++ ){
      
      result[i]=arr[i]*0x2329;
      
      printf("Hash of Number %i ist %lx\n",i,result[i]);
    
    }

  return 0;
}

