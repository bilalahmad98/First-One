#include <stdio.h> // basic I/O
#include <stdlib.h>
#include <sys/types.h> // standard system types
#include <netinet/in.h> // Internet address structures
#include <sys/socket.h> // socket API
#include <arpa/inet.h>
#include <netdb.h> // host to IP resolution
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#define HOSTNAMELEN 40 // maximal host name length; can make it variable if you want
#define BUFLEN 1024 // maximum response size; can make it variable if you want

int main(int argc, char *argv[])
{

  	if (argc != 2)								// check that there are enough parameters
    	{
      		fprintf(stderr, "Usage: mydns <hostname>\n");
      		exit(-1);
    	}
	struct hostent *serv;

  	serv = gethostbyname(argv[1]);						// Address resolution stage by using gethostbyname()
 										// Write your code here!
	if (serv == NULL)
	{
		cout << "Error: Resolving hostname \n";
		return 1; 
	}

  	struct in_addr **ip_name = (struct in_addr **)serv->h_addr_list;	// Print to standard output

	for (int i = 0; ip_name[i] != NULL; i++)
	{
		cout << inet_ntoa(*ip_name[i]) << endl;
	}
  	return 0;
}