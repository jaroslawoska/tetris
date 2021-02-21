#ifndef CANVA_H
#define CANVA_H

#include <QObject>

class Canva : public QObject
{
    Q_OBJECT
public:
    explicit Canva(QObject *parent = nullptr);

signals:

};

#endif // CANVA_H
