CPP	?= g++
CFLAGS	?= -g -O3

HEADERS = ConstSingleton_T.h \
    	FileOperations.h \
	Filter_Duplicates.h \
	GetDate.h \
	HSV.h \
	LinearAxis.h \
	LRL_CreateFileName.h \
	LRL_DataStreamToString.h \
	LRL_DataToSVG.h \
	LRL_inverse.h \
	LRL_MaximaTools.h \
	LRL_MinMaxTools.h \
	LRL_RandTools.h \
	LRL_StringTools.h \
	LRL_ToString.h \
	LRL_Vector3.h \
	Mat.h \
	PairReporter.h \
	RGB.h \
	rhrand.h \
	ScoredReservoir.h \
	spline_under_tension.hpp \
	StoreResults.h \
	StringMatcher.h \
	SuperFastHash.h \
	SVG_Tools.h \
	TensionSpline.h \
	Theta.h \
	ThetaInsensitive.h \
	TNear.h \
	TriangleAreaFromSides.h \
	triple.h \
	ConstSingleton_T.h \
	FileOperations.h \
	Filter_Duplicates.h \
	GetDate.h \
	HSV.h \
	LinearAxis.h \
	LRL_CreateFileName.h \
	LRL_DataStreamToString.h \
	LRL_DataToSVG.h \
	LRL_inverse.h \
	LRL_MaximaTools.h \
	LRL_MinMaxTools.h \
	LRL_RandTools.h \
	LRL_StringTools.h \
	LRL_ToString.h \
	LRL_Vector3.h \
	Mat.h \
	NumericTools.h \
	PairReporter.h \
	RGB.h \
	rhrand.h \
	ScoredReservoir.h \
	spline_under_tension.hpp \
	StoreResults.h \
	StringMatcher.h \
	SuperFastHash.h \
	SVG_Tools.h \
	TensionSpline.h \
	Theta.h \
	ThetaInsensitive.h \
	TNear.h \
	TriangleAreaFromSides.h \
	triple.h

OBJECTS	= FileOperations.o \
	GetDate.o \
	HSV.o \
	LinearAxis.o \
	LRL_CreateFileName.o \
	LRL_inverse.o \
	LRL_MaximaTools.o \
	LRL_RandTools.o \
	LRL_StringTools.o \
	LRL_Vector3.o \
	RGB.o \
	spline_under_tension.o \
	SuperFastHash.o \
	SVG_Tools.o \
	TriangleAreaFromSides.o


FileOperations.o:	$(HEADERS) FileOperations.cpp
	$(CPP) $(CFLAGS) -c FileOperations.cpp

GetDate.o:	$(HEADERS) GetDate.cpp
	$(CPP) $(CFLAGS) -c GetDate.cpp

HSV.o:	$(HEADERS) HSV.cpp
	$(CPP) $(CFLAGS) -c HSV.cpp

LinearAxis.o:	$(HEADERS) LinearAxis.cpp
	$(CPP) $(CFLAGS) -c LinearAxis.cpp

LRL_CreateFileName.o:   $(HEADERS) LRL_CreateFileName.cpp
	$(CPP) $(CFLAGS) -c LRL_CreateFileName.cpp

LRL_inverse.o:   $(HEADERS) LRL_inverse.cpp
	$(CPP) $(CFLAGS) -c LRL_inverse.cpp

LRL_MaximaTools.o:   $(HEADERS) LRL_MaximaTools.cpp
	$(CPP) $(CFLAGS) -c LRL_MaximaTools.cpp

LRL_RandTools.o:   $(HEADERS) LRL_RandTools.cpp
	$(CPP) $(CFLAGS) -c LRL_RandTools.cpp

LRL_StringTools.o:   $(HEADERS) LRL_StringTools.cpp
	$(CPP) $(CFLAGS) -c LRL_StringTools.cpp

LRL_Vector3.o:   $(HEADERS) LRL_Vector3.cpp
	$(CPP) $(CFLAGS) -c LRL_Vector3.cpp

RGB.o:   $(HEADERS) RGB.cpp
	$(CPP) $(CFLAGS) -c RGB.cpp

spline_under_tension.o:   $(HEADERS) spline_under_tension.cpp
	$(CPP) $(CFLAGS) -c spline_under_tension.cpp

SuperFastHash.o:   $(HEADERS) SuperFastHash.cpp
	$(CPP) $(CFLAGS) -c SuperFastHash.cpp

SVG_Tools.o:   $(HEADERS) SVG_Tools.cpp
	$(CPP) $(CFLAGS) -c SVG_Tools.cpp

TriangleAreaFromSides.o:   $(HEADERS) TriangleAreaFromSides.cpp
	$(CPP) $(CFLAGS) -c TriangleAreaFromSides.cpp   

LRL_Tools.a:	$(OBJECTS)
	cat $(OBJECTS) > LRL_Tools.a

