#pragma once
#include <qtwidgets-config.h>
#include <qwidget.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include "Matrix.h"
#include <string>

class TInterface :
    public QWidget
{
    Q_OBJECT
    QLineEdit**** LEditArr;
    QPushButton* CalculateBut, * TransposeBut;
    QLabel* DeterminantLabel, * RankLabel;
    uint size;
    const float Scale = 1.5;

    number* GetValues();
public:
    TInterface(uint size, QWidget *parent = 0) : size(size)
    {
        setWindowTitle("Matrix");
        setFixedSize(60 * size * Scale + 20, 50 * size * Scale + 30);
        LEditArr = new QLineEdit *** [size];
        for (uint i = 0; i < size; i++)
        {
            *(LEditArr + i) = new QLineEdit ** [size];
            for (uint j = 0; j < size; j++)
            {
                *(*(LEditArr + i) + j) = new QLineEdit * [2];
                **(*(LEditArr + i) + j) = new QLineEdit("", this);
                *(*(*(LEditArr + i) + j) + 1) = new QLineEdit("", this);
                LEditArr[i][j][0]->setGeometry((30 * j + 10) * Scale, (40 * i + 10) * Scale, 15 * Scale, 15 * Scale);
                LEditArr[i][j][1]->setGeometry((30 * j + 10) * Scale, (40 * i + 25) * Scale, 15 * Scale, 15 * Scale);
            }
        }
        CalculateBut = new QPushButton("Calculate", this);
        CalculateBut->setGeometry((40 * size) * Scale, 10 * Scale, 50 * Scale, 30 * Scale);

        TransposeBut = new QPushButton("Transpose", this);
        TransposeBut->setGeometry((40 * size) * Scale, 40 * Scale, 50 * Scale, 30 * Scale);        

        DeterminantLabel = new QLabel("Determinant:", this);
        DeterminantLabel->setGeometry(15 * Scale, (40 * size + 20) * Scale, 70 * Scale, 20 * Scale);

        RankLabel = new QLabel("Rank:", this);
        RankLabel->setGeometry(15 * Scale, (40 * size) * Scale, 30 * Scale, 20 * Scale);

        connect(CalculateBut, SIGNAL(pressed()), this, SLOT(Calculate()));
        connect(TransposeBut, SIGNAL(pressed()), this, SLOT(Transpose()));
    }


    ~TInterface() 
    { 

        for (uint i = 0; i < size; i++)
        {
            for (uint j = 0; j < size; j++)
            {
                delete** (*(LEditArr + i) + j);
                delete* (*(*(LEditArr + i) + j) + 1);
                delete[]* (*(LEditArr + i) + j);
            }
            delete[] * (LEditArr + i);
        }
        delete[] LEditArr;
        delete CalculateBut;
        delete TransposeBut;
        delete DeterminantLabel;
        delete RankLabel;
    }
public slots:
    void Calculate();
    void Transpose();
};

class AdditionalInterface
    : public QWidget
{
    Q_OBJECT
    QPushButton* ConfirmBut;
    QLabel* SizeLabel;
    QLineEdit* SizeValue;
    uint size;
    TInterface* fc;
public:
    AdditionalInterface(TInterface* fc, QWidget* parent = 0) : fc(fc)
    {
        setWindowTitle("Size");
        setFixedSize(180, 100);

        SizeLabel = new QLabel("Enter size:", this);
        SizeLabel->setGeometry(45, 10, 55, 20);

        SizeValue = new QLineEdit("", this);
        SizeValue->setGeometry(105, 10, 30, 20);

        ConfirmBut = new QPushButton("Continue", this);
        ConfirmBut->setGeometry(5, 45, 170, 45);

        connect(ConfirmBut, SIGNAL(pressed()), this, SLOT(Confirm()));
    }


    ~AdditionalInterface()
    {
        delete ConfirmBut;
        delete SizeLabel;
        delete SizeValue;
    }
public slots:
    void Confirm();
};