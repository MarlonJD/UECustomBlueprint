#include "MyEnums.generated.h"
#pragma once

UENUM()
enum class ECount : uint8 {
    one,
    two,
    three,
};

UENUM()
enum class TreeType : uint8 {
    get,
    post,
    put,
    del,
    test,
};