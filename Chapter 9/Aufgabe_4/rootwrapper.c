#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
setuid(0);
system("./myid.sh");
return 0;
}
