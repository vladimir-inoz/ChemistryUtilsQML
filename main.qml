import QtQuick 2.6
import QtQuick.Controls 2.0
import io.qt.examples.backend 1.0
import QtQuick.Layouts 1.3
import QtCharts 2.0

ApplicationWindow {
    id: root
    width: 300
    height: 480
    visible: true

    ColumnLayout {
        anchors.fill: parent

        TextField {
            Layout.fillWidth: true
            id: tx1
            placeholderText: qsTr("Введите формулу")
        }

        Button {
            Layout.fillWidth: true
            text: "Рассчитать"
            onClicked: {
                backend.input = tx1.text
                dataSource.update(view.series(0));
            }
        }

        Text {
            Layout.alignment: Qt.AlignCenter
            text: backend.output
            font.pointSize: 24
        }

        ChartView {
            Layout.alignment: Qt.AlignCenter
            Layout.fillHeight: true
            Layout.fillWidth: true

            id: view
            theme: ChartView.ChartThemeBrownSand
            antialiasing: true

            PieSeries {
                id: pieSeries
                PieSlice { label: "eaten"; value: 94.9 }
                PieSlice { label: "not yet eaten"; value: 5.1 }
            }
        }

    }

}
