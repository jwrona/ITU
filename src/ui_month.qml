import QtQuick 1.1

Item {
    id: base
    width: 1024
    height: 500
    opacity: 0.7

    // size properties
    property int days_shown: 7
    property int rows_shown: 6

    //font properties
    property double font_size_factor: 1.8
    property int font_style: Text.Normal //font style
    property color font_style_color: "black" //for instance shadow color, depends on font_style
    property color font_color: "black"

    //border properties
    property int border_width: 0
    property color border_color: "black"
    property double spacing_width: 4

    //grid color properties
    property string alfa: "#40"
    property string grid_col: "FF8080"
    property string col_head_col: "80FF80"
    property color res_grid_col: alfa + grid_col
    property color red_col_head_col: alfa + col_head_col

    //event default properties
    property color default_event_color: "transparent"
    property int events_in_day: 3

    Row {
        width: parent.width
        height: parent.height
    spacing: spacing_width
    Column {
    id: month_num_id
    width: parent.width / 40
    height: parent.width
    spacing: spacing_width
    Repeater {
        model: grid_id.rows
        Rectangle {
            property int column_row_index: index
        objectName: "week_num" + column_row_index
        property string week_num: ""
        color: "pink"
        width: parent.width
        height: {(modelData == 0)? grid_id.col_head_h : grid_id.day_col_h}
        Text {
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: Math.min(height / font_size_factor, 15)
            //elide: Text.ElideRight
            clip: true
            text: {(column_row_index == 0)? "#" : week_num}
        }
        }
    }
    }
    Grid { //grid for month view
        id: grid_id
    width: parent.width - month_num_id.width
    height: parent.height
        columns: days_shown
        rows: rows_shown + 1 // + 1 -> header
        spacing: spacing_width

    property double col_head_h: height / 25
    property double day_col_h: ((height - col_head_h) / rows_shown) - spacing
    property double day_col_w: (width / days_shown) - spacing

    property double day_num_h: day_col_h / 4

        Repeater { //repeater for header
            model: ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
            Rectangle { //header rectangles
                color: red_col_head_col
                width: grid_id.day_col_w
                height: grid_id.col_head_h
        border.width: border_width
        border.color: border_color
                Text {
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: height / font_size_factor
            //elide: Text.ElideRight
            clip: true
                    text: modelData;
                }
            }
        }

        Repeater { //over rows (5 rows, header allready drawn)
            model: grid_id.rows - 1
            Repeater { //over columns (7 days)
                model: grid_id.columns
                property int grid_row_index: index
                Rectangle {
            property int grid_day_index: index
                    property string txt: ""
                    objectName: (grid_row_index+1) + ":" + grid_day_index
                    border.width: border_width
                    border.color: border_color
                    color: res_grid_col
                    width: grid_id.day_col_w
                    height: grid_id.day_col_h
            Column {
                width: parent.width
                height: parent.height-2
            Text {
                objectName:  (grid_row_index + 1) + ":"+ (grid_day_index + 1)
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                width: parent.width
                height: parent.height / 4
                font.pixelSize: height / font_size_factor
                clip: true
                text: txt
            }
            Repeater { //events in one day generator
                model: base.events_in_day
                Rectangle {
                property int grid_event_index: index
                property string event_text: ""
                objectName: (grid_row_index + 1) + ":" + (grid_day_index + 1) + ":" + (grid_event_index + 1)
                color: default_event_color
                width: parent.width
                height: parent.height / (events_in_day + 1)
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    style: font_style
                    styleColor: font_style_color
                    font.pixelSize: height / font_size_factor
                    elide: Text.ElideRight
                    color: font_color
                    text: event_text
                }
                }
            }
            }
        }
        }
    }
    }
    }
}
