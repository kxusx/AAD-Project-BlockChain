
#include "utils.h"

void blockInsertion()
{
    bChain.AddBlock(Block(id));
    id++;
}

void displayLastBlock()
{
    Block b = bChain.GetLastBlock();
    cout << "From:" << b.blockData.from << "\n";
    cout << "To:" << b.blockData.to << "\n";
    cout << "Amount:" << b.blockData.amount << "\n";
}

void displayAllBlocks()
{

    for (int l = 1; l <id; l++)
    {
        Block b = bChain.vChain.at(l);
        cout <<"-------------------------------\n";
        cout << "id : "<<l<<"\n";
        cout << "From : " << b.blockData.from << "\n";
        cout << "To : " << b.blockData.to << "\n";
        cout << "Amount : " << b.blockData.amount << "\n";
        
    }
}
