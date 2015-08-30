#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class childlist;
class person;
class birthdata;

extern person * reference;
extern person * edit_person_procedure(person * some_person);

class childlist
    {
    //friend void person::add_child(person *c);
    public:
    person * child;
    childlist * next;
    };

class dates
    {
    friend class person;
    friend ostream& operator<< (ostream& os, person& p);
    public:
    int year;
    int month;
    int day;
    int mat;
    char place[50];
    };

class person
    {
    friend ostream& operator<< (ostream& os, person& p);
    public:
    int gender;
    char name[20];
    char fnames[50];
    dates birth;
    dates death;
    person *father;
    person *mother;
    person *partner;
    childlist * children;
    person(int igender, char *iname, char *ifnames, int iyear=0, int imonth=0, int iday=0, int imat=0, char *iplace=0, person *ifather=0, person *imother=0);
    int add_father(person *f);
    int add_mother(person *m);
    int add_partner(person *p);
    int add_child(person *c);
    int edit();
    };

int reinitialisize(char * action)
                                                                                     {
    system("cls");
    if(reference)
        cout << "# " << reference->name << ", " << reference->fnames << "\n#\n";
    else
        cout << "# Creating reference person...\n#\n";
    cout << "# " << action;
    cout << "\n#\n###############################################################################\n\n";
    return 1;
    }

person::person(int igender, char *iname, char *ifnames, int iyear=0, int imonth=0, int iday=0, int imat=0, char *iplace=0, person *ifather=0, person *imother=0)
    {
    this->gender = igender;
    memcpy(this->name, iname, strlen(iname)+1);
    memcpy(this->fnames, ifnames, strlen(ifnames)+1);
    this->father = ifather;
    this->mother = imother;
    this->birth.year = iyear;
    this->birth.month = imonth;
    this->birth.day = iday;
    this->birth.mat = imat;
    memcpy(this->birth.place, iplace, strlen(iplace)+1);
    this->children = 0;
    this->partner = 0;
    }

//just for control
/*person::~person()
    {
    cout << this->fnames << " " << this->name << "destructed!\n";
    }*/

int person::add_father(person *f)
    {
    if (f->gender)
        {
        this->father = f;
        return 1;
        }
    reinitialisize("Add father | Error");
    cout << "\n#####\nError: a father must be male!\n#####\n";
    getchar();
    reinitialisize("Add father");
    return 0;
    }

int person::add_mother(person *m)
    {
    if (!m->gender)
        {
        this->mother = m;
        return 1;
        }
    reinitialisize("Add mother | Error");
    cout << "\n#####\nError: a mother must be female!\n#####\n";
    getchar();
    reinitialisize("Add mother");
    return 0;
    }

int person::add_partner(person *p)
    {
    this->partner = p;
    return 1;
    }

int person::edit()
    {
    person * newref;
    person * oldref = reference;
    person * mother = reference->mother;
    person * father = reference->father;
    person *partner = reference->partner;
    childlist *children = reference->children;
    reinitialisize("Edit");
    cout << "Please complete the following form including the changes:\n";
    newref = edit_person_procedure(reference);
    if(!newref)
        return 0;
    reference = newref;
    reference->mother = mother;
    reference->father = father;
    reference->partner = partner;
    reference->children = children;
    oldref->~person();
    return 1;
    }

int person::add_child(person *c)
    {
    childlist * newcl;
    childlist * oldcl;
    newcl = (childlist *)malloc(sizeof(childlist));
    oldcl = this->children;
    newcl->child = c;
    newcl->next  = 0;
    if(this->children == 0)                                  //there are no children yet
        {
        this->children = newcl;
        }
    else
        {
            while(oldcl->next)                               //there are already children => this.children is not 0
            oldcl = oldcl->next;
            oldcl->next = newcl;
        }
    return 1;
    }

ostream& operator<< (ostream& os, person& p)
    {
    childlist* childs;
    reinitialisize("All information");
    os << p.name << ", " << p.fnames << "\nBorn";
    if(p.birth.place)
        os << " in " << p.birth.place;
    if(p.birth.year)
        os << " on " << p.birth.day << "." << p.birth.month << "." << p.birth.year;
    os << " as a " << ((p.gender)?"boy":"girl") << "\n";
    if(p.birth.mat && p.birth.year && p.birth.month && p.birth.day)
        {
        os << "Social security number: " << p.birth.year;
        if(p.birth.month<10)
                os << '0';
        os << p.birth.month;
        if(p.birth.day<10)
                os << '0';
        os << p.birth.day;
        if(p.birth.mat<100)
                os << '0';
        if(p.birth.mat<10)
                os << '0';
        os << p.birth.mat << "\n";
        }
    if(p.father)
        os << "Father:\t" << p.father->name << ", " << p.father->fnames << "\n";
    if(p.mother)
        os << "Mother:\t" << p.mother->name << ", " << p.mother->fnames << "\n";
    if(p.partner)
        os << "Partner:\t" << p.partner->name << ", " << p.partner->fnames << "\n";
    childs = p.children;
    if(childs)
        os << "Children:";
    while(childs)
        {
        os << "\t" << childs->child->name << ", " << childs->child->fnames << "\n\t";
        childs = childs->next;
        }
    os << "\n";
    }


