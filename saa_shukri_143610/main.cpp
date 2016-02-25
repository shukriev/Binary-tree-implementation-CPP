//
//  main.cpp
//  sa_shukri_143610
//
//  Created by Shukri Shukriev on 1/30/16.
//  Copyright © 2016 Shukri Shukriev. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

struct BinaryTree {
    char info[8];
    BinaryTree *leftNode, *rightNode;
    
    BinaryTree(){}
    
    BinaryTree(char data[8]) {
        strcpy(info, data);
        leftNode = NULL;
        rightNode = NULL;
    }
    
};

typedef BinaryTree* BinaryTreePointer;

void insertNode (BinaryTreePointer &bpt, char newItem[8]) {
    if (bpt == NULL) {
        bpt = new BinaryTree( newItem );
    }
    else if ( newItem < bpt->info ) {
        insertNode( bpt->leftNode, newItem );
    }
    else {
        insertNode( bpt->rightNode, newItem );
    }
}

bool removeNodeByValue(BinaryTreePointer &bpt, char nodeName[8]) {
    if (bpt == NULL) {
        // Tree is empty, so it certainly doesn't contain item.
        cout << "Tree is empty, so it certainly doesn't contain item.";
        return false;
    }
    else if (strcmp(nodeName, bpt->info) == 0){
        // Yes, the item has been found in the root node.
        cout << "Yes, the item has been found in the root node.";
        
        //Process DELETION
        if((bpt->leftNode == NULL && bpt->rightNode != NULL) || (bpt->leftNode != NULL && bpt->rightNode == NULL)) {
            if(bpt->leftNode == NULL && bpt->rightNode != NULL) {
                if(bpt->leftNode == bpt) {
                    //               Redirect current leftNode to parent leftNode
                    //               parent->leftNode = curr->rightNode;
                    
                    delete bpt;
                }
                else {
                    //              Redirect current rigtNode to parent's left node
                    //              parent->rightNode = curr->rightNode;
                    delete bpt->leftNode;
                }
            }
        }
        
        //We're looking at a leaf node
        if(bpt->leftNode == NULL && bpt->rightNode== NULL) {
//            if(parent->left == curr) parent->left = NULL;
//            else parent->right = NULL;
            delete bpt;
            
        }
        
        return true;
    }
    else if (nodeName < bpt->info) {
        // If the item occurs, it must be in the left subtree.
        return removeNodeByValue(bpt->leftNode, nodeName);
        
    }
    else {
        // If the item occurs, it must be in the right subtree.
        return removeNodeByValue(bpt->rightNode, nodeName);
    }
}

void print(BinaryTreePointer binaryTree) {
    
    if (binaryTree != NULL) {
        cout<<binaryTree->info<<endl;
        print(binaryTree->leftNode);
        print(binaryTree->rightNode);
    }
}


int main(int argc, const char * argv[]) {
    BinaryTreePointer departure;
    BinaryTreePointer landing = new BinaryTree();
    
    departure = NULL;
    landing = NULL;
    
    int command;
    
    while(command != 0) {
        
        cout << "Please enter option (1 - 5)" << endl;
        cout << "1 Add plane"
        << endl
        << "2 Control plane"
        << endl
        << "3 Print tree for flying planes"
        << endl
        << "4 print tree for departure planes"
        << endl
        << "5 print planes already fly"
        << endl
        << "0 for exit"
        << endl;
        
        cin >> command;
        
        if(command == 1){
            
        }
        switch (command) {
            case 1: {
               
                cout << "Please enter option (1 - 2)" << "\n";
                cout << "1 add departure plane" << "\n";
                cout << "2 add landing plane " << "\n";
                int sub_command = 0;
                cin >> sub_command;
                if(sub_command == 1){
                    cout << "Please enter departure plane number: ";
                    char planeNumber[8];
                    cin >> planeNumber;

                    if(strlen(planeNumber) != 7) {
                        cout << "Plane number should be with 7 chars";
                        cout << "\n";
                    }
                    
                    insertNode(departure, planeNumber);
                }else if (sub_command == 2){
                    cout << "Please enter landing plane number: ";
                    char planeNumber[8];
                    cin >> planeNumber;
                    
                    if(strlen(planeNumber) != 7) {
                        cout << "Plane number should be with 7 chars";
                        cout << "\n";
                        
                    }

                    insertNode(landing, planeNumber);
                }
                
            }
                break;
            case 2:{
                print(departure);
            }
            break;
            case 3:{
                cout << "Print tree for flying planes";
                print(landing);
                break;
            }
            case 4:
                cout << "Please insert plane number for deletion";
                char planeNumber[8];
                cin >> planeNumber;
                
                if(strlen(planeNumber) != 7) {
                    cout << "Plane number should be with 7 chars";
                }

                removeNodeByValue(departure, planeNumber);
            break;
                //            case 5:
                //                cout << "Print planes already fly";
                //                break;
                //            case 6:
                //                cout << "Planes already departure";
                //            break;
                //            
                //        default:
                //            break;
        }
    }
    
    return 0;
}
