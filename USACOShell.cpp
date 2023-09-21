#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

ifstream read("shell.in");
ofstream write("shell.out");

vector<int> monte = {1,2,3};
vector< vector<char> >directions;
vector<int>guess;
vector< vector<int> >gamepos;
vector<char>tempss;

int var = 0; int bex = 0; int swapnum = 0; int finalans;
int sol1 = 1; int sol2 = 2; int sol3 = 3;
int solx1counter = 0; int soly2counter = 0; int solz3counter = 0; int counter = 0;

string line;
char characterlist;

int main(){
    if (read.is_open()){
        while(getline(read, line)){
            if (counter == 0){
                swapnum = stoi(line);
            }
            if (counter >= 1){
                int hextall = line.size();
                for(int h=0; h < hextall; h+=1){
                    if (isspace(line[h])!=0){
                        continue;
                    }
                    else{
                        tempss.push_back(line[h]);
                    }
                }
                directions.push_back(tempss);
            }
            counter += 1;
            tempss.clear();
        }
    }

    for(int x=0; x <= swapnum-1; x+=1){
        for(int t = 0; t < directions[x].size(); t+=1){
            int placees = directions[x][t] - '0';
            directions[x][t] = placees;
        }
        guess.push_back(directions[x][2]);
        int onepos = monte[directions[x][0]-1]; 
        int twopos = monte[directions[x][1]-1];
        monte[directions[x][0]-1] = twopos;
        monte[directions[x][1]-1] = onepos;
        gamepos.push_back(monte);
    }

    for (int z=0; z <= swapnum-1; z+=1){
        if (sol1 == gamepos[z][guess[z]-1]){
            solx1counter+=1;
        }
        if (sol2 == gamepos[z][guess[z]-1]){
            soly2counter+=1;
        }
        if (sol3 == gamepos[z][guess[z]-1]){
            solz3counter+=1;
        }
    }
    int finalans = max(solx1counter, max(soly2counter, solz3counter));
    write << finalans << endl;
    return 0;
}