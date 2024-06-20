import QtQuick

Item {

    id: root

    Rectangle {
        id: plane

        width: planeViewModel.size.width
        height: planeViewModel.size.height

        border {
            width: 1
            color: "black"
        }
    }

    Repeater {
        id: chunks

        model: planeViewModel.chunkList

        delegate: Rectangle {
            property var chunkData: modelData

            // x: chunkData.x
            // y: chunkData.y
            width: chunkData.width
            height: chunkData.height

            border {
                width: 1
                color: chunkData.color
            }

            color: dragArea.drag.active ? chunkData.color : "white"

            Drag.active: dragArea.drag.active
            Drag.hotSpot.x: 10
            Drag.hotSpot.y: 10

            MouseArea {
                id: dragArea
                anchors.fill: parent
                drag.target: parent
            }

            Text {
                anchors.fill: parent

                text: chunkData.uuid
            }
        }
    }

    Item {
        id: priv

        // ListModel {
        //     id: chunkModel

        //     ListElement {
        //         x: 10
        //         y: 10
        //         width: 50
        //         height: 50
        //         color: "green"
        //     }

        //     ListElement {
        //         x: 100
        //         y: 100
        //         width: 50
        //         height: 50
        //         color: "red"
        //     }
        // }

    }

}
