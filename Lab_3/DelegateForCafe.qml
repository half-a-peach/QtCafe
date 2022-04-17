import QtQuick 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0

Rectangle {
    id: cafeItem
    readonly property color backgroundColor: "#F0FFF7"  //цвет пунктов списка
    readonly property color selectedBackgroundColor: "#C9FFF3"  //цвет выделенного элемента списка

    property bool isCurrent: cafeItem.ListView.view.currentIndex === index
    property bool selected: cafeItemMouseArea.containsMouse || isCurrent
    property variant cafeData: model //свойство для доступа к данным

    width: parent ? parent.width : cafeList.width
    height: 100

    MouseArea {
               id: mouseArea
               anchors.fill: parent
            }
    //состояния rectangle
    states: [
        State {
            when: selected
            PropertyChanges {
                target: cafeItem;
                color: isCurrent ? palette.highlight : selectedBackgroundColor
            }
        },

        State {
            when: !selected
            PropertyChanges {
                target: cafeItem;
                color: isCurrent ? palette.highlight : backgroundColor
            }
        }
    ]

    MouseArea {
        id: cafeItemMouseArea
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            cafeItem.ListView.view.currentIndex = index
            cafeItem.forceActiveFocus()
        }
    }
    Item {
        id: itemOfCafes
        width: parent.width
        height: 80
        Column{
            id: t2
            anchors.left: parent.left
            anchors.leftMargin: 10
            width: 200
            anchors.verticalCenter: parent.verticalCenter
            Text {
                id: t1
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Название:"
                color: "Black"
                font.pointSize: 13
            }
            Text {
                id: textName
                anchors.horizontalCenter: parent.horizontalCenter
                text: cafeName
                color: "Black"
                font.pointSize: 16
                font.bold: true
            }
        }
        Column{
            id: t3
            anchors.left: t2.right
            anchors.leftMargin: 10
            width: 300
            anchors.verticalCenter: parent.verticalCenter
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Адрес:"
                color: "Black"
                font.pointSize: 13
            }
            Text {
                id: textAddress
                anchors.horizontalCenter: parent.horizontalCenter
                text: cafeAddress
                color: "Black"
                font.pointSize: 16
                font.bold: true
            }
        }
        Column{
            id: t4
            anchors.left: t3.right
            anchors.leftMargin: 10
            width: 200
            anchors.verticalCenter: parent.verticalCenter
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Тип кухни:"
                color: "Black"
                font.pointSize: 13
            }
            Text {
                id: textCuisine
                anchors.horizontalCenter: parent.horizontalCenter
                color: "Black"
                text: cafeCuisine
                font.pointSize: 16
                font.bold: true
            }
        }
        Column{
            anchors.left: t4.right
            anchors.leftMargin: 10
            width: 200
            anchors.verticalCenter: parent.verticalCenter
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Время работы:"
                color: "Black"
                font.pointSize: 13
            }
            Text {
                id: textOpeningHours
                anchors.horizontalCenter: parent.horizontalCenter
                text: cafeOpeningHours
                color: "Black"
                font.pointSize: 16
                font.bold: true
            }
        }
    }
}
