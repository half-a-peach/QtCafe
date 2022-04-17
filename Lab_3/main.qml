import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0

Window {
    visible: true
    width: 1000
    height: 500
    title: qsTr("Каталог кафе")

    SystemPalette {
          id: palette;
          colorGroup: SystemPalette.Active
       }

    Rectangle{
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: addBtn.top
        anchors.bottomMargin: 6
        color: "#DAFFC4"

        ListView {
            id: cafeList
            anchors.fill: parent
            model: cafeModel
            delegate: DelegateForCafe{}
            clip: true
            focus: true
        }
    }

    Button {
        id: addBtn
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        anchors.leftMargin: 8
        anchors.right: labelCount.left
        text: "Добавить запись"
        width: 130
        onClicked: windowAdd.show()
    }

    Button {
        id: editBtn
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: delBtn.left
        anchors.rightMargin: 8
        text: "Редактировать запись"
        width: 150
        onClicked: {
            var cafeName = cafeList.currentItem.cafeData.cafeName
            var cafeAddress = cafeList.currentItem.cafeData.cafeAddress
            var cafeCuisine = cafeList.currentItem.cafeData.cafeCuisine
            var cafeOpeningHours = cafeList.currentItem.cafeData.cafeOpeningHours

            windowEdit.execute(cafeName, cafeAddress, cafeCuisine, cafeOpeningHours, cafeList.currentIndex)
        }
    }

    Button {
        id: delBtn
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right:parent.right
        anchors.rightMargin: 8
        text: "Удалить запись"
        width: 100
        enabled: cafeList.currentIndex >= 0
        onClicked: del(cafeList.currentIndex)
    }

        Label {
            id: labelCount
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 12
            anchors.right: textFindcuisine.left
            anchors.rightMargin: 8
            anchors.leftMargin: 8
            Layout.alignment: Qt.AlignRight
            text: qsTr("Укажите тип кухни:")
        }
        TextField {
            id: textFindcuisine
            Layout.fillWidth: true
            placeholderText: qsTr("")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.leftMargin: 8
            anchors.right: countBtn.left
            anchors.rightMargin: 8
        }
        Button {
            id: countBtn
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            anchors.right: editBtn.left
            anchors.leftMargin: 8
            anchors.rightMargin: 8
            text: "Вычислить"
            width: 100
            enabled: textFindcuisine.text !== ""
            onClicked: windowAnswer.countCafes(textFindcuisine.text)
        }

    DelegateForAdd {
        id: windowAdd
    }
    DelegateForEdit {
        id: windowEdit
    }
    DelegateForAnswer {
        id: windowAnswer
    }
}
