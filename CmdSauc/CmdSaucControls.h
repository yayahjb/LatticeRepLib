#ifndef CMDSAUC_CONTROLS_H
#define CMDSAUC_CONTROLS_H

#include "BaseControlVariables.h"
#include "CmdSaucControls.h"
#include "CmdSaucUtils.h"
#include "InputHandler.h"

#include <iostream>
#include <ostream>

class CmdSaucControls : public BaseControlVariables {
public:

   friend std::ostream& operator<< (std::ostream& os, const CmdSaucControls& cgc) {
      os << "number of cells of each type to generate: " << cgc.generateCount << std::endl;
      os << "raw types to generate: " << cgc.types << std::endl;
      for (const auto& t : cgc.selectedTypes) {
         os << "  selected type: " << t << std::endl;
      }
      return os;
   }

   CmdSaucControls() {
      InputHandler::clearHandlers();

      InputHandler::registerHandler("COUNT", 0.35,
         [this](BaseControlVariables&, const std::string& value) {
            generateCount = CmdSaucUtils::validatePointCount(stoi(value));
         });




      //InputHandler::registerHandler("PERTURBBY", 0.35,
      //   [](BaseControlVariables& cv, const std::string& value) {
      //      if (auto* followCtrl = cv.getFeature<FollowerControl>()) {
      //         followCtrl->setPerturbBy(std::stod(value));
      //      }
      //   });

      InputHandler::registerHandler("TYPE", 0.35,
         [this](BaseControlVariables&, const std::string& value) {
            std::istringstream iss(value);
            std::string token;
            while (iss >> token) {
               const std::string type = CmdSaucUtils::validateTypes(token);
               selectedTypes.insert(token);
            }
         });
   }

   int getCount() const { return generateCount; }

   std::set<std::string> getTypes() const { return selectedTypes; }

   std::vector<std::string> getTypesAsVector() const {
      std::vector<std::string> out;
      for (const auto& s : selectedTypes) {
         out.emplace_back(s);
      }
      return out;
   }
   std::string getTypesAsString() const {
      std::string out;
      for (const auto& s : selectedTypes) {
         out += s + " ";
      }
      return out;
   }

private:
   int generateCount = 5;
   std::string types;
   std::set<std::string> selectedTypes;
};
#endif // CMDSAUC_CONTROLS_H
