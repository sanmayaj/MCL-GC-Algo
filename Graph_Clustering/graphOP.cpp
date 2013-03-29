#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

double calcweight(vector<string> tags1, vector<string> tags2)
{
    vector<string> all;
    double count = 0, total = 0;
    for(size_t i = 0; i < tags1.size(); i++)
    {
        for(size_t j = 0; j < tags2.size(); j++)
        {
            if(tags1[i] == tags2[j])
                count++;
            if(find(all.begin(), all.end(), tags1[i]) == all.end())
            {
                all.push_back(tags1[i]);
                total++;
            }
            if(find(all.begin(), all.end(), tags2[j]) == all.end())
            {
                all.push_back(tags2[j]);
                total++;
            }
        }
    }
    return count/ total;
}
