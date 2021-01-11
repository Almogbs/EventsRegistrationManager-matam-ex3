#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <iostream>

namespace mtm {
    /** Parent Exception */
    class Exception : public std::exception {};

    /** Exceptions for DateWrap */
    class InvalidDate : public Exception {};
    class NegativeDays : public Exception {};

    /** Exceptions for BaseEvent */
    class InvalidStudent : public Exception {};
    class AlreadyRegistered : public Exception {};
    class RegistrationBlocked : public Exception {};
    class NotRegistered : public Exception {};
    class AlreadyInvited : public Exception {};
    

    

}





#endif /**   EXCEPTIONS_H_   */