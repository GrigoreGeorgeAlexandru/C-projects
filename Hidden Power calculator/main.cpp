#include <iostream>
#include <fstream>
using namespace std;

int main()
{
int stat[7];int q,w,e,r,t,y,u,i,o,p,S=0,nr=0;
ofstream g("IVs.in");
for(q=1; q<=6; q++)
{stat[q]=31;
for(w=1; w<=6; w++)
{if(w==q)continue;
stat[w]=31;
for(e=1; e<=6; e++)
{if(e==q||e==w)continue;
stat[e]=31;
for(r=1; r<=6; r++)
{if(r==q||r==w||r==e)continue;
stat[r]=31;
for(t=1;t<=6;t++){
if(t==q||t==w||t==e||t==r)continue;
for(u=0;u<=31;u++){
stat[t]=u;
for(y=1;y<=6;y++){
  if(y==q||y==w||y==e||y==r||y==t)continue;
  for(p=0;p<=31;p++){
stat[y]=p;
if(stat[1]%2!=0)
 S=S+1;
if(stat[2]%2!=0)
S=S+2;
 if(stat[3]%2!=0)
 S=S+4;
 if(stat[4]%2!=0)
 S=S+16;
 if(stat[5]%2!=0)
 S=S+32;
 if(stat[6]%2!=0)
 S=S+8;
if(S==63)
{nr++;
for(o=1;o<=6;o++)
g<<stat[o]<<" ";
g<<"nr"<<nr;
g<<endl;
}S=0;


}}}}}}}}return 0;}

