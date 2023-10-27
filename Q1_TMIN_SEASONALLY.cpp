#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main()
{
    ifstream file("TMinData - Historical.csv"); // Replace. "data.csv" with your file path
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

    for (int k = 1951; k <= 2014; k++)
    {
        if ((k % 4) == 0)
            n = 366;
        else
            n = 365;

        int i = it1;
        while (i < (it1 + n))
        {
            // FOR WINTER
            vector<double> winter(data[0].size(), 0);
            winter[0] = k;
            int win = 59;
            if (n == 366)
                win = 60;
            for (int l = i; l < (i + win); l++)
            {
                for (size_t j = 1; j < data[l].size(); ++j)
                {
                    winter[j] += data[l][j];
                }
            }
            for (size_t j = 1; j < data[i].size(); ++j)
            {
                winter[j] /= win;
            }
            i += win;
            ans.push_back(winter);

            // FOR PRE-MONSOON
            vector<double> pre(data[0].size(), 0);
            pre[0] = k;
            for (int l = i; l < (i + 92); l++)
            {
                for (size_t j = 1; j < data[l].size(); ++j)
                {
                    pre[j] += data[l][j];
                }
            }
            for (size_t j = 1; j < data[i].size(); ++j)
            {
                pre[j] /= 92;
            }
            i += 92;
            ans.push_back(pre);

            // FOR MONSOON
            vector<double> mon(data[0].size(), 0);
            mon[0] = k;
            for (int l = i; l < (i + 122); l++)
            {
                for (size_t j = 1; j < data[l].size(); ++j)
                {
                    mon[j] += data[l][j];
                }
            }
            for (size_t j = 1; j < data[i].size(); ++j)
            {
                mon[j] /= 122;
            }
            i += 122;
            ans.push_back(mon);

            // FOR POST-MONSOON
            vector<double> post(data[0].size(), 0);
            post[0] = k;
            for (int l = i; l < (i + 92); l++)
            {
                for (size_t j = 1; j < data[l].size(); ++j)
                {
                    post[j] += data[l][j];
                }
            }
            for (size_t j = 1; j < data[i].size(); ++j)
            {
                post[j] /= 92;
            }
            i += 92;
            ans.push_back(post);
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
