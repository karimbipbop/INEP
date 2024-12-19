
class CapaDePresentacio {
private:
	CapaDePresentacio();

public:
	//Metode per obtenir la única instància
	static CapaDePresentacio& getInstance() {
		static CapaDePresentacio instance;
		return instance;
	}
	// aquí tots els métodes que
	void processarRegistreUsuari();
	void processarConsultaUsuari();
};