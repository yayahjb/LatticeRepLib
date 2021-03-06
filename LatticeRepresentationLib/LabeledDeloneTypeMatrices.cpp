#include "GenerateRandomLattice.h"
#include "LabeledSellaMatrices.h"
#include "LabeledDeloneTypeMatrices.h"
#include "S6Dist.h"
#include "DeloneTypeList.h"
#include <string>


bool LabeledDeloneTypeMatrices::AlreadyHasThisProjector( const MatS6& m, const LabeledDeloneTypeMatrices& lsm) const{
   for (size_t i=0; i<lsm.m_prjs.size(); ++i ) {
      const double d = (m - lsm.m_prjs[i]).norm();
      if ((m - lsm.m_prjs[i]).norm() < 1.0E-4) return true;
   }
   return false;
}

std::vector<LabeledDeloneTypeMatrices> 
   LabeledDeloneTypeMatrices::ProcessVectorMapToPerpsAndProjectors
   (const std::map<std::string, std::vector<S6_Ordinals> >& themap)
{
   static const MatS6 unit = MatS6().unit();
   std::vector<LabeledDeloneTypeMatrices> vlsm;
   for (std::map<std::string, std::vector<S6_Ordinals> >::const_iterator it = themap.begin(); it != themap.end(); ++it) {
      const std::pair<std::string, std::vector<S6_Ordinals> > p = *it;
      LabeledDeloneTypeMatrices lsm;
      std::vector<MatS6> vmprj;
      std::vector<MatS6> vmprp;
      std::vector<MatS6> vmcan;
      const std::string label = p.first;
      lsm.m_label = label;
      for (size_t i = 0; i < p.second.size(); ++i) {
         const MatS6 prj = ProjectorFromVector(label, p.second[i]);
         if (!AlreadyHasThisProjector(prj, lsm)) {
            lsm.m_prjs.push_back(ProjectorFromVector(label, p.second[i]));
            lsm.m_perps.push_back(unit - ProjectorFromVector(label, p.second[i]));
            lsm.m_toCanons.push_back(ToCanon(p.second[i]));
         }
      }

      vlsm.push_back(lsm);
   }
   return vlsm;
}

MatS6 LabeledDeloneTypeMatrices::ToCanon(const S6_Ordinals& s) {
   const MatS6 fromCanon = ToCanon(s.m_ordinals);
   MatN mn(6);
   mn.SetVector(fromCanon.GetVector());
   MatS6 ms6I = mn.inverse();
   for (size_t i = 0; i < 36; ++i) if(ms6I[i] == 0.0) ms6I[i] = 0.0;
   return ms6I;
}

MatS6 LabeledDeloneTypeMatrices::ToCanon(const S6& s) {
   MatS6 m(MatS6().Zero());
   for (size_t i = 0; i < 6; ++i) {
      m[6 * i + int(s[i])] = 1.0;
   }
   return m;
}

std::vector<MatS6> LabeledDeloneTypeMatrices::GetPrj(const std::string& s) {
   return m_prjs;
}

std::vector<MatS6> LabeledDeloneTypeMatrices::GetPerp(const std::string& s) {
   return m_perps;
}

std::vector<MatS6> LabeledDeloneTypeMatrices::GetTocanon(const std::string& s) {
   return m_toCanons;
}

size_t LabeledDeloneTypeMatrices::Index6(const size_t i, const size_t j) {
   return 6 * i + j % 6;
}

static size_t CountEqualButNonZero(const double d, const S6& s) {
   size_t count = 0;
   for (size_t i = 0; i < 6; ++i) {
      if (abs(s[i] - d) < 1.0E-6 && abs(d) > 1.0E-6) ++count;
   }
   return count;
}

 double LabeledDeloneTypeMatrices::Fraction(const double d, const S6& s) {
   const double count = CountEqualButNonZero(d, s);
   return (count == 0.0) ? 0.0 : 1.0 / (double)(count);
}

static S6 ReZeroScalars(const S6& s) {
   S6 s6(s);
   for (size_t i = 0; i < 6; ++i)
      if (abs(s6[i]) < 1.0E-6) s6[i] = 0.0;
   return s6;
}

