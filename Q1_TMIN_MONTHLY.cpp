#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main()
{
    ifstream file("TMinData - Historical_monthly.csv"); // Replace. "data.csv" with your file path
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
            double value = stod(cell);
            row.push_back(value);
        }
        data.push_back(row);
    }

    vector<vector<double>> ans;
    int n;
    int it1 = 0;
    vector<int> month(13, 0);
    month[1] = 31;
    month[2] = 28;
    month[3] = 31;
    month[4] = 30;
    month[5] = 31;
    month[6] = 30;
    month[7] = 31;
    month[8] = 31;
    month[9] = 30;
    month[10] = 31;
    month[11] = 30;
    month[12] = 31;

    for (int k = 1951; k <= 2014; k++)
    {
        if ((k % 4) == 0)
            n = 366;
        else
            n = 365;

        if (n == 366)
            month[2] = 29;

        int i = it1;
        while (i < (it1 + n))
        {
            vector<double> sumValues(data[0].size(), 0);
            sumValues[0] = k;
            sumValues[1] = data[i][1];
            for (int l = i; l < (i + month[data[i][1]]); l++)
            {
                for (size_t j = 2; j < data[l].size(); ++j)
                {
                    sumValues[j] += data[l][j];
                }
            }

            for (int l = 2; l < data[l].size(); l++)
            {
                sumValues[l] /= month[data[i][1]];
            }

            i += month[data[i][1]];
            ans.push_back(sumValues);
        }
        it1 += n;
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
