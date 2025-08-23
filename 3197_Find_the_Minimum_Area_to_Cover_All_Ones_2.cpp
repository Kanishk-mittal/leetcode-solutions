#include<bits/stdc++.h>
#include<iostream>  

using namespace std;

class Solution {
private:
    vector<int> minimumRectangle(vector<vector<int>>& grid,vector<int> limits){
        int min_x = grid.size(), min_y = grid[0].size();
        int max_x = -1, max_y = -1;
        for(int i = limits[0]; i < limits[2]; i++) {
            for(int j = limits[1]; j < limits[3]; j++) {
                if(grid[i][j] == 1) {
                    min_x = min(min_x, i);
                    min_y = min(min_y, j);
                    max_x = max(max_x, i);
                    max_y = max(max_y, j);
                }
            }
        }
        if(max_x < min_x) return {-1,-1,-1,-1};
        return {min_x,min_y,max_x+1,max_y+1};
    }
    int getArea(vector<int> rect) {
        return (rect[2] - rect[0]) * (rect[3] - rect[1]);
    }
    int minimumRectangleWithSplit(vector<vector<int>>& grid,vector<int> limits){
        vector<int> rect=minimumRectangle(grid,limits);
        if(rect[0]==-1) return -1;
        int minArea=getArea(rect);
        // trying to split horizontally 
        for(int i=limits[0];i<limits[2]-1;i++){
            vector<int> posTop={limits[0],limits[1],i+1,limits[3]};
            vector<int> posBottom={i+1,limits[1],limits[2],limits[3]};
            vector<int> rectTop=minimumRectangle(grid,posTop);
            vector<int> rectBottom=minimumRectangle(grid,posBottom);
            if(rectTop[0]==-1||rectBottom[0]==-1) continue;
            int area=getArea(rectTop)+getArea(rectBottom);
            minArea=min(minArea,area);
        }
        // trying to split vertically 
        for(int j=limits[1];j<limits[3]-1;j++){
            vector<int> posLeft={limits[0],limits[1],limits[2],j+1};
            vector<int> posRight={limits[0],j+1,limits[2],limits[3]};
            vector<int> rectLeft=minimumRectangle(grid,posLeft);
            vector<int> rectRight=minimumRectangle(grid,posRight);
            if(rectLeft[0]==-1||rectRight[0]==-1) continue;
            int area=getArea(rectLeft)+getArea(rectRight);
            minArea=min(minArea,area);
        }
        return minArea;
    }
    bool isAllZero(vector<vector<int>>& grid,vector<int> limits){
        for(int i = limits[0]; i < limits[2]; i++) {
            for(int j = limits[1]; j < limits[3]; j++) {
                if(grid[i][j] == 1) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int minimumSum(vector<vector<int>>& grid) {
        // first we will find the minimum rectangle and will start working on it 
        vector<int> minPos=minimumRectangle(grid,{0,0,(int)grid.size(),(int)grid[0].size()});
        int minArea=grid.size()*grid[0].size();
        // splitting horizontally the splits should be made so that atleast one row is there 
        for(int i=0;i<grid.size()-1;i++){
            vector<int> posTop={0,0,i+1,(int)grid[0].size()};
            vector<int> posBottom={i+1,0,(int)grid.size(),(int)grid[0].size()};
            // if one of them is all zero skip this one 
            if(isAllZero(grid,posTop)||isAllZero(grid,posBottom)) continue;
            // now we know that both will have some ones so trying two possibilites
            int case1=minimumRectangleWithSplit(grid,posTop)+getArea(minimumRectangle(grid,posBottom));
            int case2=minimumRectangleWithSplit(grid,posBottom)+getArea(minimumRectangle(grid,posTop));
            minArea=min(minArea,min(case1,case2));
        }
        //splitting vertically the splits should be made so that atleast one column is there
        for(int j=0;j<grid[0].size()-1;j++){
            vector<int> posLeft={0,0,(int)grid.size(),j+1};
            vector<int> posRight={0,j+1,(int)grid.size(),(int)grid[0].size()};
            // if one of them is all zero skip this one
            if(isAllZero(grid,posLeft)||isAllZero(grid,posRight)) continue;
            // now we know that both will have some ones so trying two possibilites
            int case1=minimumRectangleWithSplit(grid,posLeft)+getArea(minimumRectangle(grid,posRight));
            int case2=minimumRectangleWithSplit(grid,posRight)+getArea(minimumRectangle(grid,posLeft));
            minArea=min(minArea,min(case1,case2));
        }
        return minArea;
    }
};