// this program grew from KIMI.ai's translation of the Wikipedia page for
// Hexagonal crystal family
// https://en.wikipedia.org/wiki/Hexagonal_crystal_family
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

#include "R_Settings.h"
#include "Processing.h"
#include "ThetaInsensitive.h"
#include "HR_InfoControls.h"
#include "ProgramSetup.h"
#include "WebIO.h"

#define DEBUG 1

#include <string>

std::string escapeHtml(const std::string& input) {
    std::string result;
    result.reserve(input.length() * 2); // Reserve space to avoid frequent reallocations
    
    for (char c : input) {
        switch (c) {
            case '&':
                result += "&amp;";
                break;
            case '<':
                result += "&lt;";
                break;
            case '>':
                result += "&gt;";
                break;
            default:
                result += c;
                break;
        }
    }
    
    return result;
}


// ------------------------------------------------------------------
//  Centralised input loop
// ------------------------------------------------------------------
int main( int argc, char * argv[] )
{
   HR_InforControls controls;

   // Show program info
   std::cout << "Navigating the Hexagonal crystal family\n\n";
   WebIO webio(argc, argv, "HR_info", 0);
   if (DEBUG==1) std::cout << "webio.m_hasWebInstructions: " << webio.m_hasWebInstructions << std::endl;
   if (!webio.m_hasWebInstructions) {
       std::cout << "This program was partly written by the AI Kimi.\n"
          "Kimi used the Wikipedia page for Hexagonal crystal family\n"
          "for the source data.\n"
          "Some of the logic, especially for controls was written\n"
          "with the aid of Claude.ai";
       std::cout << "One should note that both of these AI's contributed\n"
          "a substantial number of coding errors\n\n";
   }

   std::cout << controls << std::endl;  // Show available commands

   // Use command-based input processing (true = use command system)
   InputHandler::handleInput(controls, true);

   if (controls.shouldShowControls()) {
      std::cout << controls << std::endl;
   }

   return 0;
}
