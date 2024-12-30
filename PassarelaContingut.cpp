#include "PassarelaContingut.h"

PassarelaContingut::PassarelaContingut()
{
    titol = "";
    descripcio = "";
    qualificacio = "";
    tipus = "";
}

PassarelaContingut::PassarelaContingut(sql::ResultSet* result)
{
    titol = result->getString("titol");
    descripcio = result->getString("descripcio");
    qualificacio = result->getString("qualificacio");
    tipus = result->getString("tipus");
}


PassarelaContingut::PassarelaContingut(string titolC, string descripcioC, string qualificacioC, string tipusC)
{
    titol = titolC;
    descripcio = descripcioC;
    qualificacio = qualificacioC;
    tipus = tipusC;
}

string PassarelaContingut::obteTitol()
{
    return titol;
}


string PassarelaContingut::obteDescripcio()
{
    return descripcio;
}

string PassarelaContingut::obteQualificacio()
{
    return qualificacio;
}

string PassarelaContingut::obteTipus()
{
    return tipus;
}