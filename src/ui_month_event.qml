import QtQuick 1.1

    Rectangle { //event
        objectName: "defaultEvent"
        property int column: 2 //0-6
        property int row: 2 //0-4
        property string content: "WWWWWWWWWWWWWW"

        color: "transparent"
        x: (day_col_w * column) + border_width
        y: (col_head_h + (row * day_col_h)) + border_width
  width: day_col_w - (2 * border_width)
  height:day_col_h - (2 * border_width)
        Text {
          anchors.centerIn: parent
    font.pointSize: font_size
    style: font_style
    styleColor: font_style_color
    color: font_color
          text: parent.content
        }
    }

