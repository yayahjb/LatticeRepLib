CXX	=	g++ -g -O3 -std=gnu++17 -fpermissive
COMMAND = CmdSella

all:	$(COMMAND)

$(COMMAND):	$(COMMAND).cpp \
	Cmdsellatests.cpp VCPVector.cpp \
	CheckABReflection.h DirectClassify.h ExpandAcrossBoundaryZeros.h \
	ExploreReductionTies.h FlexibleSellaTestMode.h HelpSella.h \
	TestHarness.h VCPVector.cpp VCPVector.h\
	../InputHandler/BlockLimits.h \
	../InputHandler/ControlFeature.h \
 	../InputHandler/InputHandler.h ../InputHandler/InputHandler.cpp \
 	../InputHandler/LatticeCell.h \
	../LatticeRepresentationLib/B4.cpp \
	../LatticeRepresentationLib/C3.cpp \
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
	../LatticeRepresentationLib/GenerateLatticeTypeExamples.cpp \
	../LatticeRepresentationLib/LabeledSellaMatrices.cpp \
	../LatticeRepresentationLib/LatticeConverter.cpp ../LatticeRepresentationLib/LRL_Cell.cpp  \
	../LatticeRepresentationLib/LRL_Cell_Degrees.cpp ../LatticeRepresentationLib/LRL_CoordinateConversionMatrices.cpp \
	../LRL_Tools/LRL_inverse.cpp ../LRL_Tools/LRL_MaximaTools.cpp \
	../LatticeRepresentationLib/LRL_ReadLatticeData.cpp ../LRL_Tools/LRL_StringTools.cpp \
	../LatticeRepresentationLib/MatD13.cpp \
	../LatticeRepresentationLib/MatD7.cpp ../LatticeRepresentationLib/MatG6.cpp ../LatticeRepresentationLib/MatMN.cpp \
	../LatticeRepresentationLib/MatN.cpp ../LatticeRepresentationLib/MatS6.cpp ../LatticeRepresentationLib/Niggli.cpp \
	../LatticeRepresentationLib/Polar.h ../LatticeRepresentationLib/Polar.cpp \
	../LatticeRepresentationLib/S6.cpp ../LatticeRepresentationLib/S6Dist.cpp \
	../LatticeRepresentationLib/S6_Matrices.cpp ../LatticeRepresentationLib/Selling.cpp \
	../LatticeRepresentationLib/S6BoundaryTransforms.h ../LatticeRepresentationLib/S6BoundaryTransforms.cpp \
	../LatticeRepresentationLib/VecN.cpp  ../LatticeRepresentationLib/V7.cpp ../LRL_Tools/LRL_Vector3.cpp \
	../LatticeRepresentationLib/Vector_2.h ../LatticeRepresentationLib/Vector_2.cpp \
	../LatticeRepresentationLib/WebIO.h ../LatticeRepresentationLib/WebIO.cpp \
	../SellaLib/BravaisHeirarchy.cpp ../SellaLib/BravaisHeirarchy.h \
	../SellaLib/CmdSellaControls.h ../SellaLib/CmdSellaControls.h \
	../SellaLib/CmdSellaControls.h ../SellaLib/ConventionalCell.h \
	../SellaLib/DeloneFitComputation.cpp ../SellaLib/DeloneFitComputation.h \
	../SellaLib/Deloneparentagetest.h ../SellaLib/DiagnoseBoundaryCandidates.h \
	../SellaLib/DiagnoseO1BCoverage.h ../SellaLib/DiagnoseO2Gap.h \
	../SellaLib/FaceCrossedArrangements.h ../SellaLib/framework.h \
	../SellaLib/GrimmerDeloneTree.cpp ../SellaLib/GrimmerDeloneTree.h \
	../SellaLib/GrimmerTree.cpp ../SellaLib/GrimmerTree.h \
	../SellaLib/NestingCheckResults.h ../SellaLib/RemediatedFit.h \
	../SellaLib/SearchBoundaryNeighborsByTransform.h \
	../SellaLib/Sella.cpp ../SellaLib/Sella.h ../SellaLib/SellaLib.cpp
	$(CXX) -o $(COMMAND) -I . -I ../SellaLib -I ../LatticeRepresentationLib \
	-I ../LRL_Tools -I ../InputHandler $(COMMAND).cpp \
	Cmdsellatests.cpp VCPVector.cpp \
	VCPVector.cpp \
	../InputHandler/InputHandler.cpp \
	../LatticeRepresentationLib/B4.cpp \
	../LatticeRepresentationLib/C3.cpp \
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
	../LRL_Tools/HSV.cpp ../LRL_Tools/RGB.cpp  \
	../LatticeRepresentationLib/GenerateLatticeTypeExamples.cpp \
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
	../SellaLib/Sella.cpp \
	../LatticeRepresentationLib/VecN.cpp  ../LatticeRepresentationLib/V7.cpp ../LRL_Tools/LRL_Vector3.cpp \
	../LatticeRepresentationLib/Vector_2.cpp \
	../LatticeRepresentationLib/WebIO.cpp
	../SellaLib/BravaisHeirarchy.cpp \
	../SellaLib/DeloneFitComputation.cpp \
	../SellaLib/GrimmerDeloneTree.cpp \
	../SellaLib/GrimmerTree.cpp \
	../SellaLib/Sella.cpp ../SellaLib/SellaLib.cpp
clean:
	rm -rf $(COMMAND)
