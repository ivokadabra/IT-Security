#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
static int check_rights_by_reading_shadow(){
  FILE*fd_shadow;
  int count;
  char buffer[256];
  fd_shadow=fopen("/etc/shadow","r");
if(fd_shadow==NULL) {
    perror("/etc/shadow");
   return-1;
}
fgets( buffer,sizeof(buffer), fd_shadow );
printf("    SHADOW: \"%s\"", buffer);
fclose( fd_shadow );
return 0;

}



int main(int argc,char**argv,char**envp )
{
int old_id; 
int set;
printf("\nACHTUNG: Das Programm ist nicht auf einem verschluesselten\n");
printf("Homeverzeichnis (ecryptfs) funktionstuechtig!\n\n");
printf("PROGRAMMSTART 1: uid=%d euid=%d\n", getuid(), geteuid() );
check_rights_by_reading_shadow();



printf("DROPPING PRIVILEGES 2: uid=%d euid=%d setuid=%d \n", getuid(), geteuid(),set );
old_id=getuid();
set=seteuid( getuid() );



check_rights_by_reading_shadow();
printf("RAISING PRIVILEGES 3: uid=%d euid=%d  setuid=%d saved id=%d\n", getuid(), geteuid(),set,old_id );
// TODO: raise privileges and check success or fail
set=seteuid( 0 );


if(seteuid( 0 )) {printf("can't get special rights\n");}


check_rights_by_reading_shadow();
printf("DROPPING PRIVILEGES 4: uid=%d euid=%d  setuid=%d   saved id=%d\n", getuid(), geteuid(),set,old_id );
// TODO: drop privileges
set=seteuid( getuid() );


int ret=check_rights_by_reading_shadow();

return 0;
}
