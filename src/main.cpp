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

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtQuick/QtQuick>
#include <QtQml/QtQml>
#include "shorty.h"

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);
    QQuickView view;
    if(app.arguments().count() != 2) {
        qFatal("no qml script provided");
    }
    QString script = app.arguments().at(1);

    Shorty shorty(&view);
    view.rootContext()->setContextProperty(QLatin1String("shorty"), &shorty);

    view.setSource(QUrl::fromLocalFile(script));
    QObject::connect(view.engine(), SIGNAL(quit()), QGuiApplication::instance(), SLOT(quit()));


    view.show();
    return app.exec();
}
