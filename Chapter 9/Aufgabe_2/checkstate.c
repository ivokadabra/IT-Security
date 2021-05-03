#define _GNU_SOURCE
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

void decode_state(){

    uid_t euid, ruid, suid;
    getresuid(&ruid, &euid, &suid);
    printf("EUID: %d, RUID: %d, SUID: %d\n", euid, ruid, suid);

   if(euid==1000 && ruid==1000 && suid==1000){
      printf("user rights, no root possible\n");
   }

   else if(euid==1000 && ruid==1000 && suid==0){
      printf("user rights, root possible\n");
   } 

   else if(euid==0 && ruid==1000 && suid==0){
      printf("superuser rights, less possible\n");
   } 
   
    else if(euid==0 && ruid==0 && suid==0){
      printf("pure superuser rights\n");
   } 
    
	


}

int main(){

        printf("drop privileges...\n");
        seteuid( getuid() );
        decode_state();

       printf("gain privileges...\n");
       seteuid( 0 );
        decode_state();
        
        

    /*printf("Real user ID: %d\n", getuid());
    printf("Effective user ID: %d\n", geteuid());
    printf("Real group ID: %d\n", getgid());
    printf("Effective group ID: %d\n", getegid());*/

return 0;
}
