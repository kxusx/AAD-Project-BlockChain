# AAD-Project-BlockChain

I have implemented a rudimentary blockchain where :
each block contains data on who sent, who received, amount sent.
also the Nonce,Hash and the time it was inserted
blocks are inserted by proof of work using sha256 hashing.
the difficulty of mining can be changed like it is done for bitcoin blockchain each block is connected to its previous block through a hash pointer

I then implemented some graph algorithms, on top of this blockchain, to showcase how the mix of graph theory and blockchains can help us to analyze blockchains. Any analysis would provide a live insight into the usage patterns which ultimately would be useful for making a number of inferences by law-enforcement agencies, economists, tech-enthusiasts, etc

I was inspired to take this project up after reading this paper :
https://arxiv.org/pdf/2002.06403.pdf

1. Deducing importance of the user entities could help us in understanding various dynamics of the blockchain’s network thus giving us an insight into much deeper structural changes. In graph theory, importance relates to the centrality of a vertex.
In my implementation for this use case, I find how many directed edges are coming in and going out of a specific user node.

2. To understand the connectivity of entities, traversal in a graph is often useful .
A typical use case is exploring the path from one address to another (possibly known) address, such exploration could help to track the flow of coins from suspicious addresses.
 AAD Project Report 1
In my implementation for this use case, I take 2 user addresses as input (one as source, one as destination) and find number of paths connecting these 2 users.

3. By detecting strongly connected components, we can find addresses that are closely related to each other. An example is labeling merchants and some of their loyal customers in a connected component formed due to regular transactions between these nodes.
In my implementation for this use, I use Kosaraju's algorithm to find the various strongly connected components of this blockchain.
