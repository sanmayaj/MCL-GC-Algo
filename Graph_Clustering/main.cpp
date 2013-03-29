#include <map>
#include <set>
#include <list>
#define _USE_MATH_DEFINES
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef map<char, ll> MapType;

using namespace std;

void printmat(double Matrix[][100], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<Matrix[i][j]<<" ";
        cout<<endl;
    }
}

void printvec(vector<int> v)
{
    for(size_t i = 0; i < v.size(); i++)
        cout<<v[i] + 1<<" ";
    //cout<<"Length = "<<v.size();
}

void normalize(double Matrix[][100], int n);                // MATRIX_OP
void roundmatrixto(double Matrix[][100], int n, int prec);  // MATRIX_OP
void multiply(double Matrix[100][100], int n);              // MATRIX_OP
void inflate(double Matrix[][100], int n, int p);           // MATRIX_OP

void enteradjacencymatrix(double Adjacency_Matrix[][100])
{
    int start, end, weight;
    int noofedges;
    cout<<"Enter no. of edges: ";
    cin>>noofedges;
    for(int i = 0; i < noofedges; i++)
    {
        cin>>start>>end>>weight;
        Adjacency_Matrix[start][start] = Adjacency_Matrix[end][end] = 1;
        Adjacency_Matrix[end][start] = Adjacency_Matrix[start][end] = weight;
    }
}

void tagsdata(double Adjacency_Matrix[][100]);

int main()
{
    double Adjacency_Matrix[100][100];
    vector<vector<int> > clusters;
    int e = 2, r = 2, n;
    /*cin>>n;
    for(int i = 0; i < n; i++)                      //INPUT ADJACENCY MATRIX FROM TERMINAL
        for(int j = 0; j < n; j++)
            cin>>Adjacency_Matrix[i][j];*/
    tagsdata(Adjacency_Matrix);                     //INPUT FROM TEXT FILE
    int iterations = 10;
    normalize(Adjacency_Matrix, n);
    while(iterations--)
    {
        multiply(Adjacency_Matrix, n);
        inflate(Adjacency_Matrix, n, r);
        roundmatrixto(Adjacency_Matrix, n, 3);
        normalize(Adjacency_Matrix, n);
        /*cout<<"iteration no."<<10 - iterations<<endl;
        printmat(Adjacency_Matrix, n);
        cout<<endl;*/
    }
    vector<int> t, skip;
    for(int i = 0; i < n; i++)
    {
        if(find(skip.begin(), skip.end(), i) != skip.end())
            continue;
        if(Adjacency_Matrix[i][i] == 0)
            continue;
        for(int j = 0; j < n; j++)
        {
            if(Adjacency_Matrix[i][j] > 0)
                t.push_back(j);
            if(0 < Adjacency_Matrix[i][j] && Adjacency_Matrix[i][j] < 1)
                skip.push_back(j);
        }
        if(t.size() > 0)
            clusters.push_back(t);
        t.clear();
    }
    for(vector<vector<int> >::iterator it = clusters.begin(); it != clusters.end(); it++)
    {
        printvec(*it);
        cout<<endl;
    }
    printmat(Adjacency_Matrix, n);
    return 0;
}
