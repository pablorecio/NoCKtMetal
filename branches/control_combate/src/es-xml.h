#include <iostream>
#include <fstream>

#include <boost/archive/tmpdir.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>

using namespace std;

template <typename T>
void guardar_XML(const T &a, const char *fichero){
  cout << "void guardar_XML(const T &a, const char *fichero)" << endl;
  std::ofstream sal(fichero);
  cout << "std::ofstream sal(fichero);" << endl;
  assert(sal.good());
  cout << "assert(sal.good());" << endl;  
  boost::archive::xml_oarchive xml_sal(sal);
  cout << "boost::archive::xml_oarchive xml_sal(sal);" << endl;
  xml_sal << BOOST_SERIALIZATION_NVP(a);
  cout << "xml_sal << BOOST_SERIALIZATION_NVP(a);" << endl;
}

template <typename T>
void cargar_XML(T &a, const char *fichero){
  std::ifstream ent(fichero);
  assert(ent.good());
  boost::archive::xml_iarchive xml_ent(ent);
  xml_ent >> BOOST_SERIALIZATION_NVP(a);
}
