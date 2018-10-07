/*  Huffman codes

Problem: Given a text file with alphabet characters (for
simplicity), how to encode and decode this file.

Example: A text file consisted of 100,000 characters in
{a, b, c, d, e, f}.

Obvious solution:
  - Encode each character as a binary code (code for short),
    we have 6 characters => can use 3 bits to encode:
    a   b   c   d   e   f
    000 001 010 011 100 101

  - Memory need: 100,000 * 3 = 300,000

Huffman codes: This approach involves the frequency of each
character, high frequency characters use fews number of bits
to encode, low frequency characters use more number of bits
to encode => overall we use less total of bits to encode
the text file.
    For example frequency table and their huffman codes:
    a  b   c   d   e    f
    45 13  12  16  9    5
    0  101 100 111 1101 1100

  - Encode is trivial, in order to decode, their huffman
    codes must be "prefix codes", it means no code is a
    prefix of some other code:
    For example a valid huffman code for 2 characters a & b
    can be 0 and 001, because 0 is prefix of 001, and
    this confuses the decoding process. Let's say we have
    an encoded code:
    001
    -  a
    ---  or b?

  - To aid the decoding process, we can relate to trie
    data structure to represent our Huffman codes, this
    gives us a binary tree since we'in in binary system.
    CLRS 3rd, Figure 16.4 (b) p/430 best illustrates the tree.
    Notice: each character must be a leave of the tree
    to be prefix code.

Finding Huffman code:
  - We will find (prefix) Huffman codes using Greedy algorithm.

  - So: we have prefix Huffman codes of characters,
    we build the corresponding binary tree to aid decoding
    process. But inorder to find Huffman codes, we start
    from building the tree based on the frequency.

  - Greedily, we grab the least 2 frequency character
    (using a min-heap / min priority) to connect them
    with a parent node => tends to push the low frequency
    character to the bottom of the tree.

  => Problem solved
*/
