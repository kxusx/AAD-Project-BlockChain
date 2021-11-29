#ifndef __utils
#define __utils

#include <cstdint>
#include <iostream>
#include <sstream>
#include <string.h>
#include "sha256.h"
#include <vector>
#include <list>
using namespace std;

//---------------------------------------------------------------------------

// Data stored in the blocks
struct Data
{
    int from;
    int to;
    int amount;
};
typedef struct Data Data;

//---------------------------------------------------------------------------

// Structure and functions associated with a block
class Block
{
public:
    string sPrevHash;
    Block(uint32_t nIndexIn1, int from, int to, int amount);
    string GetHash();
    void MineBlock(uint32_t nDifficulty);
    // variable difficulty since in the actual Bitcoin blockchain, difficulty is revised every 2016 blocks based on block rate

    uint32_t nIndex; // index of Block
    int64_t nNonce;  // the nonce which allows the sHash to meet target
    Data blockData;  // the data in Block
    string sHash;    //the hash of the previous block
    time_t tTime;    // time block was created
private:
    string CalculateHash() const;
};

//---------------------------------------------------------------------------

// Structure and functions associated with a blockchain
class Blockchain
{
public:
    Blockchain(int difficulty);

    void AddBlock(Block newBlock);

    Block GetLastBlock() const;

    void changeDifficulty(int difficulty);

    uint32_t nDifficulty;
    vector<Block> vChain;
};

//---------------------------------------------------------------------------

class Graph
{
    
public:
    //Graph(int V);
    int numVertices;
    vector<int> fromList;
    vector<pair<int, int>> adj[100];


    void addEdge(int from, int to, int amount)
    { 

        if (find(fromList.begin(), fromList.end(), from) != fromList.end())
        {   // from exists
            adj[from].push_back(make_pair(to, amount));
        }else{
            fromList.push_back(from);
            adj[from].push_back(make_pair(to, amount));
            numVertices++;
        }
        
        
    }

    void printGraph()
    {
        int v, w;
        for (auto it = fromList.begin(); it != fromList.end(); it++)
        {
            int from = *it;
            cout << "From " << from << "->";
            for (auto it = adj[from].begin(); it != adj[from].end(); it++)
            {
                v = it->first;
                w = it->second;
                cout << "\tTo:" << v << ",Amt:" << w;
            }
            cout << "\n";
        }
    }

    // void clearGraph(){
    //     vector<pair<int, int>>::iterator it1, it2;
    //     iterator it1= adj.begin(), it2= adj.end();
    //     adj.erase(iterator1, iterator2);
    //     //adj.clear();
    //     fromList.clear();
    // }
};

static Graph G;

// Print the graph

//---------------------------------------------------------------------------

// Blockchain object declared with difficulty 1
static Blockchain bChain = Blockchain(1);
extern int id;

//---------------------------------------------------------------------------

void blockInsertion();
void displayLastBlock();
void displayAllBlocks();
void changeDiff();
void graphConverter();
void displayGraph();

//---------------------------------------------------------------------------

#endif