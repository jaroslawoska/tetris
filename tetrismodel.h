#ifndef TETRISMODEL_H
#define TETRISMODEL_H

#include <array>
#include <QAbstractTableModel>
#include <QPoint>
#include <QKeyEvent>
#include <QtQml/qqml.h>
#include <tetromino.h>

class TetrisModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT

    Q_ENUMS(Roles)
public:
    enum Roles {
        CellRole
    };

    QHash<int, QByteArray> roleNames() const override {
        return {
            { CellRole, "value" }
        };
    }

    explicit TetrisModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    Q_INVOKABLE void nextStep();
    Q_INVOKABLE void clear();
    Q_INVOKABLE void keyPressed(Qt::Key & key);

private:
    static std::size_t cellIndex(const QPoint &coordinates);

private:
    static constexpr int m_width = 10;
    static constexpr int m_height = 22;
    static constexpr int m_size = m_width * m_height;

    using StateContainer = std::array<bool, m_size>;
    StateContainer m_screenState;
    StateContainer m_staticState;
    Tetromino m_tetromino;
    void refreshCanva();
    bool checkCollision(Tetromino &tetromin);
};

#endif // TETRISMODEL_H
