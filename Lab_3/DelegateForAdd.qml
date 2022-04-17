import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0


Window {
    id: root
    modality: Qt.ApplicationModal
    title: qsTr("Данные о кафе")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 200
    maximumHeight: 200

    GridLayout {
        anchors {
            left: parent.left;
            top: parent.top;
            right: parent.right;
            bottom: cancelBtn.top;
            margins: 8
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
        visible: {textName.length>0 && textAddress.length>0}
        anchors {
            right: cancelBtn.left;
            verticalCenter: cancelBtn.verticalCenter;
            rightMargin: 10
        }
        text: qsTr("Добавить запись")
        width: 110
        onClicked: {
            root.hide()
            add(textName.text, textAddress.text, textCuisine.text, textOpeningHours.text)
        }
    }
    Button {
        id: cancelBtn
        anchors {
            right: parent.right;
            bottom: parent.bottom;
            rightMargin: 10;
            bottomMargin: 10
        }
        text: qsTr("Отмена")
        width: 90
        onClicked: {
             root.hide()
        }
    }

    //изменение статуса видимости окна диалога
    onVisibleChanged: {
      if (visible) {
          textName.text = ""
          textAddress.text = ""
          textCuisine.text = ""
          textOpeningHours.text = ""
      }
    }
 }
