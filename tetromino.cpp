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
    int pi;
    switch (m_rotation % 4)
    {
    case 0: // 0 degrees                // 0  1  2  3
        pi = py * 4 + px;               // 4  5  6  7
        break;                          // 8  9 10 11
                                        //12 13 14 15

    case 1: // 90 degrees               //12  8  4  0
        pi = 12 + py - (px * 4);        //13  9  5  1
        break;                          //14 10  6  2
                                        //15 11  7  3

    case 2: // 180 degrees              //15 14 13 12
        pi = 15 - (py * 4) - px;        //11 10  9  8
        break;                          // 7  6  5  4
                                        // 3  2  1  0
    case 3: // 270 degrees              // 3  7 11 15
        pi = 3 - py + (px * 4);         // 2  6 10 14
        break;                          // 1  5  9 13
    }
    return pi;
}

QColor Tetromino::getPos(QColor val, int posX, int posY)
{
    if((posX >= m_posX) && (posY >= m_posY) && (posX < m_posX + 4) && (posY < m_posY + 4)){
        return m_container[rotate(posX-m_posX, posY-m_posY)];
    }else{
        return val;
    }
}
