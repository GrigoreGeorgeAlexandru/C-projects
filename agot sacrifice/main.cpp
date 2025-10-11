#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Sacrifice{
public:
string type;
string leader;
string sacrifice;
string sacrifice_type;
string catalyst;
private:

};





int Check (Sacrifice sac){
int sum=10;
if (sac.type== "esoteric")
    sum+=22;
else
    sum+=24;

if ((sac.type== "esoteric" and sac.sacrifice_type== "life") || (sac.type== "knowledge" and sac.sacrifice_type== "animal"))
    sum+=10;

if(sac.sacrifice== "pet")
sum+=6;
if(sac.sacrifice== "exotic")
sum+=6;
if(sac.sacrifice== "wild")
sum+=3;
if(sac.sacrifice== "pet" && sac.type=="esoteric")
sum+=4;
if(sac.sacrifice== "blood_myself")
sum+=11;
if(sac.sacrifice== "blood_everyone")
sum+=12;
if(sac.sacrifice== "life_npc")
sum+=16;
if(sac.sacrifice== "wild" && sac.catalyst== "wood")
sum+=10;
if(sac.sacrifice== "blood_myself" && sac.catalyst== "oil")
sum+=10;
if(sac.sacrifice== "blood_everyone" && sac.catalyst== "oil")
sum+=10;
if(sac.sacrifice== "exotic" && sac.catalyst== "wildfyre")
sum+=10;
if(sac.sacrifice== "pet" && sac.catalyst== "lava")
sum+=10;
if(sac.sacrifice== "blood_myself" && sac.catalyst== "magnifying_glass")
sum+=10;
if(sac.leader== "scholar" && (sac.catalyst=="coal"||sac.catalyst=="magnifying_glass"))
sum+=10;
if(sac.leader== "witch" && sac.catalyst=="wood")
sum+=10;
if(sac.leader== "pyromancer" && sac.catalyst=="wildfyre")
sum+=10;
if(sac.leader== "septon" && sac.catalyst=="oil")
sum+=10;
if(sac.leader== "red_priest" && sac.catalyst=="lava")
sum+=10;
if(sac.leader== "warlock" && sac.catalyst=="magnifying_glass")
sum+=10;
if(sac.leader== "myself" && sac.catalyst=="magnifying_glass")
sum+=10;



if((sac.leader== "scholar" || sac.leader== "witch") && sac.sacrifice_type=="animal")
sum+=10;

if((sac.leader== "warlock" || sac.leader== "witch") && sac.sacrifice_type=="life")
sum+=10;
if(sac.leader== "myself" && sac.sacrifice=="life_npc")
sum+=10;
if(sac.leader== "red_priest" && sac.sacrifice=="life_npc")
sum+=10;

if(sac.leader=="archmaester")
sum+=10;

if(sac.leader=="myself")
sum+=10;

if(sum>=80)
    cout<<sac.type<<" + "<<sac.leader<<" + "<<sac.sacrifice<<" + "<<sac.catalyst<<"  "<<sum<<endl;

return 0;
}








int main()
{   vector<string> type  = {"knowledge", "esoteric"};
 vector<string> leader_1= {"myself", "scholar", "septon", "archmaester"}; ;
  vector<string> leader_2= {"myself","warlock","witch","pyromancer","red_priest"}; ;
  vector<string> sacrifice_1= {"pet", "exotic","wild"}; ;
    vector<string> sacrifice_2= {"blood_myself","blood_everyone","life_npc"}; ;
   vector<string> sacrifice_type= {"life", "animal"}; ;
   vector<string> catalyst= {"wood", "oil","lava","wildfyre","magnifying_glass", "coal",}; ;




for (const string& w:type){
        Sacrifice sac;
            sac.type=w;
    if(w=="esoteric"){
        for (const string& w:leader_2){
            sac.leader=w;
            for(const string& w:sacrifice_type){
                sac.sacrifice_type=w;
                if(w=="animal"){
                    for(const string& w:sacrifice_1){
                        sac.sacrifice=w;
                        for(const string& w:catalyst){
                            sac.catalyst=w;
                            Check(sac);
                        }
                    }
                }
                if( w=="life"){
                     for(const string& w:sacrifice_2){
                        sac.sacrifice=w;
                        for(const string& w:catalyst){
                            sac.catalyst=w;
                            Check(sac);
                        }
                    }
                }
            }
        }
    }
    if( w=="knowledge"){
        for (const string& w:leader_1){
            sac.leader=w;
            for(const string& w:sacrifice_type){
                sac.sacrifice_type=w;
                if(w=="animal"){
                    for(const string& w:sacrifice_1){
                        sac.sacrifice=w;
                        for(const string& w:catalyst){
                            sac.catalyst=w;
                            Check(sac);
                        }
                    }
                }
                if(w=="life"){
                     for(const string& w:sacrifice_2){
                        sac.sacrifice=w;
                        for(const string& w:catalyst){
                            sac.catalyst=w;
                            Check(sac);
                        }
                    }
                }
            }
        }
    }




}







}
