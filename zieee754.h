#ifndef ZIEEE754_H
#define ZIEEE754_H

#include <QDebug>
#include <QtGlobal>
#include <QtCore/qmath.h>

class ZIeee754
{
public:
    ZIeee754();
    ~ZIeee754();

    qreal toIeee754(quint32 binary32);

private:
    quint32 bsign;
    quint32 bexponent;
    quint32 bmantassa;

    qreal sign;
    qreal exponent;
    qreal mantassa;
};

#endif // ZIEEE754_H
