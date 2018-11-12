When we transfer plain data, some character can have special meaning (for example directive characters).

Base64 encoding solves this problem by encode the data into only legel ASCII characters. Specifically we use 64 of them in order:
- `A` to `Z`
- `a` to `z`
- `0` to `9`
- `+` and `/`

These 64 characters are perfectly compatible with any channel. Because the encoded data contains only 64 characters, we can use 6 bits to represent each character (since 2^6 = 64).

For example: encode `0xAB34` using base64 encoding.

```
0xA = 1010
0xB = 1011
0x3 = 0011
0x4 = 0100
=>  1010_1011_0011_0100
```

The group 6 bits into one:

```
101010 = 42 -> q
110011 = 51 -> z
010000 = 16 (trailing zeros) -> Q
=> Encoded data in base64: qzQ
```
