
#include "utils.h"
using namespace std;

Blockchain::Blockchain(int difficulty) {
    vChain.emplace_back(Block(0));
    nDifficulty = difficulty;
}

Block Blockchain::GetLastBlock() const {
    return vChain.back();       // return the last block 
}

void Blockchain::AddBlock(Block bNew) {
    cout << "Mining block "<<id<<"..." << endl;
    bNew.sPrevHash = GetLastBlock().GetHash();  // setting prevHash to the hash of the previous block
    bNew.MineBlock(nDifficulty);                // mining
    vChain.push_back(bNew);
}


