/*
Send a file over a socket.

Interface:

    ./executable [<input_path> [<sever_hostname> [<port>]]]

Defaults:

- input_path: input.tmp
- server_hostname: 127.0.0.1
- port: 12345
*/

#define _XOPEN_SOURCE 700

#include <my_global.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h> /* getprotobyname */
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <mysql.h>
#include <time.h>


#define BUFSIZE 2000
#define SIZE 20

void connectto_database(char* file_path, time_t now){
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
   char *server = "localhost";
   char *user = "root";
   char *password = "vicnoob123"; /* set me first */
   char *database = "transfer_history";
   char q[BUFSIZE];
   sprintf(q,"INSERT INTO history (filename,time) VALUES('%s','%s')",file_path,ctime(&now));
   conn = mysql_init(NULL);
   /* Connect to database */
   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   /* send SQL query */
   if (mysql_query(conn, q)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   res = mysql_use_result(conn);
   /* output table name */
   // printf("MySQL Tables in UNIX database:\n");
   // while ((row = mysql_fetch_row(res)) != NULL)
   //    printf("%s \n", row[0]);
   /* close connection */
   mysql_free_result(res);
   mysql_close(conn);
}


int main(int argc, char **argv) {
    char protoname[] = "tcp";
    struct protoent *protoent;
    char *file_path = "input.tmp";
    char *server_hostname = "127.0.0.1";
    char *server_reply = NULL;
    char *user_input = NULL;
    char buffer[BUFSIZ];
    in_addr_t in_addr;
    in_addr_t server_addr;
    int filefd;
    int sockfd;
    ssize_t i;
    ssize_t read_return;
    struct hostent *hostent;
    struct sockaddr_in sockaddr_in;
    unsigned short server_port = 12345;
    time_t t;
    time(&t);

    if (argc > 1) {
        file_path = argv[1];
        if (argc > 2) {
            server_hostname = argv[2];
            if (argc > 3) {
                server_port = strtol(argv[3], NULL, 10);
            }
        }
    }

    filefd = open(file_path, O_RDONLY);
    if (filefd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    /* Get socket. */
    protoent = getprotobyname(protoname);
    if (protoent == NULL) {
        perror("getprotobyname");
        exit(EXIT_FAILURE);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, protoent->p_proto);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    /* Prepare sockaddr_in. */
    hostent = gethostbyname(server_hostname);
    if (hostent == NULL) {
        fprintf(stderr, "error: gethostbyname(\"%s\")\n", server_hostname);
        exit(EXIT_FAILURE);
    }
    in_addr = inet_addr(inet_ntoa(*(struct in_addr*)*(hostent->h_addr_list)));
    if (in_addr == (in_addr_t)-1) {
        fprintf(stderr, "error: inet_addr(\"%s\")\n", *(hostent->h_addr_list));
        exit(EXIT_FAILURE);
    }
    sockaddr_in.sin_addr.s_addr = in_addr;
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_port = htons(server_port);
    /* Do the actual connection. */
    if (connect(sockfd, (struct sockaddr*)&sockaddr_in, sizeof(sockaddr_in)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    while (1) {
        read_return = read(filefd, buffer, BUFSIZ);
	
        if (read_return == 0)
            break;
        if (read_return == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        if (write(sockfd, buffer, read_return) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }
    connectto_database(file_path, t);
    free(user_input);
    free(server_reply);
    close(filefd);
    exit(EXIT_SUCCESS);
}
