#include "search.hpp"
#include "graphs.hpp"
#include "lists.hpp"
#include <queue>
#include <stack>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef unsigned int Vertex;

int main (){

Graph graf;

string name;

cout<<"Insert file name:";
cin>>name;
cout<<endl;

ifstream input(name);

int vertices,edges;
input>>vertices>>edges;
cout<<vertices<<" "<<edges<<endl;
Vertex vertex1,vertex2;
while(edges>0)
{input>>vertex1>>vertex2;
cout<<vertex1<<" "<<vertex2<<endl;
graf.add_node(vertex1);
graf.add_node(vertex2);
graf.add_edge(vertex1,vertex2);
 edges--;
}

cout<<"boop";


}
