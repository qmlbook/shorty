/*
 * Shorty - a QML screenshot utility
 * Copyright (C) 2012-14 Johan Thelin <e8johan@gmail.com>
 *                   and Juergen Bocklage-Ryannel <juergen@ryannel.org>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

import QtQuick 2.0

Rectangle {
    width: 512
    height: 96+32
    color: 'black'
    property int imageCount: 5
    property string imagePrefix: 'sample'


    Row {
        anchors.centerIn: parent
        spacing: 4
        Repeater {
            model: imageCount

            Rectangle {
                width: 96; height: 96
                Image {
                    source: imagePrefix + index + '.png'
                }
            }
        }
    }

    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 4
        spacing: 4
        Repeater {
            model: 32
            Rectangle {
                width: 12; height: 8
                color: '#fefefe'
                border.color: Qt.darker(color)
                smooth: true
            }
        }
    }

    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        y: parent.height-4-height
        spacing: 4
        Repeater {
            model: 32
            Rectangle {
                width: 12; height: 8
                color: '#fefefe'
                border.color: Qt.darker(color)
                smooth: true
            }
        }
    }
}