MatS6 LabeledDeloneTypeMatrices::ProjectorFromVector(const std::string& label, const S6& s6in) {
   MatS6 m;
   m = m.Zero();
   const S6 s = ReZeroScalars(s6in);

   for (size_t j = 0; j < 6; ++j) {
      for (size_t k = j; k < 6; ++k) {
         const double thisFrac = Fraction(s[k], s);
         m[Index6(j, k)] = (abs(s[j] - s[k]) < 1.0E-5 && abs(s[k]) > 1.0E-5) ? thisFrac : 0.0;
         m[Index6(k, j)] = m[Index6(j, k)];
      }
   }

	//std::cout << label << "   " << s << std::endl;
   //std::cout << m << std::endl << std::endl;
   return m;
}

//
static std::string WriteOneNumber(const double d) {
   std::ostringstream ostr;
   if (abs(d - 1.0 / 3.0) < 1.0E-8) ostr << "1.0/3.0";
   else if (abs(d + 1.0 / 3.0) < 1.0E-8) ostr << "-1.0/3.0";
   else if (abs(d - 2.0 / 3.0) < 1.0E-8) ostr << "2.0/3.0";
   else if (abs(d + 2.0 / 3.0) < 1.0E-8) ostr << "-2.0/3.0";
   else ostr << d;
   return ostr.str();
}

void LabeledDeloneTypeMatrices::DoPerps(const std::vector<LabeledDeloneTypeMatrices>& matsForAllDeloneTypes) const {
   for (size_t i=0; i<matsForAllDeloneTypes.size(); ++i ) {
      WriteSellaMatrices("Perp", matsForAllDeloneTypes[i].m_label, matsForAllDeloneTypes[i].m_perps);
   }
}

void LabeledDeloneTypeMatrices::DoPrjs(const std::vector<LabeledDeloneTypeMatrices>& matsForAllDeloneTypes) const {
   for (size_t i = 0; i < matsForAllDeloneTypes.size( ); ++i) {
      WriteSellaMatrices( "Prj", matsForAllDeloneTypes[i].m_label, matsForAllDeloneTypes[i].m_perps );
   }
   for (size_t i = 0; i < matsForAllDeloneTypes.size( ); ++i) {
      std::cout << matsForAllDeloneTypes[i].GetLabel( ) << "   " << matsForAllDeloneTypes[i].size( ) << std::endl;;
   }
}

void LabeledDeloneTypeMatrices::DoToCanon(const std::vector<LabeledDeloneTypeMatrices>& matsForAllDeloneTypes) const {
   for (size_t i = 0; i < matsForAllDeloneTypes.size(); ++i) {
      WriteSellaMatrices("ToCanon", matsForAllDeloneTypes[i].m_label, matsForAllDeloneTypes[i].m_toCanons);
   }
}

void LabeledDeloneTypeMatrices::WriteSellaMatrices(const std::vector<LabeledDeloneTypeMatrices>& matsForAllDeloneTypes) const {
   DoPerps(matsForAllDeloneTypes);
   DoPrjs(matsForAllDeloneTypes);
   DoToCanon(matsForAllDeloneTypes);
}

void LabeledDeloneTypeMatrices::WriteSellaMatrices(const std::string& functionName, const std::string& label, const std::vector<MatS6>& mat) const {

   std::cout << "std::vector<LabeledSellaMatrices> " << functionName << "() {" << std::endl;
   std::vector<MatS6> vm;

   std::cout << "   std::vector<MatS6> vm;\n";

      std::cout << "/*  " << label << "  */" << std::endl;
      for (size_t k = 0; k < mat.size(); ++k) {
         std::cout << "   vm.push_back(MatS6(";

         for (size_t ll = 0; ll < mat[k].size(); ++ll) {
            std::cout << WriteOneNumber(mat[k][ll]);
            const size_t ssss = mat[k].size() - 1;
            std::cout << ((ll < ssss) ? "," : "));\n");
         }
      }
      std::cout << std::endl;
      std::cout << "   return LabeledSellaMatrices(\"" << label << "\", vm);" << std::endl;

   std::cout << "}   // end of " << functionName << std::endl << std::endl;
}