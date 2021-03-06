#pragma once
#include <QObject>
#include <QLoggingCategory>
#include <memory>
#include <string>
#include <KService>
#include <QSet>
#include <QString>
#include "albert/extension.h"
#include "albert/queryhandler.h"
Q_DECLARE_LOGGING_CATEGORY(qlc)

using namespace std;

namespace ExtraKdeSettings {

    class Private;

    class Extension final :
        public Core::Extension, 
        public Core::QueryHandler {
        
        Q_OBJECT
        Q_PLUGIN_METADATA(IID ALBERT_EXTENSION_IID FILE "metadata.json")

        public:

            Extension();
            ~Extension() override;

            QString name() const override { return "Extra KDE Settings"; }
            QWidget *widget(QWidget *parent = nullptr) override;
            void handleQuery(Core::Query * query) const override;

        private:

            std::unique_ptr<Private> d;
            QString generateQuery(const QString &strList) const;

    };
}
