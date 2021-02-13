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

    return m_height;
}

int TetrisModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_width;
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

void TetrisModel::clear()
{
    m_screenState.fill(QColorConstants::Gray);
    m_staticState.fill(QColorConstants::Gray);
    m_tetromino.clear();
    emit dataChanged(index(0, 0), index(m_height - 1, m_width - 1), {CellRole});
}

void TetrisModel::refreshCanva()
{
    StateContainer newValues;
    newValues = std::move(m_staticState);
    for (std::size_t i = 0; i < m_width; ++i) {
        for (std::size_t j = 0; j < m_height; ++j) {
            newValues[i + j * m_width] = m_tetromino.getPos(QColorConstants::Gray, i, j);
        }
    }
    m_screenState = std::move(newValues);
    emit dataChanged(index(0, 0), index(m_height - 1, m_width - 1), {CellRole});
}

bool TetrisModel::checkCollision(Tetromino &tetromino)
{
    if(tetromino.inside(m_width, m_height)){
        return true;
    }else{
        return false;
    }

//    for (std::size_t i = 0; i < m_width; ++i) {
//        for (std::size_t j = 0; j < m_height; ++j) {
//            newValues[i + j * m_width] = tetromino.getPos(false, i, j);
//        }
//    }
    return false;
}

void TetrisModel::nextStep()
{
    m_tetromino.moveDown();
    refreshCanva();
}

void TetrisModel::keyPressed(Qt::Key & key)
{
    Tetromino tetromino(m_tetromino);
    if (key == Qt::Key_Left) tetromino.moveLeft();
    if (key == Qt::Key_Right) tetromino.moveRight();
    if (key == Qt::Key_Down) tetromino.moveDown();
    if (key == Qt::Key_Shift) tetromino.rotate();

    if(checkCollision(tetromino)){

    }else{
        m_tetromino = tetromino;
    }
    refreshCanva();
}

std::size_t TetrisModel::cellIndex(const QPoint &coordinates)
{
    return std::size_t(coordinates.y() * m_width + coordinates.x());
}
