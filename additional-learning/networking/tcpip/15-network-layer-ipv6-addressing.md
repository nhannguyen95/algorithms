IPv6 it is **128-bits** long.

An IPv6 address is represented in 8 blocks of four hexadecimal digits:

```
2001:0DB8:AC10:FE01:0000:0000:0000:0001

Leading 0s can be omitted
2001:DB8:AC10:FE01:0:0:0:1

Consecutives 0s can be replaced by :
2001:DB8:AC10:FE01::1
```

The address is divided into two equals parts: **Network Prefix** and **Interface ID**:
- The network prefix can be compared to the IPv4 Subnet ID, it represents a group of IPv6 addresses.
- The Interface ID is pretty similar to the IPv4 Host ID, but with a simple difference in the concept.

> With version 4, we were used to the fact that IP addresses were host-related, but the truth is that an IP address is related to the network interface (NIC), and if an host has multiple NICs it can have multiple addresses.

