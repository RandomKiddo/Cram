# Cram

[![License](https://img.shields.io/github/license/RandomKiddo/Cram)](https://opensource.org/licenses/MIT)
[![Codacy Security Scan](https://github.com/RandomKiddo/Cram/actions/workflows/codacy-analysis.yml/badge.svg)](https://github.com/RandomKiddo/Cram/actions/workflows/codacy-analysis.yml)

Sister Repository - [Uncram](https://github.com/RandomKiddo/Uncram)

:exclamation: This repository's contents are not yet completed

___

### Table of Contents

1. [About](#about)
2. [Algorithms](#algorithms)
3. [Sister Repository](#sister-repository)
4. [Further Reading](#further-reading)
5. [How to Run](#how-to-run)

___

### About

Cram is a repository that attempts to implement multiple compression algorithms, both lossless and lossy, that span files like `.txt`, `.gif`, `.pdf`, etc. 

___

### Algorithms

This repository implements the following lossless algorithms: [Run Length](#run-length), [LZW](#lzw), and [Huffman](#huffman)

This repository implements the following lossy algorithms: [DFT](#dft) and [Wavelet](#wavelet)

##### Run Length

Run Length encoding uses the following system, and is a very simple text file compression method.

Simplify a line like `aaaabbcddddee` to `a4b2c1d4e2`

##### LZW

LZW compression wokrs by reading a string of symbols and grouping the symbols, and then coverting the groups into integer codes.

LZW compression usess a code table, with 4096 being the most popular number of table entries. The codes from 0 to 255 are always assigned to single bytes of the input.

When the encoding begins, the table contains the 256 entries of 0-255, and as compression continues, LZW identifies sequences in the data and assigns them a code, and adds the value to the code table.

```cpp
PSEUDOCODE
Initialize table with single character strings
P = first input
WHILE not end of input stream
    C = next input
    IF P + C is in the code table
        P = P + C
    ELSE
        output the code for P
    add P + C to the string table
        P = C
    END WHILE
output code for P
```

Here is a visualization:
<img src="https://cdncontribute.geeksforgeeks.org/wp-content/uploads/lempel–ziv–welch-compression-technique.png">

(Example Link Provided In [Further Reading](#further-reading))

##### Huffman

Huffman encoding is a little complicated. I recommend visiting the [Further Reading](#further-reading) section to learn about it in more detail.

To start Huffman encoding, you must read all the lines from the files and count the amount of characters in the file. Then you would sort the map of characters and their frequency from smallest frequency to largest.

Example:
```cpp
character   Frequency
    a           5
    b           9
    c           12
    d           13
    e           16
    f           45
...
```

You would then combine the two lowest frequency characters into one node (in this case a & b), with a value of their combined frequency (15). You would then sort the map once again, and continue the process until you reach the top (root) node. You can sort these nodes into a tree (usually a min heap). Then start at the root node, and going left will assign a value of "0", and going right would assign a value of "1". You then string these values together to get each character's encoding. You can then replace each character in the file with its encoded value.

Here is a visualization using the data above: <br>
<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/fig-6-300x167.jpg">

This would result in the codes being:
```cpp
character   code-word
    f          0
    c          100
    d          101
    a          1100
    b          1101
    e          111
```

(Example Link Provided In [Further Reading](#further-reading))

##### DFT

##### Wavelet

___

### Sister Repository

This repository has a sister repository called Uncram that seeks to decompress the files compressed using these algorithms. 

Visit the repository [here](https://github.com/RandomKiddo/Uncram)

:exclamation: The repository's contents is not finished yet

___

### Further Reading

Run-Length Encoding:
- [Run-Length Encoding Wikipedia Page](https://en.wikipedia.org/wiki/Run-length_encoding)

LZW Encoding:
- [LZW Wikipedia Page](https://en.wikipedia.org/wiki/Lempel–Ziv–Welch)
- [LZW Examples & Algorithms](https://www.geeksforgeeks.org/lzw-lempel-ziv-welch-compression-technique/)

Huffman Encoding: 
- [About Huffman Encoding](https://www.studytonight.com/data-structures/huffman-coding)
- [Huffman Coding Wikipedia Page](https://en.wikipedia.org/wiki/Huffman_coding)
- [Huffman Examples & Algorithms](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/)

___

### How to Run

Just simply download the [`cram_latest.zip`](https://github.com/RandomKiddo/cram/blob/master/cram_latest.zip) file in the repository and extract the contents.
Then just run whichever file you want to test out. 

:exclamation: `G++` compiler recommended. This repository has not been tested for `Clang`, `GCC`, `EDG`, and other compilers. `GCC` is the most likely alternative to work, since it is closely related to `G++`

___

[Back to Top](#cram)

<sub>This page was last edited on 07.12.2021</sub>