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
    vector<int> toList;
    vector<int> comList;
    vector<pair<int, int>> adj[100];

    void addEdge(int from, int to, int amount)
    {

        if (find(fromList.begin(), fromList.end(), from) != fromList.end())
        { // from exists
            if (find(toList.begin(), toList.end(), to) != toList.end())
            {
                // to exists
                adj[from].push_back(make_pair(to, amount));
            }
            else
            { // to doesnt exist
                toList.push_back(to);
                adj[from].push_back(make_pair(to, amount));
                numVertices++;
            }
        }
        else
        { // from doesnt exist
            if (find(toList.begin(), toList.end(), to) != toList.end())
            {
                // to exists
                fromList.push_back(from);
                adj[from].push_back(make_pair(to, amount));
            }
            else
            {
                // to doesnt exist
                fromList.push_back(from);
                toList.push_back(to);
                adj[from].push_back(make_pair(to, amount));
                numVertices++;
            }
        }
    }

    void printGraph()
    {
        int v, w;
        for (auto it = fromList.begin(); it != fromList.end(); it++)
        {
            int from = *it;
            cout << "From " << from << "->";
            for (auto it1 = adj[from].begin(); it1 != adj[from].end(); it1++)
            {
                v = it1->first;
                w = it1->second;
                cout << "\tTo:" << v << ",Amt:" << w;
            }
            cout << "\n";
        }
    }

    void findInOutDegree()
    {
        vector<int> iN(100, 0);
        vector<int> ouT(100, 0);
        //fill(total.begin(), total.end(), 0);
        vector<int> total(100, 0);
        vector<int> AB;

        int v, w;
        for (auto it = fromList.begin(); it != fromList.end(); it++)
        {
            int from = *it;
            ouT[from] = adj[from].size();
            for (auto it1 = adj[from].begin(); it1 != adj[from].end(); it1++)
            {
                v = it1->first;
                w = it1->second;
                iN[v]++;
                //cout << "\tTo:" << v << ",Amt:" << w;
            }
            //cout << "\n";
        }

        // AB.insert(AB.end(), fromList.begin(), fromList.end());
        // AB.insert(AB.end(), toList.begin(), toList.end());

        // cout<<"From List:";
        // for (auto it = fromList.begin(); it != fromList.end(); it++)
        // {
        //     int from = *it;
        //     cout<<from<<" ";
        // }
        // cout<<"\nTo List:";
        // for (auto it = toList.begin(); it != toList.end(); it++)
        // {
        //     int to = *it;
        //     cout<<to<<" ";
        // }

        for (auto it = fromList.begin(); it != fromList.end(); it++)
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

        for (auto it = toList.begin(); it != toList.end(); it++)
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
            int t = *it;
            total[t] = ouT[t] + iN[t];
        }

        //sort(total.begin(), total.end(), greater<int>());

        int k = 1;
        int f = AB.size();

        cout << "\n";
        for (auto it = AB.begin(); it != AB.end(); it++)
        {
            int l = *it;
            cout << "User " << l << ": " << total[l] << "\n";
            k++;
        }
        cout << "\n";
    }

    int count_paths(int src, int dst)
    {
        int path_count = 0;
        vector<bool> visited(100, false);
        path_counter(src, dst, path_count, visited);
        return path_count;
    }

    /*
 * A recursive function that counts all paths from src to
 * dst. Keep track of the count in the parameter.
 */
    void path_counter(int src, int dst, int &path_count,vector<bool> &visited)
    {
        visited[src] = true;
        if (src == dst)
        {
            path_count++;
        }
        else
        {
            for (auto it1 = adj[src].begin(); it1 != adj[src].end(); it1++)
            {
                int v = it1->first;
                if (!visited[v])
                    path_counter(v, dst, path_count,visited);
            }
        }
        visited[src] = false;
    }
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
void findInOutDegree();
void connections();
void scc();

//---------------------------------------------------------------------------

#endif