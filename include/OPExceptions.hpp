#include <stdexcept>
using std::runtime_error;

// Class DivideByZeroException definition.
// DivideByZeroException objects should be thrown by functions
// upon detecting division-by-zero exceptions
class DivideByZeroException : public runtime_error {
    public:
        // constructor specifies default error message
        DivideByZeroException() : runtime_error( "attempted to divide by zero" ) {}
};