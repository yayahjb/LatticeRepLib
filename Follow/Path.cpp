#include "Path.h"


Path Path::generatePointPath(const LatticeCell& startPoint, const int numPoints) {
   // Convert to primitive before Niggli reduction
   G6 primitive = startPoint.toPrimitive();
   G6 niggliReduced;
   Niggli::Reduce(primitive, niggliReduced);
   const S6 startS6(startPoint.getCell());
   const S6 endS6(niggliReduced);
   const std::string latticeType = startPoint.getLatticeType();

   Path path;
   path.reserve(numPoints);

   for (int i = 0; i < numPoints; ++i) {
      const double t = i / static_cast<double>(numPoints - 1);
      S6 currentS6 = startS6 * (1.0 - t) + endS6 * t;
      if (!PathPointIsValid(currentS6)) currentS6 = MakeInvalidS6();

      path.emplace_back(LatticeCell(G6(currentS6), latticeType),
         LatticeCell(G6(endS6), latticeType));
   }
   return path;
}

Path Path::generateLinePath(const LatticeCell& startPoint, const LatticeCell& endPoint, const int numPoints) {
   const S6 startS6(startPoint.getCell());
   const S6 endS6(endPoint.getCell());
   const std::string startType = startPoint.getLatticeType();
   const std::string endType = endPoint.getLatticeType();

   Path path;
   path.reserve(numPoints);

   for (int i = 0; i < numPoints; ++i) {
      const double t = i / static_cast<double>(numPoints - 1);
      S6 currentS6 = startS6 * (1.0 - t) + endS6 * t;
      if (!PathPointIsValid(currentS6)) currentS6 = MakeInvalidS6();
      path.emplace_back(LatticeCell(G6(currentS6), startType),
         LatticeCell(G6(endS6), endType));
   }
   return path;
}

Path Path::generateChordPath(const LatticeCell& point1, const LatticeCell& point2, const int numPoints) {
   G6 primitive1 = point1.toPrimitive();
   G6 primitive2 = point2.toPrimitive();
   G6 reduced1G6, reduced2G6;
   Niggli::Reduce(primitive1, reduced1G6);
   Niggli::Reduce(primitive2, reduced2G6);

   const S6 p1S6(point1.getCell());
   const S6 p2S6(point2.getCell());
   const S6 reduced1(reduced1G6);
   const S6 reduced2(reduced2G6);
   const std::string type1 = point1.getLatticeType();
   const std::string type2 = point2.getLatticeType();

   Path path;
   path.reserve(numPoints);

   for (int i = 0; i < numPoints; ++i) {
      const double t = i / static_cast<double>(numPoints - 1);
      S6 mobile1 = p1S6 * (1.0 - t) + reduced1 * t;
      S6 mobile2 = p2S6 * (1.0 - t) + reduced2 * t;
      if (!PathPointIsValid(mobile1)) mobile1 = MakeInvalidS6();
      if (!PathPointIsValid(mobile2)) mobile2 = MakeInvalidS6();
      path.emplace_back(LatticeCell(G6(mobile1), type1),
         LatticeCell(G6(mobile2), type2));
   }
   return path;
}

Path Path::generateChord3Path(const LatticeCell& mobile1, const LatticeCell& mobile2,
   const LatticeCell& target, const int numPoints) {
   const S6 m1S6(mobile1.getCell());
   const S6 m2S6(mobile2.getCell());
   S6 initialDirection = m2S6 - m1S6;
   const double separation = initialDirection.Norm();
   initialDirection = initialDirection * (1.0 / separation);
   const S6 initialMidpoint = (m1S6 + m2S6) * 0.5;
   const S6 targetS6(target.getCell());
   const std::string type1 = mobile1.getLatticeType();
   const std::string type2 = mobile2.getLatticeType();

   Path path;
   path.reserve(numPoints);

   for (int i = 0; i < numPoints; ++i) {
      const double t = i / static_cast<double>(numPoints - 1);
      S6 currentMidpoint = initialMidpoint * (1.0 - t) + targetS6 * t;
      S6 point1 = currentMidpoint - initialDirection * (separation * 0.5);
      S6 point2 = currentMidpoint + initialDirection * (separation * 0.5);
      if (!PathPointIsValid(point1)) point1 = MakeInvalidS6();
      if (!PathPointIsValid(point2)) point2 = MakeInvalidS6();
      path.emplace_back(LatticeCell(G6(point1), type1),
         LatticeCell(G6(point2), type2));
   }
   return path;
}

Path Path::generateSplinePath(const int numPoints) { return Path(); }

Path Path::generateTrianglePath(const LatticeCell& point1, const LatticeCell& point2,
   const LatticeCell& point3, const int numPoints) {
   const S6 p1S6(point1.getCell());
   const S6 p2S6(point2.getCell());
   const S6 p3S6(point3.getCell());
   const std::string type1 = point1.getLatticeType();
   const std::string type2 = point2.getLatticeType();

   Path path;
   path.reserve(numPoints);

   for (int i = 0; i < numPoints; ++i) {
      const double t = i / static_cast<double>(numPoints - 1);
      S6 mobile1 = p1S6 * (1.0 - t) + p3S6 * t;
      S6 mobile2 = p2S6 * (1.0 - t) + p3S6 * t;
      if (!PathPointIsValid(mobile1)) mobile1 = MakeInvalidS6();
      if (!PathPointIsValid(mobile2)) mobile2 = MakeInvalidS6();
      path.emplace_back(LatticeCell(G6(mobile1), type1),
         LatticeCell(G6(mobile2), type2));
   }
   return path;
}