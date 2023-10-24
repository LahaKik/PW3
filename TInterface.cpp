#include "TInterface.h"

void TInterface::Calculate()
{
    Matrix matrix(size, GetValues());
    number det = matrix.Determinant();
    uint rank = matrix.ComputeRank();

    DeterminantLabel->setText("Determinant:" + QString::fromStdString(std::to_string(det.decimal())));
    RankLabel->setText("Rank:" + QString::fromStdString(std::to_string(rank)));
}

void TInterface::Transpose()
{
    Matrix matrix(size, GetValues());
    matrix.SetTransposed();
    for (uint i = 0; i < size; i++)
    {
        for (uint j = 0; j < size; j++)
        {
            LEditArr[i][j][0]->setText(QString::fromStdString(std::to_string(matrix.GetValue(i, j).upNum)));
            LEditArr[i][j][1]->setText(QString::fromStdString(std::to_string(matrix.GetValue(i, j).downNum)));
        }
    }
}


number* TInterface::GetValues()
{
	number* values = new number[size * size];
    uint k = 0;
    for (uint i = 0; i < size; i++)
    {
        for (uint j = 0; j < size; j++)
        {
            values[k] = number(LEditArr[i][j][0]->text().toUInt(), LEditArr[i][j][1]->text().toUInt());
            k++;
        }
    }
    return values;
}

void AdditionalInterface::Confirm()
{
    if (SizeValue->text().toUInt() > 15)
    {
        QMessageBox warning = QMessageBox(this);
        warning.setText("Value is too much or negative");

        warning.exec();
        return;
    }
    size = SizeValue->text().toUInt();
    
    fc = new TInterface(size);
    fc->show();
    this->hide();
}