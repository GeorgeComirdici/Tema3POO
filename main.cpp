#include <iostream>
#include <list>
#include <iterator>
#include <typeinfo>
using namespace std;

class Animal
{
protected:
    string nume;
    int varsta;
public:
    //constructor de initializare
    Animal()
    {
         varsta=0;
    }
    //constructor parametrizat
    Animal(string name,int age)
    {
        nume=name;
        varsta=age;
    }
    //constructor de copiere
    Animal(const Animal &a)
    {
        nume=a.nume;
        varsta=a.varsta;
    }
    //destructor + tratarea exceptiei in care animalul nu are varsta introdusa
    ~Animal()
    {
        try {
           varsta=0;
           throw(varsta);
        }
        catch(int varsta)
        {
            if(varsta==0)
                return;
        }
    }
    //supraincarcare <<
    friend ostream& operator<<(ostream &os,const Animal &a)
    {
        cout<<"Sunt"<<a.nume<<",am"<<a.varsta<<"ani";
        return os;
    }
    //supraincarcare >>
    friend istream& operator>>(istream &is,Animal &a)
    {
        cout<<"Numele animalului?"<<endl;
        is>>a.nume;
        cout<<"Varsta animalului?"<<endl;
        is>>a.varsta;
        return is;
    }
    //supraincarcare =
    Animal& operator=(const Animal& a)
    {
        nume=a.nume;
        varsta=a.varsta;
        return *this;
    }
    //functie virtuala de afisare
    virtual void afisare(){};
};

class Animale_nevertebrate:public Animal
{
    int greutate;
public:
    //constructor fara parametru
    Animale_nevertebrate()
    {
        greutate=0;
    }
    //apel constructor din clasa Animal
    Animale_nevertebrate(string name,int age):Animal(name,age)
    {
        nume=name;
        varsta=age;
    }
    //constructor de copiere din clasa Animal
    Animale_nevertebrate(const Animale_nevertebrate& a):Animal(a)
    {
        nume=a.nume;
        varsta=a.varsta;
    }
    //destructor
    ~Animale_nevertebrate(){};
    //supraincarcare >>
    friend istream& operator>>(istream &is,Animale_nevertebrate &nevert)
    {
        cout<<"Numele animalului?"<<endl;
        is>>nevert.nume;
        cout<<"\nVarsta animalului?"<<endl;
        is>>nevert.varsta;
        cout<<"\nGreutate?"<<endl;
        is>>nevert.greutate;
        return is;
    }
    void operator=(const Animale_nevertebrate &nevert)
    {
        greutate=nevert.greutate;
    }
    //functia de afisare din clasa de baza
    void afisare()
    {
        cout<<nume<<"nevertebrat/a, "<<greutate<<"kg si "<<varsta<<"ani"<<endl;
    }
};

class Animale_vertebrate:public Animal
{
protected:
    int nrPicioare;
public:
    //constructor de initializare
    Animale_vertebrate()
    {
        nrPicioare=0;
    }
    //constructor parametrizat
    Animale_vertebrate(int nrPici)
    {
        nrPicioare=nrPici;
    }
    //destructor
    ~Animale_vertebrate(){};
    //constructor parametrizat din clasa Animal
    Animale_vertebrate(string name,int age):Animal(name,age)
    {
        nume=name;
        varsta=age;
    }
    //constructor de copiere din clasa de baza
    Animale_vertebrate(const Animale_vertebrate& a):Animal(a)
    {
        nume=a.nume;
        varsta=a.varsta;
    }
    //supraincarcare >>
    friend istream& operator >>(istream &is,Animale_vertebrate& vert)
    {
        cout<<"Numele animalului?"<<endl;
        is>>vert.nume;
        cout<<"\nVarsta animalului?"<<endl;
        is>>vert.varsta;
        cout<<"\nCate picioare are animalul?"<<endl;
        is>>vert.nrPicioare;
        return is;
    }
    //supraincarcare =
    void operator =(const Animale_vertebrate &vert)
    {
        nrPicioare=vert.nrPicioare;
    }
    //functia de afisare din clasa de baza
    void afisare()
    {
        cout<<nume<<" vertebrat/a, "<<nrPicioare<<" picioare si "<<varsta<<" ani"<<endl;
    }
};

class Pesti:public Animale_vertebrate
{
    string culoare;
public:
    //constructor fara parametru
    Pesti()
    {
        culoare="incolor";
    }
    //constructor din clasa de animale vertebrate
    Pesti(int nrPici):Animale_vertebrate(nrPici)
    {
        nrPicioare=nrPici;
    }
    //constructor de copiere din clasa de baza
    Pesti(const Pesti& macrou):Animale_vertebrate(macrou)
    {
        nrPicioare=macrou.nrPicioare;
    }
    //destructor
    ~Pesti(){};
    //supraincarcare >>
    friend istream& operator>>(istream &is,Pesti& macrou)
    {
        cout<<"Ce peste este?"<<endl;
        is>>macrou.nume;
        cout<<"\nCati ani are?"<<endl;
        is>>macrou.varsta;
        cout<<"\nCe culoare are?"<<endl;
        is>>macrou.culoare;
        return is;
    }

    void operator =(const Pesti& macrou)
    {
        culoare=macrou.culoare;
    }
    //functia de afisare din clasa de baza
    void afisare()
    {
        cout<<nume<<" "<<culoare<<" ,de varsta "<<varsta<<" ani"<<endl;
    }
};

