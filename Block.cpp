#include "utils.h"
using namespace std;
// here we implement the functionality of the class Block
// --------------------------------------------------------------------------------
Block::Block(uint32_t nIndexIn1)
{
    // initalizing the values of the block
    nIndex = (nIndexIn1);
    string from, to;
    int amount;
    if (nIndexIn1 != 0)
    {
        cout << "From:";
        cin >> from;
        cout << "To:";
        cin >> to;
        cout << "Amount:";
        cin >> amount;
        blockData.from = from;
        blockData.to = to;
        blockData.amount = amount;
    }
    nNonce = -1;
    tTime = time(nullptr);
}
// --------------------------------------------------------------------------------
string Block::GetHash()
{ // returns the string _sHash
    return sHash;
}
// --------------------------------------------------------------------------------
void Block::MineBlock(uint32_t nDifficulty)
{

    // higher nDifficulty -> greater the no of zeros -> therefore smaller the target under which sHash has to fall
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    // copying cstr into str
    string str(cstr);

    // now we try out different hash values until we get a value under the target
    do
    {
        nNonce++;
        sHash = CalculateHash();
    } while (sHash.substr(0, nDifficulty) != str);
    // the above while loop checks if the substring of sHash has the same no of 0s as str in the first nDifficulty indexes
    // if condition failes, we increment nNonce and try again till we succeed!

    cout << "Block mined: " << sHash << endl;
    // message is sent to the output buffer to say that the block has been successfully mined
}
// --------------------------------------------------------------------------------

// this function calculates the hash based on
// - index of Block
// - time it was created
// - the data in it
// - the nonce which allows the sHash to meet target
// - the hash of the previous block
string Block::CalculateHash() const
{
    stringstream ss;
    ss << nIndex << tTime << blockData.from << blockData.to << blockData.amount << nNonce << sPrevHash;

    return sha256(ss.str());
}