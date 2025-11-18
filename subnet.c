#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ip to 32-bit int
unsigned int iptoint(char* ip) {
  unsigned int a, b, c, d;
  sscanf(ip, "%u.%u.%u.%u", &a, &b, &c, &d);
  return (a<<24)|(b<<16)|(c<<8)|d;
  
}

//32-bit int to ip
void inttoip(unsigned int ip, char* buffer) {
  sprintf(buffer, "%u.%u.%u.%u", (ip >> 24) & 0xFF, (ip >> 16) &0xFF, (ip >> 8) & 0xFF, ip &0xFF);
}

unsigned int calcsubmask(int prefix) {
  return prefix == 0? 0 : ~(( 1 << (32 - prefix)) - 1);
}

int main() {
  char ip[16];
  int prefix, newprefix;
  unsigned int mask, newmask, ipint;
  char buffer[16];

  //i/p ip addr & prefix len
  printf("Enter ip: ");
  scanf("%s", ip);
  printf("Enter curr prefix len:" );
  scanf("%d", &prefix);

  // new prefix len
newprefix = prefix+1;
ipint = iptoint(ip);

//calc og subnet mask
mask = calcsubmask(prefix);
newmask = calcsubmask(newprefix);
int hostsub = (1 << (32 - newprefix)) - 2;

// subtract 2 for network and broadcast addresses
printf("\nnum of subnet:\n");
printf("num of hosts per subnet: %d\n", hostsub); 
