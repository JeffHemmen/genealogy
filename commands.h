extern person * reference;
extern person * chosen;
extern char chosen_action;

void command_help()
    {
    reinitialisize("Command help");
    cout << "Possible commands:\n";
    cout << "?\tDisplays this message\n";
    cout << "s\tDisplays info about the selected person\n";
    cout << "f\tSelects selected person's father or adds a father\n";
    cout << "m\tSelects selected person's mother or adds a mother\n";
    cout << "p\tSelects selected person's partner or adds a partner\n";
    cout << "c\tSelects one of the selected person's children or adds a child\n";
    cout << "e\tEdits the selected person\n";
    cout << "d\tDeclares death of selected person (not operative)\n";
    cout << "x\tEnds this program\n";
    switch (::chosen_action)
        {
        case 'f':
        cout << "z\tDefines the selected person as father of " << chosen->fnames << " " << chosen->name << "\n";
        break;
        case 'm':
        cout << "z\tDefines the selected person as mother of " << chosen->fnames << " " << chosen->name << "\n";
        break;
        case 'c':
        cout << "z\tDefines the selected person as a child of " << chosen->fnames << " " << chosen->name << "\n";
        break;
        case 'p':
        cout << "z\tDefines the selected person as partner of " << chosen->fnames << " " << chosen->name << "\n";
        break;
        }
    }

int select_father()
    {
    char resp;
    if(reference->father)
        {
        reference = reference->father;
        cout << *reference;
        return 1;
        }
    reinitialisize("Add father ?");
    cout << "Father unknown!\nWould you like to add a father? (y/n)";
    cin >> resp;
    fflush(stdin);
        while(resp=='y'||resp=='n')
        {
            if (resp=='y')
                        {
                        reinitialisize("Add father");
                        cout << "Has the father been created yet? (y/n)";
                        cin >> resp;
                        fflush(stdin);
                        while (resp=='y'||resp=='n')
                             {
                             if (resp=='y')
                                  {
                                  cout << "Please select the father and type 'z' as command\n";
                                  ::chosen = reference;
                                  ::chosen_action = 'f';
                                  return 1;
                                  }
                             else
                                  {
                                  add_father_procedure(reference);
                                  reference = reference->father;
                                  reinitialisize("...just added!");
                                  return 1;
                                  }
                             }
                        }
            else
                        {
                        reinitialisize("");
                        return 0;
                        }
        }
    }

int select_mother()
    {
    char resp;
    if(reference->mother)
        {
        reference = reference->mother;
        cout << *reference;
        return 1;
        }
    reinitialisize("Add mother ?");
    cout << "Mother unknown!\nWould you like to add a mother? (y/n)";
    cin >> resp;
    fflush(stdin);
        while(resp=='y'||resp=='n')
        {
            if (resp=='y')
                        {
                        reinitialisize("Add mother");
                        cout << "Has the mother been created yet? (y/n)";
                        cin >> resp;
                        fflush(stdin);
                        while (resp=='y'||resp=='n')
                             {
                             if (resp=='y')
                                  {
                                  cout << "Please select the mother and type 'z' as command\n";
                                  ::chosen = reference;
                                  ::chosen_action = 'm';
                                  getchar();
                                  reinitialisize("");
                                  return 1;
                                  }
                             else
                                  {
                                  add_mother_procedure(reference);
                                  reference = reference->mother;
                                  reinitialisize("...just added!");
                                  return 1;
                                  }
                             }
                        }
            else
                        {
                        reinitialisize("");
                        return 0;
                        }
        }
    }
    
int select_partner()
    {
    char resp;
    if(reference->partner)
        {
        reference = reference->partner;
        cout << *reference;
        return 1;
        }
    reinitialisize("Add partner ?");
    cout << "Partner unknown!\nWould you like to add a partner? (y/n)";
    cin >> resp;
    fflush(stdin);
        while(resp=='y'||resp=='n')
        {
            if (resp=='y')
                        {
                        reinitialisize("Add partner");
                        cout << "Has the partner been created yet? (y/n)";
                        cin >> resp;
                        fflush(stdin);
                        while (resp=='y'||resp=='n')
                             {
                             if (resp=='y') 
                                  {
                                  cout << "Please select the partner and type 'z' as command\n";
                                  ::chosen = reference;
                                  ::chosen_action = 'p';
                                  return 1;
                                  }
                             else
                                  {
                                  add_partner_procedure(reference);
                                  reference = reference->partner;
                                  reinitialisize("...just added!");
                                  return 1;
                                  }
                             }
                        }
            else
                        {
                        reinitialisize("");
                        return 0;
                        }
        }
    }

