import QtQml 2.12
import QtQuick 2.12
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import TetrisModel 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 10 * 16
    height: 22 * 16
    minimumWidth: 10 * 16
    minimumHeight: 22 * 16

    color: "grey"
    title: qsTr("Tetris")

    TableView {
        id: tableView
        anchors.fill: parent

        rowSpacing: 1
        columnSpacing: 1

        ScrollBar.horizontal: ScrollBar {}
        ScrollBar.vertical: ScrollBar {}

        delegate: Rectangle {
            id: cell
            implicitWidth: 15
            implicitHeight: 15

            required property var model
            required property bool value

            color: value ? "blue" : "grey"
        }

        model: TetrisModel {
            id: tetrisModel
        }
    }

    Item {
        anchors.fill: parent
        focus: true

        Keys.onPressed: {
            tetrisModel.keyPressed(event.key);
      }
    }

    Timer {
        id: timer
        interval: 1000
        running: true
        repeat: true
        onTriggered: tetrisModel.nextStep()
    }
}
