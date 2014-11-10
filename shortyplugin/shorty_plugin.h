#ifndef SHORTY_PLUGIN_H
#define SHORTY_PLUGIN_H

#include <QQmlExtensionPlugin>

class ShortyPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
    
public:
    void registerTypes(const char *uri);
};

#endif // SHORTY_PLUGIN_H

