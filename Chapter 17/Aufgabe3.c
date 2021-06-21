#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
extern MYSQL*init_database(void);
extern void echo_off();
extern void echo_on();

char*read_password(char*buffer,intbuffersize )
{
echo_off();
gets( buffer );
echo_on();

if( strlen(buffer)>=buffersize ) {
fprintf(stderr,"Passwort zu lang\n");
return NULL;
}
returnbuffer;
}

int authorize(char*u )
{
char buffer[50], username[50], query_string[200];
MYSQL*conn;
MYSQL_RES*res;
MYSQL_ROW row;
intret= -1;
if( u ) {
strcpy( username, u );//strcpy( username, u );
}else{
printf("Bitte Username eingeben:\n"),
scanf("%50s", username );//scanf( "%s", username );
}

printf("Bitte Passwort eingeben:\n");
read_password( buffer,sizeof(buffer) );// Datenbankabfrage vorbereiten
if( (conn=init_database()) ) {
sprintf( query_string,40"SELECT u, pw FROM logintable WHERE "41"user='%s' AND password='%s'",42username, buffer );
if( mysql_query(conn,query_string)) {
fprintf(stderr,"%s\n", mysql_error(conn));
mysql_close(conn);
return-2;
}
res=mysql_use_result(conn);
if( (row=mysql_fetch_row(res)) ){ret=0;}
mysql_free_result(res);
mysql_close(conn);
}
return ret;
