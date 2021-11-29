#include "utils.h"
using namespace std;

int id = 1;

int main() {  
    int choice=0;
    while(1){
        cout <<"-------------------------------\n";
        cout<<"1. Insert Block\n";
        cout<<"2. Display last block inserted\n";
        cout<<"3. Display all blocks\n";
        cout<<"4. Change Difficulty of Blockchain\n";
        cout<<"5. Display Graph\n";
        cout<<"6. Display Importance of Users\n";
        cout<<"7. Find how strongly 2 nodes are connected\n";
        cout<<"8. Find strongly connected groups of users\n";
        cout<<"9. Exit\n";
        cout <<"-------------------------------\n";
        cin>> choice;
        cout <<"-------------------------------\n";

        switch(choice){
            case 1 : blockInsertion();
                     break;
            case 2 : displayLastBlock();
                     break;
            case 3 : displayAllBlocks();
                     break;
            case 4 : changeDiff();
                     break;
            case 5 : displayGraph();
                     break;
            case 6 : findInOutDegree();
                     break;
            case 7 : connections();
                     break;
            case 8 : scc();
                     break;
            case 9 : return 0;
        }     
    }
    return 0;
}

