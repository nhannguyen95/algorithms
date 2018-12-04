The classful addressing scheme is now considered legacy, it has been replaced by classless addressing, which relies on subnet masks.

The **CIDR (Classless Inter-Domain Routing) notation**:

```
10.80.96.11/22
22 is the number of 1s in the subnet mask
```

If we have IP address of a host and the CIDR notation, then the **subnet address** is:

```
subnet_address = IP & subnet_mask (ignore the host ID part in the IP address)
```

---

When working with custom subnets, an IP address is made of [three different parts](https://www.ictshore.com/wp-content/uploads/2016/11/1014-05-Subnet_ID.png):
- *The Major*: comes from the major/classful network and that cannot be modified with subnetting.
- *Subnet ID*: identifies the subnet between all the subnets you create from the major.
- *Host ID*: identifies the host within a subnet.

> An address that has all zero in the Host ID field is a subnet address (it identifies the subnet).

> An address that has all ones in the Host ID field is the directed broadcast address for that subnet.

## Subnetting

Subnetting is the process of sizing the Subnet ID and Host ID portions in order to create a certain number of subnets that can contain a certain number of hosts each.

### Fixed-Length Subnet Masking (FLSM)

Dividing a major network into subnets of the same size (each with the same subnet mask and containing the same number of hosts).

Example:

```
Given an IP address 192.168.1.1/25 (/25 major), divide it into 4 subnets, each with 30 hosts.

We can find the Subnet ID first: 2^x >= 4 => x = 2
=> the subnet ID portion has 2 bits.

We can also find the Host ID first: 2^x >= 30 + 2 (subnet and broadcast address) = 32
=> x = 5
=> the host ID portion has 5 bits.

So each subnet has the subnet mask of 255.255.255.224 (/27).
Each subnet can contains at most 2^5 - 2 = 30 hosts.
```

### Variable-Length Subnet Masking (VLSM)

VLSM allows you to create subnets of different size from the same major network.

## Private and public IP addresses

**Public addresses** – the majority of IP addresses – are addresses known in the Internet, they are assigned from the Regional Internet Registries (RIRs), that receive them from the Internet Assigned Numbers Authority (IANA).

Private addresses, instead, are managed internally inside enterprises and they are not publicly known over the Internet. An enterprise will use these addresses for the inside traffic, and another enterprise will use the same addresses for its inside traffic, *without conflict because they are significant only inside the single enterprise and they are never seen in the Internet*.

IPv4 Addresses:

|Subnet|Use|
|-|-|
|10.0.0.0/8|Mainly used in enterprises|
|176.16.0.0/12|Rarely used in enterprises|
|192.168.0.0/16|Used in home network with off-the-shelf routers|
|169.254.0.0/16|This is the APIPA (Automatic Private IP Addressing) range and a PC unable to get a "real" IP address will use an address from this category. It is not administratively assigned to any device – and basically allows no communication|
|127.0.0.0/8|This is the **localhost address**. This address range, `127.0.0.1` (*) specifically, represents “this very device”|

> (*): If a device source traffic destined for that address, it won’t even touch the NIC, it will remain inside the CPU. It is sometimes used to allow IP communication between applications on the same device.

