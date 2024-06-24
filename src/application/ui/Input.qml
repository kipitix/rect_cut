import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import Qt.labs.qmlmodels

Item {
    id: root

    width: 500
    height: 500

    HorizontalHeaderView {
        id: horizontalHeader
        anchors.left: tableView.left
        anchors.top: parent.top
        syncView: tableView
        clip: false
        model: [qsTr("Width"), qsTr("Height"), qsTr("Count"), qsTr("Color"), qsTr("Action")]
    }

    VerticalHeaderView {
        id: verticalHeader
        anchors.top: tableView.top
        anchors.left: parent.left
        syncView: tableView
        clip: false
    }

    TableView {
        id: tableView
        anchors.left: verticalHeader.right
        anchors.top: horizontalHeader.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        clip: false

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
                    text: model.display
                    selectByMouse: true
                    implicitWidth: 100
                    onTextEdited: model.display = text
                    validator: DoubleValidator {
                        decimals: 2
                        locale: Qt.locale().toString()
                        notation: DoubleValidator.StandardNotation
                    }
                    visible: model.row !== tableView.model.rowCount-1
                }
            }
            DelegateChoice {
                column: 1
                delegate: TextField {
                    text: model.display
                    selectByMouse: true
                    implicitWidth: 100
                    onTextEdited: model.display = text
                    validator: DoubleValidator {
                        decimals: 2
                        locale: Qt.locale().toString()
                        notation: DoubleValidator.StandardNotation
                    }
                    visible: model.row !== tableView.model.rowCount-1
                }
            }
            DelegateChoice {
                column: 2
                delegate: TextField {
                    text: model.display
                    selectByMouse: true
                    implicitWidth: 100
                    onTextEdited: model.display = text
                    validator: IntValidator {
                        locale: Qt.locale().toString()
                    }
                    visible: model.row !== tableView.model.rowCount-1
                }
            }
            DelegateChoice {
                column: 3
                delegate: Rectangle {
                    implicitWidth: 100
                    color: model.display
                    visible: model.row !== tableView.model.rowCount-1

                    MouseArea {
                        id: colorMouseArea
                        anchors.fill: parent
                        onClicked: {
                            colorDialog.selectedColor = model.display;
                            colorDialog.rowToSetColor = model.row;
                            colorDialog.visible = true;
                            // colorDialog.open();
                        }
                    }

                    // onAccepted: model.display = text
                }
            }
            DelegateChoice {
                column: 4
                delegate: Button {
                    implicitWidth: 100
                    text: model.display
                    onClicked: {
                        if (model.row === tableView.model.rowCount-1) {
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

    Dialog {
        id: removeDialog

        property int rowToRemove: -1

        x: (root.width - width) / 2
        y: (root.height - height) / 2
        parent: ApplicationWindow.overlay
        width: 300
        height: 100

        title: "Remove"
        modal: true
        contentItem: Label {
            text: qsTr("Remove item?")
        }

        standardButtons: Dialog.Yes | Dialog.No

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

        // x: (root.width - width) / 2
        // y: (root.height - height) / 2
        // parent: ApplicationWindow.overlay

        // title: "Color"


        // selectedColor: tableView.model.getRow(rowToSetColor).color
        onAccepted: {
            let rowData = tableView.model.getRow(rowToSetColor);
            rowData.color = selectedColor;
            tableView.model.setRow(rowToSetColor, rowData);
            // console.log(tableView.model.getRow(rowToSetColor));
            rowToSetColor = -1;
        }
    }

}
