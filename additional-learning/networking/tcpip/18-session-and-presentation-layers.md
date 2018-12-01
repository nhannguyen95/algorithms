Session and presentation layers in the OSI stack are known only by a small part of Network Engineers. This is probably because all their features blend either in transport-layer protocols or in application-layer protocols.

The only place we can see session and presentation layers truly implemented is when they are based over a UDP transport. UDP leaves some room to this two layers (if compared to TCP) because it is extremely simple and lacking features.

## Session layer

The session layer defines the re-transmission of data, the segment ordering method and control the communication in general.
> All these features are covered by TCP for applications using that transport protocol, but applications that leverage UDP have to implement these features autonomously (within the application) or rely on an extra protocol specifically sitting at the session layer.

### Real-time Transport Protocol (RTP)

This protocol uses UDP as their underlying transport, spending some time on RTP is certainly well-worth since Voice and Video are the king applications among all UDP-based applications.

The [RTP header](https://www.ictshore.com/wp-content/uploads/2016/12/1018-02-UDP_RTP_Frame.png):
- **Version**: RTP version, the up-to-date is 2.
- **P (Padding)** – Flag used to indicate whether padding is present or not in the segment.
- **X (Extension)** – Flag used to indicate whether extension header is present or not
- **CC (CSRC count)** – Number of CSRC identifiers contained in the header
- **M (Marker)** – Flag that, if set, indicates that this segment has some special relevance for the application
- **PT (Payload Type)** – Indicates the type of RTP payload (e.g. for VoIP/Video stream)
- **Sequence number** – Used from the receiver to re-order packets, incremented by one each segment sent
- **Timestamp** – Time the segment was created, used to allow the receiver to play the content of the segment (assuming that it is audio or video) at the proper interval
- **SSCS – Synchronization Source Identifier**, identifies a stram of UDP/RTP segments
- **CSRC – Contributing Source IDs*, indicates the source of the audio stream, multiple CSRCs can be specified if there are multiple sources (e.g. in a three-party conference)
- **Header extension** – extra header, optional and profile-specific.

You can see there's `sequence number`, but no `acknowledgement number`; this is because RTP allows the receiver to **reorder segments**, but not to arrange a retransmission.
> This behavior is purposefully designed this way, as a VoIP call or a video stream needs to be delivered now. In case something is lost, there is no time to re-transmit it, the show must go on. If we re-transmit it, it would arrive too late so there is no point in the retransmission at all.

Another interesting field adding a feature TCP is lacking of is the timestamp, with that field you can know when the content was generated and reproduce the sound and video at the same interval it was generated. Otherwise, you would have audio and video streams increasing and decreasing speed according to the network connection available.

> Reordering is crucial to almost any application, to transfer a file we need to know the order of its part, and to transfer audio stream we need to know in which order to play the sounds.

## Presentation layer for Real-Time Applications

Presentation layer defines how data should be presented to the application.

Read more at the [original article](https://www.ictshore.com/free-ccna-course/session-and-presentation-layers/).

## Session and presentation layers in the shadow

Read more at the [original article](https://www.ictshore.com/free-ccna-course/session-and-presentation-layers/), seriously.


