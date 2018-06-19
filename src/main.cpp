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

#include <QtCore>
#include <QtGui>
#include <QtQml>
#include <QtQuick>
#include "shorty.h"

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);
    QCoreApplication::setApplicationName("shorty");
    QCoreApplication::setApplicationVersion("1.0");
    // parse command line args
    QCommandLineParser parser;
    parser.setApplicationDescription("Screenshot tool");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("script", "qml script to run");
    parser.process(app);

    // extract script argument
    const QStringList args = parser.positionalArguments();
    if(args.count() != 1) {
        qFatal("no qml script provided");
    }
    QString script = args.at(0);

    // setup shorty
    QQuickView view;
    Shorty shorty(&view);
    view.rootContext()->setContextProperty(QLatin1String("shorty"), &shorty);

    view.setSource(QUrl::fromLocalFile(script));
    QObject::connect(view.engine(), SIGNAL(quit()), QGuiApplication::instance(), SLOT(quit()));

    // run shorty
    view.show();
    return app.exec();
}
