The application layer is the one that truly makes the difference: you can find here protocols that allow you to send and receive emails, surf the web, watch video and play online games, etc.

While the rest of the OSI stack works with the same protocols all the time, in this layer each application has its very own protocol.

---

We can say that the Web is a subset of the Internet: the Internet is the collection of all devices interconnected world-wide, while the Web is the group of devices within the Internet that offer websites and web content.

---

Any application needing network access can craft its own network protocol, provided that all instances of that application will use the same protocol. This results in having a huge variety of protocols working at this layer, with huge differences between one another.

However, many applications are standardized and they work with well-known protocols. The features of these protocols are well-documented and available for free online, so that you can develop your own application supporting that protocol.

---

## Web protocols: [HTTP (80)](/additional-learning/http/http-the-definitive-guide), HTTPs (443)

HTTP allows the transfer of Hyper Texts, that are web contents such as web pages, images or videos.

This transfer is designed with a client-server model, where there is always a device (the client) that makes requests to the other device (the server), with the server that just replies with what asked.

HTTP uses TCP at the transport layer, with a random port used by the client and a well-known port used by the server: the port 80 (by default).

HTTP is **text-based**, meaning that its headers are made of plain text.

HTTPS works on TCP port 443 (server-side).

HTTPS traffic is still plain text, but it uses an additional layer of security at the Transport Layer, named **TLS (Transport Layer Security)**. TLS is the new version of **SSL (Secure Socket Layer)**.

## Mail Protocols: SMTP (25), POP3 (110) / IMAP (143)

Read the [original article](https://www.ictshore.com/free-ccna-course/application-layer/).

## Controlling Remote Devices

Two technologies to control devices remotely (without having to physically go where they are):

### Remote Desktop

Remote Desktop protocol family is a group of protocols that allows you to control devices using graphical interface. You establish a session with the remote device, then your PC will send everything you do to the remote device (keyboard, mouse movement, etc.). The remote device reponses with video and audio.

2 main protocols:
- **Remote Desktop Protocol (RDP)** by Microsoft, port 3389.
- **PC over IP (PCoIP)** by VMware.

### Remote Shell

Not all devices have graphical interface, some of them just have a text interface, named Shell. This type of user interface is lightweight since it doesn not consume a lot of resource).

Remote shell interface can be delivered using 2 protocols:
- **Telnel**, port 23: this simple protocol opens a TCP connection to the remote device (on port 23) and send everything you type to it.
  > Since all application protocols are text-based, you can telnet-in a web server opening a connection to port 80, then manually craft an HTTP Request.
  >
  > If the remote device asks you to authenticate, the username and password you provide are sent in plain-text, so an attacker in the middle could see your personal data.
- **Secure Shell (SSH)**, port 22: it encrypts traffic in both direction. 
  > Since you can change the configuration of devices using remote shell protocols, it is bet to configure those devices to accept only SSH connection as Telnet can be spoofed – an attacker gaining access to your devices could seriously harm your infrastructure.

## File Transfer: FTP (21, 20~)

FTP uses 2 ports (server-side):
- 21 for control: used to exchange instructions, e.g. list files on the remote device.
- 20 for data in active mode or a random port in passive mode: used to physically transfer files.

Read more in the [original article](https://www.ictshore.com/free-ccna-course/application-layer/).













