#pragma once //Evitar inclusions multiples
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <string>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include "Excepcio.h"

using namespace std;

class ConnexioBD {
private:
	sql::mysql::MySQL_Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	#include "config.txt"

	//creadora
	ConnexioBD();

public:

	static ConnexioBD& getInstance() {
		static ConnexioBD c;
		return c;
	}

	//destructora
	~ConnexioBD();

	//consulta
	sql::ResultSet* consulta(string sql);

	//execucio
	void execucio(string sql);
};