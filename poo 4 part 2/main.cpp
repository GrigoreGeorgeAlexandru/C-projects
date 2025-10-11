#include <bits/stdc++.h>
using namespace std;
class Vector{
private:
    std::vector <int*> vec;
    size_t len;
    static int nr_inst;
public:
    Vector()
    {
        nr_inst++;
    }
    static int get_nr_inst()
    {
        return nr_inst;
    }
    Vector(std::vector <int> vect) : len(vect.size())
    {
        nr_inst++;
        for(auto &it : vect)/// <=> for(int i=0; i<vect.size(); ++i), it <=>vect[i]
        {
            ///daca it nu avea referinta, it ar fi doar o copie a lui vect[i]
            vec.push_back(new int(it));///emplace_back e un push_back mai eficient
            ///vect este de int* deci trebuie sa pun un pointer in el
        }
    }
    Vector(const Vector& v) : len(v.len)
    {
        nr_inst++;
        for(auto &it : v.vec)
        {
            vec.push_back(new int(*it));
        }
    }

    friend ostream& operator<< (ostream&, const Vector&);
    friend istream& operator>>(istream&, Vector&);

    Vector operator+ (int nr) const
    {
        Vector v(*this);
        for(auto &it:v.vec)
            (*it)+=nr;
        return v;
    }

friend Vector operator+(int nr,const Vector &v)
{
    return v+nr;
}
Vector& operator=(const Vector&v)
{if(this!=&v)
    {len=v.len;

        for(auto &it:vec)
        {delete it;}

        vec.clear();
        for(auto &it:v.vec)
        {vec.push_back(new int (*it));

        }


    }
return *this;
}
int& operator[] (int poz){return *vec[poz];}


};
int Vector::nr_inst=0;///trebuie neaparat initializat aici


ostream& operator<< (ostream& out, const Vector& v){
    for(auto &it : v.vec){
        out << *it << " ";
    }
    out <<'\n';
    return out;
}
istream& operator>>(istream&in,Vector&v)
{   for(auto &it:v.vec){
    delete it;}
    v.vec.clear();
    in>>v.len;

    for(unsigned int i=0;i<v.len;i++)
    {int x;
    in>>x;
    v.vec.push_back(new int(x));}
    return in;
}



int main()
{
    Vector v;
    std::cout<<Vector::get_nr_inst();
    Vector v1(v);
    cout << '\n';
    Vector v2(std::vector<int>({2,8,-9,77,-88}));
    cout << v2<<v2;

   /* cin >> v2;
    cout << v2;*/

Vector v3 = v2 + 9;
cout << v3;
Vector v4 = 6+ v3;
	cout<< v4;
v4 = v2;
v4[1] = 100;
cout << v4;


}

