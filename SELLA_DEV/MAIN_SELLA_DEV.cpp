// SELLA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "LabeledSellaMatrices.h"
#include "DeloneTypeList.h"
#include "LatticeConverter.h"
#include "LRL_CoordinateConversionMatrices.h"
#include "LRL_ReadLatticeData.h"
#include "LRL_StringTools.h"
#include "LRL_ToString.h"
#include "LRL_Vector3.h"
#include "MatG6.h"
#include "S6.h"
#include "SellaBuild.h"
#include "Selling.h"

static LRL_CoordinateConversionMatrices lccm;


std::string Letters(void) {
   return "V,G,D,S,P,A,B,C,I,F,R,C3,G6,S6,B4,D7,H";
}

void OutputCellData(LatticeConverter& converter, const std::vector<LRL_ReadLatticeData>& cellDataList) {
   const std::string letters = Letters();
   for (size_t i1 = 0; i1 < cellDataList.size(); ++i1) {
      const LRL_ReadLatticeData& rcd = cellDataList[i1];
      const std::string lattice = rcd.GetLattice();
      if (letters.find(LRL_StringTools::strToupper(lattice)) == std::string::npos) continue;
      std::cout << std::endl;
      std::cout << "LRL_Cell # " << i1 << "  *******************************" << std::endl;
      converter.Output("Input Data", lattice, rcd.GetCell());
      std::cout << std::endl;
      converter.NiggliReducedOutput("Niggli Reduced", lattice, rcd.GetCell());
      std::cout << std::endl;
      converter.DeloneReducedOutput("Delone Reduced", lattice, rcd.GetCell());
      std::cout << std::endl;
      const LRL_Cell reducedCell = converter.DeloneReduceCell(lattice, rcd.GetCell());
   }
}

std::vector<LRL_ReadLatticeData> GetInputCells(void) {
   const std::string letters = Letters();
   std::string lattice;
   std::vector<LRL_ReadLatticeData> cellDataList;
   LRL_ReadLatticeData rcd;
   while (lattice != "EOF") {
      rcd.read();
      lattice = rcd.GetLattice();
      if ((!lattice.empty()) && (letters.find(toupper(lattice[0])) != std::string::npos))
         cellDataList.push_back(rcd);
   }

   return cellDataList;
}

std::vector<MatS6> vS6_Refl = MatS6::GetReflections();

std::vector<S6> MakeReflections(const S6& s6) {
   std::vector<S6> v;
   for (size_t i = 0; i < vS6_Refl.size(); ++i) {
      v.push_back(vS6_Refl[i] * s6);
   }
   return v;
}

//B4 FromPrimitiveToCentered(const std::vector<double>& v, const LRL_Cell& cell) {
//   const B4 b4(cell);
//   const Vector_3 v1 = v[0] * b4[0] + v[3] * b4[1] + v[6] * b4[2];
//   const Vector_3 v2 = v[1] * b4[0] + v[4] * b4[1] + v[7] * b4[2];
//   const Vector_3 v3 = v[2] * b4[0] + v[5] * b4[1] + v[8] * b4[2];
//   const Vector_3 v4 = -v1 - v2 - v3;
//   return B4(v1, v2, v3, v4);
//}

B4 FromPrimitiveToCentered(const std::vector<double>& v, const LRL_Cell& cell) {
   // Transpose of matrices from International Tables !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   const B4 b4(cell);
   const Vector_3 v1 = v[0] * b4[0] + v[1] * b4[1] + v[2] * b4[2];
   const Vector_3 v2 = v[3] * b4[0] + v[4] * b4[1] + v[5] * b4[2];
   const Vector_3 v3 = v[6] * b4[0] + v[7] * b4[1] + v[8] * b4[2];
   const Vector_3 v4 = -v1 - v2 - v3;
   return B4(v1, v2, v3, v4);
}

B4 FromPrimitiveToCentered(const LRL_Cell& cell, const std::vector<double>& v) {
   return FromPrimitiveToCentered(v, cell);
}

B4 FromPrimitiveTo_R1_A( const LRL_Cell& cell) {
   const B4 b4(cell);
   const Vector_3 v1 = b4[0] + b4[2];
   const Vector_3 v2 = -b4[0] + b4[1] + b4[2];
   const Vector_3 v3 = -b4[1] + b4[2];
   const Vector_3 v4 = -v1 - v2 - v3;
   return B4(v1, v2, v3, v4);
}

B4 FromPrimitiveTo_R1_TRANSPOSE(const LRL_Cell& cell) {
   const B4 b4(cell);
   const Vector_3 v1 = b4[0] - b4[1];
   const Vector_3 v2 = b4[1] - b4[2];
   const Vector_3 v3 = b4[0] + b4[1] + b4[2];
   const Vector_3 v4 = -v1 - v2 - v3;
   return B4(v1, v2, v3, v4);
}

void TestLatticeCentering() {
   LatticeConverter converter;
   DeloneTypeList latcenter;
   std::vector<LRL_ReadLatticeData> input = GetInputCells();

   exit(0);
}

