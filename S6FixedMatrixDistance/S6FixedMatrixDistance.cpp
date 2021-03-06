// S6FixedMatrixDistance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "MatS6.h"
#include "S6.h"

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main()
{
   static const std::vector<std::pair<MatS6, MatS6> > red = S6::SetUnreductionMatrices();
   static const std::vector<MatS6> ref = MatS6::GetReflections();
   std::vector<std::pair<long, long> > indices;
   std::vector<MatS6> trans;

   for (size_t i = 0; i < 24; ++i) {
         trans.push_back(ref[i]);
         indices.push_back(std::make_pair(i, -1));
   }

   for (size_t i = 0; i < 24; ++i) {
      for (size_t j = 0; j < 6; ++j) {
         trans.push_back(ref[i] * red[j].first);
         indices.push_back(std::make_pair(i, j));
      }
   }
   std::cout << trans.size() << std::endl;
}
