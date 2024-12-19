
class CapaDePresentacio {
private:
	CapaDePresentacio();

public:
	//Metode per obtenir la �nica inst�ncia
	static CapaDePresentacio& getInstance() {
		static CapaDePresentacio instance;
		return instance;
	}
	// aqu� tots els m�todes que
	void processarRegistreUsuari();
	void processarConsultaUsuari();
};