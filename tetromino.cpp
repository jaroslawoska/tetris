#include "tetromino.h"
#include <QDebug>
#include <QRandomGenerator>

Tetromino::Tetromino(QObject *parent) : QObject(parent)
{
    genATetromino();
}

Tetromino::Tetromino(Tetromino &tetromino)
{
    m_posX = tetromino.m_posX;
    m_posY = tetromino.m_posY;
    m_rotation = tetromino.m_rotation;
    m_container = tetromino.m_container;
}

Tetromino & Tetromino::operator=(Tetromino &tetromino)
{
    m_posX = tetromino.m_posX;
    m_posY = tetromino.m_posY;
    m_rotation = tetromino.m_rotation;
    m_container = tetromino.m_container;
    return *this;
}

void Tetromino::genATetromino()
{
    m_container = m_tetromino[QRandomGenerator::global()->bounded(0,MAX_TERMINOS)];
}

bool Tetromino::inside(int x_max, int y_max)
{
//    for (std::size_t i = 0; i < m_width; ++i) {
//        for (std::size_t j = 0; j < m_height; ++j) {
//            if(m_container[rotate(i,j)] && ){

//            }else{

//            }
//        }
//    }
    return false;
}

void Tetromino::clear()
{
    m_posX = 0;
    m_posY = 0;
}

void Tetromino::moveLeft()
{
    m_posX-=1;
}

void Tetromino::moveRight()
{
    m_posX+=1;
}

void Tetromino::moveDown()
{
    m_posY+=1;
    if(m_posY > 22){
        clear();
        genATetromino();
    }
}

void Tetromino::rotate()
{
    ++m_rotation %= 4;
}

int Tetromino::rotate(int px, int py)
{

    std::function<int(int,int)> r[4]  = {[](int px, int py){return py * 4 + px;},
                 [](int px, int py){return 12 + py - (px * 4);},
                 [](int px, int py){return 15 - (py * 4) - px;},
                 [](int px, int py){return 3 - py + (px * 4);}};

    return r[m_rotation % 4](px, py);

}

QColor Tetromino::getPos(QColor val, int posX, int posY)
{
    if((posX >= m_posX) && (posY >= m_posY) && (posX < m_posX + 4) && (posY < m_posY + 4)){
        return m_container[rotate(posX-m_posX, posY-m_posY)];
    }else{
        return val;
    }
}

std::list<QColor> Tetromino::getBrick()
{
    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_height; ++j) {
            QColor color = m_tetromino.getBrick(i,j);
            newValues[i + j * m_width] = m_tetromino.getBrick(i,j);
        }
    }
    return m_container[rotate(posX, posY)];
}
