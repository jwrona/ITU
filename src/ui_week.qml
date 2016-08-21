import QtQuick 1.1

Item {
    id: base
    width: 1024
    height: 500
    opacity: 0.7

    // size properties
    property int hours_shown: 24
    property int days_shown: 7

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
    property string col_head_col: "80FF80"
    property string row_col_head_col: "80FF80"
    property string odd: "FFE0E0"
    property string even:"FFFFFF"
    property color res_col_head_col: alfa + col_head_col
    property color res_row_col_head_col: alfa + row_col_head_col
    property color res_odd: alfa + odd
    property color res_even: alfa + even

    //event default properties
    property string default_event_color: "FF0000"
    property color res_default_event_color: alfa + default_event_color

    Grid { //grid for week view
        id: grid_id
        width: parent.width
        //height: parent.height - current_date_id.height
        height: parent.height
        columns: base.days_shown + 1 // + 1 -> header
        rows: base.hours_shown + 1 // + 1 -> header
        spacing: base.spacing_width

        property double col_head_h: height / rows
        property double row_head_w: width / 24
        property double day_col_h: (height - col_head_h) / hours_shown - spacing
        property double day_col_w: (width - row_head_w) / days_shown - spacing

        Repeater { //repeater for header
            model: ["", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
            Rectangle { //header rectangles
                objectName: {(modelData == "")? "week_num" : "header_"+index}
                color: {(modelData == "")? "transparent" : res_col_head_col }
                width: {(modelData == "")? grid_id.row_head_w : grid_id.day_col_w }
                height: grid_id.col_head_h;
                border.width: border_width
                border.color: border_color
                property string week_num: ""
                Text {
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    width: parent.width
                    height: parent.height
                    font.pixelSize: height / font_size_factor
                    //elide: Text.ElideRight
                    clip: true
                    style: font_style
                    styleColor: font_style_color
                    color: font_color
                    text: {(modelData == "")? week_num : modelData}
                }
            }
        }

        Repeater { //over rows (24 hours, header allready drawn)
            model: grid_id.rows - 1
            Repeater { //over columns (7 days + 1 header)
                model: grid_id.columns
                property int grid_hour_index: index
                Rectangle {
                    property int grid_day_index: index
                    objectName: grid_hour_index + ":" + grid_day_index
                    border.width: border_width
                    border.color: border_color
                    color: {(grid_day_index <= 0)? res_row_col_head_col : ((grid_hour_index & 1)? res_odd : res_even)}
                    width: {(index <= 0)? grid_id.row_head_w : grid_id.day_col_w}
                    height: grid_id.day_col_h;
                    Text {
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        //elide: Text.ElideRight
                        clip: true
                        font.pixelSize: height / font_size_factor
                        style: font_style
                        styleColor: font_style_color
                        color: font_color
                        text: {(grid_day_index <= 0)? (grid_hour_index + ":00") : ""}
                    }
                    Rectangle {
                        objectName: (grid_hour_index + 1) + ":" + grid_day_index
                        id: objectName
                        color: res_default_event_color
                        property string event_text: ""
                        //initial event position (day and hour)
                        property int begin_hour: grid_hour_index //0-23
                        property int begin_minute: 0 //0-59

                        //event position
                        property int end_hour: grid_hour_index //0-23
                        property int end_minute: 0 //0-59

                        property int hdx: end_hour - begin_hour

                        //event content
//                        y: parent.height * ((begin_minute % 60) / 60)
                        width: parent.width
                        height: parent.height * (hdx + ((end_minute % 60) / 60)) - y
                        Text {
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            font.pixelSize: Math.min(parent.height / font_size_factor, 15)
                            elide: Text.ElideRight
                            clip: true
                            wrapMode: Text.WordWrap
                            style: font_style
                            styleColor: font_style_color
                            color: font_color
                            text: parent.event_text
                        }
                    }
                }
            }
        }
    }
}
