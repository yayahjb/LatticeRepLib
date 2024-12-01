CXX	?=	g++-9 -g -O3 -std=gnu++17 -fpermissive
COMMAND = Follow
DEBUGFLAG = "-g"

all:	$(COMMAND)

$(COMMAND):	MAIN_Follow.cpp \
	ControlVariables.cpp ControlVariables.h \
	DistanceFactory.cpp DistanceFactory.h \
	FollowUtils.h.cpp \
	InputHandler.cpp InputHandler.h \
	SvgPlotWriter.cpp SvgPlotWriter.h \
	Follow.cpp Follow.h \
	../LatticeRepresentationLib/B4.cpp \
	../LatticeRepresentationLib/BravaisHeirarchy.cpp ../LatticeRepresentationLib/C3.cpp \
	../LatticeRepresentationLib/C3Plot.cpp ../LatticeRepresentationLib/CellInputData.cpp \
	../LatticeRepresentationLib/ColorTables.h ../LatticeRepresentationLib/ColorTables.cpp \
	../LatticeRepresentationLib/DC7u.cpp \
	../LatticeRepresentationLib/D13.cpp \
	../LatticeRepresentationLib/D7_Boundary.cpp ../LatticeRepresentationLib/D7_BoundaryList.cpp  \
	../LatticeRepresentationLib/D7_ClassifySubboundaries.cpp ../LatticeRepresentationLib/D7.cpp \
	../LatticeRepresentationLib/D7_Subboundary.cpp ../LatticeRepresentationLib/Delone.cpp \
	../LatticeRepresentationLib/DeloneFitResults.cpp \
	../LatticeRepresentationLib/EnhancedS6.cpp ../LatticeRepresentationLib/EnhancedS6.h \
	../LRL_Tools/FileOperations.cpp ../LRL_Tools/LRL_CreateFileName.cpp ../LatticeRepresentationLib/G6.cpp \
	../LRL_Tools/HSV.cpp ../LRL_Tools/RGB.cpp \
	../LRL_Tools/LinearAxis.cpp ../LRL_Tools/LinearAxis.h \
	../LRL_Tools/spline_under_tension.hpp ../LRL_Tools/spline_under_tension.cpp \
	../LatticeRepresentationLib/GenerateLatticeTypeExamples.cpp \
	../LatticeRepresentationLib/GrimmerTree.h ../LatticeRepresentationLib/GrimmerTree.h \
	../LatticeRepresentationLib/Polar.h ../LatticeRepresentationLib/Polar.cpp \
	../LatticeRepresentationLib/G6.cpp ../LatticeRepresentationLib/G6.h \
	../LatticeRepresentationLib/S6.cpp ../LatticeRepresentationLib/S6.h \
	../LatticeRepresentationLib/LabeledSellaMatrices.cpp \
	../LatticeRepresentationLib/LatticeConverter.cpp ../LatticeRepresentationLib/LRL_Cell.cpp  \
	../LatticeRepresentationLib/LRL_Cell_Degrees.cpp ../LatticeRepresentationLib/LRL_CoordinateConversionMatrices.cpp \
	../LRL_Tools/LRL_inverse.cpp ../LRL_Tools/LRL_MaximaTools.cpp \
	../LatticeRepresentationLib/LRL_ReadLatticeData.cpp ../LRL_Tools/LRL_StringTools.cpp \
	../LatticeRepresentationLib/MatD13.cpp \
	../LatticeRepresentationLib/MatD7.cpp ../LatticeRepresentationLib/MatG6.cpp ../LatticeRepresentationLib/MatMN.cpp \
	../LatticeRepresentationLib/MatN.cpp ../LatticeRepresentationLib/MatS6.cpp ../LatticeRepresentationLib/Niggli.cpp \
	../LatticeRepresentationLib/S6.cpp ../LatticeRepresentationLib/S6Dist.cpp \
	../LatticeRepresentationLib/S6_Matrices.cpp ../LatticeRepresentationLib/Selling.cpp \
	../LatticeRepresentationLib/S6BoundaryTransforms.h ../LatticeRepresentationLib/S6BoundaryTransforms.cpp \
	../LatticeRepresentationLib/Sella.cpp \
	../LatticeRepresentationLib/VecN.cpp  ../LatticeRepresentationLib/V7.cpp ../LRL_Tools/LRL_Vector3.cpp \
	../LatticeRepresentationLib/Vector_2.h ../LatticeRepresentationLib/Vector_2.cpp \
	../LatticeRepresentationLib/WebIO.h ../LatticeRepresentationLib/WebIO.cpp
	$(CXX) $(DEBUGFLAG) -I ../LatticeRepresentationLib -I ../LRL_Tools -o $(COMMAND) MAIN_Follow.cpp \
	ControlVariables.cpp \
	DistanceFactory.cpp \
	Follow.cpp \
	FollowUtils.h.cpp \
	InputHandler.cpp \
	SvgPlotWriter.cpp \
	../LatticeRepresentationLib/B4.cpp \
	../LatticeRepresentationLib/BravaisHeirarchy.cpp ../LatticeRepresentationLib/C3.cpp \
	../LatticeRepresentationLib/C3Plot.cpp ../LatticeRepresentationLib/CellInputData.cpp \
	../LatticeRepresentationLib/ColorTables.cpp \
	../LatticeRepresentationLib/DC7u.cpp \
	../LatticeRepresentationLib/D13.cpp \
	../LatticeRepresentationLib/D7_Boundary.cpp ../LatticeRepresentationLib/D7_BoundaryList.cpp  \
	../LatticeRepresentationLib/D7_ClassifySubboundaries.cpp ../LatticeRepresentationLib/D7.cpp \
	../LatticeRepresentationLib/D7_Subboundary.cpp ../LatticeRepresentationLib/Delone.cpp \
	../LatticeRepresentationLib/DeloneFitResults.cpp \
	../LatticeRepresentationLib/EnhancedS6.cpp \
	../LRL_Tools/FileOperations.cpp ../LRL_Tools/LRL_CreateFileName.cpp ../LatticeRepresentationLib/G6.cpp \
	../LRL_Tools/HSV.cpp ../LRL_Tools/HSV.h ../LRL_Tools/RGB.cpp ../LRL_Tools/RGB.h \
	../LRL_Tools/LinearAxis.cpp \
	../LRL_Tools/spline_under_tension.cpp \
	../LatticeRepresentationLib/GenerateLatticeTypeExamples.cpp \
	../LatticeRepresentationLib/GrimmerTree.cpp \
	../LatticeRepresentationLib/LabeledSellaMatrices.cpp \
	../LatticeRepresentationLib/LatticeConverter.cpp ../LatticeRepresentationLib/LRL_Cell.cpp  \
	../LatticeRepresentationLib/LRL_Cell_Degrees.cpp ../LatticeRepresentationLib/LRL_CoordinateConversionMatrices.cpp \
	../LRL_Tools/LRL_inverse.cpp ../LRL_Tools/LRL_MaximaTools.cpp \
	../LatticeRepresentationLib/LRL_ReadLatticeData.cpp ../LRL_Tools/LRL_StringTools.cpp \
	../LatticeRepresentationLib/MatD13.cpp \
	../LatticeRepresentationLib/MatD7.cpp ../LatticeRepresentationLib/MatG6.cpp ../LatticeRepresentationLib/MatMN.cpp \
	../LatticeRepresentationLib/MatN.cpp ../LatticeRepresentationLib/MatS6.cpp ../LatticeRepresentationLib/Niggli.cpp \
	../LatticeRepresentationLib/Polar.cpp \
	../LatticeRepresentationLib/S6.cpp ../LatticeRepresentationLib/S6Dist.cpp \
	../LatticeRepresentationLib/S6_Matrices.cpp ../LatticeRepresentationLib/Selling.cpp \
	../LatticeRepresentationLib/S6BoundaryTransforms.cpp \
	../LatticeRepresentationLib/Sella.cpp \
	../LatticeRepresentationLib/VecN.cpp  ../LatticeRepresentationLib/V7.cpp ../LRL_Tools/LRL_Vector3.cpp \
	../LatticeRepresentationLib/Vector_2.cpp \
	../LatticeRepresentationLib/WebIO.cpp

clean:
	rm -rf $(COMMAND)
