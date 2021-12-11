/*

This is the base class for the Pi Transport Protocol (PiTP).
*/
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>


enum PiTransportProtocolType { Client = 0, Server = 1 };

class PiTransportProtocol {
public:
  PiTransportProtocol() {}
  ~PiTransportProtocol() {}
  void set_opts(int port);
  void connect();
  int send_data();
  std::string recv_data();

private:
  PiTransportProtocolOptions pitp_opts;
};

struct PiTransportProtocolOptions {
  PiTransportProtocolOptions() {}
  PiTransportProtocolOptions(PiTransportProtocolType type, int sin_port,
                             short sin_fam, unsigned long sock_addr) {
    protocol_type = type;
    port = sin_port;
    sin_family = sin_fam;
    s_addr = sock_addr;
  }
  ~PiTransportProtocolOptions() {}

  PiTransportProtocolType protocol_type;
  int port;
  short sin_family;
  unsigned long s_addr;
  char sin_zero[8];
};