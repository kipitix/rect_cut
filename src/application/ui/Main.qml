import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: root

    width: 1024
    height: 768
    visible: true
    title: qsTr("Rect Cut")

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            Action { text: qsTr("&New...") }
            Action { text: qsTr("&Open...") }
            Action { text: qsTr("&Save") }
            Action { text: qsTr("Save &As...") }
            MenuSeparator { }
            Action { text: qsTr("&Quit") }
        }
        Menu {
            title: qsTr("&Edit")
            Action { text: qsTr("Cu&t") }
            Action { text: qsTr("&Copy") }
            Action { text: qsTr("&Paste") }
        }
        Menu {
            title: qsTr("&Help")
            Action { text: qsTr("&About") }
        }
    }

    SplitView {
        id: splitView

        anchors.fill: parent

        orientation: Qt.Horizontal

        Input {
            id: input

            SplitView.fillHeight: true
            SplitView.minimumWidth: 300
        }

        Plane {
            id: plane

            SplitView.fillHeight: true
            SplitView.minimumWidth: 300
        }
    }
}
