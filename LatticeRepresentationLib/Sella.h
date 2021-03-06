#ifndef SELLA_H
#define SELLA_H

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <map>
#include <string>
#include <vector>

#include "Delone.h"
#include "LabeledSellaMatrices.h"
#include "DeloneType.h"
#include "MatS6.h"
#include "S6.h"
#include "StoreResults.h"

class SellaResult {
public:


   const std::string m_label;
   const double m_distance;
   const S6 m_projected;
   const S6 m_perped;
};

class Sella {
public:

   Sella();
   double TestOneType(const std::string& label, const S6 &s6, const std::vector<MatS6>& vm);
   std::vector<std::pair<std::string, double> > GetVectorOfFits(const S6& s6);

   std::vector<LabeledSellaMatrices> GetPerps(void) const {
      return perps;
   }

   std::vector<LabeledSellaMatrices> GetProjectors(void) const {
      return projectors;
   }

   std::pair<std::string, double>  GetBestFitForCrystalSystem(const std::string& type, const S6& s6);
   double GetFitForDeloneType(const std::string& type, const S6& s6);
   std::vector<std::pair<std::string, double> > GetAllFitsForCrystalSystem(const std::string& type);

   void GetDeloneTypesForCrystalType();
   void GetCrystalTypesForDeloneType();

private:
   static const std::vector<LabeledSellaMatrices> projectors;
   static const std::vector<LabeledSellaMatrices> perps;
	static std::vector<DeloneType> m_latticeCharacters;

private:
};

#endif // SELLA_H



