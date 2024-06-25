import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import Qt.labs.qmlmodels

Item {
    id: root

    width: 500
    height: 500

    GroupBox {
        id: actionsGroupBox

        anchors.top: root.top
        anchors.left: root.left
        anchors.right: root.right

        title: qsTr("Actions")

        Button {
            anchors.fill: parent

            text: qsTr("Calculate")

            onClicked: {
                planeAPI.calculate();
            }
        }
    }


    GroupBox {
        id: planeGroupBox

        anchors.top: actionsGroupBox.bottom
        anchors.left: root.left
        anchors.right: root.right

        title: qsTr("Plane")

        Row {

            spacing: 10

            Row {

                spacing: 5

                Label {
                    text: qsTr("Width:")
                    verticalAlignment: Text.AlignVCenter
                }

                TextField {
                    implicitWidth: 60

                    text: planeViewModel.size.width

                    validator: DoubleValidator {
                        decimals: 2
                        locale: Qt.locale().toString()
                        notation: DoubleValidator.StandardNotation
                    }

                    onTextEdited: {
                        planeAPI.setPlaneWidth(text);
                    }
                }
            }

            Row {

                spacing: 5

                Label {
                    text: qsTr("Height:")
                    verticalAlignment: Text.AlignVCenter
                }

                TextField {
                    implicitWidth: 60

                    text: planeViewModel.size.height

                    validator: DoubleValidator {
                        decimals: 2
                        locale: Qt.locale().toString()
                        notation: DoubleValidator.StandardNotation
                    }
                }
            }

        }
    }

    GroupBox {
        id: chunksGroupBox

        anchors.top: planeGroupBox.bottom
        anchors.left: root.left
        anchors.right: root.right
        anchors.bottom: root.bottom

        title: qsTr("Chunks")

        HorizontalHeaderView {
            id: horizontalHeader
            anchors.left: tableView.left
            anchors.top: parent.top
            syncView: tableView
            clip: false
            resizableColumns: false
            model: [qsTr("Width"), qsTr("Height"), qsTr("Count"), qsTr("Color"), qsTr("Action")]

            columnWidthProvider: function(column) {
                return 100;
            }
        }

        VerticalHeaderView {
            id: verticalHeader
            anchors.top: tableView.top
            anchors.left: parent.left
            syncView: tableView
            clip: false
            resizableRows: false
        }

        TableView {
            id: tableView
            anchors.left: verticalHeader.right
            anchors.top: horizontalHeader.bottom
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            clip: false

            ScrollBar.vertical: ScrollBar { }

            columnSpacing: 1
            rowSpacing: 1

            model: TableModel {
                TableModelColumn { display: "width" }
                TableModelColumn { display: "height" }
                TableModelColumn { display: "count" }
                TableModelColumn { display: "color" }
                TableModelColumn { display: "action" }

                rows: [
                    {
                        width: 100.0,
                        height: 100.0,
                        count: 1,
                        color: "black",
                        action: "➕"
                    }
                ]
            }
            delegate: DelegateChooser {


                DelegateChoice {
                    column: 0
                    delegate: TextField {

                        property bool isLastRow: (model.row === tableView.model.rowCount-1)

                        text: model.display
                        selectByMouse: true
                        implicitWidth: tableView.width / 5
                        onTextEdited: model.display = text
                        validator: DoubleValidator {
                            decimals: 2
                            locale: Qt.locale().toString()
                            notation: DoubleValidator.StandardNotation
                        }
                        visible: !isLastRow
                    }
                }
                DelegateChoice {
                    column: 1
                    delegate: TextField {

                        property bool isLastRow: (model.row === tableView.model.rowCount-1)

                        text: model.display
                        selectByMouse: true
                        implicitWidth: tableView.width / 5
                        onTextEdited: model.display = text
                        validator: DoubleValidator {
                            decimals: 2
                            locale: Qt.locale().toString()
                            notation: DoubleValidator.StandardNotation
                        }
                        visible: !isLastRow
                    }
                }
                DelegateChoice {
                    column: 2
                    delegate: TextField {

                        property bool isLastRow: (model.row === tableView.model.rowCount-1)

                        text: model.display
                        selectByMouse: true
                        implicitWidth: tableView.width / 5
                        onTextEdited: model.display = text
                        validator: IntValidator {
                            locale: Qt.locale().toString()
                        }
                        visible: !isLastRow
                    }
                }
                DelegateChoice {
                    column: 3
                    delegate: Rectangle {

                        property bool isLastRow: (model.row === tableView.model.rowCount-1)

                        implicitWidth: tableView.width / 5
                        color: model.display
                        visible: !isLastRow

                        MouseArea {
                            id: colorMouseArea
                            anchors.fill: parent
                            onClicked: {
                                colorDialog.selectedColor = model.display;
                                colorDialog.rowToSetColor = model.row;
                                colorDialog.visible = true;
                            }
                        }
                    }
                }
                DelegateChoice {
                    column: 4
                    delegate: Button {

                        property bool isLastRow: (model.row === tableView.model.rowCount-1)

                        implicitWidth: tableView.width / 5
                        text: model.display

                        ToolTip.visible: hovered
                        ToolTip.text: isLastRow ? qsTr("Add new chunk") : qsTr("Remove this chunk")

                        onClicked: {
                            if (isLastRow) {
                                // Add
                                tableView.model.insertRow(model.row,
                                                          {
                                                              width: 100.0,
                                                              height: 100.0,
                                                              count: 1,
                                                              color: "black",
                                                              action: "🗑️"
                                                          }
                                                          );
                            } else {
                                // Remove
                                removeDialog.rowToRemove = model.row;
                                removeDialog.visible = true;
                            }
                        }
                    }
                }
            }
        }

        MessageDialog {
            id: removeDialog

            property int rowToRemove: -1

            title: "Remove"
            text: qsTr("Remove item?")

            buttons: MessageDialog.Yes | MessageDialog.No

            onAccepted: {
                removeDialog.visible = false;
                tableView.model.removeRow(rowToRemove);
                rowToRemove = -1;
            }

            onRejected: {
                removeDialog.visible = false;
                rowToRemove = -1;
            }
        }

        ColorDialog {
            id: colorDialog

            property int rowToSetColor: -1

            onAccepted: {
                let rowData = tableView.model.getRow(rowToSetColor);
                rowData.color = selectedColor;
                tableView.model.setRow(rowToSetColor, rowData);
                rowToSetColor = -1;
            }
        }
    }
}
