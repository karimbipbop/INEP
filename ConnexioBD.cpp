#include "ConnexioBD.h"

ConnexioBD::ConnexioBD() {
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect(ser, nom, pass);
	con->setSchema(nom);
	stmt = con->createStatement();
}

ConnexioBD& ConnexioBD::getInstance() {
	static ConnexioBD c;
	return c;
}

//destructora
ConnexioBD::~ConnexioBD() {
	con->close();
}

//consulta
sql::ResultSet* ConnexioBD::consulta(string sql) {
	sql::ResultSet* res;
	res = stmt->executeQuery(sql);
	return res;
}

//execucio
void ConnexioBD::execucio(string sql) {
	stmt->execute(sql);
}