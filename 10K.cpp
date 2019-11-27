#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

struct Pair{
    int x;
    int y;
};

struct cells{
    char type;
    int space = 0;
};

void PrintChart(vector<vector<cells>> &chart, int linenum, int linesize);
void FloodFill(int x, int y, char BC, int FC, vector<vector<cells>> &chart, int xbounds, int ybounds, bool done);

int main()
{
    vector<char> line;
    vector<cells> cline;
    vector<vector<char>> input;
    vector<vector<cells>> chart, filler;
    long long linenum, len, linesize, count=0, numC, tempx, tempy, BC, FC;
    bool binary = false, decimal = false, done = false;
    Pair *startpaths, *endpaths;
    long long cspace = 1;
    char temp;
    cells ctemp;

    cin >> linenum >> linesize;
    //cout << "linenum: " << linenum << " linesieze: " << linesize << endl;
    //cout << "Create the chart with a 2d vector like the problem shows" << endl;
    cin.ignore(256, '\n');
    for(int k = 0; k < linenum; k++)
    {
        for(int i = 0; i < linesize; i++)
        {
            //create one line of the chart
            cin >> temp;
            //cout << "temp is: " << temp << endl;
            line.push_back(temp);
            count++;
        }
        //push the line into the chart
        input.push_back(line);
        line.clear();
    }

    //cout << "Creating the chart of my struct" << endl;
    for(int k = 0; k < linenum; k++)
    {
        for(int i = 0; i < linesize; i++)
        {
            //cout << "Input: " << input[k][i] << endl;
            ctemp.type = input[k][i];
            cline.push_back(ctemp);
            //cout << "did insert" << endl;
        }
        chart.push_back(cline);
        cline.clear();
    }


    cin >> numC;

    //create array of pairs for the coordinates
    startpaths = new Pair[numC];
    endpaths = new Pair[numC];

    //read in coordinates
    for(int i = 0; i < numC; i++)
    {
        cin >> tempx;
        cin >> tempy;

        startpaths[i].x = tempx-1;
        startpaths[i].y = tempy-1;

        cin >> tempx;
        cin >> tempy;
        endpaths[i].x = tempx-1;
        endpaths[i].y = tempy-1;
    }

    for(int k = 0; k < linenum; k++)
    {
        for(int i = 0; i < linesize; i++)
        {
          if(chart[k][i].space == 0)
          {
            done = false;
            FloodFill(k, i, chart[k][i].type, cspace, chart, linenum-1, linesize-1, done);
            /*cout << "****************** " << endl;
            PrintChart(chart, linenum, linesize);
            cout << "****************** " << endl;*/
            cspace++;
          }
        }
    }
    /*cout << "Here" << endl;
    PrintChart(chart, linenum, linesize);*/
    for(int i = 0; i < numC; i++)
    {
        if(chart[startpaths[i].x][startpaths[i].y].space == chart[endpaths[i].x][endpaths[i].y].space)
        {
          if(chart[startpaths[i].x][startpaths[i].y].type == '1')
          {
            cout << "decimal " << endl;
          }
          else
          {
            cout << "binary " << endl;
          }
        }
        else
        {
          cout <<"neither " << endl;
        }
    }
    return 0;
}

void FloodFill(int x, int y, char BC, int FC, vector<vector<cells>> &chart, int xbounds, int ybounds, bool done)
{
    //If still in bounds of chart
    if(x > xbounds || x < 0)
        return;
    if(y > ybounds || y < 0)
        return;

    if(chart[x][y].type != BC || chart[x][y].space > 0){
        return;
    }
    if(chart[x][y].type == BC && chart[x][y].space == 0)
        chart[x][y].space = FC;

    //cout << "Calling 1" << endl;
    FloodFill(x+1, y, BC, FC, chart, xbounds, ybounds, done);
    //cout << "Calling 2" << endl;
    FloodFill(x-1, y, BC, FC, chart, xbounds, ybounds, done);
    //cout << "Calling 3" << endl;
    FloodFill(x, y+1, BC, FC, chart, xbounds, ybounds, done);
    //cout << "Calling 4" << endl;
    FloodFill(x, y-1, BC, FC, chart, xbounds, ybounds, done);

    return;
}

void PrintChart(vector<vector<cells>> &chart, int linenum, int linesize)
{
    for(int k = 0; k < linenum; k++)
    {
        for(int i = 0; i < linesize; i++)
        {
            cout << chart[k][i].type << " " << chart[k][i].space << " | ";
        }
        cout << endl;
    }
    return;
}