std::vector<S6> GetInputSellingReducedVectors() {
   std::vector<S6> v;
   std::vector<LRL_ReadLatticeData> input = GetInputCells();
   LatticeConverter converter;


   for (size_t i = 0; i < input.size(); ++i) {
      const LRL_ReadLatticeData& rcd = input[i];
      const S6 s6 = converter.SellingReduceCell(input[i].GetLattice(), input[i].GetCell());
      v.push_back(s6);
   }
   return v;
}

int seed = 19192;
GenerateRandomLattice<S6> generator(seed);

S6 GenerateRandomUnitSphereAtOrigin(const double radius) {
   S6 s6;
   for (size_t i = 0; i < 6; ++i) {
      s6[i] = 2.0 * rhrand.urand() - 1.0;
   }
   return s6 / s6.norm();
}

S6 ScaleAndThenPerturbByPercent( const S6& s6, const double scale, const double percent) {
   const S6 master = scale * s6 / s6.norm();
   const S6 ran = GenerateRandomUnitSphereAtOrigin(percent/100.0);
   const S6 scaledRandom = scale * percent / 100.0 * ran / ran.norm();

   const double n1 = master.norm();
   const double n2 = scaledRandom.norm();
   const double n3 = (master + scaledRandom).norm();
   return master + scaledRandom;
}

void SellaLineTest(const S6& s6) {
   const S6 delta = generator.randSellingReduced();
   const size_t nsteps = 100;
   S6 step = 2.0 * delta / (nsteps - 1);
   step /= step.norm();
   S6 stepper = s6 + step * nsteps / 2;
   SellaBuild sellaBuild;
   std::vector<std::vector<std::pair<std::string, double> >  > fits;

   for (size_t i = 0; i < nsteps; ++i) {
      S6 reducedStepper;
      const bool b = Selling::Reduce(stepper, reducedStepper);
      reducedStepper = s6.norm() * reducedStepper / reducedStepper.norm();
      const std::vector<std::pair<std::string, double> > out = sellaBuild.GetVectorOfFits(reducedStepper);
      stepper -= step;
      fits.push_back(out);

      if (i == 0) {
         for (size_t k = 0; k < out.size(); ++k) {
            std::cout << out[k].first << " ";
         }
      }
      for (size_t k = 0; k < out.size(); ++k) {
         std::cout << out[k].second << " ";
      }
      std::cout << std::endl;
   }
   std::cout << fits.size() << std::endl;
}

void SellaTwoLatticeLineTest(const S6& s1, const S6& s2) {
   const S6& start(s1);
   const S6& target(s2);
   const size_t nsteps = 100;
   S6 step = (target-start) / (nsteps);
   SellaBuild sellaBuild;
   std::vector<std::vector<std::pair<std::string, double> >  > fits;

   for (size_t i = 0; i <= nsteps; ++i) {
      S6 reducedStepper;
      S6 stepper = start + step * i;
      const bool b = Selling::Reduce(stepper, reducedStepper);
      const std::vector<std::pair<std::string, double> > out = sellaBuild.GetVectorOfFits(reducedStepper);
      stepper += step;
      fits.push_back(out);

      if (i == 0) {
         for (size_t k = 0; k < out.size(); ++k) {
            std::cout << out[k].first << " ";
         }
      }
      for (size_t k = 0; k < out.size(); ++k) {
         std::cout << out[k].second << " ";
      }
      std::cout << std::endl;
   }
   std::cout << fits.size() << std::endl;
}

int main()
{
   DeloneTypeList();
   SellaBuild sellaBuild;
   //sellaBuild.Build();
   //exit(0);

   //TestLatticeCentering();

   //std::vector<S6> vLat = GetInputSellingReducedVectors();

   //const size_t n = 1000;

   //for (size_t lat = 0; lat < vLat.size(); ++lat) {
   //   std::vector<std::pair<std::string, double> > out;
   //   std::vector<double> sum(24, 0.0);
   //   std::vector<double> sumsq(24, 0.0);
   //   std::vector<doublpdbe> maxDist(24, -DBL_MAX);

   //   double sign = 1.0;
   //   for (size_t k = 0; k < n; ++k) {
   //      out = sellaBuild.GetVectorOfFits(ScaleAndThenPerturbByPercent(vLat[lat], 1000.0, sign * 0.0));
   //      if ( out.size() < sum.size()) {
   //         sum.resize(out.size());
   //         sumsq.resize(out.size());
   //      }
   //      for (size_t i = 0; i < out.size(); ++i) {
   //         if ( out[i].second > 2.0 && out[i].first == "C5 ") {
   //            const int i19191 = 19191;
   //         }
   //         sum[i] += out[i].second;
   //         sumsq[i] += out[i].second*out[i].second;
   //         maxDist[i] = std::max(maxDist[i], out[i].second);
   //      }
   //      sign = -sign;
   //   }

   //   for (size_t i = 0; i < sum.size(); ++i) {
   //      const double avg = sum[i] / n;
   //      const double stddev = sqrt(sumsq[i] / n - avg * avg);
   //      std::cout << out[i].first << "  " << avg << "   " << stddev << "      max " << maxDist[i];
   //      if (maxDist[i] > 0.0) std::cout << "    avg/max " << avg / maxDist[i];
   //      std::cout << std::endl;
   //   }
   //   std::cout << std::endl;
   //}

   //sellaBuild.ShowIndexResults();

   ////sellaBuild.TestPerps();
   //const int  i19191 = 19191;
}
