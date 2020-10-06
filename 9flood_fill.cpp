//Flood fill, also called seed fill, is an algorithm that determines the area connected to a given node in a multi-dimensional array. 
//It is used in the "bucket" fill tool of paint programs to determine which parts of a bitmap to fill with color, and in games such as Go and Minesweeper for determining which pieces are cleared.
//When applied on an image to fill a particular bounded area with color, it is also known as boundary fill.

//The algorithm is simple. Just use a recursive function to check the node is connected or not which are adjacent to one node:
/*Flood-fill (node, target-color, replacement-color):
 1. If the color of node is not equal to target-color, return.
 2. Set the color of node to replacement-color.
 3. Perform Flood-fill (one step to the west of node, target-color, replacement-color).
    Perform Flood-fill (one step to the east of node, target-color, replacement-color).
    Perform Flood-fill (one step to the north of node, target-color, replacement-color).
    Perform Flood-fill (one step to the south of node, target-color, replacement-color).
5.  Return.*/
//source:codeforces blog
#include<iostream>

 

using namespace std;

 

int r,c,mat[100][100];

 
void rec(int i, int j) {
   if (i < 0 || i >= r || j < 0 || j >= c)
      return;
   if (mat[i][j] != 1)
      return;
   mat[i][j] = 0;
   for (int di = -1; di <= 1; ++di)
      for (int dj = -1; dj <= 1; ++dj)
         if (di != 0 || dj != 0)
            rec(i + di, j + dj);
}
 
 

void floodfill()

{

 int i,j,count=0;   

 for(i=0;i<r;i++)

 {

  for(j=0;j<c;j++)

  {

   if(mat[i][j]==1)

   {                             

    count++;

    rec(i,j);

   }              

  }               

 }

 cout<<"The Number Of Disjoint Nodes: "<<count<<endl;    

}

 

int main()

{

 int i,j;  

   

 cout<<"Number of Row : ";

 cin>>r;

 cout<<"Number Of Column : ";

 cin>>c;

 

 cout<<"Give The Map : "<<endl;

 

 for(i=0;i<r;i++)

 {

  for(j=0;j<c;j++)

  {              

   cin>>mat[i][j];               

  }               

 }

 

 floodfill();

   

 return 0;    

}

 




