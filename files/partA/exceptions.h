#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <iostream>

namespace mtm {
    /** Parent Exception */
    class Exception : public std::exception {};

    /** Exceptions for partA */
    class InvalidDate : public Exception {};
    class NegativeDays : public Exception {};

    /** Exceptions for partB */
    class InvalidStudent : public Exception {};
    class AlreadyRegistered : public Exception {};
    class RegistrationBlocked : public Exception {};
    class NotRegistered : public Exception {};
    class AlreadyInvited : public Exception {};
    class NotSupported : public Exception {};

    /** Exceptions for partC */
    class DateMismatch : public Exception {};
    class InvalidNumber : public Exception {};
    class InvalidInterval : public Exception {};
    class EventAlreadyExists : public Exception {};
    class EventDoesNotExist : public Exception {};
}





#endif /**   EXCEPTIONS_H_   */