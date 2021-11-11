#include <iostream>
#include "cantera/thermo/IdealGasPhase.h"
#include "cantera/thermo/SurfPhase.h"
#include "cantera/equil/MultiPhase.h"
#include "cantera/equil/MultiPhaseEquil.h"

/* 1865 K
 * 2623 K
 * 3353 K
 * 4868 K
 * 5090 K
 * 5234 K
 *
*/

int main()
{
	auto gas= std::shared_ptr<Cantera::IdealGasPhase>(new Cantera::IdealGasPhase());
	std::vector<std::shared_ptr<Cantera::Species>> m_Gas;
	auto YamlMapGas= Cantera::AnyMap::fromYamlFile("gas.yaml");
	m_Gas= Cantera::getSpecies(YamlMapGas.at("species"));
	for (auto s : m_Gas) gas->addSpecies(s);

	auto Fe_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto FeO_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto Fe2O3_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto Fe3O4_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto Al_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto Al2O3_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto AlH3_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto Be_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto BeO_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto K_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto KO2_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto K2O_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto K2O2_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto KH_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());
	auto KOH_c= std::shared_ptr<Cantera::SurfPhase> (new Cantera::SurfPhase());

	std::vector<std::shared_ptr<Cantera::Species>> m_Fe_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_FeO_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_Fe2O3_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_Fe3O4_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_Al_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_Al2O3_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_AlH3_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_Be_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_BeO_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_K_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_KO2_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_K2O_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_K2O2_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_KH_c;
	std::vector<std::shared_ptr<Cantera::Species>> m_KOH_c;

	auto YamlMapFe_c= Cantera::AnyMap::fromYamlFile("Fe(c).yaml");
	auto YamlMapFeO_c= Cantera::AnyMap::fromYamlFile("FeO(c).yaml");
	auto YamlMapFe2O3_c= Cantera::AnyMap::fromYamlFile("Fe2O3(c).yaml");
	auto YamlMapFe3O4_c= Cantera::AnyMap::fromYamlFile("Fe3O4(c).yaml");
	auto YamlMapAl_c= Cantera::AnyMap::fromYamlFile("Al(c).yaml");
	auto YamlMapAl2O3_c= Cantera::AnyMap::fromYamlFile("Al2O3(c).yaml");
	auto YamlMapAlH3_c= Cantera::AnyMap::fromYamlFile("AlH3(c).yaml");
	auto YamlMapBe_c= Cantera::AnyMap::fromYamlFile("Be(c).yaml");
	auto YamlMapBeO_c= Cantera::AnyMap::fromYamlFile("BeO(c).yaml");
	auto YamlMapK_c= Cantera::AnyMap::fromYamlFile("K(c).yaml");
	auto YamlMapKO2_c= Cantera::AnyMap::fromYamlFile("KO2(c).yaml");
	auto YamlMapK2O_c= Cantera::AnyMap::fromYamlFile("K2O(c).yaml");
	auto YamlMapK2O2_c= Cantera::AnyMap::fromYamlFile("K2O2(c).yaml");
	auto YamlMapKH_c= Cantera::AnyMap::fromYamlFile("KH(c).yaml");
	auto YamlMapKOH_c= Cantera::AnyMap::fromYamlFile("KOH(c).yaml");

	m_Fe_c= Cantera::getSpecies(YamlMapFe_c.at("species"));
	m_FeO_c= Cantera::getSpecies(YamlMapFeO_c.at("species"));
	m_Fe2O3_c= Cantera::getSpecies(YamlMapFe2O3_c.at("species"));
	m_Fe3O4_c= Cantera::getSpecies(YamlMapFe3O4_c.at("species"));
	m_Al_c= Cantera::getSpecies(YamlMapAl_c.at("species"));
	m_Al2O3_c= Cantera::getSpecies(YamlMapAl2O3_c.at("species"));
	m_AlH3_c= Cantera::getSpecies(YamlMapAlH3_c.at("species"));
	m_Be_c= Cantera::getSpecies(YamlMapBe_c.at("species"));
	m_BeO_c= Cantera::getSpecies(YamlMapBeO_c.at("species"));
	m_K_c= Cantera::getSpecies(YamlMapK_c.at("species"));
	m_KO2_c= Cantera::getSpecies(YamlMapKO2_c.at("species"));
	m_K2O_c= Cantera::getSpecies(YamlMapK2O_c.at("species"));
	m_K2O2_c= Cantera::getSpecies(YamlMapK2O2_c.at("species"));
	m_KH_c= Cantera::getSpecies(YamlMapKH_c.at("species"));
	m_KOH_c= Cantera::getSpecies(YamlMapKOH_c.at("species"));

	Fe_c->addSpecies(m_Fe_c.front());
	FeO_c->addSpecies(m_FeO_c.front());
	Fe2O3_c->addSpecies(m_Fe2O3_c.front());
	Fe3O4_c->addSpecies(m_Fe3O4_c.front());
	Al_c->addSpecies(m_Al_c.front());
	Al2O3_c->addSpecies(m_Al2O3_c.front());
	AlH3_c->addSpecies(m_AlH3_c.front());
	Be_c->addSpecies(m_Be_c.front());
	BeO_c->addSpecies(m_BeO_c.front());
	K_c->addSpecies(m_K_c.front());
	KO2_c->addSpecies(m_KO2_c.front());
	K2O_c->addSpecies(m_K2O_c.front());
	K2O2_c->addSpecies(m_K2O2_c.front());
	KH_c->addSpecies(m_KH_c.front());
	KOH_c->addSpecies(m_KOH_c.front());

	std::shared_ptr<Cantera::MultiPhase> mix= std::shared_ptr<Cantera::MultiPhase>(new Cantera::MultiPhase);

	mix->addPhase(gas.get(), 0);
	mix->addPhase(Fe_c.get(), 0);
	mix->addPhase(FeO_c.get(), 0);
	mix->addPhase(Fe2O3_c.get(), 0);
	mix->addPhase(Fe3O4_c.get(), 0);
	mix->addPhase(Al_c.get(), 0);
	mix->addPhase(Al2O3_c.get(), 0);
	mix->addPhase(AlH3_c.get(), 0);
	mix->addPhase(Be_c.get(), 0);
	mix->addPhase(BeO_c.get(), 0);
	mix->addPhase(K_c.get(), 0);
	mix->addPhase(KO2_c.get(), 0);
	mix->addPhase(K2O_c.get(), 0);
	mix->addPhase(K2O2_c.get(), 0);
	mix->addPhase(KH_c.get(), 0);
	mix->addPhase(KOH_c.get(), 0);


	mix->init();
	mix->setMolesByName("H:44.407, O:34.704, Al:3.706, K:2.558, Be:11.096, Fe:1.791");
//	mix->setMolesByName("Al:2, O:3");
	mix->setPressure(Cantera::OneBar * 5);
	mix->setTemperature(3353);
	mix->equilibrate("TP", "gibbs");

	std::cout << "p = " << mix->pressure() << " Pa, T = " << mix->temperature() << "K, H = " << mix->enthalpy() << " S = " << mix->entropy() << std::endl;
	for (size_t i= 0; i < mix->nSpecies(); i++) {
		std::cout << i + 1 << ": " << mix->speciesName(i) << "\t" << mix->speciesMoles(i) << std::endl;
	}


	return 0;
}

