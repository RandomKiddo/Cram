# Cram

[![License](https://img.shields.io/github/license/RandomKiddo/Cram)](https://opensource.org/licenses/MIT)

Sister Repository - [Uncram](https://github.com/RandomKiddo/Uncram)

:exclamation: This repository's contents are not yet completed

___

### Table of Contents

1. [About](#about)
2. [Algorithms](#algorithms)
3. [Sister Repository](#sister-repository)
4. [Further Reading](#further-reading)

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

Huffman Encoding: 
- [About Huffman Encoding](https://www.studytonight.com/data-structures/huffman-coding)
- [Huffman Coding Wikipedia Page](https://en.wikipedia.org/wiki/Huffman_coding)

___

[Back to Top](#cram)

<sub>This page was last edited on 07.09.2021</sub>