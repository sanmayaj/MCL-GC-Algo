#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

double calcweight(vector<string> tags1, vector<string> tags2);

vector<string> extracttags(string s)
{
    vector<string> v;
    string temp;
    char *cstr = new char[s.length() + 1];
    strcpy(cstr, s.c_str());
    char *pch;
    pch = strtok (cstr, ",");
    while(pch != NULL)
    {
        temp.assign(pch);
        v.push_back(temp);
        pch = strtok (cstr, ",");
    }
    delete [] cstr;
    delete [] pch;
    return v;
}

void tagsdata(double Adjacency_Matrix[][100])
{
    ifstream file;
    string s;
    vector<vector<string> > tagdat;
    file.open("C:\\Users\\Sanmaya Jolly\\Documents\\influential_bloggers_tags_data.txt", ios::in);
    if(!file.is_open())
    {
        cout<<"Unable to open file"<<endl;
        return;
    }
    while(!file.good())
    {
        getline(file, s);
        tagdat.push_back(extracttags(s));
    }
    /*int count = 0;
    while(count < 80)
    {
        getline(file, s);
        tagdat.push_back(extracttags(s));
        count++;
    }*/
    for(size_t i = 0; i < tagdat.size(); i++)
    {
        for(size_t j = 0; j < tagdat.size(); j++)
            Adjacency_Matrix[i][j] = calcweight(tagdat[i], tagdat[j]);
    }
}
