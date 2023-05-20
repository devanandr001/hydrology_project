#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
// #include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream file("historical_full_data.csv"); // Replace. "data.csv" with your file path
    string line;
    vector<vector<double>> data;
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
            double value = std::stod(cell);
            row.push_back(value);
        }
        data.push_back(row);
    }

    vector<vector<double>> ans;
    int n;
    int it1 = 0;

    for (int k = 1951; k <= 2014; k++)
    {
        if ((k % 4) == 0)
            n = 366;
        else
            n = 365;
        vector<double> maxValues(data[0].size(), -1.79769E+308);
        maxValues[0] = k;
        for (int i = it1; i < (it1 + n); i++)
        {
            for (size_t j = 1; j < data[i].size(); ++j)
            {
                if (data[i][j] >= maxValues[j])
                {
                    maxValues[j] = data[i][j];
                }
            }
        }
        it1 += n;

        ans.push_back(maxValues);
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
