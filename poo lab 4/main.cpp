#include <bits/stdc++.h>

using namespace std;

class Vector{

private:
    std::vector<int*> vec;
    size_t len=0;
    static int nrinst;
    public:
Vector(){nrinst++;}

static int getNrInstances(){

return nrinst;
}

Vector(std::vector<int> vect):len(vect.size()){

 nrinst++;

 for(auto &it:vect)   //for(int=0;i<vect.size;i++)  it=vect[i]
 vec.push_back(new int(it));// vec.push_back(new int(vect[i]));




}

Vector(const Vector& v):len(v.len)
{nrinst++;

for(auto &it:v.vec)
{vec.push_back(new int(*it));///vector de pointeri,trebuie deferentiati

}
}



};
class C

{
private:
    static int x;
public:
    C(){x++;
    }

~C(){x--;}
static inline int get_x(){return x;}



};

int C::x=0;



int Vector::nrinst=0;

int main()
{/*cout<<sizeof(C);
    {C c1;
 cout<<c1.get_x()<<endl;}
 cout<<C::get_x()<<endl;
*/


Vector v;
cout<<Vector::getNrInstances()<<endl;
/*
vector v2(v1);
v2[9]=8;
cout<<v1;
*/
Vector v1(v);


}
