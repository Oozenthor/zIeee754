#include "zieee754.h"
// 11111111111111111111111111111111 = 0xFFFFFFFF
// 10000000000000000000000000000000 = 0x80000000 - sign part
// 01111111100000000000000000000000 = 0x7F800000 - exponent part
// 00000000011111111111111111111111 = 0x007FFFFF - mantassa part

ZIeee754::ZIeee754() { }

ZIeee754::~ZIeee754() { }

qreal ZIeee754::toIeee754(quint32 binary32) // Single precision (32 bit)
{
    // extract ieee754 bit components
        bsign = (binary32 & 0x80000000) >> 31;
    bexponent = (binary32 & 0x7F800000) >> 23;
    bmantassa = (binary32 & 0x007FFFFF);
    // qDebug() << bsign << bexponent << bmantassa;

    // convert bit parts to doubles and calculate real values
        sign = qPow(-1, static_cast<qreal>(bsign));
    exponent = qPow(2, static_cast<qreal>(bexponent) - 127);
    mantassa = (static_cast<qreal>(bmantassa) / qPow(2, 23)) + 1;
    // qDebug() << sign << exponent << mantassa;

    return(sign * exponent * mantassa);   // final result
}
