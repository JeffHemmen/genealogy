person * new_person_procedure()
    {
    int ngender, nyear, nmonth, nday, nmat;
    char ngendercode, nname[20], nfnames[50], nplace[30];
    cout << "Name: ";
    cin >> nname;
    fflush(stdin);
    cout << "First names: ";
    cin >> nfnames;
    fflush(stdin);
    cout << "Gender (male: 'm'/female: 'f'): ";
    while(1)
    {
    cin >> ngendercode;
    fflush(stdin);
    if(ngendercode == 'm')
        ngender = 1;
    else{
            if(ngendercode == 'f' || ngendercode == 'w')
                        ngender = 0;
            else continue;
        }
    break;
    }
    cout << "Birthday and social security number (yyyy mm dd mat): ";
    cin >> nyear >> nmonth >> nday >> nmat;
    fflush(stdin);
    cout << "Birthplace: ";
    cin >> nplace;
    fflush(stdin);
    cout << "\n";
    
    person *new_person= new person(ngender, nname, nfnames, nyear, nmonth, nday, nmat, nplace);
    return new_person;
    }

person * edit_person_procedure(person * oldpers)
    {
    int ngender, nyear, nmonth, nday, nmat;
    char ngendercode, nname[20], nfnames[50], nplace[30];
    cout << "Name (" << oldpers->name << "): ";
    cin >> nname;
    fflush(stdin);
    cout << "First names (" << oldpers->fnames << "): ";
    cin >> nfnames;
    fflush(stdin);
    cout << "Gender  (" << (oldpers->gender?"m":"f") << "): ";
    while(1)
    {
    cin >> ngendercode;
    fflush(stdin);
    if(ngendercode == 'm')
        ngender = 1;
    else{
            if(ngendercode == 'f' || ngendercode == 'w')
                        ngender = 0;
            else continue;
        }
    break;
    }
    cout << "Birthday and social security number (" << oldpers->birth.year << " " << oldpers->birth.month << " " << oldpers->birth.day << " " << oldpers->birth.mat << "): ";
    cin >> nyear >> nmonth >> nday >> nmat;
    fflush(stdin);
    cout << "Birthplace (" << oldpers->birth.place << "): ";
    cin >> nplace;
    fflush(stdin);
    cout << "\n";
    
    person *new_person= new person(ngender, nname, nfnames, nyear, nmonth, nday, nmat, nplace);
    return new_person;
    }


person * add_father_procedure(person * child)
    {
    person * father;
    reinitialisize("Add father");
    
    while(1)
        {
        father = 0;
        cout << "Please complete all information about the father below:\n";
        father = new_person_procedure();
        if (!father)
                continue;
        if (!child->add_father(father))
                continue;
        child->father->add_child(child);
        break;
        }
    }

person * add_mother_procedure(person * child)
    {
    person * mother;
    reinitialisize("Add mother");
    
    while(1)
        {
        cout << "Please complete all information about the mother below:\n";
        mother = 0;
        mother = new_person_procedure();
        if(!mother)
                continue;
        if (!child->add_mother(mother))
                continue;
        child->mother->add_child(child);
        break;
        }
    }
    
person * add_partner_procedure(person * pers)
    {
    person * partner;
    reinitialisize("Add partner");
    
    while(1)
        {
        cout << "Please complete all information about the partner below:\n";
        partner = new_person_procedure();
        if(!partner)
                continue;
        if (pers->add_partner(partner))
        pers->partner->add_partner(pers);
        break;
        }
    }

person * add_child_procedure(person * parent)
    {
    person * child;
    reinitialisize("Add child");
    
    while(1)
        {
        cout << "Please complete all information about the child below:\n";
        child = 0;
        child = new_person_procedure();
                if (!child)
                                continue;
        parent->add_child(child);
        if(parent->gender)
                child->add_father(parent);
        else
                child->add_mother(parent);
        break;    
        }
    return child;
    }
