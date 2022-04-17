import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0


Window {
    id: root
    modality: Qt.ApplicationModal
    title: qsTr("Результат")
    width: 380
    height: 50

    property int currentIndex: -1

    GridLayout {
        anchors {
            left: parent.left;
            top: parent.top;
            right: parent.right;
            margins: 10
        }
        columns: 2

        Label {
            id: countLab
            Layout.alignment: Qt.AlignRight
            text: qsTr("Количество найденных кафе:")
        }
        Label {
            id: textCount
            Layout.fillWidth: true
        }

    }

    function countCafes(cuisine){
        textCount.text = count(cuisine);
        countLab.text = qsTr("Количество найденных кафе с типом кухни \"" + cuisine + "\" равно:");
        root.show()
    }
 }

