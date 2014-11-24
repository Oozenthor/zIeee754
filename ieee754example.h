#ifndef IEEE754EXAMPLE_H
#define IEEE754EXAMPLE_H

#include <QDialog>
#include "zieee754.h"

namespace Ui {
class Ieee754Example;
}

class Ieee754Example : public QDialog
{
    Q_OBJECT

public:
    explicit Ieee754Example(QWidget *parent = 0);
    ~Ieee754Example();

private:
    Ui::Ieee754Example *ui;
};

#endif // IEEE754EXAMPLE_H
