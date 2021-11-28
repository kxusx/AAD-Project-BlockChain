#ifndef __utils
#define __utils

#include <cstdint>
#include <iostream>
#include <sstream>
#include <string.h>
#include "sha256.h"
#include <vector>
using namespace std;



struct Data{
    string from;
    string to;
    int amount;
};
typedef struct Data Data;

class Block {
public:
    string sPrevHash;
    Block(uint32_t nIndexIn);
    string GetHash();
    void MineBlock(uint32_t nDifficulty); 
    // variable difficulty since in the actual Bitcoin blockchain, difficulty is revised every 2016 blocks based on block rate

    uint32_t nIndex;        // index of Block
    int64_t nNonce;         // the nonce which allows the sHash to meet target
    Data blockData;           // the data in Block
    string sHash;           //the hash of the previous block
    time_t tTime;           // time block was created
private:
    
    string CalculateHash() const;
};

class Blockchain {
public:
    Blockchain(int difficulty);

    void AddBlock(Block newBlock);

    Block GetLastBlock() const;

    uint32_t nDifficulty;
    vector<Block> vChain;

    
};

static Blockchain bChain = Blockchain(1);

extern int id;

void blockInsertion();
void displayLastBlock();
void displayAllBlocks();

#endif