#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <iostream>

namespace mtm {
    /** Parent Exception */
    class Exception : public std::exception {};

    /** Exceptions for DateWrap.h */
    class InvalidDate : public Exception {};
    class NegativeDays : public Exception {};

    /** Exceptions for base_event.h */
    class InvalidStudent : public Exception {};

    

}





#endif /**   EXCEPTIONS_H_   */