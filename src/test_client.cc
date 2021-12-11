#include <pitp.h>
#define PORT 8080

int main(int argc, char const *argv[]) {
  PiTransportProtocol pitp;
  PiTransportProtocolType protocol_type = Client;
  PiTransportProtocolOptions pi_opts(protocol_type, htons(PORT), AF_NET,
                                     INADDR_ANY);
  
  
  return 0;
}
