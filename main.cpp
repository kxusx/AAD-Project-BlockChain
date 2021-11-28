#include "utils.h"
using namespace std;

int id = 1;

int main() {  
    

    
    int difficulty,choice=0;
    printf("HI\n");
    while(1){
        cout<<"1. Insert Block\n";
        cout<<"2. Display last block inserted\n";
        cout<<"3. Display all blocks\n";
        cout<<"4. Exit\n";
        cin>> choice;

        switch(choice){
            case 1 : blockInsertion();
                     //printf("Hello\n");
                     break;
            case 2 : displayLastBlock();
                     break;
            case 3 : displayAllBlocks();
                     break;
            case 4 : return 0;
        }     
    }
    return 0;
}

