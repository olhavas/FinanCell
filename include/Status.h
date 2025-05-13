#ifndef Status_h
#define Status_h



enum IOStatus {
    SUCCESS,
    FILE_NOT_OPEN
};

enum ValidationStatus
{
    VALID,
    DESCRIPTION_NOT_VALID,
    AMOUNT_INCORRECT = 2137
};


#endif
