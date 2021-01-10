#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <iostream>

namespace mtm {

    class Exception : public std::exception {
    };
    class InvalidDate : public Exception {
    };
    class NegativeDays : public Exception {
    };


}





#endif /**   EXCEPTIONS_H_   */