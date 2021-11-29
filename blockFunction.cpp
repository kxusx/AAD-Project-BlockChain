
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
    G.addEdge(from, to, amount);
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

void changeDiff()
{
    int difficulty;
    cout << "Enter New Difficulty : ";
    cin >> difficulty;
    bChain.changeDifficulty(difficulty);
}

void graphConverter()
{
    //G.clearGraph();
    for (int l = 1; l < id; l++)
    {
        int from, to, amt;
        Block b = bChain.vChain.at(l);

        from = b.blockData.from;
        to = b.blockData.to;
        amt = b.blockData.amount;

        G.addEdge(from, to, amt);
    }
}

void displayGraph()
{
    G.printGraph();
}

void findInOutDegree()
{
    G.findInOutDegree();
}

void connections()
{
    int src, dest;
    vector<int> AB;

    for (auto it = G.fromList.begin(); it != G.fromList.end(); it++)
    {
        int from = *it;
        if (find(AB.begin(), AB.end(), from) != AB.end())
        {
            continue;
        }
        else
        {
            AB.push_back(from);
        }
    }

    for (auto it = G.toList.begin(); it != G.toList.end(); it++)
    {
        int to = *it;
        if (find(AB.begin(), AB.end(), to) != AB.end())
        {
            continue;
        }
        else
        {
            AB.push_back(to);
        }
    }

    for (auto it = AB.begin(); it != AB.end(); it++)
    {
        src = *it;
        for (auto it1 = AB.begin(); it1 != AB.end(); it1++)
        {
            dest = *it1;
            if(src!=dest){
                int c = G.count_paths(src, dest);
                cout << "Source : "<<src<<" Destination : "<<dest<<" No. of Paths : "<<c<<"\n";
            }   
        }
    }
}

void scc(){
    G.printSCC();
}
