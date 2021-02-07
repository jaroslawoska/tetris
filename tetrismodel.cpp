#include <QFile>
#include <QTextStream>
#include <QRect>
#include <QRandomGenerator>
#include "tetrismodel.h"

TetrisModel::TetrisModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    clear();
}

int TetrisModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return height;
}

int TetrisModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return width;
}

QVariant TetrisModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != CellRole)
        return QVariant();

    return QVariant(m_screenState[cellIndex({index.column(), index.row()})]);
}

bool TetrisModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != CellRole || data(index, role) == value)
        return false;

    m_screenState[cellIndex({index.column(), index.row()})] = value.toBool();
    emit dataChanged(index, index, {role});

    return true;
}

Qt::ItemFlags TetrisModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

void TetrisModel::nextStep()
{
    StateContainer newValues;
    for (std::size_t i = 0; i < size; ++i) {
        newValues[i] = static_cast<bool>(QRandomGenerator::global()->bounded(0,2));
    }
    m_screenState = std::move(newValues);

    emit dataChanged(index(0, 0), index(height - 1, width - 1), {CellRole});
}

void TetrisModel::clear()
{
    m_screenState.fill(false);
    emit dataChanged(index(0, 0), index(height - 1, width - 1), {CellRole});
}

std::size_t TetrisModel::cellIndex(const QPoint &coordinates)
{
    return std::size_t(coordinates.y() * width + coordinates.x());
}
