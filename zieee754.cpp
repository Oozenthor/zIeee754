#include "zieee754.h"
// 11111111111111111111111111111111 = 0xFFFFFFFF
// 10000000000000000000000000000000 = 0x80000000 - sign part
// 01111111100000000000000000000000 = 0x7F800000 - exponent part
// 00000000011111111111111111111111 = 0x007FFFFF - mantissa part

ZIeee754::ZIeee754() { }

ZIeee754::~ZIeee754() { }

qreal ZIeee754::toIeee754(quint32 binary32) // Single precision IEEE754 (32 bit)
{
    // extract ieee754 bit components
        bsign = (binary32 & 0x80000000) >> 31;
    bexponent = (binary32 & 0x7F800000) >> 23;
    bmantissa = (binary32 & 0x007FFFFF);
    // qDebug() << bsign << bexponent << bmantissa;

    // convert bit parts to doubles and calculate real values
        sign = qPow(-1, static_cast<qreal>(bsign));
    exponent = qPow( 2, static_cast<qreal>(bexponent) - 127);
    mantissa = 1 + (static_cast<qreal>(bmantissa) / qPow(2, 23));
    // qDebug() << sign << exponent << mantissa;

    return(sign * exponent * mantissa);   // final result
}
