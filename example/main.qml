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
    width: 200
    height: 200
    color: 'red'
    property int index: 0

    Rectangle {
        x: 20; y: 30
        width: 20; height: 20
        color: 'green'
        NumberAnimation on x {
            to: 160; duration: 10000
        }
    }

    Timer {
        id: delay
        interval: 10000/4 // 5 frames, each 96x96 px
        repeat: true
        triggeredOnStart: true
        onTriggered: shoot()
    }

    function shoot() {
        shorty.shoot('sample'+index+'.png')
        if(index == 4) {
            delay.stop()
            Qt.quit()
        }
        index += 1
    }



    Component.onCompleted: {
        delay.start()
    }
}
