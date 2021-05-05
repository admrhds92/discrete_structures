// Author: Adam Rhodes 
// Course: CSCI 3080 
// 30805
// Purpose: This lab will take in an adjacency relation and produce an adjacency matrix of the graph.
// It will also tell the user if there are any isolated nodes and if a Euler path exists for the graph.
// Due: 10/28/2020

#include <iostream>
#include <string>
using namespace std;

int main()

{
    
    int nodes[10][10]; //Maximum matrix size 10x10
    int size; // User defined matrix size. Up to 10x10
    int adjNodes; // Number of adjacent nodes for current node in loop
    int oddNodes = 0; // Number of odd nodes total in matrix
    int nodeWeight = 0; // Sum of adjacent nodes. If 0 then node is isolated
    int isoNodes = 0; // Sum of isolated nodes
    string relation; // Input in form of {(x,y),(x,y)...}
    
    cout << "Please input the number of nodes: \n";
    cin >> size; 
    
    // Initialize all nodes to 0
    for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                {
                    nodes[i][j] = 0;    
                }
        }

    cout << "Please input the adjaceny relation: \n";
    cin.ignore();
    getline(cin, relation);

    for (int i=0; i < relation.length(); i++)
        if (isdigit(relation[i]))
        {
            // relation[i] is a char. Subracting '1' gives us the char value for the number we want
            // i+2 is for skipping the characters ),( to the next integer
            nodes[relation[i] -'1'][relation[i+2]-'1'] = 1; // places 1 in index of (n, m)
            nodes[relation[i+2] - '1'][relation[i] - '1'] = 1; // places 1 in index of (m, n)

            i += 2; // skips to the next pair of ints 
        }
     cout << endl;

    // Print adjacency matrix
    cout << "The Adjacency matrix is: " << endl;
    for (int i=0; i < size; i++)
    {
        for (int j=0; j < size; j++)
            {
                cout << nodes[i][j] << " ";    
            }
        cout << endl;
    }
    cout << endl;

    // Sum adjacent nodes for current node. Sum isolated nodes
    for (int i=0; i < size; i++)
    {   
        adjNodes = 0;
        nodeWeight = 0;
        for (int j=0; j < size; j++)
            {
                if (nodes[i][j] == 1)
                    adjNodes += 1;
            }
        if (adjNodes % 2 == 1)
            oddNodes += 1;
        if (adjNodes == 0)
        {
            cout << i+1 << " is an isoldated node" << endl;
            isoNodes +=1;
        }

    }

    // Prints results for isolated nodes and Euler path
    if(isoNodes == 0)
        cout << "There are no isolated nodes" << endl;

    if (oddNodes == 0 || oddNodes == 2)    
        cout << "A Euler path DOES exist in the graph" << endl;
    else
        cout << "A Euler path DOES NOT exist in the graph" << endl;

}


