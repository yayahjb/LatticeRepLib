#include "CmdSauc.h"

#include "D7.h"
#include "GetDate.h"
#include "LatticeConverter.h"
#include "LRL_Cell_Degrees.h"
#include "LRL_DataToSVG.h"
#include "LRL_inverse.h"
#include "LRL_ReadLatticeData.h"
#include "LRL_StringTools.h"
#include "LRL_ToString.h"
#include "SVG_Tools.h"
#include "TriangleAreaFromSides.h"
#include "LRL_Vector3.h"

#include <cmath>
#include <iomanip>
#include <sstream>
#include <ctime>


std::string CmdSauc::HandleOneCell(const CmdSauc& csc) {
   std::string svg = CreateStereoSVGText(dc);
   return svg;
}

