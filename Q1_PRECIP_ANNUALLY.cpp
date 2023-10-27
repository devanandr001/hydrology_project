#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// PRECIPITATION ANNUALLY

int main()
{
    ifstream file("PrecipData - historical_seasonal.csv"); // Replace. "data.csv" with your file path
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
            double value = stod( cell );
            row.push_back(value);
        }
        data.push_back(row);
    }

    vector< vector<double> > ans;
    int n;
    int it1 = 0;

    for (int k = 1951; k <= 2014; k++)                    // FOR FUTURE DATA, CHANGE K VALUE AS 2015 TO 2100
    {
        if ((k % 4) == 0)
            n = 366;
        else
            n = 365;
        vector<double> sumValues(data[0].size(), 0);
        sumValues[0] = k;
        for (int i = it1; i < (it1 + n); i++)
        {
            for (size_t j = 2; j < data[i].size(); ++j)
            {
                sumValues[j] += data[i][j];
            }
        }
        it1 += n;

        ans.push_back(sumValues);
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
