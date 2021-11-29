
#include "utils.h"

void blockInsertion()
{
    int from, to, amount;
    cout << "From:";
    cin >> from;
    cout << "To:";
    cin >> to;
    cout << "Amount:";
    cin >> amount;
    bChain.AddBlock(Block(id, from, to, amount));
    G.addEdge(from,to,amount);
    id++;
}

void displayLastBlock()
{
    Block b = bChain.GetLastBlock();

    cout << "From:" << b.blockData.from << "\n";
    cout << "To:" << b.blockData.to << "\n";
    cout << "Amount:" << b.blockData.amount << "\n";
    cout << "-------------------------------\n";
}

void displayAllBlocks()
{

    for (int l = 1; l < id; l++)
    {
        Block b = bChain.vChain.at(l);
        cout << "id : " << l << "\n";
        cout << "From : " << b.blockData.from << "\n";
        cout << "To : " << b.blockData.to << "\n";
        cout << "Amount : " << b.blockData.amount << "\n";
        cout << "-------------------------------\n";
    }
}

void changeDiff(){
    int difficulty;
    cout<<"Enter New Difficulty : ";
    cin>>difficulty;
    bChain.changeDifficulty(difficulty);
}

void graphConverter(){
    //G.clearGraph();
    for (int l = 1; l < id; l++)
    {   int from,to,amt;
        Block b = bChain.vChain.at(l);

        from = b.blockData.from ;
        to = b.blockData.to ;
        amt = b.blockData.amount;
        
        G.addEdge(from,to,amt);
    }
}

void displayGraph(){
    G.printGraph();
}
