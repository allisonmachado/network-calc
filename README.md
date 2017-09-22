# network-calc

Easy way to quickly find key values for a network environment such as the binary net ip,
netmask, broadcast address and so on for a given input. See the example below:

```

$ net-calc 192.168.1.0/24

Entry: 192.168.1.0/24

Network address:     11000000 10101000 00000001 00000000    192.168.1.0
Netmask:             11111111 11111111 11111111 00000000    255.255.255.0 (24 bits)
Broadcast addr:      11000000 10101000 00000001 11111111    192.168.1.255
Min Host value:      11000000 10101000 00000001 00000001    192.168.1.1
Max Host value:      11000000 10101000 00000001 11111110    192.168.1.254

The possible number of hosts on this network is 254.

```

## Install

`curl https://raw.githubusercontent.com/allisonmachado/network-calc/master/install.sh | bash`
