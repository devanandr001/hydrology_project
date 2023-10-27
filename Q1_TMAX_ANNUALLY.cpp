#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main()
{
    ifstream file("TMaxData - Historical.csv"); // Replace. "data.csv" with your file path
    string line;
    vector< vector<double> > data;
    string cell;

    // Read the CSV file line by line
    while (std::getline(file, line))
    {
        std::vector<double> row;
        std::stringstream ss(line);
        // Split each line into cells
        while (std::getline(ss, cell, ','))
        {
            // Convert cell value to double
            double value = stod(cell);
            row.push_back(value);
        }
        data.push_back(row);
    }

    vector< vector<double> > ans;
    int n;
    int it1 = 0;

    for (int k = 1951; k <= 2014; k++)                 //YEAR WISE 
    {
        if ((k % 4) == 0)
            n = 366;
        else
            n = 365;
        vector<double> sumValues(data[0].size());
        sumValues[0] = k;
        for (int i = it1; i < (it1 + n); i++)
        {
            // size_t j;
            int temp=0;
            for (size_t j = 1; j < data[i].size(); ++j)
            {
                sumValues[j] += data[i][j];
                // temp+=data[i][j];
            }
            
        }
        for(int l = 1; l < data[0].size(); l++)
        {
        	sumValues[l] /= n;
		}
        it1 += n;

        ans.push_back(sumValues);                       //data for a year for every station is pushed as a row into ans
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ",";
        }
        cout << endl;
    }
    
    return 0;
}