int select_children()        
    {
    person * child;
    childlist * nxt_child;
    int i, card, maxcard;
    char resp;
    reinitialisize("Add / Select child");
    nxt_child = reference->children;
    if(!nxt_child)
        cout << "No children!\n";
    else
        {
        cout << "Children:\n";
        for(i=1; nxt_child; i++, nxt_child = nxt_child->next)
                cout << i << ": " << nxt_child->child->name << ", " << nxt_child->child->fnames << "\n";
        maxcard = i-1;
        }
    
    //reinitialisize("Add / Select child");
    cout << "\nWould you like to add a child? (y/n)";
    cin >> resp;
    fflush(stdin);
        while(resp=='y'||resp=='n')
        {
            if (resp=='y')
                        {
                        reinitialisize("Add child");
                        cout << "Has the child been created yet? (y/n)";
                        cin >> resp;
                        fflush(stdin);
                        while (resp=='y'||resp=='n')
                             {
                             if (resp=='y')
                                  {
                                  cout << "Please select the child and type 'z' as command\n";
                                  chosen = reference;
                                  chosen_action = 'c';
                                  return 1;
                                  }
                             else
                                  {
                                  child = add_child_procedure(reference);
                                  reference = child;
                                  reinitialisize("...just added!");
                                  return 1;
                                  }
                             }
                        }
            if (resp=='n')
                        {
                        nxt_child = reference->children;
                        cout << "\nPlease enter the number of the child to select (0 for cancel): ";
                        cin >> card;
                        fflush(stdin);
                        while(card<0 || card>maxcard)
                                                {
                                                cout << "Number must be between 0 and " << maxcard << "\nReenter: ";
                                                cin >> card;
                                                fflush(stdin);
                                                }
                        if(card == 0)
                                                return 0;
                        for(;card > 1; card--)
                                                {
                                                nxt_child = nxt_child->next;
                                                }
                        reference = nxt_child->child;
                        reinitialisize("");
                        return 0;
                        }
        }
    return 0;
    }

int special()
    {
    if (chosen_action == 'f')
        {
        chosen->add_father(reference);
        reference->add_child(chosen);
        chosen_action = 0;
        chosen = 0;
        }
        
    if (chosen_action == 'm')
        {
        chosen->add_mother(reference);
        reference->add_child(chosen);
        chosen_action = 0;
        chosen = 0;
        }
        
    if (chosen_action == 'c')
        {
        chosen->add_child(reference);
        chosen_action = 0;
        chosen = 0;
        }
    
    if (chosen_action == 'p')
        {
        chosen->add_partner(reference);
        reference->add_partner(chosen);
        chosen_action = 0;
        chosen = 0;
        }
    reinitialisize("...just added!");
    }

    int prgm_exit()
        {
        system("cls");
        cout << "Unable to save, sure to quit? (y/n)\n";
        getchar();
        return 0;
        }

int std_choice()
    {
    char choice;
    cout << "\n################################################################################\n";
    cout << "Please type command (type '?' for help): ";
    cin >> choice;
    fflush(stdin);
    
    switch(choice)
        {
        case '?':
                command_help();
                break;
        case 's':
                cout << *reference;
                break;
        case 'f':
                select_father();
                break;
        case 'm':
                select_mother();
                break;
        case 'p':
                select_partner();
                break;
        case 'c':
                select_children();
                break;
        case 'e':
                reference->edit();
                break;
        case 'x':
                return prgm_exit();
                break;
        case 'z':
                special();
                break;
        default:
                cout << "Invalid command!\n";
                reinitialisize("");
                break;
                
        }
    return 1;
    }
