#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <ifaddrs.h>

int main (int argc, char **argv) {
  struct ifaddrs *ifaddresses;
  if(getifaddrs(&ifaddresses) < 0) {
    printf("Errore getifaddrs - %s\n", strerror(errno));
    return -1;
  }
  struct ifaddrs *ifaddress = ifaddresses;
  char host[NI_MAXHOST];
  //ciclo su llist
  for(ifaddress = ifaddresses; ifaddress != NULL; ifaddress = ifaddress->ifa_next) {
    if(ifaddress->ifa_addr == NULL) continue;
    int family = ifaddress->ifa_addr->sa_family;
    if(family == AF_INET || family == AF_INET6) {
      printf("%s\t", ifaddress->ifa_name);
      printf("%s\n", ifaddress->ifa_addr->sa_family == AF_INET ? "IPv4" : "IPv6");
      char ap[100];
      const int family_size = family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
      getnameinfo(ifaddress->ifa_addr, family_size, ap, NI_MAXHOST, 0, 0, NI_NUMERICHOST);
      printf("\t%s\n", ap);
    }
    ifaddress = ifaddress->ifa_next;
  }
  /*libera spazio*/
  freeifaddrs(ifaddresses);
  return 0;
}