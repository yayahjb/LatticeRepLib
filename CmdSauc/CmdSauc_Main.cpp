
#include <algorithm>
#include <cmath>
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setfill, std::setw
#include <string>
#include <utility>
#include <vector>

#include "CmdSauc.h"
#include "CmdSaucConstants.h"
#include "CmdSaucProgramConstants.h"
#include "FileOperations.h"
#include "InputHandler.h"
#include "LatticeCell.h"
#include "ProgramSetup.h"
#include "ReadCmdSaucGlobalData.h"
#include "WebIO.h"

int main(int argc, char* argv[]) {
   std::cout << "; Dirichlet (Voronoi) cells" << std::endl;
   const ProgramSetup<CmdSaucContstants> CmdSauc_setup(argc, argv, "CmdSauc");

   const size_t blockstart = CmdSauc_setup.getBlockStart();
   const size_t blocksize = CmdSauc_setup.getBlockSize();
   const size_t blockend = CmdSauc_setup.getBlockEnd();
   std::cout << "; CmdSauc cell block start " << blockstart << std::endl;
   std::cout << "; CmdSauc cell block size " << blocksize << std::endl;
   std::cout << "; CmdSauc cell block end " << blockend << std::endl;

   const std::vector<LatticeCell>& inputList = CmdSauc_setup.getInputList();

   for (size_t whichCell = blockstart;
      whichCell < inputList.size() && whichCell < blockstart + blocksize; ++whichCell) {
      const std::string html = CmdSauc::HandleOneCell(CmdSaucCell(inputList[whichCell]));
      CmdSauc_setup.writeResultFile(html, whichCell);
   }

   exit(0);
}
