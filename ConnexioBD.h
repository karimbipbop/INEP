#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <string>
#include <mysql_connection.h>
#include <mysql_driver.h>

using namespace std;

class ConnexioBD {
private:
	sql::mysql::MySQL_Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	#include "private.h"

	//creadora
	ConnexioBD();

public:

	static ConnexioBD& getInstance();

	//destructora
	~ConnexioBD();

	//consulta
	sql::ResultSet* consulta(string sql);

	//execucio
	void execucio(string sql);
};