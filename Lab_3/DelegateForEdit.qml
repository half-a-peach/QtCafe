import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0

Window {
    id: root
    modality: Qt.ApplicationModal
    title: qsTr("Данные о кафе")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 200
    maximumHeight: 200

    property int currentIndex: -1

    GridLayout {
        anchors {
            left: parent.left;
            top: parent.top;
            right: parent.right;
            bottom: buttonCancel.top;
            margins: 10
        }
        columns: 2

        Label {
            Layout.alignment: Qt.AlignRight  //выравнивание по правой стороне
            text: qsTr("Название кафе")
        }
        TextField {
            id: textName
            Layout.fillWidth: true
            placeholderText: qsTr("Введите название")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Адрес")
        }
        TextField {
            id: textAddress
            Layout.fillWidth: true
            placeholderText: qsTr("Введите адрес")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Тип кухни")
        }
        TextField {
            id: textCuisine
            Layout.fillWidth: true
            placeholderText: qsTr("Введите тип кухни")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Время работы")
        }
        TextField {
            id: textOpeningHours
            Layout.fillWidth: true
            placeholderText: qsTr("Введите время работы")
        }
    }

    Button {
        visible: {textName.length>0 && textAddress.length>0 && root.currentIndex <0}
        anchors {
            right: buttonCancel.left;
            verticalCenter: buttonCancel.verticalCenter;
            rightMargin: 10
        }
        text: qsTr("Добавить запись")
        width: 100
        onClicked: {
            root.hide()
            add(textName.text, textAddress.text, textCuisine.text, textOpeningHours.text)
        }
    }
    Button {
        visible: {root.currentIndex>=0}
        anchors {
            right: buttonCancel.left;
            verticalCenter: buttonCancel.verticalCenter;
            rightMargin: 10
        }
        text: qsTr("Сохранить")
        width: 100
        onClicked: {
            root.hide()
            edit(textName.text, textAddress.text, textCuisine.text, textOpeningHours.text, root.currentIndex)
        }
    }
    Button {
        id: buttonCancel
        anchors {
            right: parent.right;
            bottom: parent.bottom;
            rightMargin: 10;
            bottomMargin: 10
        }
        text: qsTr("Отмена")
        width: 100
        onClicked: {
             root.hide()
        }
    }

    function execute(name, address, cuisine, openingHours, index){
        textName.text = name
        textAddress.text = address
        textCuisine.text = cuisine
        textOpeningHours.text = openingHours
        root.currentIndex = index

        root.show()
    }
 }