class Pasari:public Animale_vertebrate
{
    string culoarePene;
public:
    Pasari()
    {
        culoarePene="incolor";
    }
    //constructor din clasa de baza
    Pasari(int nrPici):Animale_vertebrate(nrPici)
    {
        nrPicioare=nrPici;
    }
    //constructor de copiere din clasa de baza
    Pasari(const Pasari& pas):Animale_vertebrate(pas)
    {
        nrPicioare=pas.nrPicioare;
    }
    //destructor
    ~Pasari(){};
    //supraincarcare>>
    friend istream& operator>>(istream &is,Pasari& pas)
    {
        cout<<"Ce pasare este?"<<endl;
        is>>pas.nume;
        cout<<"\nCati ani are?"<<endl;
        is>>pas.varsta;
        cout<<"\nCe culoare au penele?"<<endl;
        is>>pas.culoarePene;
        return is;
    }
    void operator =(const Pasari &pas)
    {
        culoarePene=pas.culoarePene;
    }
    //functia de afisare din clasa de baza
    void afisare()
    {
        cout<<nume<<" care are "<<varsta<<" ani si penele de culoare "<<culoarePene<<endl;
    }
};

class Mamifere:public Animale_vertebrate
{
    string culoareBlana;
public:
    Mamifere()
    {
        culoareBlana="NuAreBlana";
    }
    //constructor din clasa de baza
    Mamifere(int nrPici):Animale_vertebrate(nrPici)
    {
        nrPicioare=nrPici;
    }
    //constructor de copiere din clasa de baza
    Mamifere(const Mamifere& mami):Animale_vertebrate(mami)
    {
        nrPicioare=mami.nrPicioare;
    }
    //destructor
    ~Mamifere(){};
    //supraincarcare >>
    friend istream& operator>>(istream &is,Mamifere& mami)
    {
        cout<<"Ce animal e?"<<endl;
        is>>mami.nume;
        cout<<"\nCati ani are?"<<endl;
        is>>mami.varsta;
        cout<<"\nCe culoare are blana?"<<endl;
        is>>mami.culoareBlana;
        return is;
    }
    void operator =(const Mamifere& mami)
    {
        culoareBlana=mami.culoareBlana;
    }
    //functia de afisare din clasa de baza
    void afisare()
    {
        cout<<nume<<"care are "<<varsta<<" ani si blana de culoare "<<culoareBlana<<endl;
    }
};

class Reptile:public Animale_vertebrate
{
    string culoareSolzi;
public:
    Reptile()
    {
        culoareSolzi="NuAreSolzi";
    }
    //constructor din clasa de baza
    Reptile(int nrPici):Animale_vertebrate(nrPici)
    {
        nrPicioare=nrPici;
    }
    //constructor de copiere din clasa de baza
    Reptile(const Reptile& repti):Animale_vertebrate(repti)
    {
        nrPicioare=repti.nrPicioare;
    }
    //destructor
    ~Reptile(){};
    //supraincarcare>>
    friend istream& operator>>(istream &is,Reptile& repti)
    {
        cout<<"Ce reptila e?"<<endl;
        is>>repti.nume;
        cout<<"\nCati ani are?"<<endl;
        is>>repti.varsta;
        cout<<"\nCe culoare au solzii?"<<endl;
        is>>repti.culoareSolzi;
        return is;
    }
    void operator =(const Reptile &repti)
    {
        culoareSolzi=repti.culoareSolzi;
    }
    //functia de afisare din clasa de baza
    void afisare()
    {
        cout<<nume<<"care are "<<varsta<<" ani si solzii de culoare "<<culoareSolzi<<endl;
    }
};
//clasa pentru citire, memorare si afisare n obiecte de tipul Animal
class Citire
{
    int n;
    Animal *w;
public:
    Citire()
    {
        cout<<"numar de animale=";cin>>n;
        w=new Animal[n];
        for(int i=0;i<n;i++)
            cin>>w[i];
    }
    ~Citire()
    {
      delete []w;
      n=0;
    }
    void Affisare()
    {
        for(int i=0;i<n;i++)
            cout<<w[i]<<endl;
    }
    friend class Animal;
};
/*void showlist(list <Animal*>g)
    {
        list <Animal*> :: iterator it;
    for(it=g.begin();it!=g.end();++it)
        cout << '\t' << *it;
    cout << '\n';
    }*/
/*template <typename T>
class AtlasZoologic
{
    static int nrAnimale;
    T pagina;
public:
    AtlasZoologic()
    {
        nrAnimale=0;
    }
    ~AtlasZoologic(){};
    void Pagina(T)
    {
        cout<<"\nExista"<<typeid(T).name()<<"pe pagina"<<endl;
    }
};*/
int main()
{
    Animale_vertebrate animalul;
    cin>>animalul;
    Pasari pasare;
    cin>>pasare;
    Pesti pestele;
    cin>>pestele;
    animalul.afisare();
    pasare.afisare();
    pestele.afisare();
    /*Mamifere mamif;
    AtlasZoologic<Mamifere>atlas;
    atlas.pagina(mamif);*/
    /*list<Animal*>listaan;
    list<Animal*>::iterator it;

    listaan.push_back(&animalul);
    listaaan.push_back(&pasare);
    listaan.push_back(&pestele);
    for(it=listaan.begin();it!=listaan.end();it++)
    {

    }*/
    /*animalule.afisare();
    pasare.afisare();
    pestele.afisare();*/
    /*Citire ob;
    ob.Affisare();*/

    return 0;
}
