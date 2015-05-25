#include "ieee754example.h"
#include "ui_ieee754example.h"

Ieee754Example::Ieee754Example(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ieee754Example)
{
    ui->setupUi(this);
    ui->textOut->setFontPointSize(12);

    ZIeee754 iee;

    qreal answer;

    ui->textOut->insertPlainText(QString("Zero test\r"));
    answer = iee.toIeee754(0x00000000);
    ui->textOut->insertPlainText(QString("0.0: %1\r\r").arg(answer, 0, 'f', 18));

    ui->textOut->insertPlainText(QString("Unity test\r"));
    answer = iee.toIeee754(0x3F800000);
    ui->textOut->insertPlainText(QString("1.0: %1\r\r").arg(answer, 0, 'f', 18));

    ui->textOut->insertPlainText(QString("Sign test\r"));
    answer = iee.toIeee754(0x447A0000);
    ui->textOut->insertPlainText(QString("+1000: %1\r").arg(answer, 0, 'f', 0));
    answer = iee.toIeee754(0xC47A0000);
    ui->textOut->insertPlainText(QString("-1000: %1\r\r").arg(answer, 0, 'f', 0));

    ui->textOut->insertPlainText(QString("Hex precision tests\r"));
    answer = iee.toIeee754(0xC9742400);
    ui->textOut->insertPlainText(QString("-1000000.0000: %1\r").arg(answer, 0, 'f', 5));
    answer = iee.toIeee754(0xC9742401);
    ui->textOut->insertPlainText(QString("-1000000.0625: %1\r").arg(answer, 0, 'f', 5));
    answer = iee.toIeee754(0xC9742402);
    ui->textOut->insertPlainText(QString("-1000000.1250: %1\r\r").arg(answer, 0, 'f', 5));

    ui->textOut->insertPlainText(QString("Decimal precision tests\r"));
    answer = iee.toIeee754(0x4B3C614E);
    ui->textOut->insertPlainText(QString("12345678: %1\r").arg(answer, 0, 'f', 1));
    answer = iee.toIeee754(0x4B3C614F);
    ui->textOut->insertPlainText(QString("12345679: %1\r").arg(answer, 0, 'f', 1));
    answer = iee.toIeee754(0x4B3C6150);
    ui->textOut->insertPlainText(QString("12345680: %1\r\r").arg(answer, 0, 'f', 1));

    ui->textOut->insertPlainText(QString("Maximum value test ((1−2^−24) × 2^128)\r"));
    answer = iee.toIeee754(0x7F7FFFFF);
    ui->textOut->insertPlainText(QString("3.4028234663852886e+38:\r %1\r\r").arg(answer, 0, 'e', 17));

    ui->textOut->insertPlainText(QString("Minimum value test (2^-126)\r"));
    answer = iee.toIeee754(0x007FFFFF);
    ui->textOut->insertPlainText(QString("1.1754943508222875e-38:\r %1\r").arg(answer, 0, 'e', 17));
    ui->textOut->insertPlainText(QString("(This test is rarely correct)"));
}

Ieee754Example::~Ieee754Example()
{
    delete ui;
}
