#include "PassarelaRelacionat.h"

PassarelaRelacionat::PassarelaRelacionat()
{
    titolX = "";
    titolY = "";
}

PassarelaRelacionat::PassarelaRelacionat(sql::ResultSet* result)
{
    titolX = result->getString("titol_x");
    titolY = result->getString("titol_y");
}

PassarelaRelacionat::PassarelaRelacionat(string titolXr, string titolYr)
{
    titolX = titolXr;
    titolY = titolYr;
}

string PassarelaRelacionat::obteTitolX()
{
    return titolX;
}


string PassarelaRelacionat::obteTitolY()
{
    return titolY;
}
