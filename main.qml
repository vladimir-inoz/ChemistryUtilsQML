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

    footer: TabBar {
        id: bar
        width: parent.width
        TabButton {
            text: qsTr("Home")
        }
        TabButton {
            text: qsTr("Discover")
        }
        TabButton {
            text: qsTr("Activity")
        }
    }

    StackLayout {
        currentIndex: bar.currentIndex
        Item {
            id: homeTab
            ColumnLayout {
                anchors.fill: parent

                ChartView {
                    anchors.fill: parent
                      id: view
                      theme: ChartView.ChartThemeBrownSand
                      antialiasing: true

                      PieSeries {
                          id: pieSeries
                          PieSlice { label: "eaten"; value: 94.9 }
                          PieSlice { label: "not yet eaten"; value: 5.1 }
                      }
                  }

                TextField {
                    id: tx1
                    placeholderText: qsTr("Введите формулу")
                }

                Button {
                    text: "Рассчитать"
                    onClicked: {
                        backend.input = tx1.text
                        dataSource.update(view.series(0));
                    }
                }

                Text {
                    text: backend.output
                }

            }
        }
        Item {
            id: discoverTab
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Discover"
            }
        }
        Item {
            id: activityTab
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Activity"
            }
        }
    }

}
