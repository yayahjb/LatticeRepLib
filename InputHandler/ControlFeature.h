#ifndef INPUTHANDLER_CONTROL_FEATURE_H
#define INPUTHANDLER_CONTROL_FEATURE_H

#include <string>
#include <ostream>

// In ControlFeature.h
class ControlFeature {
public:
   virtual ~ControlFeature() = default;
   virtual std::string getFeatureState() const = 0;
   virtual void writeToStream(std::ostream& os) const = 0;
   virtual bool handleInput(const std::string& command, const std::string& value) = 0;
};

#endif // INPUTHANDLER_CONTROL_FEATURE_H
