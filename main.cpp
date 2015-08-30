#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "classes.h"
#include "procedures.h"
#include "commands.h"

person * reference;
person * chosen = 0;
char chosen_action = 0;

int main()
{
  cout << "Please complete all information about the reference person below:\n";
  cout << "(Please enter '0' for no data)\n\n";
  reference = new_person_procedure();
  reinitialisize("First person defined");
  while(std_choice());
  return 0;
}
